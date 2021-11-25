/* Created by bar1k4real on 15.11.2021. */

#include "Enemy.h"

namespace TowerDefence {

    // Update data for Enemy.
    void Enemy::update() {
        //добавить про маршрут, про бафы аурами, про
    }

    // Attack Castle.
    int Enemy::attackCastle(int health) {
        health -= m_damage;
    }

    // Getter for m_speed.
    int Enemy::getSpeed() const {
        return m_speed;
    }

    // Setter for m_speed.
    void Enemy::setSpeed(int mSpeed) {
        m_speed = mSpeed;
    }

    // Getter for m_recovery.
    int Enemy::getRecovery() const {
        return m_recovery;
    }

    // Setter for m_recovery.
    void Enemy::setRecovery(int mRecovery) {
        m_recovery = mRecovery;
    }

    // Getter for m_damage.
    int Enemy::getDamage() const {
        return m_damage;
    }

    // Setter for m_damage.
    void Enemy::setDamage(int mDamage) {
        m_damage = mDamage;
    }

} /* namespace TowerDefence */
