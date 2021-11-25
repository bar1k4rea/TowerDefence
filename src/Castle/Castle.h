/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_CASTLE_H
#define TOWER_DEFENCE_CASTLE_H

#include "../ObjectWithHealth/ObjectWithHealth.h"
#include "../Table/Table.h"

namespace TowerDefence {

    // Class Castle
    class Castle : public ObjectWithHealth {
    protected:
        int m_level;
        int m_gold;
        int m_counter;
        CastleTable *m_table;
    public:
        Castle();

        Castle(const Point &point, int health, int counter, CastleTable *table);

        Castle(const Point &point, int health, int maxHealth, int level, int gold, int counter, CastleTable *table);

        [[nodiscard]] int getGold() const;

        void setGold(int gold);

        void upgrade();

        void update();

        int getMLevel() const;

        void setMLevel(int mLevel);

        int getMCounter() const;

        void setMCounter(int mCounter);

        CastleTable *getMTable() const;

        void setMTable(CastleTable *mTable);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_CASTLE_H */
