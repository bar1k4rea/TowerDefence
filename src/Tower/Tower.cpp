/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include "Tower.h"

namespace TowerDefence {

    // Empty constructor for Tower.
    Tower::Tower() : ObjectWithLocation(), m_level(1), m_table() {}

    // First constructor for Tower.
    Tower::Tower(const Point &point, int level, const Table<int, TowerData> &table) : ObjectWithLocation(point),
                                                                                      m_level(level), m_table(table) {}

    // Increase level for Tower.
    void Tower::upgrade(std::shared_ptr<Castle> castle) {
        int gold = castle->getGold();
        if (m_level == m_table.getCounter())
            throw std::length_error("Maximum level for Castle has been reached!");
        if (gold < m_table[m_level + 1].cost)
            throw std::out_of_range("Not enough gold to level up Castle!");
        castle->setGold(gold - m_table[m_level].cost);
        m_level += 1;
    }

    // Attack Enemy.
    void Tower::attackEnemy(std::shared_ptr<Enemy> enemy) {
        if (m_table[m_level].radius > distance(enemy->getPoint()))
            enemy->decreaseHealth(m_table[m_level].damage);
    }

} /* namespace TowerDefence */
