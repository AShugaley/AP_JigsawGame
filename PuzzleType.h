//
//  PuzzleType.h
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef PuzzleType_h
#define PuzzleType_h
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <map>
#include <fstream>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <string>
#define JOKER 100
using namespace std;

class PuzzleType{
protected:
    int l, t, r, b;
public:
    PuzzleType(int l, int t, int r, int b) : l(l), t(t), r(r), b(b){}
    int getTop() const {return t;}
    int getLeft() const {return l;}
    int getRight() const {return r;}
    int getBot() const {return b;}
    bool operator==(const PuzzleType& otherType) const ;
    bool operator<(const PuzzleType& otherType) const ;
};

#endif /* PuzzleType_h */
