//
// Created by okleinfeld on 12/13/17.
//

#include "PuzzlePiecesMapWithRotate.h"
#include "PuzzleTypeWithRotation.h"

PuzzlePiecesMapWithRotate::PuzzlePiecesMapWithRotate(vector<PuzzlePiece>& pieces): PuzzlePiecesMap(pieces){};

void PuzzlePiecesMapWithRotate::toBuckets(vector<PuzzlePiece>& pieces){
    for(auto& p : pieces){
        PuzzleTypeWithRotation type = PuzzleTypeWithRotation(p.getLeftEdge(),p.getTopEdge(),p.getRightEdge(), p.getBottomEdge());
        typesMap[type].push_back(p);
    }
}