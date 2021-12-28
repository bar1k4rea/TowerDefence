/* Created by bar1k on 19.12.2021. */

#include <exception>
#include "GameManager.h"
#include "../CorrectInput/CorrectInput.h"

namespace TowerDefence {

    // Empty constructor for GameManager.
    GameManager::GameManager() : m_numberOfEnemies(0), m_counterOfEnemies(0), m_enemies(), m_towers(),
                                 m_routesForLightOrHeavyEnemies(), m_routesForAirEnemies() {
        loader = std::make_shared<Loader>();
        landscape = std::make_shared<Landscape>();
        m_castle = std::make_shared<Castle>();
    }

    // Loading loader.
    void GameManager::loadingLoader() {
        int option;
        std::cout << "Do you want to change the configuration files? (0 - No, 1 - Yes) -> ";
        getNumber(option);
        if (option) {
            std::cout << "Are you sure? (0 - No, 1 - Yes) -> ";
            getNumber(option);
            if (option)
                loader->createTable();
        }
        m_numberOfEnemies = loader->loadTable();
        createCastle();
        std::cout << "Do you want to see the configuration files? (0 - No, 1 - Yes) -> ";
        getNumber(option);
        if (option) {
            std::cout << "Are you sure? (0 - No, 1 - Yes) -> ";
            getNumber(option);
            if (option)
                loader->showTable();
        }
    }

    // Loading landscape.
    void GameManager::loadingLandscape() {
        int option;
        std::cout << "Do you want to change landscape design? (0 - No, 1 - Yes) -> ";
        getNumber(option);
        if (option) {
            std::cout << "Are you sure? (0 - No, 1 - Yes) -> ";
            getNumber(option);
            if (option)
                landscape->createMap();
        }
        landscape->loadMap();
    }

    // Create Castle.
    void GameManager::createCastle() {
        m_castle->setMaxHealth(loader->m_castleTable[1].maxHealth);
        m_castle->setTable(loader->m_castleTable);
    }

    // Create routes.
    void GameManager::createRoutes() {
        createRoutesForLightOrHeavyEnemies();
        createRoutesForAirEnemies();
    }

    // Create routes for light and heavy enemies.
    void GameManager::createRoutesForLightOrHeavyEnemies() {
        int H = landscape->getHeight(), W = landscape->getWidth(), field[H][W], ax, ay, bx, by;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int d = 0, x, y, k, len, px[H * W], py[H * W];
        bool stop;

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++) {
                if (landscape->getCell(i, j) == 'L') {
                    ax = i;
                    ay = j;
                    field[ax][ay] = 0;
                } else if (landscape->getCell(i, j) == 'C') {
                    bx = i;
                    by = j;
                    m_castle->setPoint(Point(j, i));
                    field[bx][by] = -2;
                } else if (landscape->getCell(i, j) == ' ')
                    field[i][j] = -2;
                else
                    field[i][j] = -1;
            }

        do {
            stop = true;
            for (x = 0; x < H; x++)
                for (y = 0; y < W; y++)
                    if (field[x][y] == d)
                        for (k = 0; k < 4; k++) {
                            int ix = x + dx[k], iy = y + dy[k];
                            if (0 <= x < H && 0 <= y < W && field[ix][iy] == -2) {
                                stop = false;
                                field[ix][iy] = d + 1;
                            }
                        }
            d++;
        } while (!stop && field[bx][by] == -2);

        len = field[bx][by];
        x = bx;
        y = by;
        d = len;
        while (d > 0) {
            px[d] = y;
            py[d] = x;
            d--;
            for (k = 0; k < 4; k++) {
                int ix = x + dx[k], iy = y + dy[k];
                if (0 <= ix < H && 0 <= iy < W && field[ix][iy] == d) {
                    x = x + dx[k];
                    y = y + dy[k];
                    break;
                }
            }
        }
        py[0] = ax;
        px[0] = ay;

        for (int i = 0; i < len + 1; i++)
            m_routesForLightOrHeavyEnemies.push_back(Point(px[i], py[i]));
    }

    // Create routes for air enemies.
    void GameManager::createRoutesForAirEnemies() {
        int H = landscape->getHeight(), W = landscape->getWidth(), field[H][W], ax, ay, bx, by;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int d = 0, x, y, k, len, px[H * W], py[H * W];
        bool stop;

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++) {
                if (landscape->getCell(i, j) == 'L') {
                    ax = i;
                    ay = j;
                    field[ax][ay] = 0;
                } else if (landscape->getCell(i, j) == 'C') {
                    bx = i;
                    by = j;
                    field[bx][by] = -2;
                } else
                    field[i][j] = -2;
            }

        do {
            stop = true;
            for (x = 0; x < H; x++)
                for (y = 0; y < W; y++)
                    if (field[x][y] == d)
                        for (k = 0; k < 4; k++) {
                            int ix = x + dx[k], iy = y + dy[k];
                            if (0 <= x < H && 0 <= y < W && field[ix][iy] == -2) {
                                stop = false;
                                field[ix][iy] = d + 1;
                            }
                        }
            d++;
        } while (!stop && field[bx][by] == -2);

        len = field[bx][by];
        x = bx;
        y = by;
        d = len;
        while (d > 0) {
            px[d] = y;
            py[d] = x;
            d--;
            for (k = 0; k < 4; k++) {
                int ix = x + dx[k], iy = y + dy[k];
                if (0 <= ix < H && 0 <= iy < W && field[ix][iy] == d) {
                    x = x + dx[k];
                    y = y + dy[k];
                    break;
                }
            }
        }
        py[0] = ax;
        px[0] = ay;

        for (int i = 0; i < len + 1; i++) {
            Point point(px[i], py[i]);
            m_routesForAirEnemies.push_back(point);
        }
    }

    // Draw map.
    void GameManager::drawMap(sf::RenderWindow &window) {
        (*landscape).drawMap(window);
    }

    // Create enemy.
    void GameManager::createEnemy(float time) {
        if (m_counterOfEnemies < m_numberOfEnemies)
            if (time > loader->m_lairTable[m_counterOfEnemies + 1].time) {
                m_counterOfEnemies++;
                if (loader->m_lairTable[m_counterOfEnemies].type == 0)
                    createLightEnemy();
                if (loader->m_lairTable[m_counterOfEnemies].type == 1)
                    createHeavyEnemy();
                if (loader->m_lairTable[m_counterOfEnemies].type == 2)
                    createAirEnemy();
            }
    }

    // Create LightEnemy.
    void GameManager::createLightEnemy() {
        std::shared_ptr<LightEnemy> lightEnemySharedPtr = std::make_shared<LightEnemy>(
                m_routesForLightOrHeavyEnemies[0], loader->m_enemyTable[0].maxHealth, loader->m_enemyTable[0].maxHealth,
                loader->m_enemyTable[0].speed, loader->m_enemyTable[0].recovery, loader->m_enemyTable[0].damage,
                m_routesForLightOrHeavyEnemies, loader->m_enemyTable[0].chance);
        m_enemies.push_back(lightEnemySharedPtr);
    }

    // Create HeavyEnemy.
    void GameManager::createHeavyEnemy() {
        std::shared_ptr<HeavyEnemy> heavyEnemySharedPtr = std::make_shared<HeavyEnemy>(m_routesForLightOrHeavyEnemies[0], loader->m_enemyTable[1].maxHealth, loader->m_enemyTable[1].maxHealth,
                                                                                       loader->m_enemyTable[1].speed, loader->m_enemyTable[1].recovery, loader->m_enemyTable[1].damage,
                                                                                       m_routesForLightOrHeavyEnemies, loader->m_enemyTable[1].hit, loader->m_enemyTable[1].radius);
        m_enemies.push_back(heavyEnemySharedPtr);
    }

    // Create AirEnemy.
    void GameManager::createAirEnemy() {
        std::shared_ptr<AirEnemy> airEnemySharedPtr = std::make_shared<AirEnemy>(m_routesForAirEnemies[0], loader->m_enemyTable[2].maxHealth, loader->m_enemyTable[2].maxHealth,
                                                                                 loader->m_enemyTable[2].speed, loader->m_enemyTable[2].recovery, loader->m_enemyTable[2].damage,
                                                                                 m_routesForAirEnemies, loader->m_enemyTable[2].hit, loader->m_enemyTable[2].ammunition);
        m_enemies.push_back(airEnemySharedPtr);
    }

    // Create or renovate Wall.
    void GameManager::createOrRenovateWall(float pixelX, float pixelY) {
        int x = pixelX / 32, y = pixelY / 32;

        if (landscape->getCell(y, x) == ' ') {
            landscape->setCell(y, x, 'B');
            createWall(x, y);
        } else if (landscape->getCell(y, x) == 'B')
            renovateWall(x, y);
        else
            throw std::out_of_range("You can't place the Wall in this place!");
    }

    // Create wall.
    void GameManager::createWall(int x, int y) {
        float gold = m_castle->getGold();
        float cost = 40;
        if (gold >= cost) {
            m_castle->setGold(gold - cost);
            std::shared_ptr<Wall> wallSharedPtr = std::make_shared<Wall>(Point(x, y), 100, 100);
            m_walls.push_back(wallSharedPtr);
        } else
            throw std::out_of_range("Not enough gold to create Wall!");
    }

    // Renovate wall.
    void GameManager::renovateWall(int x, int y) {
        Point point(x, y);
        for (int i = 0; i < m_walls.size(); i++) {
            if (m_walls[i]->getPoint() == point) {
                m_walls[i]->renovate(m_castle);
                break;
            }
        }
    }

    // Create or upgrade tower.
    void GameManager::createOrUpgradeTower(float pixelX, float pixelY) {
        int x = pixelX / 32, y = pixelY / 32;

        if (landscape->getCell(y, x) == 'W' || landscape->getCell(y, x) == 'M') {
            landscape->setCell(y, x, 'T');
            createTower(x, y);
        } else if (landscape->getCell(y, x) == 'T')
            upgradeTower(x, y);
        else
            throw std::out_of_range("You can't place the Tower in this place!");
    }

    // Create Tower.
    void GameManager::createTower(int x, int y) {
        float gold = m_castle->getGold();
        float cost = loader->m_castleTable[1].cost;
        if (gold >= cost) {
            m_castle->setGold(gold - cost);
            std::shared_ptr<Tower> towerSharedPtr = std::make_shared<Tower>(Point(x, y), 1, loader->m_towerTable);
            m_towers.push_back(towerSharedPtr);
        }
        else
            throw std::out_of_range("Not enough gold to create Tower!");
    }

    // Upgrade Tower.
    void GameManager::upgradeTower(int x, int y) {
        Point point(x, y);
        for (int i = 0; i < m_towers.size(); i++)
            if (m_towers[i]->getPoint() == point) {
                m_towers[i]->upgrade(m_castle);
                break;
            }
    }

    // Towers attack enemies.
    void GameManager::towersAttackEnemies() {
        for (int i = 0; i < m_towers.size(); i++)
            for (int j = 0; j < m_enemies.size(); j++)
                m_towers[i]->attackEnemy(m_enemies[j]);
    }

    // Enemies are alive.
    void GameManager::enemiesAreAlive() {
        for (int i = 0; i < m_enemies.size(); i++)
            if (m_enemies[i]->isNotAlive())
                m_enemies.erase(m_enemies.begin() + i);
    }

    // Walls are alive.
    void GameManager::wallsAreAlive() {
        for (int i = 0; i < m_walls.size(); i++)
            if (m_walls[i]->isNotAlive()) {
                Point point = m_walls[i]->getPoint();
                landscape->setCell(point.y, point.x, ' ');
                m_walls.erase(m_walls.begin() + i);
            }
    }

    // Other updates.
    void GameManager::otherUpdates(sf::RenderWindow &window) {

    }

    // Enemies attack wall.
    void GameManager::enemiesAttackWall() {
        for (int i = 0; i < m_enemies.size(); i++) {
            if (m_enemies[i]->getMType() == 2)
                heavyEnemyAttackWall(i);
            else if (m_enemies[i]->getMType() == 3)
                airEnemyAttackWall(i);
        }
    }

    // Heavy enemy attacks wall.
    void GameManager::heavyEnemyAttackWall(int i) {
        for (int j = 0; j < m_walls.size(); j++)
            if (loader->m_enemyTable[1].radius > m_enemies[i]->distance(m_walls[j]->getPoint())) {
                m_walls[j]->decreaseHealth(loader->m_enemyTable[1].hit);
                break;
            }
    }

    // Air enemy attacks wall.
    void GameManager::airEnemyAttackWall(int i) {
        int ammunition = dynamic_cast<AirEnemy*>(m_enemies[i].operator->())->getMAmmunition() - 1;

        if (ammunition + 1 == 0)
            m_enemies[i]->setIsMove(true);

        if (ammunition + 1 != 0) {
            for (int j = 0; j < m_walls.size(); j++)
                if (1 > m_enemies[i]->distance(m_walls[j]->getPoint())) {
                    m_walls[j]->decreaseHealth(loader->m_enemyTable[2].hit);
                    dynamic_cast<AirEnemy *>(m_enemies[i].operator->())->setMAmmunition(ammunition);
                    break;
                }
        }
    }

    // Global update.
    void GameManager::update(sf::RenderWindow &window, sf::Clock &clockForGame) {
        float time = clockForGame.getElapsedTime().asSeconds();

        // Обновление данных замка, урон врагам от башен и проверка врагов на жизнь.
        if (time > 0.3) {
            clockForGame.restart();
            m_castle->update();
            towersAttackEnemies();
            enemiesAttackWall();
            enemiesAreAlive();
            wallsAreAlive();
        }

        // Рисование врагов на карте и урон замку от врагов.
        for (int i = 0; i < m_enemies.size(); i++) {
            if (m_enemies[i]->getMType() == 1)
                updateLightEnemy(window, i);
            else if (m_enemies[i]->getMType() == 2)
                updateHeavyEnemy(window, i);
            else if (m_enemies[i]->getMType() == 3)
                updateAirEnemy(window, i);
        }

    }

    // Update heavy enemy.
    void GameManager::updateHeavyEnemy(sf::RenderWindow &window, int i) {
        int action;

        m_enemies[i]->setIsMove(true);

//        std::cout << dynamic_cast<HeavyEnemy*>(m_enemies[i].operator->())->getMRadius() << std::endl;
//        std::dynamic_pointer_cast<HeavyEnemy>(m_enemies[i])->getMRadius();

        for (int j = 0; j < m_walls.size(); j++)
            if (loader->m_enemyTable[1].radius > m_enemies[i]->distance(m_walls[j]->getPoint()))
                m_enemies[i]->setIsMove(false);

        action = m_enemies[i]->update(window);
        if (action == -1) {
            m_castle->decreaseHealth(m_enemies[i]->getDamage());
            m_enemies.erase(m_enemies.begin() + i);
        }
    }

    // Update light enemy.
    void GameManager::updateLightEnemy(sf::RenderWindow &window, int i) {
        int action;
        Point point = m_routesForLightOrHeavyEnemies[m_enemies[i]->getCounter()];

        if (landscape->getCell(point.y, point.x) == 'B')
            m_enemies[i]->setIsMove(false);
        else
            m_enemies[i]->setIsMove(true);
        action = m_enemies[i]->update(window);
        if (action == -1) {
            m_castle->decreaseHealth(m_enemies[i]->getDamage());
            m_enemies.erase(m_enemies.begin() + i);
        }
    }

    // Update air enemy.
    void GameManager::updateAirEnemy(sf::RenderWindow &window, int i) {
        int action;
        int ammunition = dynamic_cast<AirEnemy*>(m_enemies[i].operator->())->getMAmmunition();
        Point point = m_routesForAirEnemies[m_enemies[i]->getCounter() - 1];

        m_enemies[i]->setIsMove(true);

        if (landscape->getCell(point.y, point.x) == 'B' && ammunition != 0)
            m_enemies[i]->setIsMove(false);


        action = m_enemies[i]->update(window);
        if (action == -1) {
            m_castle->decreaseHealth(m_enemies[i]->getDamage());
            m_enemies.erase(m_enemies.begin() + i);
        }
    }

} /* namespace TowerDefence */

// Create LightHero.
//    void GameManager::createLightHero() {}
//
//    // Create HeavyHero.
//    void GameManager::createHeavyHero() {}
//
//    // Create AirHero.
//    void GameManager::createAirHero() {}

//                if (loader->m_lairTable[m_counterOfEnemies].type == 3)
//                    createLightHero();
//                if (loader->m_lairTable[m_counterOfEnemies].type == 4)
//                    createHeavyHero();
//                if (loader->m_lairTable[m_counterOfEnemies].type == 5)
//                    createAirHero();
