/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_OBJECT_WITH_HEALTH_H
#define TOWER_DEFENCE_OBJECT_WITH_HEALTH_H

#include "../ObjectWithLocation/ObjectWithLocation.h"

namespace TowerDefence {

    // Class ObjectWithHealth
    class ObjectWithHealth : public ObjectWithLocation {
    protected:
        int m_health;
        int m_maxHealth;
    public:
        ObjectWithHealth();

        ObjectWithHealth(const Point &point, int health);

        ObjectWithHealth(const Point &point, int health, int maxHealth);

        void increaseHealth(int amount);

        void decreaseHealth(int amount);

        [[nodiscard]] bool isAlive() const;

        [[nodiscard]] int getHealth() const;

        [[nodiscard]] int getMaxHealth() const;

        void setHealth(int health);

        void setMaxHealth(int maxHealth);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_OBJECT_WITH_HEALTH_H */

