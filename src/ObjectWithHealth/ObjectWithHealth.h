/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_OBJECT_WITH_HEALTH_H
#define TOWER_DEFENCE_OBJECT_WITH_HEALTH_H

#include "../ObjectWithLocation/ObjectWithLocation.h"

namespace TowerDefence {

    /**
     * \brief Объект со здоровьем.
     * \date 15.11.2021
     * \author bar1k
     * \param m_health Текущее количество здоровья объекта.
     * \param m_maxHealth Максимальное количество здоровья объекта.
     */

    // Class ObjectWithHealth
    class ObjectWithHealth : public ObjectWithLocation {
    protected:
        float m_health;
        float m_maxHealth;
    public:
        ObjectWithHealth();

        ObjectWithHealth(const Point &point, int health, int maxHealth);

        void increaseHealth(float amount);

        void decreaseHealth(float amount);

        [[nodiscard]] bool isAlive() const;

        [[nodiscard]] int getHealth() const;

        [[nodiscard]] int getMaxHealth() const;

        void setHealth(int health);

        void setMaxHealth(int maxHealth);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_OBJECT_WITH_HEALTH_H */

