/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include <memory>
#include "Wall.h"

 namespace TowerDefence {

     // Empty constructor for Wall.
     Wall::Wall() : ObjectWithHealth() {}

     // First constructor for Wall.
     Wall::Wall(const Point &point, int health, int maxHealth) : ObjectWithHealth(point, health, maxHealth) {}

     // Repair Wall.
     void Wall::renovate(std::shared_ptr<Castle> castle) {
         int gold = castle->getGold(), strength = 1 - m_health / m_maxHealth, price = strength * m_cost;
         if (gold < price)
             throw std::out_of_range("Not enough gold to renovate wall!");
         m_health = m_maxHealth;
         castle->setGold(gold - price);
     }

     const int Wall::getMCost() {
         return m_cost;
     }

 } /* namespace TowerDefence */