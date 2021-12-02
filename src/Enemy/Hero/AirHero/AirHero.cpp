/* Created by bbara on 26.11.2021. */

#include <iostream>
#include "AirHero.h"

namespace TowerDefence {

    AirHero::AirHero() : AirEnemy(), Hero() {

    }

    AirHero::AirHero(const Point &point, int health, int speed, int recovery, int damage, int hit, int ammunition,
                     int length, Aura aura) : AirEnemy(point, health, speed, recovery, damage, hit, ammunition),
                                              Hero(length, aura) {

    }

    void AirHero::useAura(Enemy &enemy) {
        int speed = enemy.getSpeed(), maxHealth = enemy.getMaxHealth(), recovery = enemy.getRecovery(), damage = enemy.getDamage();
        if (distance(enemy.getPoint()) <= m_length) {
            enemy.setSpeed(speed + m_aura.speed);
            enemy.setMaxHealth(maxHealth + m_aura.maxHealth);
            enemy.setRecovery(recovery + m_aura.recovery);
            enemy.setDamage(damage + m_aura.damage);
        }
    }

    void AirHero::update() {
        decreaseHealth(m_recovery);
    }

} /* namespace TowerDefence */