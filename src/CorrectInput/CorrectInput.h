/* Created by bar1k on 26.12.2021. */

#ifndef TOWER_DEFENCE_CORRECT_INPUT_H
#define TOWER_DEFENCE_CORRECT_INPUT_H

#include <iostream>
#include <limits>

namespace TowerDefence {

    // Getter for number.
    template<class T>
    int getNumber(T &a) {
        while (true) {
            std::cin >> a;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid data! Try again please: ->";
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return 1;
            }
        }
    }

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_CORRECT_INPUT_H */
