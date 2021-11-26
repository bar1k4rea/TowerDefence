/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_CASTLE_H
#define TOWER_DEFENCE_CASTLE_H

#include "../ObjectWithHealth/ObjectWithHealth.h"
#include "../Table/Table.h"
#include "../Table/CastleData/CastleData.h"

namespace TowerDefence {

    // Class Castle
    class Castle : public ObjectWithHealth {
    protected:
        int m_level;
        int m_gold;
        Table<int, CastleData> m_table;
    public:
        Castle();

        Castle(const Point &point, int health, const Table<int, CastleData>& table);

        Castle(const Point &point, int health, int maxHealth, int level, int gold, const Table<int, CastleData>& table);

        [[nodiscard]] int getGold() const;

        void setGold(int gold);

        void upgrade();

        void update();
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_CASTLE_H */
