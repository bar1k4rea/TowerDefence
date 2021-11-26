/* Created by bbara on 26.11.2021. */

#include <iostream>
#include "LightHero.h"

namespace TowerDefence {

    LightHero::LightHero() : LightEnemy(), Hero() {

    }

    LightHero::LightHero(const Point &point, int health, int speed, int recovery, int damage, int chance, int length,
                         Aura aura) : LightEnemy(point, health, speed, recovery, damage, chance), Hero(length, aura) {

    }

    void LightHero::update() {
        decreaseHealth(m_recovery);
    }

} /* namespace TowerDefence */

