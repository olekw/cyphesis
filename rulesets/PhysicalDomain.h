/*
 Copyright (C) 2014 Erik Ogenvik

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#ifndef PHYSICALDOMAIN_H_
#define PHYSICALDOMAIN_H_

#include "Domain.h"
#include "modules/Location.h"
#include "ModeProperty.h"

#include <sigc++/connection.h>

#include <LinearMath/btVector3.h>

#include <map>
#include <unordered_map>
#include <tuple>
#include <array>
#include <set>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>

namespace Mercator {
    class Segment;

    class Terrain;

    class TerrainMod;
}

class btDefaultCollisionConfiguration;

class btCollisionDispatcher;

class btBroadphaseInterface;

class btCollisionWorld;

class btSequentialImpulseConstraintSolver;

class PhysicalWorld;

class btRigidBody;

class btCollisionShape;

class btSphereShape;

class btCollisionObject;

class PropertyBase;

/**
 * @brief A regular physical domain, behaving very much like the real world.
 *
 * Things move using physical rules, and sights are calculated using line of sight.
 *
 */
class PhysicalDomain : public Domain
{
    public:
        explicit PhysicalDomain(LocatedEntity& entity);

        ~PhysicalDomain() override;

        void tick(double t, OpVector& res) override;

        bool isEntityVisibleFor(const LocatedEntity& observingEntity, const LocatedEntity& observedEntity) const override;

        void getVisibleEntitiesFor(const LocatedEntity& observingEntity, std::list<LocatedEntity*>& entityList) const override;

        std::list<LocatedEntity*> getObservingEntitiesFor(const LocatedEntity& observedEntity) const override;

        void addEntity(LocatedEntity& entity) override;

        void removeEntity(LocatedEntity& entity) override;

        void applyTransform(LocatedEntity& entity, const WFMath::Quaternion& orientation,
                            const WFMath::Point<3>& pos, const WFMath::Vector<3>& velocity,
                            std::set<LocatedEntity*>& transformedEntities) override;

        void refreshTerrain(const std::vector<WFMath::AxisBox<2>>& areas) override;

        void toggleChildPerception(LocatedEntity& entity) override;

    protected:

        friend class SteppingCallback;

        class PhysicalMotionState;

        class VisibilityCallback;

        struct BulletEntry
        {
            LocatedEntity* entity = nullptr;
            std::shared_ptr<btCollisionShape> collisionShape;
            btCollisionObject* collisionObject = nullptr;
            sigc::connection propertyUpdatedConnection;
            Location lastSentLocation;
            PhysicalMotionState* motionState = nullptr;

            btCollisionObject* visibilitySphere = nullptr;
            btCollisionObject* viewSphere = nullptr;

            /**
             * Set of entries which are observing by this.
             */
            std::set<BulletEntry*> observedByThis;
            /**
             * Set of entries which are observing this.
             */
            std::set<BulletEntry*> observingThis;

            btVector3 centerOfMassOffset;

            /**
             * Max speed when on solid ground, derived from the "speed-ground" property and cached for performance.
             */
            double speedGround;
            /**
             * Max speed when in water (swimming), derived from the "speed-water" property and cached for performance.
             */
            double speedWater;
            /**
             * Max speed when flying, derived from the "speed-flight" property and cached for performance.
             */
            double speedFlight;

            /**
             * The mode of the entity, as known by the physics system.
             */
            ModeProperty::Mode mode;

            /**
             * Set to true if the mode has been changed in a tick, which should be communicated in a Move op.
             */
            bool modeChanged;

            BulletEntry* attachedTo = nullptr;

            std::set<BulletEntry*> attachedEntities;

        };

        struct TerrainEntry
        {
            std::array<float, 65 * 65>* data;
            btRigidBody* rigidBody;
        };

        std::unordered_map<long, BulletEntry*> m_entries;

        std::set<BulletEntry*> m_movingEntities;
        std::set<BulletEntry*> m_lastMovingEntities;
        std::set<BulletEntry*> m_dirtyEntries;
        /**
         * A map of all submerged entities, and the water body they currently are submerged into.
         */
        std::map<BulletEntry*, btGhostObject*> m_submergedEntities;
        std::vector<WFMath::AxisBox<2>> m_dirtyTerrainAreas;

        std::unordered_map<long, std::tuple<Mercator::TerrainMod*, WFMath::Point<3>, WFMath::Quaternion, WFMath::AxisBox<2>>> m_terrainMods;


        struct PropelEntry
        {
            btRigidBody* rigidBody;
            BulletEntry* bulletEntry;
            btVector3 velocity;
            float stepHeight;
        };
        /**
         * @brief A map of all entities that currently are self-propelling.
         *
         * Each tick the propel force will be applied to these entities.
         */
        std::map<long, PropelEntry> m_propellingEntries;
        btDefaultCollisionConfiguration* m_collisionConfiguration;
        btCollisionDispatcher* m_dispatcher;
        btSequentialImpulseConstraintSolver* m_constraintSolver;
        btBroadphaseInterface* m_broadphase;
        PhysicalWorld* m_dynamicsWorld;

        btCollisionWorld* m_visibilityWorld;

        sigc::connection m_propertyAppliedConnection;

        float m_visibilityCheckCountdown;

        BulletEntry mContainingEntityEntry;

        Mercator::Terrain* m_terrain;

        /**
         * @brief Contains all terrain segments, as height fields.
         *
         * Each segment is 65*65 points.
         */
        std::unordered_map<std::string, TerrainEntry> m_terrainSegments;

        /**
         * Contains the six planes that make out the border, which matches the bounding box of the entity to which this
         * property belongs.
         */
        std::vector<btRigidBody*> m_borderPlanes;

        /**
         * Keeps track of all water bodies, which are ghost objects which we use to detect when entities move in and out of the water.
         */
        std::vector<btGhostObject*> m_waterBodies;

        /**
         * @brief Creates borders around the domain, which prevents entities from "escaping".
         *
         * This will be done by adding planes matching the bbox of the entity to which the domain belongs.
         */
        void createDomainBorders();

        /**
         * @brief Build all terrain pages.
         */
        void buildTerrainPages();

        /**
         * @brief Builds one terrain page from a Mercator segment.
         * @param segment
         */
        TerrainEntry buildTerrainPage(Mercator::Segment& segment);

        /**
         * Listener method for all child entities, called when their properties change.
         * @param name
         * @param prop
         * @param bulletEntry
         */
        void childEntityPropertyApplied(const std::string& name, PropertyBase& prop, BulletEntry* bulletEntry);

        /**
         * Listener method for changes to properties on the entity to which the property belongs.
         * @param name
         * @param prop
         * @param bulletEntry
         */
        void entityPropertyApplied(const std::string& name, PropertyBase& prop);

        float getMassForEntity(const LocatedEntity& entity) const;

        void getCollisionFlagsForEntity(const LocatedEntity& entity, short& collisionGroup, short& collisionMask) const;

        void sendMoveSight(BulletEntry& bulletEntry, bool posChange, bool velocityChange, bool orientationChange, bool angularChange, bool modeChanged);

        void processMovedEntity(BulletEntry& bulletEntry);

        void updateVisibilityOfDirtyEntities(OpVector& res);

        void updateObservedEntry(BulletEntry* entry, OpVector& res, bool generateOps = true);

        void updateObserverEntry(BulletEntry* bulletEntry, OpVector& res);

        void applyNewPositionForEntity(BulletEntry* entry, const WFMath::Point<3>& pos, bool calculatePosition = true);

        bool getTerrainHeight(float x, float y, float& height) const;

        void updateTerrainMod(const LocatedEntity& entity, bool forceUpdate = false);

        void processDirtyTerrainAreas();

        void applyVelocity(BulletEntry& entry, const WFMath::Vector<3>& velocity);

        void calculatePositionForEntity(ModeProperty::Mode mode, BulletEntry* entry, WFMath::Point<3>& pos);

        /**
         * Called each tick to process any bodies that are moving in water.
         */
        void processWaterBodies();

        std::shared_ptr<btCollisionShape> createCollisionShapeForEntry(LocatedEntity* entity,
                                                                       const WFMath::AxisBox<3>& bbox, float mass,
                                                                       btVector3& centerOfMassOffse);

        /**
         * Transform any entities that are resting on the supplied entity.
         *
         * I.e. those that are "free" or "submerged" and are on top of the entity.
         * @param entry
         * @param posTransform
         * @param transformedEntities
         */
        void transformRestingEntities(BulletEntry* entry,
                                      const WFMath::Vector<3>& posTransform,
                                      const WFMath::Quaternion& orientationChange,
                                      std::set<LocatedEntity*>& transformedEntities);

        void plantOnEntity(BulletEntry* plantedEntry, BulletEntry* entryPlantedOn);

        void applyTransformInternal(LocatedEntity& entity, const WFMath::Quaternion& orientation,
                            const WFMath::Point<3>& pos, const WFMath::Vector<3>& velocity,
                            std::set<LocatedEntity*>& transformedEntities, bool calculatePosition);


};

#endif /* PHYSICALDOMAIN_H_ */
