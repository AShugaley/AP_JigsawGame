//
// Created by okleinfeld on 12/15/17.
//

#include "JigsawPuzzleAbstract.h"


void JigsawPuzzleAbstract::initSolMatrix(){
    this->solutionMatrix = std::vector< std::vector<int> >((size_t) this->lastRowIndex + 1, std::vector<int>((size_t) this->lastColIndex + 1));
    for (int i = 0; i < this->lastRowIndex+1; i++)
        for (int j = 0; j < this->lastColIndex+1; j++)
            this->solutionMatrix[i][j] = -1;
}

void JigsawPuzzleAbstract::initiateSolutionTry(pair<int, int> solutionDimension){
    this->lastRowIndex = solutionDimension.first-1;
    this->lastColIndex = solutionDimension.second-1;
    this->initSolMatrix();
}


pair<int,int> JigsawPuzzleAbstract::getNextPos(int i, int j){
    if(j!=lastColIndex){
        return pair<int,int>(i,j+1);
    }
    if(i!=lastRowIndex){
        return pair<int,int>(i+1,0);
    }
    return pair<int,int>(-1,-1);
};

int JigsawPuzzleAbstract::getPuzzleSize(){
    return this->numPieces;
}