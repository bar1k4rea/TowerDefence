/* Created by bbara on 19.11.2021. */

#ifndef TOWER_DEFENCE_LIGHT_HERO_H
#define TOWER_DEFENCE_LIGHT_HERO_H

#include "../Hero.h"
#include "../../LightEnemy/LightEnemy.h"

namespace TowerDefence {

    /**
     * @brief Легкий герой.
     * @details Сочетание героя и лёгкой пехоты.
     * @date 19.11.2021
     * @author bar1k4real
     */

    // Class LightHero.
    class LightHero : public LightEnemy {
    protected:
        float m_length;
        Aura m_aura;
    public:
        LightHero();

        LightHero(const Point &point, float health, float maxHelath, float speed, float recovery, float damage, std::vector<Point> &route, float chance, float length, Aura aura);

        virtual int update(sf::RenderWindow &window);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_LIGHT_HERO_H */
