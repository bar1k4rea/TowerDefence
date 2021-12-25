/* Created by bar1k4real on 25.11.2021. */

#ifndef TOWER_DEFENCE_ENEMY_DATA_H
#define TOWER_DEFENCE_ENEMY_DATA_H

namespace TowerDefence {

    /**
     * \brief  Конфигурационные данные врага.
     * \date 25.11.2021
     * \author bar1k
     * \param maxHhealth Максимальное количество здоровья врага.
     * \param recovery Скорость регенерации количества здоровья у врага.
     * \param damage Урон замку от врага.
     * \param speed Скорость врага.
     * \param hit Урон стенам от врага.
     * \param chance Шанс уклонения врага от урона башни.
     * \param radius Радиус атаки врвга.
     * \param ammunition Боезапас врага.
     */

    // Struct EnemyData
    struct EnemyData {
        float maxHealth;
        float recovery;
        float damage;
        float speed;
        float hit;
        float chance;
        float radius;
        float ammunition;

        EnemyData();

        EnemyData(float maxHealth, float recovery, float damage, float speed, float hit, float chance, float radius,
                  float ammunition);

        EnemyData(const EnemyData &enemyData);

        friend std::istream &operator>>(std::istream &in, EnemyData &enemyData);

        friend std::ostream &operator<<(std::ostream &out, const EnemyData &enemyData);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_ENEMY_DATA_H */
