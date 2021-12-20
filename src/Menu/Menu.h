/* Created by bar1k on 19.12.2021. */

#ifndef TOWER_DEFENCE_MENU_H
#define TOWER_DEFENCE_MENU_H

#include <iostream>
#include <limits>
#include "../Loader/Loader.h"
#include "../Landscape/Landscape.h"

namespace TowerDefence {

    // Getter for number.
    template<class T>
    int getNumber(T &a) {
        while (true) {
            std::cin >> a;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERROR! Invalid data! Try again please: ->";
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return 1;
            }
        }
    }

    void menu();
    void loadingLoader(Loader &loader);
    void loadingLandscape(Landscape &Landscape);
    void game(Landscape &landscape);

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_MENU_H */
