/* Created by bar1k4real on 25.11.2021. */

#ifndef TOWER_DEFENCE_CASTLE_DATA_H
#define TOWER_DEFENCE_CASTLE_DATA_H

namespace TowerDefence {

    /**
     * \brief  Конфигурационные данные замка.
     * \date 25.11.2021
     * \author bar1k
     * \param profit Прибыль замка.
     * \param maxHealth Максимальное количество здоровья замка.
     * \param recovery Регенерация замка.
     * \param cost Стоимость улучшения замка.
     */

    // Struct CastleData
    struct CastleData {
        float profit;
        float maxHealth;
        float recovery;
        float cost;

        CastleData();

        CastleData(float profit, float maxHealth, float recovery, float cost);

        CastleData(const CastleData &castleData);

        friend std::istream &operator>>(std::istream &in, CastleData &castleData);

        friend std::ostream &operator<<(std::ostream &out, const CastleData &castleData);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_CASTLE_DATA_H */
