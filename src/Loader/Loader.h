/* Created by bbara on 01.12.2021. */

#ifndef TOWER_DEFENCE_LOADER_H
#define TOWER_DEFENCE_LOADER_H

#include "../Table/Table.h"
#include "../Table/CastleData/CastleData.h"
#include "../Table/EnemyData/EnemyData.h"
#include "../Table/TowerData/TowerData.h"

namespace TowerDefence {

    // Class Loader
    class Loader {
    private:
        Table<int, CastleData> castleTable;
        Table<int, EnemyData> enemyTable;
        Table<int, TowerData> towerTable;
    public:
        Loader();

        void createTable();

        void loadTable();
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_LOADER_H */
