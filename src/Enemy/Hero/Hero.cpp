/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include "Hero.h"

namespace TowerDefence {

    // Empty constructor for Hero.
    Hero::Hero() : m_length(0), m_aura({0, 0, 0, 0}) {
        std::cout << "Empty Constructor for Hero: " << this << std::endl;
    }

    // First constructor for Hero.
    Hero::Hero(int length, Aura aura) : m_length(length), m_aura(aura) {
        std::cout << "First Constructor for Hero: " << this << std::endl;
    }

    // Improving abilities of enemies.
    void Hero::useAura(Enemy &enemy) {
        int speed = enemy.getSpeed(), maxHealth = enemy.getMaxHealth(), recovery = enemy.getRecovery(), damage = enemy.getDamage();
        if (distance(enemy.getPoint()) <= m_length) {
            enemy.setSpeed(speed + m_aura.speed);
            enemy.setMaxHealth(maxHealth + m_aura.maxHealth);
            enemy.setRecovery(recovery + m_aura.recovery);
            enemy.setDamage(damage + m_aura.damage);
        }
    }

} /* namespace TowerDefence */



