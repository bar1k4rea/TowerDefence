/* Created by bbara on 26.11.2021. */

#include <iostream>
#include "AirHero.h"

namespace TowerDefence {

    AirHero::AirHero() : AirEnemy(), Hero() {

    }

    AirHero::AirHero(const Point &point, int health, int speed, int recovery, int damage, int hit, int ammunition,
                     int length, Aura aura) : AirEnemy(point, health, speed, recovery, damage, hit, ammunition),
                                              Hero(length, aura) {

    }

    void AirHero::update() {
        decreaseHealth(m_recovery);
    }

} /* namespace TowerDefence */