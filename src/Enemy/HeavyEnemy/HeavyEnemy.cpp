/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include <cmath>
#include "HeavyEnemy.h"

namespace TowerDefence {

    // Empty constructor for HeavyEnemy.
    HeavyEnemy::HeavyEnemy() : Enemy(), m_hit(0), m_radius(0) {}

    // First constructor for  HeavyEnemy.
    HeavyEnemy::HeavyEnemy(const Point &point, float health, float maxHealth, float speed, float recovery, float damage,
                           const std::vector<Point> &route, float hit, float radius) : Enemy(point, health, maxHealth,
                                                                                         speed, recovery, damage,
                                                                                         route), m_hit(hit),
                                                                                   m_radius(radius) {
        m_type = 2;
        m_sprite.setTextureRect(sf::IntRect(128, 0, 32, 32));
    }

    // Attack Wall.
    void HeavyEnemy::attackWall(Wall &wall) {
        if (distance(wall.getPoint()) < m_radius)
            wall.decreaseHealth(m_hit);
    }

    // Update data for HeavyEnemy.
    int HeavyEnemy::update(sf::RenderWindow &window) {
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

    float HeavyEnemy::getMHit() const {
        return m_hit;
    }

    void HeavyEnemy::setMHit(float mHit) {
        m_hit = mHit;
    }

    float HeavyEnemy::getMRadius() const {
        return m_radius;
    }

    void HeavyEnemy::setMRadius(float mRadius) {
        m_radius = mRadius;
    }

} /* namespace TowerDefence */

