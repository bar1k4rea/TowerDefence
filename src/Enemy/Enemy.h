/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_ENEMY_H
#define TOWER_DEFENCE_ENEMY_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "../ObjectWithHealth/ObjectWithHealth.h"
#include "../Castle/Castle.h"
#include "../Landscape/Landscape.h"

namespace TowerDefence {

    // class Enemy
    class Enemy : public ObjectWithHealth {
    protected:
        int m_speed;
        int m_recovery;
        int m_damage;
        std::vector<Point> m_route;
        int m_counter;
        sf::Image m_image;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
    public:
        Enemy();

        Enemy(const Point &point, int health, int speed, int recovery, int damage);

        Enemy(const Point &point, int health, int maxHealth, int speed, int recovery, int damage);

        void attackCastle(Castle &castle);

        virtual void createRoute(Landscape &landscape);

        virtual void update();

        [[nodiscard]] int getSpeed() const;

        void setSpeed(int speed);

        [[nodiscard]] int getRecovery() const;

        void setRecovery(int recovery);

        [[nodiscard]] int getDamage() const;

        void setDamage(int damage);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_ENEMY_H */
