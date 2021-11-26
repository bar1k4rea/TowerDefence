/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_WALL_H
#define TOWER_DEFENCE_WALL_H

#include "../ObjectWithHealth/ObjectWithHealth.h"
#include "../Table/Table.h"
#include "../Castle/Castle.h"

namespace TowerDefence {

    // Class Wall
    class Wall : public ObjectWithHealth {
    protected:
        int m_cost;
    public:
        Wall();

        Wall(const Point &point, int health, int cost);

        Wall(const Point &point, int health, int maxHealth, int cost);

        void renovate(Castle& castle);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_WALL_H */
