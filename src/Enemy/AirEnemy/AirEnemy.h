/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_AIR_ENEMY_H
#define TOWER_DEFENCE_AIR_ENEMY_H

#include "../Enemy.h"
#include "../../Wall/Wall.h"

namespace TowerDefence {

    /**
* @brief Воздушная пехота.
* @details Враг может предвигаться через водоёмыи и через горы, имеет ограниченнный боезапас.
* @date 19.11.2021
* @author bar1k4real
*/


    // Class AirEnemy.
    class AirEnemy : public Enemy {
    protected:
        int m_hit;
        int m_ammunition;
    public:
        AirEnemy();

        AirEnemy(const Point &point, int health, int speed, int recovery, int damage, int hit, int ammunition);

        AirEnemy(const Point &point, int health, int maxHealth, int speed, int recovery, int damage, int hit, int ammunition);

        void attackWall(Wall &wall);

        virtual void update();
    };

} /* namespace TowerDefence */

#endif //TOWER_DEFENCE_AIR_ENEMY_H
