/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include <vector>
#include <cmath>
#include "LightEnemy.h"
#include <SFML/Graphics.hpp>

namespace TowerDefence {

    // Empty constructor for LightEnemy.
    LightEnemy::LightEnemy() : Enemy(), m_chance(0) {}

    // First constructor for  LightEnemy.
    LightEnemy::LightEnemy(const Point &point, float health, float maxHealth, float speed, float recovery, float damage,
                           std::vector<Point> &route, float chance) : Enemy(point, health, maxHealth, speed, recovery,
                                                                      damage, route), m_chance(chance) {
        m_sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
    }

    // Dodge hit.
    bool LightEnemy::avoidDamage() {
        return rand() % 100 > m_chance;
    }

    void LightEnemy::createRoute(Landscape &landscape) {
        int H = landscape.getHeight();
        int W = landscape.getWidth();
        int grid[H][W];
        int ax, ay, bx, by;
        ax = m_point.y;
        ay = m_point.x;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (landscape.m_map[i][j] == 'W')
                    grid[i][j] = -1;
                else if (landscape.m_map[i][j] == 'C') {
                    bx = i;
                    by = j;
                    grid[bx][by] = -2;
                } else
                    grid[i][j] = -2;
            }
        }

//        for (int i = 0; i < H; i++) {
//            for (int j = 0; j < W; j++) {
//                if (grid[i][j] >= 0)
//                    std::cout << ' ' << grid[i][j] << ' ';
//                else
//                    std::cout << grid[i][j] << ' ';
//            }
//            std::cout << std::endl;
//        }

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


//        for (int i = 0; i < H; i++) {
//            for (int j = 0; j < W; j++) {
//                if (grid[i][j] >= 0)
//                    std::cout << ' ' << grid[i][j] << ' ';
//                else
//                    std::cout << grid[i][j] << ' ';
//            }
//            std::cout << std::endl;
//        }

        for (int i = 0; i < len + 1; i++) {
            Point point(px[i], py[i]);
            m_route.push_back(point);
        }
        m_counter = 0;

//        for (int i = 0; i < m_route.size(); i++)
//            std::cout << m_route[i] << std::endl;
    }

    // Update data for LightEnemy.
    void LightEnemy::update(sf::RenderWindow &window) {


        int x = m_route[m_counter].x, y = m_route[m_counter].y;
        float distance = std::sqrt((x - m_point.x) * (x - m_point.x) + (y - m_point.y) * (y - m_point.y));

        if (distance > 0.1) {
            m_point.x += 0.01 * (x - m_point.x) / distance;
            m_point.y += 0.01 * (y - m_point.y) / distance;
        } else
            m_counter++;

//        m_image.loadFromFile("../image/Texture1.png");
//        m_texture.loadFromImage(m_image);
//        m_sprite.setTexture(m_texture);
//        m_sprite.setTextureRect(sf::IntRect(128, 0, 32, 32));

        m_sprite.setPosition(32 * m_point.x, 32 * m_point.y);
        window.draw(m_sprite);
    }

} /* namespace TowerDefence */