/* Created by bbara on 26.11.2021. */

#include <iostream>
#include <cmath>
//#include "SFML/Graphics.hpp"
#include "LightHero.h"

namespace TowerDefence {

    LightHero::LightHero() : LightEnemy(), m_length(0), m_aura(0, 0, 0, 0) {}

    LightHero::LightHero(const Point &point, float health, float maxHelath, float speed, float recovery, float damage,
                         std::vector<Point> &route, float chance, float length, Aura aura) : LightEnemy(), m_length(length),
                                                                                             m_aura(aura) {
        m_type = 4;
        m_sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
        sf::RenderWindow window;
    }

    // Update data for LightEnemy.
    int LightHero::update(sf::RenderWindow &window) {
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

