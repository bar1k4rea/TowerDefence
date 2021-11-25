/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_TOWER_H
#define TOWER_DEFENCE_TOWER_H

#include "../ObjectWithHealth/ObjectWithHealth.h"
#include "../Table/Table.h"

namespace TowerDefence {

    // Class Tower
    class Tower : public ObjectWithHealth {
    protected:
        int m_level;
        int m_counter;
        TowerTable *m_table;
    public:
        Tower();

        Tower(const Point &point, int health, int counter, TowerTable *table);

        Tower(const Point &point, int health, int maxHealth, int level, int counter, TowerTable *table);

        int upgrade(int gold);

        int attackEnemy(int health);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_TOWER_H */
