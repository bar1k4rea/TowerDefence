/* Created by bar1k on 19.12.2021. */

#ifndef TOWER_DEFENCE_GAME_MANAGER_H
#define TOWER_DEFENCE_GAME_MANAGER_H

#include <vector>
#include "../Enemy/LightEnemy/LightEnemy.h"
#include "../Castle/Castle.h"

namespace TowerDefence {

    class GameManager {
    private:
        LightEnemy m_lightEnemy;
        Castle m_castle;
    public:
        GameManager() = default;

        void createEnemy(Landscape &landscape);

//        void update(float time);
    };
}

#endif /* TOWER_DEFENCE_GAME_MANAGER_H */
