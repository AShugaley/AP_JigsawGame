//
// Created by okleinfeld on 12/13/17.
//

#include "JigsawSolutionExistsRotationsAllowed.h"


JigsawSolutionExistsRotationsAllowed::JigsawSolutionExistsRotationsAllowed(vector<PuzzlePiece>& puzzlePieces):
        puzzlePieces(puzzlePieces), numPieces((int) this->puzzlePieces.size()){;}

bool JigsawSolutionExistsRotationsAllowed::checkIfPuzzleIsLegal(){
    bool isLegal = true;

    if(!isSumEdgesZero()){
        this->errorMessages.emplace_back(SUM_TOTAL_EDGES_WRONG);
        isLegal = false;

    }

    return isLegal;
}

bool JigsawSolutionExistsRotationsAllowed::isSumEdgesZero(){
    int sum = 0;
    for(int i = 0; i<this->numPieces; i++){
        sum += this->puzzlePieces[i].edgesSum();
    }

    return sum == 0;
}


void JigsawSolutionExistsRotationsAllowed::writeToFileFailedTests(string& outputFile){
    ofstream outputFileStream;
    outputFileStream.open(outputFile);
    if (!outputFileStream.is_open()){
        cout << OUTPUT_FILE_NOT_OPEN_MESSAGE << endl;
    }
    for (auto& errorString : this->errorMessages){
        outputFileStream << errorString << endl;
    }
    outputFileStream.close();
}
