//
//  PuzzleType.h
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef PuzzleType_h
#define PuzzleType_h

#include "JigsawPuzzle.h"

using namespace std;


class PuzzleType{
protected:
    int l, t, r, b;
public:
   
    PuzzleType(int l, int t, int r, int b) : l(l), t(t), r(r), b(b){}
    int getTop(){return t;}
    int getLeft(){return l;}
    int getRight(){return r;}
    int getBot(){return b;}
     bool operator==(PuzzleType otherType);
};

#endif /* PuzzleType_h */
