//
//  PuzzleRequirement.h
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef PuzzleRequirement_h
#define PuzzleRequirement_h

#include <iostream>
#include <vector>
#include "PuzzleType.h"

#define JOKER 100

using namespace std;

class PuzzleRequirement{
/**
 * Class for representing specific requirement for the next piece to schedule
 * at some point during the solving algorithm.
 *
 * The requirement can by a concrete type (for example 1,1,1,1)
 * or contain JOKER values - meaning any piece edge can fit (for example 1,0,*,*)
 *
 */
protected:
    
    //left,top,right,bot
    int l, t, r, b;
    
    
    vector<PuzzleType> falseTypes; //types that do not match, for instance, the requirement is 1,*,*,*, and we already tried (and failed) 1,1,0,0, so we add this type here
    
public:
    PuzzleRequirement(int l, int t, int r, int b);
    //getters and setters
    void addFalseType(PuzzleType&& type);
    vector<PuzzleType>& getFalseTypesVector();
    
    bool typeSatisfiesReq(const PuzzleType& type) const; //check if type is valid for the req (incl check false types)
};

#endif /* PuzzleRequirement_h */
