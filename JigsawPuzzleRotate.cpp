//
//  JigsawPuzzleRotate.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//


#include "JigsawPuzzleRotate.h"

bool JigsawPuzzleRotate::initSolve(){
    this->piecesMap = PuzzlePiecesMapRotate(this->correctInputPieces);
    return beginMainAlgo();
}

bool JigsawPuzzleRotate::isLegalPuzzle(){
    ofstream outputFile;
    outputFile.open(this->outputFile);
    bool legal = true;
    if (!outputFile.is_open()){
        cout << OUTPUT_FILE_NOT_OPEN << endl;
        return false;
    }
    if(!hasEnoughEdges()){
        outputFile << "Cannot solve puzzle: wrong number of straight edges" << endl;
        legal = false;
    }
    
    bool TLC = false, TRC= false, BRC= false, BLC = false, allcorners = false;
    for(int i = 0; i<4; i++){
        for(auto& p: this->correctInputPieces){
            if(!TLC) {TLC = p.isTopLeftCorner();}
            if(!TRC) {TRC = p.isTopRightCorner();}
            if(!BRC) {BRC = p.isBotRightCorner();}
            if(!BLC) {BLC = p.isBotLeftCorner();}
            p.rotate();
        }
    }
    for(auto p : this->correctInputPieces)
        p.resetRotation();
    allcorners = TLC && TRC && BRC && BLC;
    if(!allcorners){
        legal = false;
        if(!TLC){outputFile << "Cannot solve puzzle: missing corner element: <TL>" << endl;}
        if(!TRC){outputFile << "Cannot solve puzzle: missing corner element: <TR>" << endl;}
        if(!BLC){outputFile << "Cannot solve puzzle: missing corner element: <BL>" << endl;}
        if(!BRC){outputFile << "Cannot solve puzzle: missing corner element: <BR>" << endl;}
    }
    
    
    if(!isSumEdgesZero()){
        outputFile << "Cannot solve puzzle: sum of edges is not zero" << endl;
        legal = false;
    }
    
    outputFile.close();
    return legal;
}
