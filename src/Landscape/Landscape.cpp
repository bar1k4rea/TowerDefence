/* Created by bar1k on 19.12.2021. */

#include <iostream>
#include "Landscape.h"

namespace TowerDefence {

    Landscape::Landscape() : m_map(), m_image(), m_texture(), m_sprite() {}

    Landscape::Landscape(const std::string (&map)[HEIGHT]) {
        m_image.loadFromFile("../image/Texture.png");
        m_texture.loadFromImage(m_image);
        m_sprite.setTexture(m_texture);
        for (int i = 0; i < HEIGHT; i++)
            m_map[i] = map[i];
    }

    void Landscape::createMap() {

    }

    void Landscape::loadMap() {
        std::string map[25] = {
                "0000000000000000000000000000000000000000",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0               C                      0",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0                                      0",
                "0000000000000000000000000000000000000000",
        };
        loadMap1(map);
    }

    void Landscape::loadMap1(const std::string (&map)[25]) {
        m_image.loadFromFile("../image/Texture.png");
        m_texture.loadFromImage(m_image);
        m_sprite.setTexture(m_texture);
        for (int i = 0; i < HEIGHT; i++)
            m_map[i] = map[i];
    }


    void Landscape::drawMap(sf::RenderWindow &window) {
        for (int i = 0; i < HEIGHT; i++)
            for (int j = 0; j < WIDTH; j++) {
                if (m_map[i][j] == ' ')
                    m_sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
                if (m_map[i][j] == '0')
                    m_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
                if (m_map[i][j] == 'C') {
                    m_sprite.setTextureRect(sf::IntRect(192, 0, 32, 32));
//                    std::cout << i << ' ' << j << std::endl;
                }
                if (m_map[i][j] == 'E')
                    m_sprite.setTextureRect(sf::IntRect(128, 0, 32, 32));
                m_sprite.setPosition(32 * j, 32 * i);
                window.draw(m_sprite);
            }
    }

    const int Landscape::getHeight() {
        return HEIGHT;
    }

    const int Landscape::getWidth() {
        return WIDTH;
    }

} /* namespace TowerDefence */
