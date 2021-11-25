/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include "ObjectWithHealth.h"

namespace TowerDefence {

    // Empty constructor for ObjectWithHealth.
    ObjectWithHealth::ObjectWithHealth() : m_health(0), m_maxHealth(0), ObjectWithLocation() {
        std::cout << "Empty Constructor for ObjectWithHealth: " << this << std::endl;
    }

    // First constructor for ObjectWithHealth.
    ObjectWithHealth::ObjectWithHealth(const Point &point, int health) : ObjectWithLocation(point),
                                                                         m_health(health), m_maxHealth(health) {
        std::cout << "First Constructor for ObjectWithHealth: " << this << std::endl;
    }

    // Second constructor for ObjectWithHealth.
    ObjectWithHealth::ObjectWithHealth(const Point &point, int health, int maxHealth) : ObjectWithLocation(point),
                                                                                        m_health(health),
                                                                                        m_maxHealth(maxHealth) {
        std::cout << "Second Constructor for ObjectWithHealth: " << this << std::endl;
    }

    // Getter for m_health.
    int ObjectWithHealth::getHealth() const {
        return m_health;
    }

    // Getter for m_maxHealth.
    int ObjectWithHealth::getMaxHealth() const {
        return m_maxHealth;
    }

    // Setter for m_health.
    void ObjectWithHealth::setHealth(int health) {
        m_health = health;
    }

    // Setter for m_maxHealth.
    void ObjectWithHealth::setMaxHealth(int maxHealth) {
        m_maxHealth = maxHealth;
    }

    // Increase health.
    void ObjectWithHealth::increaseHealth(int amount) {
        m_health = std::max(m_health + amount, m_maxHealth);
    }

    // Decrease health.
    void ObjectWithHealth::decreaseHealth(int amount) {
        m_health = std::min(m_health - amount, 0);
    }

    // Check health.
    bool ObjectWithHealth::isAlive() const {
        return m_health > 0;
    }

} /* namespace TowerDefence */
