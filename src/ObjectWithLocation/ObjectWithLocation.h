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

        friend bool operator== (const Point &left, const Point &right);
    };

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
