//
//  tests.hpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 03/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef tests_hpp
#define tests_hpp
#include "JigsawPuzzle.h"
#include <stdio.h>




class tests {
public:
    static vector<PuzzlePiece> generateRandomPuzzle(int x, int y);
    static bool solvePuzzle(vector<PuzzlePiece> pieces);
    static bool runTests(int x, int y, int numOfTests);
    
};





#endif /* tests_hpp */
