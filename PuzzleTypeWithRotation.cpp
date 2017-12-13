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
