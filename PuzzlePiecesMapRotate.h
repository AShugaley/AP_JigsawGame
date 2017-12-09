//
//  PuzzlePiecesMapRotate.h
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef PuzzlePiecesMapRotate_h
#define PuzzlePiecesMapRotate_h




#include "PuzzlePiecesMap.h"


using namespace std;

class PuzzlePiecesMapRotate: public PuzzlePiecesMap{
public:
    explicit PuzzlePiecesMapRotate(vector<PuzzlePiece>& pieces) : PuzzlePiecesMap(pieces){}
    explicit PuzzlePiecesMapRotate(): PuzzlePiecesMap(){}
    PuzzlePiece* nextPiece(PuzzleRequirement req);

    
    
};
#endif /* PuzzlePiecesMapRotate_h */
