/* Created by bar1k4real on 03.12.2021. */

#include "Cell.h"

namespace TowerDefence {

    std::istream& operator>>(std::istream &in, CellType &cellType) {
        int type;
        in >> type;
        cellType = static_cast<CellType>(type);
        return in;
    }

    Cell::Cell() : ObjectWithLocation(), m_busy(false), m_type(Plain) {}

    Cell::Cell(const Point &point, bool busy, CellType type) : ObjectWithLocation(point), m_busy(busy), m_type(type) {}

    bool Cell::isBusy() const {
        return m_busy;
    }

    void Cell::setBusy(bool busy) {
        m_busy = busy;
    }

    std::istream &operator>>(std::istream &in, Cell &cell) {
        in >> cell.m_point >> cell.m_type;
        return in;
    }

} /* namespace TowerDefence */