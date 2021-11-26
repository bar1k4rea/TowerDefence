/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include <cmath>
#include "ObjectWithLocation.h"

namespace TowerDefence {

    // Empty constructor for Point.
    Point::Point() : x(0), y(0) {
        std::cout << "Empty Constructor for Point: " << this << std::endl;
    }

    // First constructor for Point.
    Point::Point(int x) : x(x), y(0) {
        std::cout << "First Constructor for Point: " << this << std::endl;
    }

    // Second constructor for Point.
    Point::Point(int x, int y) : x(x), y(y) {
        std::cout << "Second Constructor for Point: " << this << std::endl;
    }

    // Comparison operator for Point.
    bool operator==(const Point &left, const Point &right) {
        if ((left.x == right.x) && (left.y == right.y))
            return true;
        return false;
    }

    // Empty constructor for ObjectWithLocation.
    ObjectWithLocation::ObjectWithLocation() : m_point() {
        std::cout << "Empty Constructor for ObjectWithLocation: " << this << std::endl;
    }

    // First constructor for ObjectWithLocation.
    ObjectWithLocation::ObjectWithLocation(const Point &point) : m_point(point) {
        std::cout << "First Constructor for ObjectWithLocation: " << this << std::endl;
    }

    // Calculate distance.
    double ObjectWithLocation::distance(const Point &point) const {
        return std::sqrt(std::pow(m_point.x - point.x, 2) + std::pow(m_point.y - point.y, 2));
    }

    // Getter for m_point.
    const Point &ObjectWithLocation::getPoint() const {
        return m_point;
    }

    // Setter for m_point.
    void ObjectWithLocation::setPoint(const Point &point) {
        m_point = point;
    }

} /* namespace TowerDefence */