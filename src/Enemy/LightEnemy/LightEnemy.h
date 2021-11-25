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


        void avoidDamage();

        void update();
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_LIGHT_ENEMY_H */
