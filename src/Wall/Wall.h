/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_WALL_H
#define TOWER_DEFENCE_WALL_H

#include <memory>
#include "../ObjectWithHealth/ObjectWithHealth.h"
#include "../Table/Table.h"
#include "../Castle/Castle.h"

namespace TowerDefence {

    // Class Wall
    class Wall : public ObjectWithHealth {
    protected:
        static const int m_cost = 40;
    public:
        Wall();

        Wall(const Point &point, int health, int maxHealth);

        void renovate(std::shared_ptr<Castle> castle);

        static const int getMCost();
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_WALL_H */
