/* Created by bar1k4real on 25.11.2021. */

#include <iostream>
#include "TowerData.h"

namespace TowerDefence {

    // Empty constructor for TowerData.
    TowerData::TowerData() : radius(0), damage(0), rapidity(0), cost(0) {}

    // First constructor for TowerData.
    TowerData::TowerData(float radius, float damage, float rapidity, float cost) : radius(radius), damage(damage),
                                                                                   rapidity(rapidity),
                                                                                   cost(cost) {}

    // Copy constructor for TowerData.
    TowerData::TowerData(const TowerData &towerData) : radius(towerData.radius), damage(towerData.damage),
                                                       rapidity(towerData.rapidity), cost(towerData.cost) {}

    // Input for TowerData.
    std::istream &operator>>(std::istream &in, TowerData &towerData) {
        in >> towerData.radius >> towerData.damage >> towerData.rapidity >> towerData.cost;
        return in;
    }

    // Output for TowerData.
    std::ostream &operator<<(std::ostream &out, const TowerData &towerData) {
        out << towerData.radius << ' ' << towerData.damage << ' ' << towerData.rapidity << ' ' << towerData.cost;
        return out;
    }

} /* namespace TowerDefence */
