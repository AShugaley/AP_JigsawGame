//
// Created by okleinfeld on 12/15/17.
//

#include "Factory.h"


Factory::Factory(bool rotationAllowed){
    this->rotationAllowed = rotationAllowed;
}


unique_ptr<JigsawGameInterface> Factory::getJigsawGame(vector<PuzzlePiece>& pieces){
    if (this->rotationAllowed){
        return my_make_unique<JigsawPuzzleRotations>(pieces);
    } else{
        return my_make_unique<JigsawPuzzle>(pieces);
    }
}

unique_ptr<PuzzlePieceMapInterface> Factory::getPuzzleMap(vector<PuzzlePiece>& pieces){
    if (this->rotationAllowed){
        return my_make_unique<PuzzlePiecesMapWithRotate>(pieces);
    } else{
        return my_make_unique<PuzzlePiecesMap>(pieces);
    }
}

unique_ptr<NaiveSolutionExistenceCheck> Factory::getSolutionExistenceChecker(vector<PuzzlePiece> &pieces){
    if (this->rotationAllowed){
        return my_make_unique<JigsawSolutionExistsRotationsAllowed>(pieces);
    } else{
        return my_make_unique<JigsawSolutionExistsChecks>(pieces);
    }
}

template<typename T, typename... Args>
std::unique_ptr<T> my_make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}