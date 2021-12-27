/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include <vector>
#include <cmath>
#include "LightEnemy.h"
#include <SFML/Graphics.hpp>

namespace TowerDefence {

    // Empty constructor for LightEnemy.
    LightEnemy::LightEnemy() : Enemy(), m_chance(0) {}

    // First constructor for  LightEnemy.
    LightEnemy::LightEnemy(const Point &point, float health, float maxHealth, float speed, float recovery, float damage,
                           std::vector<Point> &route, float chance) : Enemy(point, health, maxHealth, speed, recovery,
                                                                      damage, route), m_chance(chance) {
        m_type = 1;
        m_sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
    }

    // Dodge hit.
    bool LightEnemy::avoidDamage() {
        return rand() % 100 > m_chance;
    }

    // Update data for LightEnemy.
    int LightEnemy::update(sf::RenderWindow &window) {
        int x = m_route[m_counterOfWayPoint].x, y = m_route[m_counterOfWayPoint].y;
        float distance = std::sqrt((x - m_point.x) * (x - m_point.x) + (y - m_point.y) * (y - m_point.y));

        if (m_isMove) {
            if (distance > 0.1) {
                m_point.x += m_speed * (x - m_point.x) / distance;
                m_point.y += m_speed * (y - m_point.y) / distance;
            } else
                m_counterOfWayPoint++;

            if (m_counterOfWayPoint == m_numberOfWayPoint)
                return -1;
        }

        m_sprite.setPosition(32 * m_point.x, 32 * m_point.y);
        window.draw(m_sprite);

        return 0;
    }

} /* namespace TowerDefence */