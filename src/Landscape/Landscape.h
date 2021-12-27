/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_LANDSCAPE_H
#define TOWER_DEFENCE_LANDSCAPE_H

#include <SFML/Graphics.hpp>

namespace TowerDefence {

    /**
* @brief Ландшафт.
* @details Содержит размеры карты и иеё текстуры и спрайты гор, водоёмов и земли.
* @date 15.11.2021
* @author bar1k4real
*/


    // Class Landscape.
    class Landscape {
    private:
        static const int HEIGHT = 25;
        static const int WIDTH = 40;
        std::string m_map[HEIGHT];
        sf::Image m_image;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
    public:
        Landscape();

        void createMap();

        void loadMap();

        void drawMap(sf::RenderWindow &window);

        char getCell(int i, int j);

        void setCell(int i, int j, char symbol);

        static const int getHeight();

        static const int getWidth();
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_LANDSCAPE_H */