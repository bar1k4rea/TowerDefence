/* Created by bbara on 19.11.2021. */

#ifndef TOWER_DEFENCE_HEAVY_HERO_H
#define TOWER_DEFENCE_HEAVY_HERO_H

#include "../Hero.h"
#include "../../HeavyEnemy/HeavyEnemy.h"

namespace TowerDefence {

    /**
    * @brief Тяжёлый герой.
    * @details Сочетание героя и тяжёлой пехоты.
    * @date 19.11.2021
    * @author bar1k4real
    */


    // Class HeavyHero.
    class HeavyHero : public HeavyEnemy, public Hero {
    public:
        HeavyHero();

        HeavyHero(const Point &point, int health, int speed, int recovery, int damage, int hit, int radius,
                  int m_length, Aura m_aura);

        virtual void update();
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_HEAVY_HERO_H */
