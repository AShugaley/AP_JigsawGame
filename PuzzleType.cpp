//
// Created by okleinfeld on 12/15/17.
//

#include "PuzzleType.h"


PuzzleType::PuzzleType(int l, int t, int r, int b): l(l), t(t), r(r), b(b) {;}

int PuzzleType::getTop() const{
    return this->t;
};

int PuzzleType::getLeft() const{
    return this->l;
};

int PuzzleType::getRight() const{
    return this->r;
};

int PuzzleType::getBot() const{
    return this->b;
};

bool PuzzleType::operator==(const PuzzleType& otherType) const{
    return l == otherType.getLeft()&&
           t == otherType.getTop() &&
           r == otherType.getRight() &&
           b == otherType.getBot();
}

bool PuzzleType::operator<(const PuzzleType& otherType) const{
    int otherLeft = otherType.getLeft();
    int otherTop = otherType.getTop();
    int otherRight = otherType.getRight();
    int otherBot = otherType.getBot();

    if(l != otherLeft)
        return l < otherLeft;

    if(t != otherTop)
        return t < otherTop;

    if(r != otherRight)
        return r < otherRight;

    return b < otherBot;
}