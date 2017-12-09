//
//  PuzzleType.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include "PuzzleType.h"


bool PuzzleType::operator==(const PuzzleType& otherType) const {
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
    
    if(l!=otherLeft)
        return l<otherLeft;
    
    if(t!=otherTop)
        return t<otherTop;
    
    if(r!=otherRight)
        return r<otherRight;
  
    return b<otherBot;
}


void PuzzleType::rotate(){
    int temp = t;
    t = l;
    l = b;
    b = r;
    r = temp;
    
    if(rotateAngle == 270)
        rotateAngle = 0;
    else
        rotateAngle+= 90;
}
void PuzzleType::resetRotation(){
    while(rotateAngle != 0)
        rotate();
}
