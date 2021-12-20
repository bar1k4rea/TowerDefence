/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include "LightEnemy.h"

namespace TowerDefence {

    // Empty constructor for LightEnemy.
    LightEnemy::LightEnemy() : Enemy(), m_chance(0) {
        std::cout << "Empty Constructor for LightEnemy: " << this << std::endl;
    }

    // First constructor for LightEnemy.
    LightEnemy::LightEnemy(const Point &point, int health, int speed, int recovery, int damage, int chance) : Enemy(
            point, health, speed, recovery, damage), m_chance(chance) {
        std::cout << "First Constructor for LightEnemy: " << this << std::endl;
    }

    // Second constructor for  LightEnemy.
    LightEnemy::LightEnemy(const Point &point, int health, int maxHealth, int speed, int recovery, int damage,
                           int chance) : Enemy(point, health, maxHealth, speed, recovery, damage), m_chance(chance) {
        std::cout << "Second Constructor for  LightEnemy: " << this << std::endl;
    }

    // Dodge hit.
    bool LightEnemy::avoidDamage() {
        if (rand() % 100 > m_chance)
            return true;
        return false;
    }

    void LightEnemy::createRoute(Landscape &landscape) {
        int H = landscape.getHeight();
        int W = landscape.getWidth();
        int grid[H][W];
        int ax, ay, bx, by;
        ax = m_point.x;
        ay = m_point.y;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (landscape.m_map[i][j] == 'P')
                    grid[i][j] = -2;
                else if (landscape.m_map[i][j] == 'C') {
                    bx = i;
                    by = j;
                    grid[bx][by] = -2;
                }
                else
                    grid[i][j] = -1;
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
            px[d] = x;
            py[d] = y;
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
        px[0] = ax;
        py[0] = ay;
        for (int i = 0; i < len + 1; i++) {
            m_route[i].x = px[0];
            m_route[i].y = py[0];
        }
        m_counter = 0;
    }

    // Update data for LightEnemy.
    void LightEnemy::update(float time) {
        if (m_route[m_counter].x != (int)(m_sprite.getPosition().x / 32) && m_route[m_counter].y != (int)(m_sprite.getPosition().y / 32)) {
            if (m_point.x == m_route[m_counter].x && m_point.y == m_route[m_counter].y - 1) {
                m_sprite.move(0, 0.1);
            }
        } else {
            m_counter++;
        }

        decreaseHealth(m_recovery);
    }

} /* namespace TowerDefence */
