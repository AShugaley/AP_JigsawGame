//
//  PuzzlePieces.h
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef PuzzlePieces_h
#define PuzzlePieces_h

#include "PuzzleType.h"
#include "PuzzleRequirement.h"
#include "PuzzlePiece.h"
#include <map>

using namespace std;

class PuzzlePiecesMap{
public:
    map<PuzzleType,vector<PuzzlePiece> > buckets;
    explicit PuzzlePiecesMap(vector<PuzzlePiece>& pieces);
    void toBuckets(vector<PuzzlePiece> pieces);
    PuzzlePiece* nextPiece(PuzzleRequirement req);
    
    
};

#endif /* PuzzlePieces_h */
