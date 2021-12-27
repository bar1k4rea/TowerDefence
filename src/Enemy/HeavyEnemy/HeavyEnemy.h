/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_HEAVY_ENEMY_H
#define TOWER_DEFENCE_HEAVY_ENEMY_H

#include "../Enemy.h"
#include "../../Wall/Wall.h"

    /**
     * @brief Тяжёлая пехота.
     * @date 15.11.2021
     * @author bar1k4real
     */

namespace TowerDefence {

    // Class LightEnemy.
    class HeavyEnemy : public Enemy {
    protected:
        float m_hit;
        float m_radius;
    public:
        HeavyEnemy();

        HeavyEnemy(const Point &point, float health, float maxHealth, float speed, float recovery, float damage,
                   const std::vector<Point> &route, float hit, float radius);

        void attackWall(Wall &wall);

        int update(sf::RenderWindow &window);

        float getMHit() const;

        void setMHit(float mHit);

        float getMRadius() const;

        void setMRadius(float mRadius);
    };

} /* namespace TowerDefence */

#endif //TOWER_DEFENCE_HEAVY_ENEMY_H
