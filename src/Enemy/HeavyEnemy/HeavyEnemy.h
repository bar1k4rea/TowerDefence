/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_HEAVY_ENEMY_H
#define TOWER_DEFENCE_HEAVY_ENEMY_H

#include "../Enemy.h"
#include "../../Wall/Wall.h"

namespace TowerDefence {

    // Class LightEnemy.
    class HeavyEnemy : public Enemy {
    protected:
        int m_hit;
        int m_radius;
    public:
        HeavyEnemy();

        HeavyEnemy(const Point &point, int health, int speed, int recovery, int damage, int hit, int radius);

        HeavyEnemy(const Point &point, int health, int maxHealth, int speed, int recovery, int damage, int hit,
                   int radius);

        void attackWall(Wall &wall);

        virtual void update();
    };

} /* namespace TowerDefence */

#endif //TOWER_DEFENCE_HEAVY_ENEMY_H
