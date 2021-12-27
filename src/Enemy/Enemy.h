/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_ENEMY_H
#define TOWER_DEFENCE_ENEMY_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "../ObjectWithHealth/ObjectWithHealth.h"
#include "../Castle/Castle.h"
#include "../Landscape/Landscape.h"

namespace TowerDefence {
    /**
     * \brief Враг.
     * \date 15.11.2021
     * \author bar1k4real
     * \param m_speed Скорость врага.
     * \param m_recovery Скорость регенерации количества здоровья у врага.
     * \param m_damage Урон замку от врага.
     * \param m_route Маршрут врага до замка.
     * \param m_counter Счётчик номера клетки в маршруте у врага.
     * \param m_image Изображение врага.
     * \param m_texture Текстура врага.
     * \param m_sprite Спрайт врага.
     */

    // class Enemy
    class Enemy : public ObjectWithHealth {
    protected:
        int m_type;
        float m_speed;
        float m_recovery;
        float m_damage;
        std::vector<Point> m_route;
        int m_counterOfWayPoint;
        int m_numberOfWayPoint;
        bool m_isMove;
        bool m_isUseAura;
        sf::Image m_image;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
    public:
        Enemy();

        Enemy(const Point &point, float health, float maxHealth, float speed, float recovery, float damage,
              const std::vector<Point> &route);

        void attackCastle(Castle &castle); // NOT READY

//        virtual void createRoute(Landscape &landscape);
//

        virtual int update(sf::RenderWindow &window);

        int getMNumberOfWayPoint() const;

        void setMNumberOfWayPoint(int mNumberOfWayPoint);

        float getSpeed() const;

        void setSpeed(float mSpeed);

        float getRecovery() const;

        void setRecovery(float mRecovery);

        float getDamage() const;

        void setDamage(float mDamage);

        const std::vector<Point> &getRoute() const;

        void setRoute(const std::vector<Point> &mRoute);

        int getCounter() const;

        void setCounter(int mCounter);

        bool getIsMove() const;

        void setIsMove(bool mIsMove);

        const sf::Image &getImage() const;

        void setImage(const sf::Image &mImage);

        const sf::Texture &getTexture() const;

        void setTexture(const sf::Texture &mTexture);

        const sf::Sprite &getSprite() const;

        void setSprite(const sf::Sprite &mSprite);

        int getMType() const;

        void setMType(int mType);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_ENEMY_H */
