//
//  JigsawPuzzleAdvanced.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 03/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include <stdio.h>
#include "JigsawPuzzleAdvanced.h"


//sepcial const for tests
JigsawPuzzleAdvanced::JigsawPuzzleAdvanced(vector<PuzzlePiece> pieces){
    this->correctInputPieces = pieces;
    this->cannotComputeSolution = false;
    this->lastColIndex = -1;
     this->lastRowIndex = -1;
    this->numOfElements = (int)pieces.size();
}




//override -> prints with angle
bool JigsawPuzzleAdvanced::printSolutionToFile(bool solved){
    
    ofstream outputFile;
    outputFile.open(this->outputFile);
    if (!outputFile.is_open()){
        cout << OUTPUT_FILE_NOT_OPEN;
        return false;
    }
    if(solved){
        for(int i = 0; i<=this->lastRowIndex; i++){
            for(int j =0; j<=this->lastColIndex;j++){
                outputFile << this->solutionMatrix[i][j];
                if(j!=this->lastColIndex)
                    outputFile << " ";
                if(this->correctInputPieces[this->solutionMatrix[i][j]].getAngle() != 0){
                    outputFile << "[" << correctInputPieces[this->solutionMatrix[i][j]].getAngle() << "]" << " ";
                }
            }
            outputFile << endl;
        }
    }
    else
        outputFile << "Cannot solve puzzle: it seems that there is no proper solution" << endl;
    outputFile.close();
    return solved;
}
