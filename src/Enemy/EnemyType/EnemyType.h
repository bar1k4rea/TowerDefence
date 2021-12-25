/* Created by bar1k4real on 25.11.2021. */

#ifndef TOWER_DEFENCE_ENEMY_TYPE_H
#define TOWER_DEFENCE_ENEMY_TYPE_H

namespace TowerDefence {

    /**
* @brief Тип героев.
* @details 6 типов: легкая, тяжелая и воздушная пехота, а также герои.
* @date 19.11.2021
* @author bar1k4real
*/


    // Enum EnemyType
    enum EnemyType {
        AIR_ENEMY,
        HEAVY_ENEMY,
        LIGHT_ENEMY,
        AIR_HERO,
        HEAVY_HERO,
        LIGHT_HERO
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_ENEMY_TYPE_H */
