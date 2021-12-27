/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_AURA_H
#define TOWER_DEFENCE_AURA_H

namespace TowerDefence {

    /**
* @brief Аура.
* @details Аура содержит 4 харктеричтики: скорость, макисмальное здоровье, регенрация, и урон.
* @date 19.11.2021
* @author bar1k4real
*/


    // Struct Aura.
    struct Aura {
        float speed;
        float maxHealth;
        float recovery;
        float damage;

        Aura(float speed, float maxHealth, float recovery, float damage) : speed(speed), maxHealth(maxHealth), recovery(recovery), damage(damage) {}
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_AURA_H */
