/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_TOWER_H
#define TOWER_DEFENCE_TOWER_H

#include "../ObjectWithHealth/ObjectWithHealth.h"
#include "../Table/Table.h"
#include "../Table/TowerData/TowerData.h"
#include "../Castle/Castle.h"
#include "../Enemy/Enemy.h"

namespace TowerDefence {

    // Class Tower
    class Tower : public ObjectWithHealth {
    protected:
        int m_level;
        Table<int, TowerData> m_table;
    public:
        Tower();

        Tower(const Point &point, int health, const Table<int, TowerData>& table);

        Tower(const Point &point, int health, int maxHealth, int level, const Table<int, TowerData>& table);

        [[nodiscard]] int getRate();

        void upgrade(Castle &castle);

        void attackEnemy(Enemy& enemy);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_TOWER_H */
