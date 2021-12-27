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
        float m_hit;
        float m_ammunition;
    public:
        AirEnemy();

        AirEnemy(const Point &point, float health, float maxHealth, float speed, float recovery, float damage, std::vector<Point> &route, float hit, float ammunition);

        void attackWall(Wall &wall);

        virtual int update(sf::RenderWindow &window);
    };

} /* namespace TowerDefence */

#endif //TOWER_DEFENCE_AIR_ENEMY_H
