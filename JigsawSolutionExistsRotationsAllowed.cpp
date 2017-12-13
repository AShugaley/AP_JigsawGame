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

    if(!isSumEdgesZero()){
        this->errorMessages.emplace_back(SUM_TOTAL_EDGES_WRONG);
        isLegal = false;

    }

    return isLegal;
}

//vector<int> JigsawSolutionExistsRotationsAllowed::hasAllCorners(){
//    vector<int> corners = vector<int>(4,0);
//    for(int i = 0; i < this->numPieces; i++){
//        for (int j = 0; j < NUM_ANGLE_ROTATIONS; j++){
//            if (this->puzzlePieces[i].isTopLeftCorner()){
//                corners[0] = 1;
//                break;
//            }
//            this->puzzlePieces[i].rotate();
//        }
//        if(this->puzzlePieces[i].isTopLeftCorner()){
//            corners[0] = 1;
//        }
//        if(this->puzzlePieces[i].isTopRightCorner()){
//            corners[1] = 1;
//        }
//        if(this->puzzlePieces[i].isBotLeftCorner()){
//            corners[2] = 1;
//        }
//        if(this->puzzlePieces[i].isBotRightCorner()){
//            corners[3] = 1;
//        }
//    }
//    return corners;
//}