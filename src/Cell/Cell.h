/* Created by bar1k4real on 03.12.2021. */

#ifndef TOWER_DEFENCE_CELL_H
#define TOWER_DEFENCE_CELL_H

#include <iostream>
#include "../ObjectWithLocation/ObjectWithLocation.h"

namespace TowerDefence {

    // Enum CellType
    enum CellType {
        Water,
        Mountain,
        Plain,
        Tower,
        Wall
    };

    // Class Cell.
    class Cell:  public ObjectWithLocation {
    private:
        bool m_busy;
        CellType m_type;
    public:
        Cell();

        Cell(const Point &point, bool busy, CellType type);

        [[nodiscard]] bool isBusy() const;

        void setBusy(bool busy);

        friend std::istream &operator>>(std::istream &in, Cell &cell);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_CELL_H */
