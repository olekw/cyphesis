// This file may be redistributed and modified only under the terms of
// the GNU General Public License (See COPYING for details).
// Copyright (C) 2000,2001 Alistair Riddoch

#include "MemEntity.h"

static const bool debug_flag = false;

MemEntity::MemEntity(const std::string & id, long intId) : Entity(id, intId),
                                                           m_visible(false),
                                                           m_lastSeen(0.)
{
}

MemEntity::~MemEntity()
{
}
