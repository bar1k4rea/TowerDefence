/* Created by bar1k4real on 25.11.2021. */

#include <iostream>
#include "CastleData.h"

namespace TowerDefence {

    // Empty constructor for CastleData.
    CastleData::CastleData() : profit(0), maxHealth(0), recovery(0), cost(0) {
//        std::cout << "Empty Constructor for CastleData: " << this << std::endl;
    }

    // First constructor for CastleData.
    CastleData::CastleData(int profit, int maxHealth, int recovery, int cost) : profit(profit), maxHealth(maxHealth),
                                                                                recovery(recovery), cost(cost) {
//        std::cout << "First Constructor for CastleData: " << this << std::endl;
    }

    // Copy constructor for CastleData.
    CastleData::CastleData(const CastleData &castleData) : profit(castleData.profit), maxHealth(castleData.maxHealth),
                                                           recovery(castleData.recovery), cost(castleData.cost) {
//        std::cout << "Copy Constructor for CastleData: " << this << std::endl;
    }

    // Input for CastleData.
    std::istream &operator>>(std::istream &in, CastleData &castleData) {
        in >> castleData.profit >> castleData.maxHealth >> castleData.recovery >> castleData.cost;
        return in;
    }

    // Output for CastleData.
    std::ostream &operator<<(std::ostream &out, const CastleData &castleData) {
        out << castleData.profit << ' ' << castleData.maxHealth << ' ' << castleData.recovery << ' ' << castleData.cost;
        return out;
    }

} /* namespace TowerDefence */