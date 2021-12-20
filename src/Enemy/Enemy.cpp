/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include "Enemy.h"

namespace TowerDefence {

    // Empty constructor for Enemy.
    Enemy::Enemy() : ObjectWithHealth(), m_speed(0), m_recovery(0), m_damage(0) {
        std::cout << "Empty Constructor for Enemy: " << this << std::endl;
    }

    // First constructor for Enemy.
    Enemy::Enemy(const Point &point, int health, int speed, int recovery, int damage) : ObjectWithHealth(point, health),
                                                                                        m_speed(speed),
                                                                                        m_recovery(recovery),
                                                                                        m_damage(damage) {
        std::cout << "First Constructor for Enemy: " << this << std::endl;
    }

    // Second constructor for Enemy.
    Enemy::Enemy(const Point &point, int health, int maxHealth, int speed, int recovery, int damage) : ObjectWithHealth(
            point, health, maxHealth), m_speed(speed), m_recovery(recovery), m_damage(damage) {
        std::cout << "Second Constructor for Enemy: " << this << std::endl;
    }

    void Enemy::createRoute(Landscape &landscape) {

    }

    // Update data for Enemy.
    void Enemy::update() {
        //добавить про маршрут, про бафы аурами, про
    }

    // Attack Castle.
    void Enemy::attackCastle(Castle& castle) {
        if (m_point == castle.getPoint())
            castle.decreaseHealth(m_damage);
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
