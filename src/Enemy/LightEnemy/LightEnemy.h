/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_LIGHT_ENEMY_H
#define TOWER_DEFENCE_LIGHT_ENEMY_H

#include "../Enemy.h"

namespace TowerDefence {

    /**
     * \brief Лёгкая пехота.
     * \date 15.11.2021
     * \author bar1k4real
     * \param m_chance Шанс уклонения врага от урона башни.
     */

    // Class LightEnemy.
    class LightEnemy : public Enemy {
    private:
        float m_chance;
    public:
        LightEnemy();

        LightEnemy(const Point &point, float health, float maxHealth, float speed, float recovery, float damage,
                   std::vector<Point> &route, float chance);

        bool avoidDamage();

        virtual int update(sf::RenderWindow &window);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_LIGHT_ENEMY_H */
