//
//  PuzzlePieces.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include "PuzzlePiecesMap.h"

PuzzlePiecesMap::PuzzlePiecesMap() {
    this->typesMap = std::map<PuzzleType, vector<PuzzlePiece> >();
}

PuzzlePiecesMap::PuzzlePiecesMap(vector<PuzzlePiece>& pieces){
    this->typesMap = std::map<PuzzleType, vector<PuzzlePiece> >();
    toBuckets(pieces);
}

void PuzzlePiecesMap::toBuckets(vector<PuzzlePiece>& pieces){
    for(auto& p : pieces){
        PuzzleType type = PuzzleType(p.getLeftEdge(),p.getTopEdge(),p.getRightEdge(), p.getBottomEdge());
        this->typesMap[type].push_back(p);
    }
}

PuzzlePiece* PuzzlePiecesMap::nextPiece(PuzzleRequirement& req){
    for(auto& type : typesMap){
        // first check if the type itself satisfies the requirement
        if(req.typeSatisfiesReq(type.first)){
            // then check if we have an unused vector from that type
            for(auto& puzzlePiece : type.second){
                if(!puzzlePiece.isUsed()){
                    puzzlePiece.setUsed(true);
                    return &puzzlePiece;
                }
            }
        }
    }
    // if we cannot find any puzzle piece that satisfies the requirement (and wan't used yet) - return nullptr
    return nullptr;
}
