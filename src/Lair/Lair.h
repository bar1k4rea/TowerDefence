/* Created by bar1k4real on 15.11.2021. */

#ifndef TOWER_DEFENCE_LAIR_H
#define TOWER_DEFENCE_LAIR_H

#include "../ObjectWithLocation/ObjectWithLocation.h"
#include "../Table/Table.h"

namespace TowerDefence {

    // Class Lair.
    class Lair : public ObjectWithLocation {
    protected:
        int m_counter;
        LairTable m_table;
    public:

    };


} /* namespace TowerDefence */

#endif /* TOWER_DEFENCE_LAIR_H */
