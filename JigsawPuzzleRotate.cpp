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
