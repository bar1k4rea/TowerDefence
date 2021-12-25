/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_OBJECT_WITH_LOCATION_H
#define TOWER_DEFENCE_OBJECT_WITH_LOCATION_H

#include "../Point/Point.h"

namespace TowerDefence {

    /**
     * \brief Объект с местонахождением.
     * \date 15.11.2021
     * \author bar1k
     * \param m_point Точка на плоскости.
     */

    // Class ObjectWithLocation
    class ObjectWithLocation {
    protected:
        Point m_point;
    public:
        ObjectWithLocation();

        explicit ObjectWithLocation(const Point &point);

        [[nodiscard]] double distance(const Point &point) const;

        [[nodiscard]] const Point &getPoint() const;

        void setPoint(const Point &point);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_OBJECT_WITH_LOCATION_H */
