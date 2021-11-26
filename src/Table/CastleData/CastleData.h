/* Created by bbara on 25.11.2021. */

#ifndef TOWER_DEFENCE_CASTLE_DATA_H
#define TOWER_DEFENCE_CASTLE_DATA_H

namespace TowerDefence {

    // Struct CastleData
    struct CastleData {
        int profit;
        int maxHealth;
        int recovery;
        int cost;

        CastleData();

        CastleData(int profit, int maxHealth, int recovery, int cost);

        friend std::istream &operator>>(std::istream &in, CastleData &data);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_CASTLE_DATA_H */
