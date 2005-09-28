// This file may be redistributed and modified only under the terms of
// the GNU General Public License (See COPYING for details).
// Copyright (C) 2000,2001 Alistair Riddoch

#include "Pedestrian.h"

#include "Entity.h"

#include "common/const.h"
#include "common/debug.h"
#include "common/log.h"
#include "common/compose.hpp"

#include "common/Tick.h"

#include <wfmath/atlasconv.h>

#include <Atlas/Objects/Operation.h>
#include <Atlas/Objects/Anonymous.h>

using Atlas::Message::Element;
using Atlas::Objects::Operation::Move;
using Atlas::Objects::Entity::Anonymous;

static const bool debug_flag = false;

Pedestrian::Pedestrian(Entity & body) : Movement(body)
{
}

Pedestrian::~Pedestrian()
{
}

double Pedestrian::getTickAddition(const Point3D & coordinates,
                                   const Vector3D & velocity) const
{
    // This may seem a little weird. Everything is handled in squares to
    // reduce the number of square roots that have to be calculated. In
    // this case only one is required.
    double basic_square_distance = velocity.sqrMag()
                                   * consts::square_basic_tick;
    const Point3D & target = m_collPos.isValid() ? m_collPos : m_targetPos;
    if (target.isValid()) {
        double square_distance = squareDistance(coordinates, target);
        debug( std::cout << "basic_distance: " << basic_square_distance
                         << std::endl << std::flush;);
        debug( std::cout << "distance: " << square_distance << std::endl
                         << std::flush;);
        if (basic_square_distance > square_distance) {
            debug( std::cout << "\tshortened tick" << std::endl << std::flush;);
            return sqrt(square_distance / basic_square_distance)
                        * consts::basic_tick;
        }
    }
    return consts::basic_tick;
}

/// \brief Calculate the updated position of the entity since the last
/// move operation.
///
/// The does not modify the entity, but determines a new Location based
/// on the velocity of the entity, time elapsed, whether any collision
/// occurs, and whether the entity has reached its target.
/// @return 1 if no update was made, or 0 otherwise
int Pedestrian::getUpdatedLocation(Location & return_location)
{
    const double & current_time = m_body.m_world->getTime();
    double time_diff = current_time - m_body.m_location.timeStamp();
    // Don't update time yet, but FIXME it must be done when the operation
    // is actually generated. In fact FIXME it should be updated when the
    // operation is dispatched. It may be a good idea to put a time stamp
    // in Location, as it will be useful elsewhere, and will eliminate the
    // race condition.
    m_body.m_location.update(current_time);

    if (!updateNeeded(m_body.m_location)) {
        debug( std::cout << "No update" << std::endl << std::flush;);
        return 1;
    }

    Location new_location(m_body.m_location);
    // m_velocity and m_orient are of no interest yet. They contain old data,
    // and definitly should be the same as our current stuff.
    // new_location.m_velocity = m_velocity;
    // new_location.orientation() = m_orient;

    double vel_square_mag = m_body.m_location.velocity().sqrMag();

    // Update location
    Point3D new_coords = m_updatedPos.isValid() ? m_updatedPos
                                                : m_body.m_location.pos();
    new_coords += (m_body.m_location.velocity() * time_diff);
    const Point3D & target = m_collPos.isValid() ? m_collPos : m_targetPos;
    if (target.isValid()) {
        Point3D new_coords2 = new_coords;
        new_coords2 += (m_body.m_location.velocity() * (consts::basic_tick / 10.0));
        // The values returned by squareDistance are squares, so
        // cannot be used except for comparison
        double dist = squareDistance(target, new_coords);
        double dist2 = squareDistance(target, new_coords2);
        debug( std::cout << "dist: " << dist << "," << dist2 << std::endl
                         << std::flush;);
        if (dist2 > dist) {
            debug( std::cout << "target achieved";);
            new_coords = target;
            if (m_collLocChange) {
                static const Quaternion identity(Quaternion().identity());
                debug(std::cout << "CONTACT " << m_collEntity->getId()
                                << std::endl << std::flush;);
                if (m_collEntity == new_location.m_loc->m_location.m_loc) {
                    debug(std::cout << "OUT" << target
                                    << new_location.m_loc->m_location.pos()
                                    << std::endl << std::flush;);
                    const Quaternion & collOrientation = m_body.m_location.m_loc->m_location.orientation().isValid() ?
                                                         m_body.m_location.m_loc->m_location.orientation() :
                                                         identity;
                    // FIXME take account of orientation
                    new_coords = new_coords.toParentCoords(m_body.m_location.m_loc->m_location.pos(), collOrientation);
                    new_location.m_orientation *= collOrientation;
                    new_location.m_velocity.rotate(collOrientation);
                    // FIXME velocity take account of orientation
                    if (m_targetPos.isValid()) {
                        m_targetPos = m_targetPos.toParentCoords(m_body.m_location.m_loc->m_location.pos(), collOrientation);
                    }
                } else if (m_collEntity->m_location.m_loc==new_location.m_loc) {
                    debug(std::cout << "IN" << std::endl << std::flush;);
                    // FIXME take account of orientation
                    const Quaternion & collOrientation = m_collEntity->m_location.orientation().isValid() ?
                                                         m_collEntity->m_location.orientation() :
                                                         identity;
                    new_coords = new_coords.toLocalCoords(m_collEntity->m_location.pos(), collOrientation);
                    new_location.m_orientation /= collOrientation;
                    new_location.m_velocity.rotate(collOrientation.inverse());
                    // FIXME velocity take account of orientation
                    if (m_targetPos.isValid()) {
                        m_targetPos = m_targetPos.toLocalCoords(m_collEntity->m_location.pos(), collOrientation);
                    }
                } else {
                    std::string msg = std::string("BAD COLLISION: ")
                                    + m_body.getId() + " with "
                                    + m_collEntity->getId()
                                    + ". Making no coord adjustment.";
                    log(ERROR, msg.c_str());
                }
                new_location.m_loc = m_collEntity;
                m_collEntity = NULL;
                m_collLocChange = false;
                m_collPos = Point3D();
            } else {
                Vector3D & new_velocity = new_location.m_velocity;
                if (m_collPos.isValid()) {
                    // Generate touch ops
                    // This code relies on m_collNormal being a unit vector
                    new_velocity -= m_collNormal * Dot(m_collNormal, new_velocity);
                    if ((new_velocity.mag() / consts::base_velocity) > 0.05) {
                        m_collPos = Point3D();
                        m_collEntity = NULL;
                        new_velocity.normalize();
                        new_velocity *= sqrt(vel_square_mag);
                        // FIXME flag as diverted, so destination based
                        // movement doesn't get screwed up
                    } else {
                        reset();
                        new_velocity = Vector3D(0,0,0);
                    }
                } else {
                    reset();
                    new_velocity = Vector3D(0,0,0);
                }
            }
        }
    }

    std::string mode("standing");

    if (m_body.has("mode")) {
        Element mode_attr;
        m_body.get("mode", mode_attr);
        if (mode_attr.isString()) {
            mode = mode_attr.String();
        } else {
            log(ERROR, String::compose("Mode on entity is a %1 in Pedestrain::getUpdatedLocation", Element::typeName(mode_attr.getType())).c_str());
        }
    }

    float z = m_body.m_world->constrainHeight(new_location.m_loc, new_coords,
                                              mode);
    debug(std::cout << "Height adjustment " << z << " " << new_coords.z()
                    << std::endl << std::flush;);

    new_coords.z() = z;

    new_location.m_pos = new_coords;
    m_updatedPos = new_coords;

    return_location = new_location;

    return 0;
}

Operation Pedestrian::generateMove(const Location & new_location)
{
    // Create move operation
    Move moveOp;
    moveOp->setTo(m_body.getId());

    // Set up argument for operation
    Anonymous move_arg;
    move_arg->setId(m_body.getId());

    // Walk out what the mode of the character should be.
    // Performed in squares to save on that critical sqrt() call
    double vel_square_mag = 0;
    if (new_location.velocity().isValid()) {
        vel_square_mag = new_location.velocity().sqrMag();
    }
    double square_speed_ratio = vel_square_mag / consts::square_base_velocity;

    float height = 0;
    if (m_body.m_location.bBox().isValid()) {
        height = m_body.m_location.bBox().highCorner().z() - 
                 m_body.m_location.bBox().lowCorner().z();
    }

    if (new_location.pos().z() < (0 - height * 0.75)) {
        move_arg->setAttr("mode", "swimming");
    } else {
        if (square_speed_ratio > 0.25) { // 0.5 ^ 2
            move_arg->setAttr("mode", "running");
        } else if (square_speed_ratio > 0.0025) { // 0.05 ^ 2
            move_arg->setAttr("mode", "walking");
        } else {
            move_arg->setAttr("mode", "standing");
        }
    }
    debug(std::cout << move_arg->getAttr("mode").asString() << std::endl << std::flush;);

    if (vel_square_mag > 0) {
        checkCollisions(new_location);
    }

    new_location.addToEntity(move_arg);
    moveOp->setArgs1(move_arg);

    return moveOp;
}
