/* Created by bbara on 25.11.2021. */

#include <iostream>
#include "CastleData.h"

namespace TowerDefence {

    // Empty constructor for CastleData.
    CastleData::CastleData() : profit(0), maxHealth(0), recovery(0), cost(0) {
        std::cout << "Empty Constructor for CastleData: " << this << std::endl;
    }

    // First constructor for CastleData.
    CastleData::CastleData(int profit, int maxHealth, int recovery, int cost) : profit(profit), maxHealth(maxHealth),
                                                                                recovery(recovery), cost(cost) {
        std::cout << "First Constructor for CastleData: " << this << std::endl;
    }

    // Input for CastleData.
    std::istream &operator>>(std::istream &in, CastleData &data) {
        in >> data.profit >> data.maxHealth >> data.recovery >> data.cost;
        return in;
    }

} /* namespace TowerDefence */

