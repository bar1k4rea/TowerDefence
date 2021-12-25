/* Created by bar1k4real on 15.11.2021. */

#include <iostream>
#include <cmath>
#include "ObjectWithLocation.h"

namespace TowerDefence {

    // Empty constructor for ObjectWithLocation.
    ObjectWithLocation::ObjectWithLocation() : m_point() {}

    // First constructor for ObjectWithLocation.
    ObjectWithLocation::ObjectWithLocation(const Point &point) : m_point(point) {}

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