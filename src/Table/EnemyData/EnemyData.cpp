/* Created by bar1k4real on 25.11.2021. */

#include <iostream>
#include "EnemyData.h"

namespace TowerDefence {

    // Empty constructor for EnemyData.
    EnemyData::EnemyData() : health(0), recovery(0), damage(0), speed(0), hit(0), chance(0), radius(0), ammunition(0) {
//        std::cout << "Empty Constructor for EnemyData: " << this << std::endl;
    }

    // First constructor for EnemyData.
    EnemyData::EnemyData(int health, int recovery, int damage, int speed, int hit, int chance, int radius,
                         int ammunition) : health(health), recovery(recovery), damage(damage), speed(speed), hit(hit),
                                           chance(chance), radius(radius), ammunition(ammunition) {
//        std::cout << "First Constructor for EnemyData: " << this << std::endl;
    }

    // Copy constructor for EnemyData.
    EnemyData::EnemyData(const EnemyData &enemyData) : health(enemyData.health), recovery(enemyData.recovery),
                                                       damage(enemyData.damage), speed(enemyData.speed),
                                                       hit(enemyData.hit), chance(enemyData.chance),
                                                       radius(enemyData.radius), ammunition(enemyData.ammunition) {
//        std::cout << "Copy Constructor for EnemyData: " << this << std::endl;
    }

    // Input for EnemyData.
    std::istream &operator>>(std::istream &in, EnemyData &enemyData) {
        in >> enemyData.health >> enemyData.recovery >> enemyData.damage >> enemyData.speed >> enemyData.hit
           >> enemyData.chance >> enemyData.radius >> enemyData.ammunition;
        return in;
    }

    // Output for EnemyData.
    std::ostream &operator<<(std::ostream &out, const EnemyData &enemyData) {
        out << enemyData.health << ' ' << enemyData.recovery << ' ' << enemyData.damage << ' ' << enemyData.speed << ' '
            << enemyData.hit << ' ' << enemyData.chance << ' ' << enemyData.radius << ' ' << enemyData.ammunition;
        return out;
    }

} /* namespace TowerDefence */
