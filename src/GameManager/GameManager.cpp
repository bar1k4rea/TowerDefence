/* Created by bar1k on 19.12.2021. */

#include "GameManager.h"

namespace TowerDefence {

    void GameManager::createEnemy(Loader &loader, Landscape &landscape, float time) {

        if (m_counter < 5) {

            if (time > loader.m_lairTable[m_counter].time) {
                std::cout << m_counter << std::endl << std::endl << std::endl << std::endl << std::endl;
                if (loader.m_lairTable[m_counter].type == 3) {
                    LightEnemy lightEnemy(m_routesForLightOrHeavyEnemies[0], loader.m_enemyTable[3].maxHealth,
                                          loader.m_enemyTable[3].maxHealth,
                                          loader.m_enemyTable[3].speed, loader.m_enemyTable[3].recovery,
                                          loader.m_enemyTable[3].damage, m_routesForLightOrHeavyEnemies,
                                          loader.m_enemyTable[3].chance);

                    m_lightEnemies.push_back(lightEnemy);
                }
                m_counter++;
            }
        }
    }

    // следить за m_counter (ошибки возникают)

    void GameManager::createRoutes(Landscape &landscape) {
        createRoutesForLightOrHeavyEnemies(landscape);
        createRoutesForAirEnemies(landscape);
    }

    void GameManager::createRoutesForLightOrHeavyEnemies(Landscape &landscape) {
        int H = landscape.getHeight();
        int W = landscape.getWidth();
        int grid[H][W];
        int ax, ay, bx, by;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (landscape.m_map[i][j] == 'W' || landscape.m_map[i][j] == 'M')
                    grid[i][j] = -1;
                else if (landscape.m_map[i][j] == 'C') {
                    bx = i;
                    by = j;
                    grid[bx][by] = -2;
                }
                else if (landscape.m_map[i][j] == 'L') {
                    ax = i;
                    ay = j;
                }
                else
                    grid[i][j] = -2;
            }
        }

        int px[H * W], py[H * W];
        int len;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int d, x, y, k;
        bool stop;

        d = 0;
        grid[ax][ay] = 0;
        do {
            stop = true;
            for (x = 0; x < H; x++) {
                for (y = 0; y < W; y++) {
                    if (grid[x][y] == d) {
                        for (k = 0; k < 4; k++) {
                            int ix = x + dx[k], iy = y + dy[k];
                            if (ix >= 0 && ix < H && iy >= 0 && iy < W && grid[ix][iy] == -2) {
                                stop = false;
                                grid[ix][iy] = d + 1;
                            }
                        }
                    }
                }
            }
            d++;
        } while (!stop && grid[bx][by] == -2);

        len = grid[bx][by];
        x = bx;
        y = by;
        d = len;
        while (d > 0) {
            py[d] = x;
            px[d] = y;
            d--;
            for (k = 0; k < 4; k++) {
                int ix = x + dx[k], iy = y + dy[k];
                if (ix >= 0 && ix < H && iy >= 0 && iy < W && grid[ix][iy] == d) {
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
            m_routesForLightOrHeavyEnemies.push_back(point);
        }
    }

    void GameManager::createRoutesForAirEnemies(Landscape &landscape) {
        int H = landscape.getHeight();
        int W = landscape.getWidth();
        int grid[H][W];
        int ax, ay, bx, by;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (landscape.m_map[i][j] == 'W' || landscape.m_map[i][j] == 'M')
                    grid[i][j] = -2;
                else if (landscape.m_map[i][j] == 'C') {
                    bx = i;
                    by = j;
                    grid[bx][by] = -2;
                }
                else if (landscape.m_map[i][j] == 'L') {
                    ax = i;
                    ay = j;
                }
                else
                    grid[i][j] = -2;
            }
        }

        int px[H * W], py[H * W];
        int len;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int d, x, y, k;
        bool stop;

        d = 0;
        grid[ax][ay] = 0;
        do {
            stop = true;
            for (x = 0; x < H; x++) {
                for (y = 0; y < W; y++) {
                    if (grid[x][y] == d) {
                        for (k = 0; k < 4; k++) {
                            int ix = x + dx[k], iy = y + dy[k];
                            if (ix >= 0 && ix < H && iy >= 0 && iy < W && grid[ix][iy] == -2) {
                                stop = false;
                                grid[ix][iy] = d + 1;
                            }
                        }
                    }
                }
            }
            d++;
        } while (!stop && grid[bx][by] == -2);

        len = grid[bx][by];
        x = bx;
        y = by;
        d = len;
        while (d > 0) {
            py[d] = x;
            px[d] = y;
            d--;
            for (k = 0; k < 4; k++) {
                int ix = x + dx[k], iy = y + dy[k];
                if (ix >= 0 && ix < H && iy >= 0 && iy < W && grid[ix][iy] == d) {
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

    void GameManager::update(sf::RenderWindow &window) {
        for (int i = 0; i < m_lightEnemies.size(); i++) {
            m_lightEnemies[i].update(window);
        }
    }

}
