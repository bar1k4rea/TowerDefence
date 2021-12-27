/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include "ObjectWithHealth.h"

namespace TowerDefence {

    // Empty constructor for ObjectWithHealth.
    ObjectWithHealth::ObjectWithHealth() : m_health(1), m_maxHealth(1), ObjectWithLocation() {}

    // First constructor for ObjectWithHealth.
    ObjectWithHealth::ObjectWithHealth(const Point &point, int health, int maxHealth) : ObjectWithLocation(point),
                                                                                        m_health(health),
                                                                                        m_maxHealth(maxHealth) {}

    // Increase health.
    void ObjectWithHealth::increaseHealth(float amount) {
        m_health = std::min<float>(m_health + amount, m_maxHealth);
    }

    // Decrease health.
    void ObjectWithHealth::decreaseHealth(float amount) {
        m_health = std::max<float>(m_health - amount, 0);
    }

    // Check health.
    bool ObjectWithHealth::isNotAlive() const {
        return m_health == 0;
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

} /* namespace TowerDefence */
