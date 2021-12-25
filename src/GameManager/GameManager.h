/* Created by bar1k on 19.12.2021. */

#ifndef TOWER_DEFENCE_GAME_MANAGER_H
#define TOWER_DEFENCE_GAME_MANAGER_H

#include <vector>
#include "../Enemy/AirEnemy/AirEnemy.h"
#include "../Enemy/HeavyEnemy/HeavyEnemy.h"
#include "../Enemy/LightEnemy/LightEnemy.h"
#include "../Tower/Tower.h"
#include "../Castle/Castle.h"
#include "../Loader/Loader.h"
#include "../Landscape/Landscape.h"

    /**
     * @brief Игровой мэнеджер.
     * @details Класс отвечает за всю логику игры.
     * @date 19.12.2021
     * @author bar1k4real
     */


namespace TowerDefence {

    class GameManager {
    public:
        std::vector<LightEnemy> m_lightEnemies;
//        std::vector<AirEnemy> m_airEnemies;
//        std::vector<HeavyEnemy> m_heavyEnemies;
        std::vector<Tower> m_towers;
        Castle m_castle;

        std::vector<Point> m_routesForLightOrHeavyEnemies;
        std::vector<Point> m_routesForAirEnemies;

        int m_counter;
    public:
        GameManager() = default;

        void createRoutes(Landscape &landscape);

        void createRoutesForLightOrHeavyEnemies(Landscape &landscape);

        void createRoutesForAirEnemies(Landscape &landscape);

        void createEnemy(Loader &loader, Landscape &landscape, float time);

//        void draw(sf::RenderWindow &window);

        void update(sf::RenderWindow &window);

//        void update(float time);
    };
}

#endif /* TOWER_DEFENCE_GAME_MANAGER_H */
