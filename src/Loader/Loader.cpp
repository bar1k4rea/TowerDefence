/* Created by bar1k4real on 01.12.2021. */

#include <iostream>
#include <fstream>
#include "Loader.h"

namespace TowerDefence {

    // Empty constructor for Loader.
    Loader::Loader() : m_towerTable(), m_castleTable(), m_enemyTable() {
        std::cout << "Empty Constructor for Loader: " << this << std::endl;
    }

    // Load Table.
    void Loader::loadTable() {
        std::ifstream castleFile("../config/CastleData.txt"), enemyFile("../config/EnemyData.txt"), towerFile(
                "../config/TowerData.txt");
        Pair<int, CastleData> castlePair;
        Pair<int, TowerData> towerPair;
        Pair<int, EnemyData> enemyPair;

        while (castleFile >> castlePair)
            m_castleTable.push(castlePair);
        castleFile.close();

        while (towerFile >> towerPair)
            m_towerTable.push(towerPair);
        towerFile.close();

        while (enemyFile >> enemyPair)
            m_enemyTable.push(enemyPair);
        enemyFile.close();
    }

    // Create Table.
    void Loader::createTable() {
        std::ofstream castleFile("../config/CastleData.txt"), enemyFile("../config/EnemyData.txt"), towerFile(
                "../config/TowerData.txt");
        CastleData castleData;
        TowerData towerData;
        EnemyData enemyData;
        int counter;
        std::string enemyType[N_ENEMY] = {"AIR ENEMY", "HEAVY ENEMY", "LIGHT ENEMY", "AIR HERO", "HEAVY HERO",
                                          "LIGHT HERO"};

        getNumber(counter, "Enter the number of levels for the castle ->");
        for (int i = 0; i < counter; i++) {
            castleFile << i + 1 << ' ';
            std::cout << "Level #" << i + 1 << '.' << std::endl;
            getNumber(castleData, "Enter the data of the castle ->");
            castleFile << castleData << std::endl;
        }
        castleFile.close();

        getNumber(counter, "Enter the number of levels for the tower ->");
        for (int i = 0; i < counter; i++) {
            towerFile << i + 1 << ' ';
            std::cout << "Level #" << i + 1 << '.' << std::endl;
            getNumber(towerData, "Enter the data of the tower ->");
            towerFile << towerData << std::endl;
        }
        towerFile.close();

        for (int i = 0; i < N_ENEMY; i++) {
            enemyFile << i << ' ';
            std::cout << "Type of enemy: " << enemyType[i] << '.' << std::endl;
            getNumber(enemyData, "Enter the data of the enemy ->");
            enemyFile << enemyData << std::endl;
        }
        enemyFile.close();
    }

    // Show Table.
    void Loader::showTable() {
        std::cout << "Castle Table:" << std::endl;
        for (TableIterator<int, CastleData> it = m_castleTable.begin(); it != m_castleTable.end(); ++it)
            std::cout << "Key: -> " << (*it).key << " - " << "Data: -> " << (*it).data << std::endl;

        std::cout << "Tower Table:" << std::endl;

        for (TableIterator<int, TowerData> it = m_towerTable.begin(); it != m_towerTable.end(); ++it)
            std::cout << "Key: -> " << (*it).key << " - " << "Data: -> " << (*it).data << std::endl;

        std::cout << "Enemy Table:" << std::endl;
        for (TableIterator<int, EnemyData> it = m_enemyTable.begin(); it != m_enemyTable.end(); ++it)
            std::cout << "Key: -> " << (*it).key << " - " << "Data: -> " << (*it).data << std::endl;

    }

} /* namespace TowerDefence */
