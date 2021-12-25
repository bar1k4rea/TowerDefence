/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include "Castle.h"

namespace TowerDefence {

    // Empty constructor for Castle.
    Castle::Castle() : ObjectWithHealth(), m_level(0), m_gold(0), m_table() {}

    // Second constructor for Castle.
    Castle::Castle(const Point &point, float health, float maxHealth, float gold,
                   const Table<int, CastleData> &table) : ObjectWithHealth(point, health, maxHealth), m_level(1),
                                                          m_gold(gold), m_table(table) {}

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

    int Castle::getLevel() const {
        return m_level;
    }

    void Castle::setLevel(int level) {
        m_level = level;
    }

    float Castle::getGold() const {
        return m_gold;
    }

    void Castle::setGold(float Gold) {
        m_gold = Gold;
    }

    const Table<int, CastleData> &Castle::getTable() const {
        return m_table;
    }

    void Castle::setTable(const Table<int, CastleData> &table) {
        m_table = table;
    }

} /* namespace TowerDefence */

