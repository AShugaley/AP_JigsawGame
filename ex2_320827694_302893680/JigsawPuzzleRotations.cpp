//
// Created by okleinfeld on 12/15/17.
//

#include "JigsawPuzzleRotations.h"


JigsawPuzzleRotations::JigsawPuzzleRotations(vector<PuzzlePiece> pieces){
    this->puzzlePieces = vector<PuzzlePieceRotation>();
    for (auto& p : pieces){
        PuzzlePieceRotation rotationPiece = PuzzlePieceRotation(p);
        this->puzzlePieces.emplace_back(rotationPiece);
    }
    this->lastColIndex = -1;
    this->lastRowIndex = -1;
    this->numPieces = (int) this->puzzlePieces.size();
}


void JigsawPuzzleRotations::updatePuzzlePieceInSolution(int i, int j, PuzzlePiece* p){
    int pISD = p->getISD();
    int pIndex = pISD - 1;
    p->setUsed(true);
    this->solutionMatrix[i][j] = pISD;
    auto* pRotation = dynamic_cast<PuzzlePieceRotation*>(p);
    this->puzzlePieces[pIndex] = *pRotation;
}

void JigsawPuzzleRotations::revertPuzzlePieceFromSolution(int i, int j, PuzzlePiece* p){
    int pISD = p->getISD();
    int pIndex = pISD - 1;
    p->setUsed(false);
    this->solutionMatrix[i][j] = -1;
    auto* pRotation = dynamic_cast<PuzzlePieceRotation*>(p);
    pRotation->resetAngle();
    this->puzzlePieces[pIndex] = *pRotation;
}

PuzzleRequirement JigsawPuzzleRotations::getReq(int i, int j){
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


void JigsawPuzzleRotations::printSolutionToFile(std::string& outputFilePath, bool solved){
    ofstream outputFileStream;
    outputFileStream.open(outputFilePath);
    if (!outputFileStream.is_open()){
        cout << OUTPUT_FILE_NOT_OPEN << endl;
    }
    if(solved){
        for(int i = 0; i <= this->lastRowIndex; i++){
            for(int j =0; j <= this->lastColIndex; j++){
                int currentPieceISD = this->solutionMatrix[i][j];
                int currentPieceVectorIndex = currentPieceISD -1;

                outputFileStream << currentPieceISD;
                if(this->puzzlePieces[currentPieceVectorIndex].getAngle() != 0){
                    outputFileStream << " [" << puzzlePieces[currentPieceVectorIndex].getAngle() << "]";
                }

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