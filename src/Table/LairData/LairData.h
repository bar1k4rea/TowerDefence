/* Created by bar1k on 21.12.2021. */

#ifndef TOWER_DEFENCE_LAIR_DATA_H
#define TOWER_DEFENCE_LAIR_DATA_H

namespace TowerDefence {

    /**
     * \brief  Конфигурационные данные врага.
     * \date 21.12.2021
     * \author bar1k
     * \param time Время выхода врага.
     * \param type Тип врага.
     */

    // Struct LairData
    struct LairData {
        float time;
        int type;

        LairData();

        LairData(float time, int type);

        LairData(const LairData &lairData);

        friend std::istream &operator>>(std::istream &in, LairData &lairData);

        friend std::ostream &operator<<(std::ostream &out, const LairData &lairData);
    };

} /* namespace TowerDefence */

#endif //TOWER_DEFENCE_LAIR_DATA_H
