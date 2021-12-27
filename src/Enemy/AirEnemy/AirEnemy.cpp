/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include <cmath>
#include "AirEnemy.h"

namespace TowerDefence {

    // Empty constructor for AirEnemy.
    AirEnemy::AirEnemy() : Enemy(), m_hit(0), m_ammunition(0) {}

    // Second constructor for  AirEnemy.
    AirEnemy::AirEnemy(const Point &point, float health, float maxHealth, float speed, float recovery, float damage,
                       std::vector<Point> &route, float hit, float ammunition) :  Enemy(point, health, maxHealth, speed, recovery, damage, route), m_hit(hit), m_ammunition(ammunition) {
        m_type = 3;
        m_sprite.setTextureRect(sf::IntRect(160, 0, 32, 32));
    }

    // Attack Wall.
    void AirEnemy::attackWall(Wall &wall) {
        if (m_point == wall.getPoint()) {
            wall.decreaseHealth(m_hit);
            m_ammunition -= 1;
        }
    }

    // Update data for AirEnemy.
    int AirEnemy::update(sf::RenderWindow &window) {
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

