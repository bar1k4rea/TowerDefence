/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_LANDSCAPE_H
#define TOWER_DEFENCE_LANDSCAPE_H

#include <SFML/Graphics.hpp>

namespace TowerDefence {

    // Class Landscape.
    class Landscape {
    public:
        static const int HEIGHT = 25;
        static const int WIDTH = 40;
        std::string m_map[HEIGHT];
        sf::Image m_image;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
    public:
        Landscape();

        void loadMap1(const std::string (&map)[25]);

        void createMap();

        void loadMap();

        Landscape(const std::string (&map)[HEIGHT]);

        void drawMap(sf::RenderWindow &window);

        static const int getHeight();

        static const int getWidth();
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_LANDSCAPE_H */

//#include <set>
//#include <memory>
//#include "../Enemy/Enemy.h"
//#include "../Cell/Cell.h"
//#include "../Tower/Tower.h"
//#include "../Enemy/LightEnemy/LightEnemy.h"
//#include "../Enemy/HeavyEnemy/HeavyEnemy.h"
//#include "../Enemy/AirEnemy/AirEnemy.h"

//        std::set<std::shared_ptr<Enemy>> m_enemies;
//        std::set<std::shared_ptr<Cell>> m_cells;
//        std::set<std::shared_ptr<class Tower>> m_towers;
//        std::shared_ptr<Castle> m_castle;