/* Created by bar1k4real on 25.11.2021. */

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

        TowerData(const TowerData &towerData);

        friend std::istream &operator>>(std::istream &in, TowerData &towerData);

        friend std::ostream &operator<<(std::ostream &out, const TowerData &towerData);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_TOWER_DATA_H */
