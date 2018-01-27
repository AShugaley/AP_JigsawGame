//
//  PuzzleRequirement.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include "PuzzleRequirement.h"


PuzzleRequirement::PuzzleRequirement(int l, int t, int r, int b) : l(l), t(t), r(r), b(b){
    this->falseTypes = vector<PuzzleType>();
}

void PuzzleRequirement::addFalseType(PuzzleType&& type){
    falseTypes.push_back(type);
}

bool PuzzleRequirement::typeSatisfiesReq(const PuzzleType& type) const{
    // if the type is one of the false type (types that were already checked and found not valid)
    // then it of course it doesn't satisfies the requirement
    for(auto pieceType : falseTypes){
        if(pieceType == type)
            return false;
    }
    // if it is not known yet as a type that doesn't satisfies te requirement -
    // check if it is in the right format.

    bool leftOK = l == JOKER || l == type.getLeft();
    bool topOK = t == JOKER || t == type.getTop();
    bool rightOK = r == JOKER || r == type.getRight();
    bool botOK = b == JOKER || b == type.getBot();

    bool satisfiesReq = leftOK && topOK && rightOK && botOK;
    return satisfiesReq;
}
