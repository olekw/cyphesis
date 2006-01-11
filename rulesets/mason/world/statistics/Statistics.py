#This file is distributed under the terms of the GNU General Public license.
#Copyright (C) 2006 Al Riddoch (See the file COPYING for details).

from atlas import *
try:
  from random import *
except ImportError:
  from whrandom import *

import rules

class Statistics(rules.Statistics):
    """A very simple Statistics example."""
    def __init__(self, entity):
        rules.Statistics.__init__(self, entity)
        print "script init"
        self.character = entity
    def attribute(self, name):
        if name == "attack":
            return 1
        if name == "defence":
            return 1
        if name == "strength":
            return self.character.mass
        print "Script got request for ", name
