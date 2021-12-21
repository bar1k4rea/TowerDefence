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

        std::cout << "Welcome to the game TowerDefence!" << std::endl;
        loadingLoader(loader);
        loadingLandscape(landscape);

        game(landscape);
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
    void game(Landscape &landscape) {
        sf::RenderWindow window(sf::VideoMode(1280, 800), "TowerDefence");
        sf::Clock clock;
//        GameManager gameManager;
//        gameManager.createEnemy(landscape);



        Point point(23, 2);
        LightEnemy lightEnemy(point, 10, 10, 10, 10, 10);
        lightEnemy.createRoute(landscape);

        while(window.isOpen()) {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            landscape.drawMap(window);
            lightEnemy.update(window, time);
//            gameManager.update(time);
            window.display();
        }
    }

} /* namespace TowerDefence */