//
// Created by okleinfeld on 12/13/17.
//

#include "PuzzlePiecesMapWithRotate.h"

PuzzlePiecesMapWithRotate::PuzzlePiecesMapWithRotate(vector<PuzzlePieceRotation>& pieces){
    toBuckets(pieces);
}

void PuzzlePiecesMapWithRotate::toBuckets(vector<PuzzlePieceRotation>& pieces){
    for(auto& p : pieces){
        PuzzleTypeWithRotation type = PuzzleTypeWithRotation(p.getLeftEdge(),p.getTopEdge(),p.getRightEdge(), p.getBottomEdge());
        this->typesMap[type].push_back(p);
    }
}

PuzzlePiece* PuzzlePiecesMapWithRotate::nextPiece(PuzzleRequirement& req){
    int rotations;
    for (auto& typeVectorPair : typesMap){
        rotations = 0;
        PuzzleTypeWithRotation puzzleType = typeVectorPair.first;

        do{
            if(req.typeSatisfiesReq(puzzleType)){
                for(auto& puzzlePiece : typeVectorPair.second){
                    if(!puzzlePiece.isUsed()){
                        for(int j = 0; j < rotations; j++){
                            puzzlePiece.rotate();
                        }
                        puzzlePiece.setUsed(true);
                        return &puzzlePiece;
                    }
                }
            }
            puzzleType.rotate();
            rotations++;
        } while (rotations < 4);

        puzzleType.resetRotation();
    }
    return nullptr;
}