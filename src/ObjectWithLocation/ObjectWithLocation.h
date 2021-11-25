/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_OBJECT_WITH_LOCATION_H
#define TOWER_DEFENCE_OBJECT_WITH_LOCATION_H

namespace TowerDefence {

    // Struct Point
    struct Point {
        int x;
        int y;

        Point();

        explicit Point(int x);

        Point(int x, int y);
    };

    // Class ObjectWithLocation
    class ObjectWithLocation {
    protected:
        Point m_point;
    public:
        ObjectWithLocation();

        explicit ObjectWithLocation(const Point &point);

        [[nodiscard]] const Point &getPoint() const;

        void setPoint(const Point &point);

        [[nodiscard]] double distance(const Point &point) const;
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_OBJECT_WITH_LOCATION_H */
