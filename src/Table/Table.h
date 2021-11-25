/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_TABLE_H
#define TOWER_DEFENCE_TABLE_H

#include <iostream>

namespace TowerDefence {

    // Struct CastleTable
    struct CastleTable {
        int level;
        int profit;
        int maxHealth;
        int recovery;
        int cost;

        CastleTable();

        CastleTable(int level, int profit, int maxHealth, int recovery, int cost);

        friend std::istream &operator>>(std::istream &in, CastleTable &castleTable);
    };

    // Struct TowerTable
    struct TowerTable {
        int level;
        int radius;
        int damage;
        int rate;
        int cost;

        TowerTable();

        TowerTable(int level, int radius, int damage, int rate, int cost);

        friend std::istream &operator>>(std::istream &in, TowerTable &towerTable);
    };

    // Struct WallTable
    struct WallTable {
        int percent;
        int cost;

        WallTable();

        WallTable(int percent, int cost);

        friend std::istream &operator>>(std::istream &in, WallTable &wallTable);
    };

    // Struct LairTable
    struct LairTable {

    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_TABLE_H */
