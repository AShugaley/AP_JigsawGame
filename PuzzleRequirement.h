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
public:
    int l, t, r, b;
    vector<PuzzleType> falseTypes;
    PuzzleRequirement(int l, int t, int r, int b) : l(l), t(t), r(r), b(b){}
    void addFalseType(PuzzleType type);
    bool satisfiesReq(PuzzleType type);
};

#endif /* PuzzleRequirement_h */
