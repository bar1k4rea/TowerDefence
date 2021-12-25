/* Created by bar1k4real on 25.11.2021. */

#include <iostream>
#include "EnemyData.h"

namespace TowerDefence {

    // Empty constructor for EnemyData.
    EnemyData::EnemyData() : maxHealth(0), recovery(0), damage(0), speed(0), hit(0), chance(0), radius(0),
                             ammunition(0) {}

    // First constructor for EnemyData.
    EnemyData::EnemyData(float health, float recovery, float damage, float speed, float hit, float chance, float radius,
                         float ammunition) : maxHealth(health), recovery(recovery), damage(damage), speed(speed),
                                             hit(hit), chance(chance), radius(radius), ammunition(ammunition) {}

    // Copy constructor for EnemyData.
    EnemyData::EnemyData(const EnemyData &enemyData) : maxHealth(enemyData.maxHealth), recovery(enemyData.recovery),
                                                       damage(enemyData.damage), speed(enemyData.speed),
                                                       hit(enemyData.hit), chance(enemyData.chance),
                                                       radius(enemyData.radius), ammunition(enemyData.ammunition) {}

    // Input for EnemyData.
    std::istream &operator>>(std::istream &in, EnemyData &enemyData) {
        in >> enemyData.maxHealth >> enemyData.recovery >> enemyData.damage >> enemyData.speed >> enemyData.hit
           >> enemyData.chance >> enemyData.radius >> enemyData.ammunition;
        return in;
    }

    // Output for EnemyData.
    std::ostream &operator<<(std::ostream &out, const EnemyData &enemyData) {
        out << enemyData.maxHealth << ' ' << enemyData.recovery << ' ' << enemyData.damage << ' ' << enemyData.speed
            << ' ' << enemyData.hit << ' ' << enemyData.chance << ' ' << enemyData.radius << ' '
            << enemyData.ammunition;
        return out;
    }

} /* namespace TowerDefence */
