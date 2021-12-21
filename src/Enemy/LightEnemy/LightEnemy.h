/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_LIGHT_ENEMY_H
#define TOWER_DEFENCE_LIGHT_ENEMY_H

#include "../Enemy.h"

namespace TowerDefence {

    // Class LightEnemy.
    class LightEnemy : public Enemy {
    protected:
        int m_chance;
    public:
        LightEnemy();

        LightEnemy(const Point &point, int health, int speed, int recovery, int damage, int chance);

        LightEnemy(const Point &point, int health, int maxHealth, int speed, int recovery, int damage, int chance);

        bool avoidDamage();

        virtual void createRoute(Landscape &landscape);

        virtual void update(sf::RenderWindow &window, float time);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_LIGHT_ENEMY_H */
