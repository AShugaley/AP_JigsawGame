//
// Created by okleinfeld on 12/15/17.
//

#ifndef AP_JIGSAWGAME_SOLUTIONALGORITHM_H
#define AP_JIGSAWGAME_SOLUTIONALGORITHM_H

#include <cmath>
#include <memory>
#include <algorithm>

#include "JigsawGameInterface.h"
#include "PuzzlePieceMapInterface.h"

using namespace std;

class SolutionAlgorithm {
protected:
    unique_ptr<JigsawGameInterface> game;
    unique_ptr<PuzzlePieceMapInterface> piecesMap;
    virtual bool solveRec(pair<int,int> nextPos);
public:
    SolutionAlgorithm(JigsawGameInterface *game, PuzzlePieceMapInterface* piecesMap);
    virtual bool solveGame();
    virtual vector<pair<int,int> > getPossibleDimensions(int size);
};


#endif //AP_JIGSAWGAME_SOLUTIONALGORITHM_H
