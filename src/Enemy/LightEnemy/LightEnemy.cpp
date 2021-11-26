/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include "LightEnemy.h"

namespace TowerDefence {

    // Empty constructor for LightEnemy.
    LightEnemy::LightEnemy() : Enemy(), m_chance(0) {
        std::cout << "Empty Constructor for LightEnemy: " << this << std::endl;
    }

    // First constructor for LightEnemy.
    LightEnemy::LightEnemy(const Point &point, int health, int speed, int recovery, int damage, int chance) : Enemy(
            point, health, speed, recovery, damage), m_chance(chance) {
        std::cout << "First Constructor for LightEnemy: " << this << std::endl;
    }

    // Second constructor for  LightEnemy.
    LightEnemy::LightEnemy(const Point &point, int health, int maxHealth, int speed, int recovery, int damage,
                           int chance) : Enemy(point, health, maxHealth, speed, recovery, damage), m_chance(chance) {
        std::cout << "Second Constructor for  LightEnemy: " << this << std::endl;
    }

    // Dodge hit.
    bool LightEnemy::avoidDamage() {
        if (rand() % 100 > m_chance)
            return true;
        return false;
    }

    // Update data for LightEnemy.
    void LightEnemy::update() {
        decreaseHealth(m_recovery);
    }

} /* namespace TowerDefence */
