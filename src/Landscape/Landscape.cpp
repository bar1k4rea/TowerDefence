/* Created by bar1k on 19.12.2021. */

#include <iostream>
#include "Landscape.h"

namespace TowerDefence {

    Landscape::Landscape() : m_map(), m_image(), m_texture(), m_sprite() {}

    void Landscape::createMap() {
        std::cout << "Change the array of strings in the method loadMap in class Landscape." << std::endl;
    }

    void Landscape::loadMap() {
        std::string map[25] = {
                "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
                "WC                                     W",
                "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW W",
                "W                                      W",
                "W WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
                "W                                      W",
                "W MMMWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW W",
                "W                                      W",
                "W WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
                "W                                      W",
                "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW W",
                "W                                      W",
                "W WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
                "W                                      W",
                "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW W",
                "W                                      W",
                "W WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
                "W                                      W",
                "W WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW W",
                "W                                      W",
                "W WWWWWWWWWWWWWWWWWWWWWWWWWWWWWMMMWWWWWW",
                "W                                      W",
                "W WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW W",
                "WL                                     W",
                "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
        };
        m_image.loadFromFile("../image/Texture.png");
        m_texture.loadFromImage(m_image);
        m_sprite.setTexture(m_texture);
        for (int i = 0; i < HEIGHT; i++)
            m_map[i] = map[i];
    }

    void Landscape::drawMap(sf::RenderWindow &window) {
        for (int i = 0; i < HEIGHT; i++)
            for (int j = 0; j < WIDTH; j++) {
                if (m_map[i][j] == 'W')
                    m_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
                if (m_map[i][j] == ' ')
                    m_sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
                if (m_map[i][j] == 'M')
                    m_sprite.setTextureRect(sf::IntRect(64, 0, 32, 32));
                if (m_map[i][j] == 'L')
                    m_sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
                if (m_map[i][j] == 'C')
                    m_sprite.setTextureRect(sf::IntRect(192, 0, 32, 32));
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
