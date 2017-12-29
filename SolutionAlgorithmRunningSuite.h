////
////  SolutionAlgorithmRunningSuite.h
////  AdvProgEX1
////
////  Created by Alexander Shugaley on 23/12/2017.
////  Copyright © 2017 Alexander Shugaley. All rights reserved.
////
//
#ifndef SolutionAlgorithmRunningSuite_h
#define SolutionAlgorithmRunningSuite_h

#include "JigsawGameInterface.h"
#include "PuzzlePieceMapInterface.h"
#include <memory>

using namespace std;

class SolutionAlgorithmRunningSuite {
public:
    unique_ptr<JigsawGameInterface> game;
    unique_ptr<PuzzlePieceMapInterface> piecesMap;

    virtual bool solveRec(pair<int,int> nextPos);
    SolutionAlgorithmRunningSuite(unique_ptr<JigsawGameInterface> game, unique_ptr<PuzzlePieceMapInterface> piecesMap);
    virtual bool solveGame(vector<pair<int,int> > possibleDimensions);
    virtual pair<bool,unique_ptr<JigsawGameInterface> > solveGamePair(int i, int j);
};
#endif /* SolutionAlgorithmRunningSuite_h */
