//
// Created by okleinfeld on 12/15/17.
//

#ifndef AP_JIGSAWGAME_FACTORY_H
#define AP_JIGSAWGAME_FACTORY_H


#include <memory>

#include "JigsawGameInterface.h"
#include "PuzzlePieceMapInterface.h"
#include "PuzzlePiece.h"
#include "JigsawPuzzle.h"
#include "JigsawPuzzleRotations.h"
#include "PuzzlePiecesMap.h"
#include "PuzzlePiecesMapWithRotate.h"
#include "NaiveSolutionExistenceCheck.h"
#include "JigsawSolutionExistsChecks.h"
#include "JigsawSolutionExistsRotationsAllowed.h"

using namespace std;

class Factory {
protected:
    bool rotationAllowed;
public:
    explicit Factory(bool rotationAllowed);
    unique_ptr<JigsawGameInterface> getJigsawGame(vector<PuzzlePiece>& pieces);
    unique_ptr<PuzzlePieceMapInterface> getPuzzleMap(vector<PuzzlePiece>& pieces);
    unique_ptr<NaiveSolutionExistenceCheck> getSolutionExistenceChecker(vector<PuzzlePiece> &pieces);

};


#endif //AP_JIGSAWGAME_FACTORY_H
