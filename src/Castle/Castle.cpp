/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include "Castle.h"

namespace TowerDefence {

    // Empty constructor for Castle.
    Castle::Castle() : ObjectWithHealth(), m_level(0), m_gold(0), m_table(Table<int, CastleData>()) {
        std::cout << "Empty Constructor for Castle: " << this << std::endl;
    }

    // First constructor for Castle.
    Castle::Castle(const Point &point, int health, const Table<int, CastleData> &table) : ObjectWithHealth(point, health),
                                                                                          m_level(1), m_gold(0),
                                                                                          m_table(table) {
        std::cout << "First Constructor for Castle: " << this << std::endl;
    }

    // Second constructor for Castle.
    Castle::Castle(const Point &point, int health, int maxHealth, int level, int gold,
                   const Table<int, CastleData> &table) : ObjectWithHealth(point, health, maxHealth), m_level(level),
                                                          m_gold(gold), m_table(table) {
        std::cout << "Second Constructor for Castle: " << this << std::endl;
    }

    // Increase level for Castle.
    void Castle::upgrade() {
        if (m_level == m_table.getCounter())
            throw std::length_error("Maximum level for Castle has been reached!");
        if (m_gold < m_table[m_level + 1].cost)
            throw std::out_of_range("Not enough gold to level up Castle!");
        m_level += 1;
        m_gold -= m_table[m_level].cost;
        m_maxHealth = m_table[m_level].maxHealth;
    }

    // Update data for Castle.
    void Castle::update() {
        if (!isAlive())
            throw std::range_error("Castle destroyed!");
        increaseHealth(m_table[m_level].recovery);
        m_gold += m_table[m_level].profit;
    }

    // Getter for m_gold.
    int Castle::getGold() const {
        return m_gold;
    }

    // Setter for m_gold.
    void Castle::setGold(int gold) {
        m_gold = gold;
    }

} /* namespace TowerDefence */

