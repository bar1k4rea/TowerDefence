/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_ROUTE_H
#define TOWER_DEFENCE_ROUTE_H

#include <vector>
#include "../ObjectWithLocation/ObjectWithLocation.h"
#include "../Landscape/Landscape.h"

namespace TowerDefence {

    // Class Route.
    class Route {
    private:
        std::vector<Point> path;
        int counter;
    public:
        void createRoute(Landscape &landscape);
    };

} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_ROUTE_H */
