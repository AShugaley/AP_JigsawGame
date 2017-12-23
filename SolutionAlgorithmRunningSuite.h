//
//  SolutionAlgorithmRunningSuite.h
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 23/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef SolutionAlgorithmRunningSuite_h
#define SolutionAlgorithmRunningSuite_h
#include "JigsawGameInterface.h"
#include "PuzzlePieceMapInterface.h"

using namespace std;

class SolutionAlgorithmRunningSuite {
public:
    JigsawGameInterface * game;
    PuzzlePieceMapInterface * piecesMap;
    virtual bool solveRec(pair<int,int> nextPos);
    SolutionAlgorithmRunningSuite(JigsawGameInterface * game, PuzzlePieceMapInterface * piecesMap);
    virtual bool solveGame(vector<pair<int,int> > possibleDimensions);
};
#endif /* SolutionAlgorithmRunningSuite_h */
