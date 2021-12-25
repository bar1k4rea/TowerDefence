/* Created by bar1k on 19.12.2021. */

#include "Menu.h"
#include "../GameManager/GameManager.h"
#include "../Enemy/LightEnemy/LightEnemy.h"

namespace TowerDefence {

    // Main function
    void menu() {
        Loader loader;
        Landscape landscape;
        GameManager gameManager;

        gameManager.m_counter = 0;

        std::cout << "Welcome to the game TowerDefence!" << std::endl;
        loadingLoader(loader);
        loadingLandscape(landscape);

        game(loader, landscape);
    }

    // Loading Loader.
    void loadingLoader(Loader &loader) {
        int option;
        std::cout << "Do you want to change the configuration files? (0 - No, 1 - Yes) -> ";
        getNumber(option);
        if (option) {
            std::cout << "Are you sure? (0 - No, 1 - Yes) -> ";
            getNumber(option);
            if (option)
                loader.createTable();
        }
        loader.loadTable();
    }

    // Loading Landscape.
    void loadingLandscape(Landscape &landscape) {
        int option;
        std::cout << "Do you want to change landscape design? (0 - No, 1 - Yes) -> ";
        getNumber(option);
        if (option) {
            std::cout << "Are you sure? (0 - No, 1 - Yes) -> ";
            getNumber(option);
            if (option)
                landscape.createMap();
        }
        landscape.loadMap();
    }

    // Play game.
    void game(Loader &loader, Landscape &landscape) {
        float time;
        sf::RenderWindow window(sf::VideoMode(1280, 800), "TowerDefence");
        sf::Clock clock;
        GameManager gameManager;

        gameManager.m_counter = 1;

        gameManager.createRoutes(landscape);

//        Point point(1, 23);
//        LightEnemy lightEnemy(point, 10, 10, 10, 10, 10);
//        lightEnemy.createRoute(landscape);

        while(window.isOpen()) {
            time = clock.getElapsedTime().asSeconds();
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            landscape.drawMap(window);

            gameManager.createEnemy(loader, landscape, time);

            gameManager.update(window);
//            gameManager.draw(window);

//            lightEnemy.update(window, time);
            window.display();
        }
    }

} /* namespace TowerDefence */