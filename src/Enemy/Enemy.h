/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_ENEMY_H
#define TOWER_DEFENCE_ENEMY_H

#include "../ObjectWithHealth/ObjectWithHealth.h"

namespace TowerDefence {

    // class Enemy
    class Enemy : public ObjectWithHealth {
    protected:
        int m_speed;
        int m_recovery;
        int m_damage;
    public:
        int getSpeed() const;

        void setSpeed(int speed);

        int getRecovery() const;

        void setRecovery(int recovery);

        int getDamage() const;

        void setDamage(int damage);

        int attackCastle(int health);

        void update();
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_ENEMY_H */
