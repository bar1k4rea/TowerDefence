/* Created by bbara on 19.11.2021. */

#ifndef TOWER_DEFENCE_LIGHT_HERO_H
#define TOWER_DEFENCE_LIGHT_HERO_H

#include "../Hero.h"
#include "../../LightEnemy/LightEnemy.h"

namespace TowerDefence {

    // Class LightHero.
    class LightHero : public LightEnemy, public Hero {
    public:
        LightHero();

        LightHero(const Point &point, int health, int speed, int recovery, int damage, int chance, int m_length,
                  Aura m_aura);

        virtual void update();
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_LIGHT_HERO_H */
