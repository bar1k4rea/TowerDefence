/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include "Wall.h"
 namespace TowerDefence {

     // Empty constructor for Wall.
     Wall::Wall() : ObjectWithHealth(), m_cost(0) {
         std::cout << "Empty Constructor for Wall: " << this << std::endl;
     }

     // First constructor for Wall.
     Wall::Wall(const Point &point, int health, int cost) : ObjectWithHealth(point, health), m_cost(cost) {
         std::cout << "First Constructor for Wall: " << this << std::endl;
     }

     // Second constructor for Wall.
     Wall::Wall(const Point &point, int health, int maxHealth, int cost) : ObjectWithHealth(point, health, maxHealth),
                                                                           m_cost(cost) {
         std::cout << "Second Constructor for Wall: " << this << std::endl;
     }

     // Repair Wall.
     void Wall::renovate(Castle& castle) {
         int gold = castle.getGold(), strength = 1 - m_health / m_maxHealth, price = strength * m_cost;
         if (gold < price)
             throw std::out_of_range("Not enough gold to level up Castle!");
         m_health = m_maxHealth;
         castle.setGold(gold - price);
     }

 } /* namespace TowerDefence */