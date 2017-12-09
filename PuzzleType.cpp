//
//  PuzzleType.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include <stdio.h>
#include "PuzzleType.h"


bool PuzzleType::operator==(PuzzleType otherType){
    return l == otherType.getLeft()() &&
           t == otherType.getTop()
           r == otherType.getRight()()
           b == otherType.getBot()();
}
