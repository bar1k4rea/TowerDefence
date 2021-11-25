/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include "Wall.h"
 namespace TowerDefence {

     // Empty constructor for Wall.
     Wall::Wall() : ObjectWithHealth(), m_counter(0), m_table(nullptr) {
         std::cout << "Empty Constructor for Wall: " << this << std::endl;
     }

     // First constructor for Wall.
     Wall::Wall(const Point &point, int health, int counter, WallTable *table) : ObjectWithHealth(point, health),
                                                                                 m_counter(counter), m_table(table) {
         std::cout << "First Constructor for Wall: " << this << std::endl;
     }

     // Second constructor for Wall.
     Wall::Wall(const Point &point, int health, int maxHealth, int counter, WallTable *table) : ObjectWithHealth(point, health, maxHealth),
                                                                                                m_counter(counter), m_table(table) {
         std::cout << "Second Constructor for Wall: " << this << std::endl;
     }

     // Calculate index of cost in WallTable for repairing wall.
     int Wall::calculateCost(int strength) {
         for (int i = 0; i < m_counter; i++)
             if (m_table->percent >= strength)
                 return i;
         return 0;
     }

    // Repair Wall.
    int Wall::renovate(int gold) {
         int strength = m_health / m_maxHealth;
         int counter = calculateCost(strength);
         if (gold < m_table[counter].cost)
             throw std::out_of_range("Not enough gold to level up Castle!");
         gold -= m_table[counter].cost;
         m_health = m_maxHealth;
         return gold;
     }

 } /* namespace TowerDefence */