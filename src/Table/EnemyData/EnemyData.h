/* Created by bar1k4real on 25.11.2021. */

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

        EnemyData(const EnemyData &enemyData);

        friend std::istream &operator>>(std::istream &in, EnemyData &enemyData);

        friend std::ostream &operator<<(std::ostream &out, const EnemyData &enemyData);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_ENEMY_DATA_H */
