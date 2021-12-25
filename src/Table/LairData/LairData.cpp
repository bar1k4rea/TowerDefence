/* Created by bar1k on 21.12.2021. */

#include <iostream>
#include "LairData.h"

namespace TowerDefence {

    // Empty constructor for LairData.
    LairData::LairData() : time(0), type(0) {}

    // First constructor for LairData.
    LairData::LairData(float time, int type) : time(time), type(type) {}

    // Copy constructor for LairData.
    LairData::LairData(const LairData &lairData) : time(lairData.time), type (lairData.type) {}

    // Input for LairData.
    std::istream &operator>>(std::istream &in, LairData &lairData) {
        in >> lairData.time >> lairData.type;
        return in;
    }

    // Output for LairData.
    std::ostream &operator<<(std::ostream &out, const LairData &lairData) {
        out << lairData.time << ' ' << lairData.type;
        return out;
    }

} /* namespace TowerDefence */

