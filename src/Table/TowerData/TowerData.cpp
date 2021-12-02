/* Created by bbara on 25.11.2021. */

#include <iostream>
#include "TowerData.h"

namespace TowerDefence {

    // Empty constructor for TowerData.
    TowerData::TowerData() : radius(0), damage(0), rate(0), cost(0) {
        std::cout << "Empty Constructor for TowerData: " << this << std::endl;
    }

    // First constructor for TowerData.
    TowerData::TowerData(int radius, int damage, int rate, int cost) : radius(radius), damage(damage), rate(rate),
                                                                       cost(cost) {
        std::cout << "First Constructor for TowerData: " << this << std::endl;
    }

    // Copy constructor for TowerData.
    TowerData::TowerData(const TowerData &towerData) : radius(towerData.radius), damage(towerData.damage),
                                                       rate(towerData.rate), cost(towerData.cost) {
        std::cout << "Copy Constructor for TowerData: " << this << std::endl;
    }

    // Input for TowerData.
    std::istream &operator>>(std::istream &in, TowerData &towerData) {
        in >> towerData.radius >> towerData.damage >> towerData.rate >> towerData.cost;
        return in;
    }

    // Output for TowerData.
    std::ostream &operator<<(std::ostream &out, const TowerData &towerData) {
        out << towerData.radius << ' ' << towerData.damage << ' ' << towerData.rate << ' ' << towerData.cost;
        return out;
    }

} /* namespace TowerDefence */
