/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_LANDSCAPE_H
#define TOWER_DEFENCE_LANDSCAPE_H

#include <set>
#include <memory>
#include "../Enemy/Enemy.h"
#include "../Cell/Cell.h"
#include "../Tower/Tower.h"
#include "../Enemy/LightEnemy/LightEnemy.h"
#include "../Enemy/HeavyEnemy/HeavyEnemy.h"
#include "../Enemy/AirEnemy/AirEnemy.h"

namespace TowerDefence {

    // Class Landscape.
    class Landscape {
        int height;
        int weight;

//        std::set<std::shared_ptr<Enemy>> m_enemies;
//        std::set<std::shared_ptr<Cell>> m_cells;
//        std::set<std::shared_ptr<class Tower>> m_towers;
//        std::shared_ptr<Castle> m_castle;
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_LANDSCAPE_H */
