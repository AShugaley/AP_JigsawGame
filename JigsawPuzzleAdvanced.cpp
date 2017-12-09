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
    for(int k = 0; k<numOfElements-1;k++)
        if(this->moves[k] == pair<int,int>(i,j))
            return moves[k+1];
    return pair<int,int>(-1,-1);
}



void JigsawPuzzleAdvanced::Spiral( int m, int n){
    //this->moves = vector<int,int>();
    while (!this->moves.empty())
    {
        this->moves.pop_back();
    }
    this->currentMove = 0;
    int i, k = 0, l = 0;
    
    /*  k - starting row index
     m - ending row index
     l - starting column index
     n - ending column index
     i - iterator
     */
    
    while (k < m && l < n)
    {
        /* Print the first row from the remaining rows */
        for (i = l; i < n; ++i)
        {
            this->moves.push_back(pair<int,int>(k,i));
            //printf("%d ", a[k][i]);
        }
        k++;
        
        /* Print the last column from the remaining columns */
        for (i = k; i < m; ++i)
        {
            this->moves.push_back(pair<int,int>(i,n-1));
            //printf("%d ", a[i][n-1]);
        }
        n--;
        
        /* Print the last row from the remaining rows */
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                this->moves.push_back(pair<int,int>(m-1,i));
              //  printf("%d ", a[m-1][i]);
            }
            m--;
        }
        
        /* Print the first column from the remaining columns */
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                this->moves.push_back(pair<int,int>(i,l));
               // printf("%d ", a[i][l]);
            }
            l++;
        }
    }
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
            p->reset();
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
        this->lastRowIndex = p.first-1;
        this->lastColIndex = p.second-1;
        initSolMatrix();
        Spiral(lastRowIndex+1, lastColIndex+1);
        currentMove = 0;
        if(solveRec(topLeftCorner) == true)
            return true;
    }
    this->lastRowIndex = -1;
    this->lastColIndex = -1;
    return false;
}

void JigsawPuzzleAdvanced::initSolMatrix(){
    this->solutionMatrix = std::vector< std::vector<int> >(this->lastRowIndex +1, std::vector<int>(this->lastColIndex+1));
    for (int i = 0; i < this->lastRowIndex+1; i++)
        for (int j = 0; j < this->lastColIndex+1; j++)
            this->solutionMatrix[i][j] = -1;
    
}


vector<pair<int,int> > JigsawPuzzleAdvanced::getPossibleDimensions(int numOfPieces){
    vector<pair<int,int> > dim;
    for(int i = 1; i<=sqrt(numOfPieces); i++){
        if(numOfPieces % i == 0){
            dim.push_back(std::pair<int,int>(i,numOfPieces / i));
            if(i!= (numOfPieces / i))
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
