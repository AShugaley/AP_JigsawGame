//
//  PuzzleRequirement.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include <stdio.h>
#include "PuzzleRequirement.h"


void PuzzleRequirement::addFalseType(PuzzleType type){
    falseTypes.push_back(type);
}


bool PuzzleRequirement::setisfReq(PuzzleType type){
    for(auto wrongType : falseTypes){
        if(wrongType==type)
            return false;
    }
    bool leftOK = l == JOKER || l == type.getLeft();
    bool topOK = t == JOKER || t == type.getTop();
    bool rightOK = r == JOKER || r == type.getRight();
    bool botOK = b == JOKER || b == type.getBot();
    return leftOK && topOK && rightOK && botOK;
}
