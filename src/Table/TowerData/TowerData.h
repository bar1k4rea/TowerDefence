/* Created by bar1k4real on 25.11.2021. */

#ifndef TOWER_DEFENCE_TOWER_DATA_H
#define TOWER_DEFENCE_TOWER_DATA_H

namespace TowerDefence {

    /**
     * \brief  Конфигурационные данные врага.
     * \date 25.11.2021
     * \author bar1k
     * \param radius Радиус атаки башни.
     * \param damage Урон врагам от башни.
     * \param rapidity Скорострельность башни.
     * \param cost Скорость улучшения башни.
     */

    // Struct TowerData
    struct TowerData {
        float radius;
        float damage;
        float rapidity;
        float cost;

        TowerData();

        TowerData(float radius, float damage, float rapidity, float cost);

        TowerData(const TowerData &towerData);

        friend std::istream &operator>>(std::istream &in, TowerData &towerData);

        friend std::ostream &operator<<(std::ostream &out, const TowerData &towerData);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_TOWER_DATA_H */
