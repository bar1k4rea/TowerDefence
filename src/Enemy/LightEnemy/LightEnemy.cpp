/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include <cmath>
#include "LightEnemy.h"

namespace TowerDefence {

    // Empty constructor for LightEnemy.
    LightEnemy::LightEnemy() : Enemy(), m_chance(0) {
        std::cout << "Empty Constructor for LightEnemy: " << this << std::endl;
    }

    // First constructor for LightEnemy.
    LightEnemy::LightEnemy(const Point &point, int health, int speed, int recovery, int damage, int chance) : Enemy(
            point, health, speed, recovery, damage), m_chance(chance) {
//        std::cout << "First Constructor for LightEnemy: " << this << std::endl;
        m_image.loadFromFile("../image/Texture.png");
        m_texture.loadFromImage(m_image);
        m_sprite.setTexture(m_texture);
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
        ax = m_point.y;
        ay = m_point.x;

//        std::cout << std::endl << "asdas" << std::endl;


        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (landscape.m_map[i][j] == '0')
                    grid[i][j] = -1;
                else if (landscape.m_map[i][j] == 'C') {
                    bx = i;
                    by = j;
                    grid[bx][by] = -2;
                    std::cout << bx << ' ' << by << std::endl;
                }
                else
                    grid[i][j] = -2;
            }
        }

            for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] >= 0)
                std::cout << ' ' << grid[i][j] << ' ';
            else
                std::cout << grid[i][j] << ' ';
        }
        std::cout << std::endl;
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

        std::cout << "---------------------------------------------------------" << std::endl;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (grid[i][j] >= 0)
                    std::cout << ' ' << grid[i][j] << ' ';
                else
                    std::cout << grid[i][j] << ' ';
            }
            std::cout << std::endl;
        }

//        for (int i = 0; i < len + 1; i++)
//            std::cout << px[i] << ' ' << py[i] << std::endl;

//        std::cout << m_route.size() << std::endl;

        for (int i = 0; i < len + 1; i++) {
            Point point(px[i], py[i]);
            m_route.push_back(point);
        }
        m_counter = 0;

//        std::cout << m_route.size() << std::endl;
//        std::cout << len << std::endl;
//
        for (int i = 0; i < m_route.size(); i++)
            std::cout << m_route[i] << std::endl;

        m_sprite.setTextureRect(sf::IntRect(128, 0, 32, 32));
        m_sprite.setPosition(32 * m_point.x, 32 * m_point.y);
    }

    // Update data for LightEnemy.
    void LightEnemy::update(sf::RenderWindow &window, float time) {
//        std::cout << m_counter << std::endl;
//        std::cout << m_route[m_counter].x << ' ' << m_route[m_counter].y << std::endl;

//        if (m_route[m_counter].x == (int) (m_sprite.getPosition().x / 32) &&
//            m_route[m_counter].y == (int) (m_sprite.getPosition().y / 32)) {
////            std::cout << "asdasd" << std::endl;
////            m_sprite.move(-0.01, 0);
//            if (m_point.x == m_route[m_counter].x + 1 && m_point.y == m_route[m_counter].y) {
//                m_sprite.move(0, -0.1);
//            }
//        } else {
//            m_counter++;
//
//        float x = m_point.x - m_sprite.getPosition().x / 32.0, y = m_point.y - m_sprite.getPosition().y / 32.0;
//
//        std::cout << x << " " << y << std::endl;
//        std::cout << m_counter << std::endl;
////        m_sprite.move(-0.01, 0);
//
//        if (x ==  0.0 && y == 0.0) {
//            if (m_point.x == m_route[m_counter].x + 1 && m_point.y == m_route[m_counter].y)
//                m_sprite.move(-0.01, 0);
//        }
//
//        if (x > 0.0 && x < 1.0 && y == 0.0) {
//            std::cout << "sad" << std::endl;
//            m_sprite.move(-0.01, 0);
//        }
//
//        if (x == 1 && y == 0) {
//            m_point = m_route[m_counter];
//            m_counter++;
//        }
        int x = m_route[m_counter].x, y = m_route[m_counter].y;
        float distance = std::sqrt((x - m_point.x) * (x - m_point.x) + (y - m_point.y) * (y - m_point.y));
        if (distance > 0.1) {
            m_point.x += 0.001 * (x - m_point.x) / distance;
            m_point.y += 0.001 * (y - m_point.y) / distance;
        } else {
            m_counter++;
        }

        std::cout << m_counter << std::endl;

        m_sprite.setPosition(32 * m_point.x,32 * m_point.y);

        window.draw(m_sprite);
    }

//        decreaseHealth(m_recov ery);
//       }

} /* namespace TowerDefence */