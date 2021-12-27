/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include "Enemy.h"

namespace TowerDefence {

    // Empty constructor for Enemy.
    Enemy::Enemy() : ObjectWithHealth(), m_speed(0), m_recovery(0), m_damage(0), m_route(), m_counterOfWayPoint(0),
                     m_isMove(false), m_image(), m_texture(), m_sprite() {}


    // First constructor for Enemy.
    Enemy::Enemy(const Point &point, float health, float maxHealth, float speed, float recovery, float damage,
                 const std::vector<Point> &route) : ObjectWithHealth(point, health, maxHealth), m_speed(speed),
                                                    m_recovery(recovery), m_damage(damage), m_route(route),
                                                    m_counterOfWayPoint(0), m_isMove(true) {
        m_numberOfWayPoint = m_route.size();
        m_image.loadFromFile("../image/Texture.png");
        m_texture.loadFromImage(m_image);                   // ошибка при вызове более двух врагов, показывается
        m_sprite.setTexture(m_texture);                    // белый квадрат, а не спрайт врага.
    }

//    void Enemy::createRoute(Landscape &landscape) {
//
//    }

    // Update data for Enemy.
    int Enemy::update(sf::RenderWindow &window) {
        return 0;
    }

    // Attack Castle.
    void Enemy::attackCastle(Castle &castle) {
        if (m_point == castle.getPoint())
            castle.decreaseHealth(m_damage);
    }

    float Enemy::getSpeed() const {
        return m_speed;
    }

    void Enemy::setSpeed(float mSpeed) {
        m_speed = mSpeed;
    }

    float Enemy::getRecovery() const {
        return m_recovery;
    }

    void Enemy::setRecovery(float mRecovery) {
        m_recovery = mRecovery;
    }

    float Enemy::getDamage() const {
        return m_damage;
    }

    void Enemy::setDamage(float mDamage) {
        m_damage = mDamage;
    }

    const std::vector<Point> &Enemy::getRoute() const {
        return m_route;
    }

    void Enemy::setRoute(const std::vector<Point> &mRoute) {
        m_route = mRoute;
    }

    int Enemy::getCounter() const {
        return m_counterOfWayPoint;
    }

    void Enemy::setCounter(int mCounter) {
        m_counterOfWayPoint = mCounter;
    }

    bool Enemy::getIsMove() const {
        return m_isMove;
    }

    void Enemy::setIsMove(bool mIsMove) {
        m_isMove = mIsMove;
    }

    const sf::Image &Enemy::getImage() const {
        return m_image;
    }

    void Enemy::setImage(const sf::Image &mImage) {
        m_image = mImage;
    }

    const sf::Texture &Enemy::getTexture() const {
        return m_texture;
    }

    void Enemy::setTexture(const sf::Texture &texture) {
        m_texture = texture;
        m_sprite.setTexture(m_texture);
        m_sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
    }

    const sf::Sprite &Enemy::getSprite() const {
        return m_sprite;
    }

    void Enemy::setSprite(const sf::Sprite &mSprite) {
        m_sprite = mSprite;
    }

    int Enemy::getMNumberOfWayPoint() const {
        return m_numberOfWayPoint;
    }

    void Enemy::setMNumberOfWayPoint(int mNumberOfWayPoint) {
        m_numberOfWayPoint = mNumberOfWayPoint;
    }

    int Enemy::getMType() const {
        return m_type;
    }

    void Enemy::setMType(int mType) {
        m_type = mType;
    }

} /* namespace TowerDefence */
