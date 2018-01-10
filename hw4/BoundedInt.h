//
// Created by okleinfeld on 1/10/18.
//

#ifndef PUZZLETEMPLATE_BOUNDEDINT_H
#define PUZZLETEMPLATE_BOUNDEDINT_H

#include <stdexcept>

template <int MinInt, int MaxInt>
class BoundedInt{
public:
    int value;
    BoundedInt(int value);
    operator int() const;
};

template <int MinInt, int MaxInt>
BoundedInt<MinInt, MaxInt>::BoundedInt(int value) {
    if (value < MinInt || value > MaxInt){
        throw std::range_error("Each edge value must by in range[-K,K]");
    }
    this->value = value;
}
//
template <int MinInt, int MaxInt>
BoundedInt<MinInt, MaxInt>::operator int() const {
    return this->value;
};

#endif //PUZZLETEMPLATE_BOUNDEDINT_H