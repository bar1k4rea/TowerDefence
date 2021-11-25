/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include "Table.h"

namespace TowerDefence {

    // Empty constructor for CastleTable.
    CastleTable::CastleTable() : level(0), profit(0), maxHealth(0), recovery(0), cost(0) {
        std::cout << "Empty Constructor for CastleTable: " << this << std::endl;
    }

    // First constructor for CastleTable.
    CastleTable::CastleTable(int level, int profit, int maxHealth, int recovery, int cost) : level(level),
                                                                                             profit(profit),
                                                                                             maxHealth(maxHealth),
                                                                                             recovery(recovery),
                                                                                             cost(cost) {
        std::cout << "First Constructor for CastleTable: " << this << std::endl;
    }

    // Input for CastleTable.
    std::istream &operator>>(std::istream &in, CastleTable &castleTable) {
        in >> castleTable.level >> castleTable.profit >> castleTable.maxHealth >> castleTable.recovery
           >> castleTable.cost;
        return in;
    }

    // Empty constructor for TowerTable.
    TowerTable::TowerTable() : level(0), radius(0), damage(0), rate(0), cost(0) {
        std::cout << "Empty Constructor for TowerTable: " << this << std::endl;
    }

    // First constructor for TowerTable.
    TowerTable::TowerTable(int level, int radius, int damage, int rate, int cost) : level(level), radius(radius),
                                                                                    damage(damage), rate(rate),
                                                                                    cost(cost) {
        std::cout << "First Constructor for TowerTable: " << this << std::endl;
    }

    // Input for TowerTable.
    std::istream &operator>>(std::istream &in, TowerTable &towerTable) {
        in >> towerTable.level >> towerTable.radius >> towerTable.damage >> towerTable.rate >> towerTable.cost;
        return in;
    }

    // Empty constructor for WallTable.
    WallTable::WallTable() : percent(0), cost(0) {
        std::cout << "Empty Constructor for WallTable: " << this << std::endl;
    }

    // First constructor for WallTable.
    WallTable::WallTable(int percent, int cost) : percent(percent), cost(cost) {
        std::cout << "First Constructor for TowerTable: " << this << std::endl;
    }

    // Input for WallTable.
    std::istream &operator>>(std::istream &in, WallTable &wallTable) {
        in >> wallTable.percent >> wallTable.cost;
        return in;
    }

} /* namespace TowerDefence */