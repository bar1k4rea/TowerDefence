/* Created by bar1k4real on 25.11.2021. */

#include <iostream>
#include "CastleData.h"

namespace TowerDefence {

    // Empty constructor for CastleData.
    CastleData::CastleData() : profit(0), maxHealth(0), recovery(0), cost(0) {}

    // First constructor for CastleData.
    CastleData::CastleData(float profit, float maxHealth, float recovery, float cost) : profit(profit),
                                                                                        maxHealth(maxHealth),
                                                                                        recovery(recovery),
                                                                                        cost(cost) {}

    // Copy constructor for CastleData.
    CastleData::CastleData(const CastleData &castleData) : profit(castleData.profit), maxHealth(castleData.maxHealth),
                                                           recovery(castleData.recovery), cost(castleData.cost) {}

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