//
//  PuzzlePiecesMapRotate.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include "PuzzlePiecesMapRotate.h"

PuzzlePiece* PuzzlePiecesMapRotate::nextPiece(PuzzleRequirement req){
    for( auto& buck : buckets){
        int rotations = 0;
        PuzzleType type = buck.first;
        do{
            if(req.satisfiesReq(type)){
                for(auto& p : buck.second){
                    if(!p->isUsed()){
                        for(int j = 0; j<rotations; j++)
                            p->rotate();
                        p->setUsed(true);
                        return p;
                    }
                }
            }
            type.rotate();
            rotations++;
        }while(rotations<4);
        type.resetRotation();
    }
    return nullptr;
}
