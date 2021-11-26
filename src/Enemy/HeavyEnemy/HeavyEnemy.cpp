/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include "HeavyEnemy.h"

namespace TowerDefence {

    // Empty constructor for HeavyEnemy.
    HeavyEnemy::HeavyEnemy() : Enemy(), m_hit(0), m_radius(0) {
        std::cout << "Empty Constructor for HeavyEnemy: " << this << std::endl;
    }

    // First constructor for HeavyEnemy.
    HeavyEnemy::HeavyEnemy(const Point &point, int health, int speed, int recovery, int damage, int hit, int radius)
            : Enemy(point, health, speed, recovery, damage), m_hit(hit), m_radius(radius) {
        std::cout << "First Constructor for HeavyEnemy: " << this << std::endl;
    }

    // Second constructor for  HeavyEnemy.
    HeavyEnemy::HeavyEnemy(const Point &point, int health, int maxHealth, int speed, int recovery, int damage, int hit,
                           int radius) : Enemy(point, health, maxHealth, speed, recovery, damage), m_hit(hit),
                                         m_radius(radius) {
        std::cout << "Second Constructor for  HeavyEnemy: " << this << std::endl;
    }

    // Attack Wall.
    void HeavyEnemy::attackWall(Wall &wall) {
        if (distance(wall.getPoint()) < m_radius)
            wall.decreaseHealth(m_hit);
    }

    // Update data for HeavyEnemy.
    void HeavyEnemy::update() {
        decreaseHealth(m_recovery);
    }

} /* namespace TowerDefence */

