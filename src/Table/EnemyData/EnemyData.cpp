/* Created by bbara on 25.11.2021. */

#include <iostream>
#include "EnemyData.h"

namespace TowerDefence {

    // Empty constructor for EnemyData.
    EnemyData::EnemyData() : health(0), recovery(0), damage(0), speed(0), hit(0), chance(0), radius(0), ammunition(0) {
        std::cout << "Empty Constructor for EnemyData: " << this << std::endl;
    }

    // First constructor for EnemyData.
    EnemyData::EnemyData(int health, int recovery, int damage, int speed, int hit, int chance, int radius,
                         int ammunition) : health(health), recovery(recovery), damage(damage), speed(speed), hit(hit),
                                           chance(chance), radius(radius), ammunition(ammunition) {
        std::cout << "First Constructor for EnemyData: " << this << std::endl;
    }

    // Input for EnemyData.
    std::istream &operator>>(std::istream &in, EnemyData &data) {
        in >> data.health >> data.recovery >> data.damage >> data.speed >> data.hit >> data.chance >> data.radius
           >> data.ammunition;
        return in;
    }

} /* namespace TowerDefence */
