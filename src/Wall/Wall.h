/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_WALL_H
#define TOWER_DEFENCE_WALL_H

#include "../ObjectWithHealth/ObjectWithHealth.h"
#include "../Table/Table.h"

namespace TowerDefence {

    // Class Wall
    class Wall : public ObjectWithHealth {
    protected:
        int m_counter;
        WallTable *m_table;

        int calculateCost(int strength);
    public:
        Wall();

        Wall(const Point &point, int health, int counter, WallTable *table);

        Wall(const Point &point, int health, int maxHealth, int counter, WallTable *table);

        int renovate(int gold);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_WALL_H */
