#include <iostream>
#include <fstream>
#include "Table.h"
#include "CastleData.h"
#include "TowerData.h"
#include "EnemyData.h"


int main() {
//    std::ofstream castleFile("CastleData.txt");
//
//    castleFile << "1 34 45 56 67" << std::endl;
//    castleFile << "2 45 56 32 132";

    std::ifstream castleFile("CastleData.txt");
    TowerDefence::Pair<int, TowerDefence::CastleData> pair;

    if (castleFile.is_open())
        std::cout << "File is open!" << std::endl;

    while (castleFile >> pair) {

        std::cout << pair << std::endl;

    }

    castleFile.close();

    return 0;
}
