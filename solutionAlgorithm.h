//
// Created by okleinfeld on 12/15/17.
//

#ifndef AP_JIGSAWGAME_SOLUTIONALGORITHM_H
#define AP_JIGSAWGAME_SOLUTIONALGORITHM_H

#include <cmath>
#include <algorithm>

#include "JigsawGameInterface.h"
#include "PuzzlePieceMapInterface.h"

class solutionAlgorithm {
protected:
    JigsawGameInterface* game;
    PuzzlePieceMapInterface* piecesMap;
    virtual bool solveRec(pair<int,int> nextPos);
public:
    solutionAlgorithm(JigsawGameInterface *game, PuzzlePieceMapInterface* piecesMap);
    virtual bool solveGame();
    virtual vector<pair<int,int> > getPossibleDimensions(int size);
};


#endif //AP_JIGSAWGAME_SOLUTIONALGORITHM_H
