/* Created by bar1k on 19.12.2021. */

#ifndef TOWER_DEFENCE_GAME_MANAGER_H
#define TOWER_DEFENCE_GAME_MANAGER_H

#include <vector>
#include <memory>
#include "../Enemy/AirEnemy/AirEnemy.h"
#include "../Enemy/HeavyEnemy/HeavyEnemy.h"
#include "../Enemy/LightEnemy/LightEnemy.h"
#include "../Enemy/Hero/LightHero/LightHero.h"
#include "../Enemy/Hero/HeavyHero/HeavyHero.h"
#include "../Enemy/Hero/AirHero/AirHero.h"
#include "../Tower/Tower.h"
#include "../Wall/Wall.h"
#include "../Castle/Castle.h"
#include "../Loader/Loader.h"
#include "../Landscape/Landscape.h"

    /**
     * @brief Игровой мэнеджер.
     * @date 19.12.2021
     * @author bar1k4real
     */


namespace TowerDefence {

    class GameManager {
    private:
        int m_numberOfEnemies;
        int m_counterOfEnemies;
        std::shared_ptr<Loader> loader;
        std::shared_ptr<Landscape> landscape;
        std::vector<std::shared_ptr<Enemy>> m_enemies;
        std::vector<std::shared_ptr<Tower>> m_towers;
        std::vector<std::shared_ptr<Wall>> m_walls;
        std::shared_ptr<Castle> m_castle;

        std::vector<Point> m_routesForLightOrHeavyEnemies;
        std::vector<Point> m_routesForAirEnemies;
    public:
        GameManager();

        void loadingLoader();

        void loadingLandscape();

        void createRoutes();

        void createRoutesForLightOrHeavyEnemies();

        void createRoutesForAirEnemies();

        void drawMap(sf::RenderWindow &window);

        void createCastle();

        void createEnemy(float time);

        void createLightEnemy();

        void createHeavyEnemy();

        void createAirEnemy();

        void createLightHero();

        void createHeavyHero();

        void createAirHero();

        void createOrRenovateWall(float pixelX, float pixelY);

        void createWall(int x, int y);

        void renovateWall(int x, int y);

        void createOrUpgradeTower(float pixelX, float pixelY);

        void createTower(int x, int y);

        void upgradeTower(int x, int y);

        void towersAttackEnemies();

        void enemiesAreAlive();

        void enemiesAttackWall();

        void heavyEnemyAttackWall(int i);

        void airEnemyAttackWall(int i);

        void wallsAreAlive();

        void update(sf::RenderWindow &window, sf::Clock &clockForGame);

        void updateLightEnemy(sf::RenderWindow &window, int i);

        void updateHeavyEnemy(sf::RenderWindow &window, int i);

        void updateAirEnemy(sf::RenderWindow &window, int i);

        void otherUpdates(sf::RenderWindow &window);
    };

}

#endif /* TOWER_DEFENCE_GAME_MANAGER_H */
