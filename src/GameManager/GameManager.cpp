/* Created by bar1k on 19.12.2021. */

#include "GameManager.h"

namespace TowerDefence {
    void GameManager::update(float time) {
        for (int i = 0; i < m_lightEnemy.size(); i++)
            m_lightEnemy[i].update(time);
//        m_castle.update();
    }
}

