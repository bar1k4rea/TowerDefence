/* Created by bar1k4real on 01.12.2021. */

#ifndef TOWER_DEFENCE_LOADER_H
#define TOWER_DEFENCE_LOADER_H

#include <limits>
#include "../Table/Table.h"
#include "../Enemy/EnemyType/EnemyType.h"
#include "../Table/CastleData/CastleData.h"
#include "../Table/TowerData/TowerData.h"
#include "../Table/EnemyData/EnemyData.h"
#include "../Table/LairData/LairData.h"

namespace TowerDefence {

    // Class Loader
    class Loader {
    public:
        Table<int, CastleData> m_castleTable;
        Table<int, TowerData> m_towerTable;
        Table<int, EnemyData> m_enemyTable;
        Table<int, LairData> m_lairTable;
        static const int N_ENEMY = 6;
    public:
        Loader();

        void createTable();

        int loadTable();

        void showTable();

    };

    template<class T>
    int getNumber(T &number, const std::string &message) {
        while (true) {
            std::cout << message;
            std::cin >> number;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERROR! Invalid data! Try again please: ->";
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return 1;
            }
        }
    }


} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_LOADER_H */
