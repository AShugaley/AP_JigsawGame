//
// Created by okleinfeld on 12/13/17.
//

#include "PuzzleTypeWithRotation.h"

PuzzleTypeWithRotation::PuzzleTypeWithRotation(int l, int t, int r, int b): PuzzleType(l, t, r, b), rotationAngle(0){};
PuzzleTypeWithRotation::PuzzleTypeWithRotation(): PuzzleType(), rotationAngle(0){};

int PuzzleTypeWithRotation::getRotationAngle() const{
    return this->rotationAngle;
}

void PuzzleTypeWithRotation::rotate(){
    int temp = t;
    t = l;
    l = b;
    b = r;
    r = temp;
    if(this->rotationAngle == 270){
        this->rotationAngle = 0;
    } else{
        this->rotationAngle += 90;
    }
}

void PuzzleTypeWithRotation::resetRotation(){
    while(this->rotationAngle != 0)
        rotate();
}

bool PuzzleTypeWithRotation::operator==(const PuzzleTypeWithRotation& otherType) const{
    bool dimEquel = PuzzleType::operator==(otherType);
    return dimEquel && this->rotationAngle == otherType.rotationAngle;
}

bool PuzzleTypeWithRotation::operator<(const PuzzleTypeWithRotation& otherType) const{
    int otherLeft = otherType.getLeft();
    int otherTop = otherType.getTop();
    int otherRight = otherType.getRight();
    int otherBot = otherType.getBot();
    int otherRotationAngle = otherType.getRotationAngle();

    if (l !=otherLeft)
        return l <otherLeft;

    if (t !=otherTop)
        return t <otherTop;

    if (r !=otherRight)
        return r <otherRight;

    if (b != otherBot)
        return b < otherBot;

    return rotationAngle < otherRotationAngle;
}