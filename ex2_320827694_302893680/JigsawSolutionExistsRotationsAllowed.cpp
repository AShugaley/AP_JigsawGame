//
// Created by okleinfeld on 12/13/17.
//

#include "JigsawSolutionExistsRotationsAllowed.h"


JigsawSolutionExistsRotationsAllowed::JigsawSolutionExistsRotationsAllowed(vector<PuzzlePiece>& puzzlePieces):
        numPieces((int) puzzlePieces.size()), puzzlePieces(puzzlePieces){;}

bool JigsawSolutionExistsRotationsAllowed::checkIfPuzzleIsLegal(){
    bool isLegal = true;

    //check the edges
    if(!hasEnoughEdges()){
        this->errorMessages.emplace_back(WRONG_NUM_EDGES);
        isLegal = false;
    }
    //check the corners
    bool TLC = false, TRC= false, BRC= false, BLC = false, allcorners = false;
    for(int i = 0; i<4; i++){
                for(auto& p: this->puzzlePieces){
                            if(!TLC) {TLC = p.isTopLeftCorner();}
                            if(!TRC) {TRC = p.isTopRightCorner();}
                            if(!BRC) {BRC = p.isBotRightCorner();}
                            if(!BLC) {BLC = p.isBotLeftCorner();}
                            p.rotate();
                        }
            }
    for(auto& p : this->puzzlePieces)
                p.resetAngle();
    allcorners = TLC && TRC && BRC && BLC;
    if(!allcorners){
            isLegal = false;
            if(!TLC){this->errorMessages.emplace_back(NO_CORNER_TL);}
            if(!TRC){this->errorMessages.emplace_back(NO_CORNER_TR);}
            if(!BLC){this->errorMessages.emplace_back(NO_CORNER_BL);}
            if(!BRC){this->errorMessages.emplace_back(NO_CORNER_BR);}
            }

    //check the sum
    if(!isSumEdgesZero()){
        this->errorMessages.emplace_back(SUM_TOTAL_EDGES_WRONG);
        isLegal = false;
    
    }
    return isLegal;

}

bool JigsawSolutionExistsRotationsAllowed::isSumEdgesZero(){
    int sum = 0;
    for(int i = 0; i< this->numPieces; i++){
        sum += this->puzzlePieces[i].edgesSum();
    }

    return sum == 0;
}

bool JigsawSolutionExistsRotationsAllowed::hasEnoughEdges(){
    int count = 0;
    for(int i = 0; i<this->numPieces; i++){
        count += this->puzzlePieces[i].countStraightEdges();
    }
    return ((count >= (sqrt(this->numPieces))) && (count %2==0));
}


void JigsawSolutionExistsRotationsAllowed::writeToFileFailedTests(string& outputFile){
    ofstream outputFileStream;
    outputFileStream.open(outputFile);
    if (!outputFileStream.is_open()){
        cout << OUTPUT_FILE_NOT_OPEN_IN_SOLUTION_CHECK << endl;
    }
    for (auto& errorString : this->errorMessages){
        outputFileStream << errorString << endl;
    }
    outputFileStream.close();
}
