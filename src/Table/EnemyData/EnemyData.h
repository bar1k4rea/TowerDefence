/* Created by bbara on 25.11.2021. */

#ifndef TOWER_DEFENCE_ENEMY_DATA_H
#define TOWER_DEFENCE_ENEMY_DATA_H

namespace TowerDefence {

    // Struct EnemyData
    struct EnemyData {
        int health;
        int recovery;
        int damage;
        int speed;
        int hit;
        int chance;
        int radius;
        int ammunition;

        EnemyData();

        EnemyData(int health, int recovery, int damage, int speed, int hit, int chance, int radius, int ammunition);

        friend std::istream &operator>>(std::istream &in, EnemyData &data);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_ENEMY_DATA_H */
