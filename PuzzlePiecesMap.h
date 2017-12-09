//
//  PuzzlePieces.h
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef PuzzlePieces_h
#define PuzzlePieces_h
#include "JigsawPuzzle.h"
#include "PuzzleRequirement.h"


using namespace std;
class PuzzlePiecesMap{
public:
    map<PuzzleType,vector<PuzzlePiece> > buckets;
    PuzzlePiecesMap(vector<PuzzlePiece> pieces);
    void initMap();
    void toBuckets(vector<PuzzlePiece> pieces);
    
};

#endif /* PuzzlePieces_h */
