/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include "AirEnemy.h"

namespace TowerDefence {

    // Empty constructor for AirEnemy.
    AirEnemy::AirEnemy() : Enemy(), m_hit(0), m_ammunition(0) {
        std::cout << "Empty Constructor for AirEnemy: " << this << std::endl;
    }

    // First constructor for AirEnemy.
    AirEnemy::AirEnemy(const Point &point, int health, int speed, int recovery, int damage, int hit, int ammunition)
            : Enemy(point, health, speed, recovery, damage), m_hit(hit), m_ammunition(ammunition) {
        std::cout << "First Constructor for AirEnemy: " << this << std::endl;
    }

    // Second constructor for  AirEnemy.
    AirEnemy::AirEnemy(const Point &point, int health, int maxHealth, int speed, int recovery, int damage, int hit,
                           int ammunition) : Enemy(point, health, maxHealth, speed, recovery, damage), m_hit(hit), m_ammunition(ammunition) {
        std::cout << "Second Constructor for  AirEnemy: " << this << std::endl;
    }

    // Attack Wall.
    void AirEnemy::attackWall(Wall &wall) {
        if (m_point == wall.getPoint()) {
            wall.decreaseHealth(m_hit);
            m_ammunition -= 1;
        }
    }

    // Update data for AirEnemy.
    void AirEnemy::update() {
        decreaseHealth(m_recovery);
    }

} /* namespace TowerDefence */

