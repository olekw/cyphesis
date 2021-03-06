# This file is distributed under the terms of the GNU General Public license.
# Copyright (C) 1999 Al Riddoch (See the file COPYING for details).

from atlas import *

from world.objects.plants.seeds.Seed import Seed


class Apple(Seed):
    """An apple which can be eaten, and ferment as it ages."""

    def consume_operation(self, op):
        ent = Entity(self.id, status=-1)
        res = Operation("set", ent, to=self)
        to_ = op.from_
        nour = Entity(to_, mass=self.props.mass, alcohol=self.props.alcohol)
        res = res + Operation("nourish", nour, to=to_)
        return res

    def tick_operation(self, op):
        # After a short while we turn into a rotten apple, which is alcoholic
        if self.props.alcohol > 0:
            ent = Entity(self.id, status=-1)
            return Operation("set", ent, to=self)
        else:
            self.props.alcohol = 1
            op_tick = Operation("tick", to=self)
            op_tick.set_future_seconds(900)
            return op_tick
