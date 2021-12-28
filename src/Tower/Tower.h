/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_TOWER_H
#define TOWER_DEFENCE_TOWER_H

#include <iostream>
#include <memory>
#include "SFML/Graphics.hpp"
#include "../ObjectWithLocation/ObjectWithLocation.h"
#include "../Table/Table.h"
#include "../Table/TowerData/TowerData.h"
#include "../Castle/Castle.h"
#include "../Enemy/Enemy.h"
#include "../Enemy/LightEnemy/LightEnemy.h"

namespace TowerDefence {

    /**
     * \brief Замок.
     * \date 15.11.2021
     * \author bar1k
     * \param m_level Текущий уровень башни.
     * \param m_table Таблица уровней бащни с характеристиками.
     */

    // Class Tower
    class Tower : public ObjectWithLocation {
    protected:
        int m_level;
        Table<int, TowerData> m_table;
        sf::Image m_image;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
    public:
        Tower();

        Tower(const Point &point, int level, const Table<int, TowerData>& table);

        void upgrade(std::shared_ptr<Castle> castle);

        void attackEnemy(std::shared_ptr<Enemy> enemy);

        int getMLevel() const;

        void setMLevel(int mLevel);

        const Table<int, TowerData> &getMTable() const;

        void setMTable(const Table<int, TowerData> &mTable);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_TOWER_H */
