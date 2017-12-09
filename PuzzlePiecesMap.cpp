//
//  PuzzlePieces.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include "PuzzlePiecesMap.h"

PuzzlePiecesMap::PuzzlePiecesMap(vector<PuzzlePiece>& pieces){
    this->buckets = std::map<PuzzleType, vector<PuzzlePiece>>();
    toBuckets(pieces);
}

PuzzlePiecesMap::PuzzlePiecesMap() {
    this->buckets = std::map<PuzzleType, vector<PuzzlePiece>>();
}

void PuzzlePiecesMap::toBuckets(vector<PuzzlePiece> pieces){
    for(auto& p : pieces){
        PuzzleType type = PuzzleType(p.getLeftEdge(),p.getTopEdge(),p.getRightEdge(), p.getBottomEdge());
        buckets[type].push_back(p);
    }
}

PuzzlePiece* PuzzlePiecesMap::nextPiece(PuzzleRequirement req){
    for( auto& buck : buckets){
        if(req.satisfiesReq(buck.first)){
            for(auto& p : buck.second){
                if(!p.isUsed()){
                    p.setUsed(true);
                    return &p;
                }
            }
        }
    }
    return nullptr;
}
