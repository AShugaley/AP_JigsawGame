//
// Created by okleinfeld on 12/12/17.
//

#include "JigsawSolutionExistsChecks.h"

JigsawSolutionExistsChecks::JigsawSolutionExistsChecks(vector<PuzzlePiece>& puzzlePieces):
        puzzlePieces(puzzlePieces), numPieces((int) this->puzzlePieces.size()){}


vector<int> JigsawSolutionExistsChecks::hasAllCorners(){
    vector<int> corners = vector<int>(4,0);
    for(int i = 0; i < this->numPieces; i++){
        if(this->puzzlePieces[i].isTopLeftCorner()){
            corners[0] = 1;
        }
        if(this->puzzlePieces[i].isTopRightCorner()){
            corners[1] = 1;
        }
        if(this->puzzlePieces[i].isBotLeftCorner()){
            corners[2] = 1;
        }
        if(this->puzzlePieces[i].isBotRightCorner()){
            corners[3] = 1;
        }
    }
    return corners;
}

bool JigsawSolutionExistsChecks::hasEnoughEdges(){
    int count = 0;
    for(int i = 0; i<this->numPieces; i++){
        count += this->puzzlePieces[i].countStraightEdges();
    }
    return ((count >= (sqrt(this->numPieces))) && (count %2==0));
}

bool JigsawSolutionExistsChecks::isSumEdgesZero(){
    int sum = 0;
    for(int i = 0; i<this->numPieces; i++){
        sum += this->puzzlePieces[i].edgesSum();
    }

    return sum == 0;
}

bool JigsawSolutionExistsChecks::isSumHorizontalEdgesZero(){
    int sum = 0;
    for(int i = 0; i < this->numPieces; i++){
        sum += this->puzzlePieces[i].getTopEdge() + this->puzzlePieces[i].getBottomEdge();
    }

    return sum == 0;
}

bool JigsawSolutionExistsChecks::isSumVerticalEdgesZero(){
    int sum = 0;
    for(int i = 0; i < this->numPieces; i++){
        sum += this->puzzlePieces[i].getLeftEdge() + this->puzzlePieces[i].getRightEdge();
    }

    return sum == 0;
}

bool JigsawSolutionExistsChecks::checkIfPuzzleIsLegal(){
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

    } else {

        if(!isSumHorizontalEdgesZero()){
            this->errorMessages.emplace_back(SUM_HOR_EDGES_WRONG);
            isLegal = false;
        }
        if(!isSumVerticalEdgesZero()){
            this->errorMessages.emplace_back(SUM_VER_EDGES_WRONG);
            isLegal = false;
        }
    }

    return isLegal;
}

void JigsawSolutionExistsChecks::writeToFileFailedTests(string& outputFile){
    ofstream outputFileStream;
    outputFileStream.open(outputFile);
    if (!outputFileStream.is_open()){
        cout << OUTPUT_FILE_NOT_OPEN << endl;
    }
    for (auto& errorString : this->errorMessages){
        outputFileStream << errorString << endl;
    }
    outputFileStream.close();
}
