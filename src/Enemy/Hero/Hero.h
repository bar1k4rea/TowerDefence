/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_HERO_H
#define TOWER_DEFENCE_HERO_H

#include "../Enemy.h"
#include "../Aura/Aura.h"

namespace TowerDefence {

    // Class Hero.
    class Hero {
    protected:
        int m_length;
        Aura m_aura;
    public:
        Hero();

        explicit Hero(int length, Aura aura);

        void useAura(Enemy &enemy);

        [[nodiscard]] const Aura &getMAura() const {
            return m_aura;
        }

        void setMAura(const Aura &mAura) {
            m_aura = mAura;
        }
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_HERO_H */