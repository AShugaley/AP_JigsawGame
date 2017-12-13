//
// Created by okleinfeld on 12/13/17.
//

#include "JigsawPuzzleRotations.h"

JigsawPuzzleRotations::JigsawPuzzleRotations(vector<PuzzlePiece> pieces) : JigsawPuzzle(){
    this->puzzlePieces = pieces;
    this->piecesMap = PuzzlePiecesMapWithRotate(this->puzzlePieces);
    this->lastColIndex = -1;
    this->lastRowIndex = -1;
    this->numPieces = (int) this->puzzlePieces.size();
    this->puzzleSolvedSuccessfully = false;
}


bool JigsawPuzzleRotations::solveRec(pair<int,int> nextPos){
    int i = nextPos.first;
    int j = nextPos.second;
    if (i ==-1 || j ==-1){
        return true;
    }
    PuzzleRequirement req = getReq(i, j);
    PuzzlePiece* p = this->piecesMap.nextPiece(req);
    while(p!=nullptr){
        this->solutionMatrix[i][j] = p->getISD();
        if(solveRec(getNextPos(i, j)))
            return true;
        else{
            this->solutionMatrix[i][j] = -1;
            p->setUsed(false);
            req.addFalseType(PuzzleType(p->getLeftEdge(), p->getTopEdge(), p->getRightEdge(), p->getBottomEdge()));
            p = this->piecesMap.nextPiece(req);
        }
    }
    return false;
}

bool JigsawPuzzleRotations::solveGame(){
    vector<pair<int,int> > possibleDimensions = getPossibleDimensions();
    pair<int,int> topLeftCorner = pair<int,int>(0,0);
    for (auto& p : possibleDimensions){
        this->lastRowIndex = p.first-1;
        this->lastColIndex = p.second-1;
        initSolMatrix();
        if(solveRec(topLeftCorner) == true){
            this->puzzleSolvedSuccessfully = true;
            return true;
        }
    }

    this->lastRowIndex = -1;
    this->lastColIndex = -1;
    return false;
}