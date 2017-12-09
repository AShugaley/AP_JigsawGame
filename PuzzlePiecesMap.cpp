//
//  PuzzlePieces.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include <stdio.h>
#include "PuzzlePiecesMap.h"

PuzzlePiecesMap::PuzzlePiecesMap(vector<PuzzlePiece> pieces){
    initMap();
   toBuckets(pieces);
}

void PuzzlePiecesMap::initMap(){
    for(int i = -1; i< 2; i++)
        for(int j = -1; j<2 ; j++)
            for(int k = -1; k < 2; k++)
                for(int m = -1; m <2; m++)
                    buckets.insert ( std::pair<PuzzleType,vector<PuzzlePiece> >(PuzzleType(i,j,k,m),vector<PuzzlePiece>()) );
}

void PuzzlePiecesMap::toBuckets(vector<PuzzlePiece> pieces){
    for(auto& p : pieces){
        PuzzleType type = PuzzleType(p.getLeftEdge(),p.getTopEdge(),p.getRightEdge(), p.getBottomEdge());
        buckets[type].push_back(p);
    }
}
