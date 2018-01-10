//
// Created by okleinfeld on 1/10/18.
//

#ifndef AP_JIGSAWGAME_BOUNDEDINTCONDITION_H
#define AP_JIGSAWGAME_BOUNDEDINTCONDITION_H

#include <limits>
#include "BoundedInt.h"

template <int MinInt, int MaxInt>
class BoundedIntCondition : public BoundedInt<MinInt, MaxInt>{
public:
    BoundedIntCondition(int value);
    BoundedIntCondition() = default;
};

template <int MinInt, int MaxInt>
BoundedIntCondition<MinInt, MaxInt>::BoundedIntCondition(int value) {
    if ((value < MinInt || value > MaxInt) && value != std::numeric_limits<int>::min()){
        throw std::range_error("Each edge value must by in range[-K,K]");
    }
    this->value = value;
}

#endif //AP_JIGSAWGAME_BOUNDEDINTCONDITION_H
