/* Created by bar1k on 19.12.2021. */

#ifndef TOWER_DEFENCE_GAME_MANAGER_H
#define TOWER_DEFENCE_GAME_MANAGER_H

#include <vector>
#include <memory>
#include "../Enemy/AirEnemy/AirEnemy.h"
#include "../Enemy/HeavyEnemy/HeavyEnemy.h"
#include "../Enemy/LightEnemy/LightEnemy.h"
#include "../Tower/Tower.h"
#include "../Wall/Wall.h"
#include "../Castle/Castle.h"
#include "../Loader/Loader.h"
#include "../Landscape/Landscape.h"

namespace TowerDefence {

    /**
 * \brief Игровой мэнеджер.
 * \date 19.12.2021
 * \author bar1k4real
 * \param m_numberOfEnemies Общее количество врагов.
 * \param m_counterOfEnemies Счётчик врагов.
 * \param loader Загрузчик.
 * \param landscape Ланшафт.
 * \param m_enemies Вектор умных указателей на врагов.
 * \param m_towers Вектор умных указателей на башни.
 * \param m_walls Замок.
 * \param m_routesForLghtOrHeavyEnemies Маршрут для лёгкой или тяжёлойй пехоты.
 * \param m_routesForAirEnemies Маршрут для воздушной пехоты.
 */

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

        /**
         * \brief Загрузка загрузчика
         * \details Харктеристики врагов, башен, замка.
         */

        void loadingLoader();

        /**
         * \brief Загрузчик карты.
         */
        void loadingLandscape();

        /**
         * \brief Создание маршрутов.
         */

        void createRoutes();

        /**
         * \brief Создание маршрутов для лёгкой или тяжёлой пехоты.
         */

        void createRoutesForLightOrHeavyEnemies();

        /**
         * \brief Создание маршрутов для воздушной пехоты.
         */

        void createRoutesForAirEnemies();\

        /**
         * \brief Рисовальщик карты.
         */

        void drawMap(sf::RenderWindow &window);

        /**
         * \brief Создание замка.
         */

        void createCastle();

        /**
         * \brief Создание врагов(спавнер).
         * \param time Время, таймера для спавна врагов.
         */

        void createEnemy(float time);

        /**
         * \brief Создание лёгкой пехоты.
         */

        void createLightEnemy();

        /**
        * \brief Создание тяжёлой пехоты.
        */

        void createHeavyEnemy();

        /**
        * \brief Создание воздушной пехоты.
        */

        void createAirEnemy();

        /**
        * \brief Создание стены или её ремонт.
         * \param pixelX Координаты мышки по X.
         * \param pixelY Координаты мышки по Y.
        */

        void createOrRenovateWall(float pixelX, float pixelY);

        /**
        * \brief Создание стены.
         * \param x Координаты сетки (игровых координат) по X.
         * \param y Координаты сетки (игровых координат) по Y.
        */

        void createWall(int x, int y);

        /**
        * \briefРемонт стены..
         * \param x Координаты сетки (игровых координат) по X.
         * \param y Координаты сетки (игровых координат) по Y.
        */

        void renovateWall(int x, int y);

        /**
        * \brief Создание башни или её апгрейд.
         * \param pixelX Координаты мышки по X.
         * \param pixelY Координаты мышки по Y.
        */

        void createOrUpgradeTower(float pixelX, float pixelY);

        /**
        * \brief Создание башни.
         * \param x Координаты сетки (игровых координат) по X.
         * \param y Координаты сетки (игровых координат) по Y.
        */

        void createTower(int x, int y);

        /**
        * \brief Апгрейд башни.
         * \param x Координаты сетки (игровых координат) по X.
         * \param y Координаты сетки (игровых координат) по Y.
        */

        void upgradeTower(int x, int y);

        /**
        * \brief Аттака башен на врагов.
        */

        void towersAttackEnemies();

        /**
         * \brief Проверка на выживаемость всех врагов.
         */

        void enemiesAreAlive();

        /**
         * \brief Враги аттакуют стены.
         */

        void enemiesAttackWall();

        /**
         * \brief Атака тяжёлых вргагов на стены.
         * \param i i-oe значение в векторе врагов
         */

        void heavyEnemyAttackWall(int i);

        /**
         * \brief Атака воздушных вргагов на стены.
         * \param i i-oe значение в векторе врагов
         */

        void airEnemyAttackWall(int i);

        /**
         * \brief Проверка на выживаемость всех стен.
         */

        void wallsAreAlive();

        /**
         * \brief Глобальное обновление игры.
         * @param window Основное окно игры.
         * @param clockForGame Таймер для игры (например: обновляется каждые 0.3 секунды).
         */

        void update(sf::RenderWindow &window, sf::Clock &clockForGame);

        /**
         * \brief Обновление лёгкой пехоты.
         * @param window Основное окно игры.
         * @param i i-oe значение в векторе врагов.
         */

        void updateLightEnemy(sf::RenderWindow &window, int i);


        /**
         * \brief Обновление тяжёлой пехоты.
         * @param window Основное окно игры.
         * @param i i-oe значение в векторе врагов.
         */

        void updateHeavyEnemy(sf::RenderWindow &window, int i);

        /**
         * \brief Обновление воздушной пехоты.
         * @param window Основное окно игры.
         * @param i i-oe значение в векторе врагов.
         */

        void updateAirEnemy(sf::RenderWindow &window, int i);

        /**
         * \brief Прочие обновления.
         * @param window Основное окно игры.
         */

        void otherUpdates(sf::RenderWindow &window);
    };

}

#endif /* TOWER_DEFENCE_GAME_MANAGER_H */

//        void createLightHero();
//
//        void createHeavyHero();
//
//        void createAirHero();
