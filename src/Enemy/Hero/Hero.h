/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_HERO_H
#define TOWER_DEFENCE_HERO_H

#include "../Enemy.h"
#include "../Aura/Aura.h"

namespace TowerDefence {

    // Class Hero.
    class Hero : public Enemy {
    protected:
        Aura m_aura;
    public:
        void useAura();
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_HERO_H */
