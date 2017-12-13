//
// Created by okleinfeld on 12/13/17.
//

#include "JigsawSolutionExistsRotationsAllowed.h"


JigsawSolutionExistsRotationsAllowed::JigsawSolutionExistsRotationsAllowed(vector<PuzzlePiece>& puzzlePieces):
JigsawSolutionExistsChecks(puzzlePieces){};

bool JigsawSolutionExistsRotationsAllowed::checkIfPuzzleIsLegal(){
    bool isLegal = true;
    if(!hasEnoughEdges()){
        this->errorMessages.emplace_back(WRONG_NUM_EDGES);
        isLegal = false;
    }
    vector<int> corners = hasAllCorners();
    if(!corners[0]){
        this->errorMessages.emplace_back(NO_CORNER_TL);
        isLegal = false;
    }
    if(!corners[1]){
        this->errorMessages.emplace_back(NO_CORNER_TR);
        isLegal = false;
    }
    if(!corners[2]){
        this->errorMessages.emplace_back(NO_CORNER_BL);
        isLegal = false;
    }
    if(!corners[3]){
        this->errorMessages.emplace_back(NO_CORNER_BR);
        isLegal = false;
    }

    if(!isSumEdgesZero()){
        this->errorMessages.emplace_back(SUM_TOTAL_EDGES_WRONG);
        isLegal = false;

    }

    return isLegal;
}