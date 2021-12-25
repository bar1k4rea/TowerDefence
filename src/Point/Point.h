/* Created by bar1k on 15.11.2021. */

#ifndef TOWER_DEFENCE_POINT_H
#define TOWER_DEFENCE_POINT_H

namespace TowerDefence {

    /**
     * \brief Точка на плоскости.
     * \date 15.11.2021
     * \author bar1k
     * \param x Координата оси абсцисс.
     * \param y Координата оси ординат.
     */

    // Struct Point
    struct Point {
        float x;
        float y;

        Point();

        Point(int x, int y);

        friend std::istream &operator>>(std::istream &in, Point &point);

        friend std::ostream &operator<<(std::ostream &out, const Point &point);

        friend bool operator==(const Point &left, const Point &right);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_POINT_H */
