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
    bool topOK = l == JOKER || l == type.getTop();
    bool rightOK = l == JOKER || l == type.getRight();
    bool botOK = l == JOKER || l == type.getBot();
    return leftOK && topOK && rightOK && botOK;
}
