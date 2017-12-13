//
// Created by okleinfeld on 12/13/17.
//

#ifndef AP_JIGSAWGAME_PUZZLEPIECESMAPWITHROTATE_H
#define AP_JIGSAWGAME_PUZZLEPIECESMAPWITHROTATE_H

#include "PuzzlePiecesMap.h"
#include "PuzzleTypeWithRotation.h"


class PuzzlePiecesMapWithRotate : public PuzzlePiecesMap {
protected:
    map<PuzzleTypeWithRotation,vector<PuzzlePiece>> typesMap;
public:
    explicit PuzzlePiecesMapWithRotate(vector<PuzzlePiece>& pieces);
    explicit PuzzlePiecesMapWithRotate() = default;
    void toBuckets(vector<PuzzlePiece>& pieces) override;
    PuzzlePiece* nextPiece(PuzzleRequirement& req) override;
};


#endif //AP_JIGSAWGAME_PUZZLEPIECESMAPWITHROTATE_H
