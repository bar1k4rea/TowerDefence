/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_CASTLE_H
#define TOWER_DEFENCE_CASTLE_H

#include "../ObjectWithHealth/ObjectWithHealth.h"
#include "../Table/Table.h"
#include "../Table/CastleData/CastleData.h"

namespace TowerDefence {

    /**
     * \brief Замок.
     * \date 15.11.2021
     * \author bar1k
     * \param m_level Текущий уровень замка.
     * \param m_gold Текущее количество золота в замке.
     * \param m_table Таблица уровней замка с характеристиками.
     */

    // Class Castle
    class Castle : public ObjectWithHealth {
    protected:
        int m_level;
        float m_gold;
        Table<int, CastleData> m_table;
    public:
        Castle();

        Castle(const Point &point, float health, float maxHealth, float gold, const Table<int, CastleData>& table);

        void upgrade();

        void update();

        int getLevel() const;

        void setLevel(int level);

        float getGold() const;

        void setGold(float gold);

        const Table<int, CastleData> &getTable() const;

        void setTable(const Table<int, CastleData> &table);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_CASTLE_H */
