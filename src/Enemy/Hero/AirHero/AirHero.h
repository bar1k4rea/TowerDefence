/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_AIR_HERO_H
#define TOWER_DEFENCE_AIR_HERO_H

#include "../Hero.h"
#include "../../AirEnemy/AirEnemy.h"

namespace TowerDefence {

    // Class AirHero.
    class AirHero : public AirEnemy, public Hero {
    public:
        AirHero();

        AirHero(const Point &point, int health, int speed, int recovery, int damage, int hit, int ammunition, int m_length, Aura m_aura);

        virtual void useAura(Enemy &enemy);

        virtual void update();
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_AIR_HERO_H */
