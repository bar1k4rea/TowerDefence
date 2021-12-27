/* Created by bar1k on 19.12.2021. */



#include "Menu.h"

namespace TowerDefence {

    // Main function
    void menu() {
        GameManager gameManager;

        std::cout << "Welcome to the game TowerDefence!" << std::endl;
        gameManager.loadingLoader();
        gameManager.loadingLandscape();
        gameManager.createRoutes();

        try {
            play(gameManager);
        }
        catch (std::exception &unknownException) {
            std::cout << unknownException.what() << std::endl;
        }
    }

    // Play game.
    void play(GameManager &gameManager) {
        float time;
        sf::Clock clockForSpawnEnemy;
        sf::Clock clockForGame;
        sf::RenderWindow window(sf::VideoMode(1280, 800), "Tower Defence");

        while(window.isOpen()) {
            time = clockForSpawnEnemy.getElapsedTime().asSeconds();
            sf::Event event{};

            try {
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();
                    if (event.type == sf::Event::MouseButtonPressed) {
                        if (event.mouseButton.button == sf::Mouse::Left)
                            gameManager.createOrUpgradeTower(event.mouseButton.x, event.mouseButton.y);
                        else if (event.mouseButton.button == sf::Mouse::Right)
                            gameManager.createOrRenovateWall(event.mouseButton.x, event.mouseButton.y);
                    }
                }
            }
            catch (std::exception &smthException) {
                std::cout << smthException.what() << std::endl;
            }

            window.clear();
            gameManager.drawMap(window);
            gameManager.createEnemy(time);
            gameManager.update(window, clockForGame);
            window.display();
        }
    }

} /* namespace TowerDefence */