/* Created by bar1k on 24.12.2021. */

#include <iostream>
#include "Point.h"

namespace TowerDefence {

    // Empty constructor for Point.
    Point::Point() : x(0), y(0) {}

    // Second constructor for Point.
    Point::Point(int x, int y) : x(x), y(y) {}

    // Input for Point.
    std::istream &operator>>(std::istream &in, Point &point) {
        in >> point.x >> point.y;
        return in;
    }

    // Output for Point.
    std::ostream &operator<<(std::ostream &out, const Point &point) {
        out << point.x << ' ' << point.y;
        return out;
    }

    // Comparison operator for Point.
    bool operator==(const Point &left, const Point &right) {
        if ((left.x == right.x) && (left.y == right.y))
            return true;
        return false;
    }

} /* namespace TowerDefence */

