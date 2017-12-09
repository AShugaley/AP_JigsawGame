//
//  JigsawPuzzleAdvanced.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 03/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include <stdio.h>
#include "JigsawPuzzleAdvanced.h"
#include <math.h>

//sepcial const for tests
JigsawPuzzleAdvanced::JigsawPuzzleAdvanced(string& inputFilePath, string& outputFilePath): JigsawPuzzle(inputFilePath, outputFilePath), piecesMap(this->correctInputPieces){
}



JigsawPuzzleAdvanced::JigsawPuzzleAdvanced(vector<PuzzlePiece> pieces){
    this->correctInputPieces = pieces;
    this->piecesMap = PuzzlePiecesMap(this->correctInputPieces);
    this->cannotComputeSolution = false;
    this->lastColIndex = -1;
     this->lastRowIndex = -1;
    this->numOfElements = (int)pieces.size();
}


pair<int,int> JigsawPuzzleAdvanced::getNextPos(int i, int j){
    if(j!=lastColIndex){
        return pair<int,int>(i,j+1);
    }
    if(i!=lastRowIndex){
        return pair<int,int>(i+1,0);
    }
    return pair<int,int>(-1,-1);
}

//override
bool JigsawPuzzleAdvanced::initSolveGame(){
    return initSolve();
}

bool JigsawPuzzleAdvanced::solveRec(pair<int,int> nextPos){
    int i = nextPos.first;
    int j = nextPos.second;
    if(i ==-1 || j ==-1){
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



bool JigsawPuzzleAdvanced::initSolve(){
    vector<pair<int,int> > possibleDimensions = getPossibleDimensions(this->numOfElements);
    pair<int,int> topLeftCorner = pair<int,int>(0,0);
    for( auto& p : possibleDimensions){
        this->lastRowIndex = p.first;
        this->lastColIndex = p.second;
        if(solveRec(topLeftCorner) == true)
            return true;
    }
    this->lastRowIndex = -1;
    this->lastColIndex = -1;
    return false;
}


vector<pair<int,int> > JigsawPuzzleAdvanced::getPossibleDimensions(int numOfPieces){
    vector<pair<int,int> > dim;
    for(int i = 1; i<=sqrt(numOfPieces); i++){
        if(numOfPieces % i == 0){
            dim.push_back(std::pair<int,int>(i,numOfPieces / i));
            dim.push_back(std::pair<int,int>(numOfPieces / i,i));
        }
    }
    std::random_shuffle(dim.begin(), dim.end());
    return dim;
}



PuzzleRequirement JigsawPuzzleAdvanced::getReq(int i, int j){
    int l, r, t,b;
    
    
    if(j==0) {l = 0;}
    else{
        if(this->solutionMatrix[i][j-1] == -1)
            l = JOKER;
        else
            l =  (-1)*this->correctInputPieces[this->solutionMatrix[i][j-1] - 1].getRightEdge();
    }
    if(i==0) {t = 0;}
    else{
        if(this->solutionMatrix[i-1][j] == -1)
            t = JOKER;
        else
            t =  (-1)*this->correctInputPieces[this->solutionMatrix[i-1][j] - 1].getBottomEdge();
    }
    if(j==lastColIndex) {r = 0;}
    else{
        if(this->solutionMatrix[i][j+1] == -1)
            r = JOKER;
        else
            r =  (-1)*this->correctInputPieces[this->solutionMatrix[i][j+1] - 1].getLeftEdge();
    }
    if(i==lastRowIndex) {b = 0;}
    else{
        if(this->solutionMatrix[i+1][j] == -1)
            b = JOKER;
        else
            b =  (-1)*this->correctInputPieces[this->solutionMatrix[i+1][j] - 1].getTopEdge();
    }
    
    return PuzzleRequirement(l,t,r,b);
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
