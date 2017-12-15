//
// Created by okleinfeld on 12/15/17.
//

#include "JigsawPuzzle.h"

JigsawPuzzle::JigsawPuzzle(vector<PuzzlePiece> pieces){
    this->puzzlePieces = pieces;
    this->lastColIndex = -1;
    this->lastRowIndex = -1;
    this->numPieces = (int) this->puzzlePieces.size();
}


void JigsawPuzzle::updatePuzzlePieceInSolution(int i, int j, PuzzlePiece& p){
    this->solutionMatrix[i][j] = p.getISD();
    p.setUsed(true);
}

void JigsawPuzzle::revertPuzzlePieceFromSolution(int i, int j, PuzzlePiece& p){
    this->solutionMatrix[i][j] = -1;
    p.setUsed(false);
}

void JigsawPuzzle::printSolutionToFile(std::string& outputFilePath, bool solved){
    ofstream outputFileStream;
    outputFileStream.open(outputFilePath);
    if (!outputFileStream.is_open()){
        cout << OUTPUT_FILE_NOT_OPEN << endl;
    }
    if(solved){
        for(int i = 0; i <= this->lastRowIndex; i++){
            for(int j =0; j <= this->lastColIndex; j++){
                int currentPieceISD = this->solutionMatrix[i][j];

                outputFileStream << currentPieceISD;
                if (j != this->lastColIndex){
                    outputFileStream << " ";
                }
            }
            outputFileStream << endl;
        }

    } else{
        outputFileStream << NO_SOLUTION_MESSAGE << endl;
    }
    outputFileStream.close();
}

PuzzleRequirement JigsawPuzzle::getReq(int i, int j){
    int l, r, t,b;

    if(j==0){
        l = 0;
    } else {
        if(this->solutionMatrix[i][j-1] == -1)
            l = JOKER;
        else
            l =  (-1)*this->puzzlePieces[this->solutionMatrix[i][j-1] - 1].getRightEdge();
    }

    if(i==0) {
        t = 0;
    } else{
        if(this->solutionMatrix[i-1][j] == -1)
            t = JOKER;
        else
            t =  (-1)*this->puzzlePieces[this->solutionMatrix[i-1][j] - 1].getBottomEdge();
    }

    if(j==lastColIndex) {
        r = 0;
    } else{
        if(this->solutionMatrix[i][j+1] == -1)
            r = JOKER;
        else
            r =  (-1)*this->puzzlePieces[this->solutionMatrix[i][j+1] - 1].getLeftEdge();
    }

    if(i==lastRowIndex) {
        b = 0;
    } else{
        if(this->solutionMatrix[i+1][j] == -1)
            b = JOKER;
        else
            b =  (-1)*this->puzzlePieces[this->solutionMatrix[i+1][j] - 1].getTopEdge();
    }

    return PuzzleRequirement(l,t,r,b);
}