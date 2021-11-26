/* Created by bbara on 25.11.2021. */

#ifndef TOWER_DEFENCE_TOWER_DATA_H
#define TOWER_DEFENCE_TOWER_DATA_H

namespace TowerDefence {

    // Struct TowerData
    struct TowerData {
        int radius;
        int damage;
        int rate;
        int cost;

        TowerData();

        TowerData(int radius, int damage, int rate, int cost);

        friend std::istream &operator>>(std::istream &in, TowerData &data);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_TOWER_DATA_H */
