/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include "Tower.h"

namespace TowerDefence {

    // Empty constructor for Tower.
    Tower::Tower() : ObjectWithHealth(), m_level(0), m_table(Table<int, TowerData>()) {
        std::cout << "Empty Constructor for Tower: " << this << std::endl;
    }

    // First constructor for Tower.
    Tower::Tower(const Point &point, int health, const Table<int, TowerData> &table) : ObjectWithHealth(point, health),
                                                                                       m_level(1),
                                                                                       m_table(table) {
        std::cout << "First Constructor for Castle: " << this << std::endl;
    }

    // Second constructor for Tower.
    Tower::Tower(const Point &point, int health, int maxHealth, int level, const Table<int, TowerData> &table)
            : ObjectWithHealth(point, health, maxHealth),
              m_level(level),
              m_table(table) {
        std::cout << "Second Constructor for Castle: " << this << std::endl;
    }

    // Getter for rate.
    int Tower::getRate() {
        return m_table[m_level].rate;
    }

    // Increase level for Tower.
    void Tower::upgrade(Castle &castle) {
        int gold = castle.getGold();
        if (m_level == m_table.getCounter())
            throw std::length_error("Maximum level for Castle has been reached!");
        if (gold < m_table[m_level + 1].cost)
            throw std::out_of_range("Not enough gold to level up Castle!");
        castle.setGold(gold - m_table[m_level].cost);
        m_level += 1;
    }

    // Attack Enemy.
    void Tower::attackEnemy(Enemy& enemy) {
        if (m_table[m_level].radius < distance(enemy.getPoint())) {
            enemy.decreaseHealth(m_table[m_level].damage);
        }
    }

} /* namespace TowerDefence */
