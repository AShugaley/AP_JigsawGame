//
// Created by okleinfeld on 12/15/17.
//

#include "Factory.h"


Factory::Factory(bool rotationAllowed){
    this->rotationAllowed = rotationAllowed;
}


unique_ptr<JigsawGameInterface> Factory::getJigsawGame(vector<PuzzlePiece>& pieces){
    if (this->rotationAllowed){
        return std::make_unique<JigsawPuzzleRotations>(pieces);
    } else{
        return std::make_unique<JigsawPuzzle>(pieces);
    }
}

unique_ptr<PuzzlePieceMapInterface> Factory::getPuzzleMap(vector<PuzzlePiece>& pieces){
    if (this->rotationAllowed){
        return std::make_unique<PuzzlePiecesMapWithRotate>(pieces);
    } else{
        return std::make_unique<PuzzlePiecesMap>(pieces);
    }
}

unique_ptr<NaiveSolutionExistenceCheck> Factory::getSolutionExistenceChecker(vector<PuzzlePiece> &pieces){
    if (this->rotationAllowed){
        return std::make_unique<JigsawSolutionExistsRotationsAllowed>(pieces);
    } else{
        return std::make_unique<JigsawSolutionExistsChecks>(pieces);
    }
}