/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include "Tower.h"

namespace TowerDefence {

    // Empty constructor for Tower.
    Tower::Tower() : ObjectWithHealth(), m_level(0), m_counter(0), m_table(nullptr) {
        std::cout << "Empty Constructor for Tower: " << this << std::endl;
    }

    // First constructor for Tower.
    Tower::Tower(const Point &point, int health, int counter, TowerTable *table) : ObjectWithHealth(point, health),
                                                                                   m_level(1), m_counter(counter),
                                                                                   m_table(table) {
        std::cout << "First Constructor for Castle: " << this << std::endl;
    }

    // Second constructor for Tower.
    Tower::Tower(const Point &point, int health, int maxHealth, int level, int counter, TowerTable *table) : ObjectWithHealth(point, health, maxHealth),
                                                                                                             m_level(level), m_counter(counter),
                                                                                                             m_table(table) {
        std::cout << "Second Constructor for Castle: " << this << std::endl;
    }

    // Increase level for Tower.
    int Tower::upgrade(int gold) {
        if (m_level == m_counter)
            throw std::length_error("Maximum level for Castle has been reached!");
        if (gold < m_table[m_level].cost)
            throw std::out_of_range("Not enough gold to level up Castle!");
        gold -= m_table[m_level].cost;
        m_level += 1;
        return gold;
    }

    // Attack Enemy.
    int Tower::attackEnemy(int health) {

        return health;
    }

} /* namespace TowerDefence */
