// This file may be redistributed and modified only under the terms of
// the GNU General Public License (See COPYING for details).
// Copyright (C) 2000,2001 Alistair Riddoch

#ifndef SERVER_RESTORER_H
#define SERVER_RESTORER_H

#include "common/Database.h"

#include <string>

class Entity;

template <class T>
class Persistor;

/// \brief Class template to handle restoring an entity of the parameter
/// class from the database.
///
/// This class should never ever be instantiated, so the constructor is private
/// and unimplemented. Instead the template should be instantiated with
/// T as the class to be restored, and a reference to the object being
/// restored is cast to a reference to this type, allowing code in
/// this class to write to the protected methods.
/// This class is probably going to want to directly decode data from the
/// database layer.
template <class T>
class Restorer : public T {
  private:
    Restorer(); // DO NOT IMPLEMENT THIS

    bool checkBool(const char * c) {
        if (c == 0) { return false; }
        if (*c == 't') {
            return true;
        } else {
            return false;
        }
    }

    void rEntity(DatabaseResult::const_iterator & dr);
    void rCharacter(DatabaseResult::const_iterator & dr);
    void rPlant(DatabaseResult::const_iterator & dr);
  public:
    static Persistor<T> m_persist;

    void populate(DatabaseResult::const_iterator & dr);

    static Entity * restore(const std::string & id, long intId,
                            DatabaseResult::const_iterator & dr);

};

#endif // SERVER_RESTORER_H
