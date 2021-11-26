/* Created by bbara on 26.11.2021. */

#include <iostream>
#include "HeavyHero.h"

namespace TowerDefence {

    HeavyHero::HeavyHero() : HeavyEnemy(), Hero() {

    }

    HeavyHero::HeavyHero(const Point &point, int health, int speed, int recovery, int damage, int hit, int radius,
                         int m_length, Aura m_aura) : HeavyEnemy(point, health, speed, recovery, damage, hit, radius) {

    }

    void HeavyHero::update() {
        decreaseHealth(m_recovery);
    }

} /* namespace TowerDefence */

