#include <iostream>
#include <fstream>
#include "Table.h"
#include "CastleData.h"
#include "TowerData.h"
#include "EnemyData.h"
#include "src/Loader/Loader.h"


int main() {
    TowerDefence::Pair<int, TowerDefence::CastleData> pair;
    std::cout << pair << std::endl;

    TowerDefence::Pair<int, TowerDefence::CastleData> pair1;
    std::cout << pair << std::endl;

    TowerDefence::Pair<int, TowerDefence::CastleData> pair2;
    std::cout << pair << std::endl;

    TowerDefence::Pair<int, TowerDefence::CastleData> pair3;
    std::cout << pair << std::endl;

    return 0;
}
