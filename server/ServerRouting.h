// This file may be redistributed and modified only under the terms of
// the GNU General Public License (See COPYING for details).
// Copyright (C) 2000,2001 Alistair Riddoch

#ifndef SERVER_SERVER_ROUTING_H
#define SERVER_SERVER_ROUTING_H

#include "Account.h"

#include "common/OOGThing.h"

class BaseWorld;
class Lobby;

/// \brief ServerRouting represents the core of the server.
///
/// This class has one instance which is the core object in the server.
/// It maintains list of all out-of-game (OOG) objects in the server.
class ServerRouting : public OOGThing {
  private:
    /// A mapping of ID to object of all the OOG objects in the server.
    BaseDict m_objects;
    /// A mapping of ID to object of all the accounts in the server.
    AccountDict m_accounts;
    /// The text name of the ruleset this server is running.
    const std::string m_svrRuleset;
    /// The name of this server.
    const std::string m_svrName;
    /// The number of clients currently connected.
    int m_numClients;
  public:
    /// A reference to the World management object.
    BaseWorld & m_world;
    /// A reference to the Lobby management object.
    Lobby & m_lobby;

    ServerRouting(BaseWorld & wrld,
                  const std::string & ruleset,
                  const std::string & name);
    ~ServerRouting();

    bool idle();

    /// Add an OOG object to the server.
    void addObject(BaseEntity * obj) {
        m_objects[obj->getId()] = obj;
    }

    /// Add an Account object to the server.
    void addAccount(Account * a) {
        m_accounts[a->m_username] = a;
        addObject(a);
    }

    /// Accessor for OOG objects map.
    const BaseDict & getObjects() const {
        return m_objects;
    }

    /// \brief Find an object with the given id.
    ///
    /// @return a pointer to the object with the given id, or
    /// zero if no object with this id is present.
    BaseEntity * getObject(const std::string & id) const {
        BaseDict::const_iterator I = m_objects.find(id);
        if (I == m_objects.end()) {
            return 0;
        } else {
            return I->second;
        }
    }

    /// \brief Find an account with a given username.
    ///
    /// @return a pointer to the Account object with the given
    /// username, or zero if the Account is not present. Does
    /// not check any external authentication sources, or the
    /// database.
    Account * getAccountByName(const std::string & username) const {
        AccountDict::const_iterator I = m_accounts.find(username);
        if (I == m_accounts.end()) {
            return 0;
        } else {
            return I->second;
        }
    }

    /// Increment the number of clients connected to this server.
    void incClients() { ++m_numClients; }
    /// Decrement the number of clients connected to this server.
    void decClients() { --m_numClients; }

    /// Accessor for world manager object.
    BaseWorld & getWorld() { return m_world; }

    /// Accessor for server name.
    const std::string & getName() const { return m_svrName; }

    /// Copy the attribute values of this object into an Atlas message.
    virtual void addToMessage(Atlas::Message::MapType &) const;
};

#endif // SERVER_SERVER_ROUTING_H
