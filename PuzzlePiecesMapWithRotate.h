//
// Created by okleinfeld on 12/13/17.
//

#ifndef AP_JIGSAWGAME_PUZZLEPIECESMAPWITHROTATE_H
#define AP_JIGSAWGAME_PUZZLEPIECESMAPWITHROTATE_H

#include "PuzzlePieceMapInterface.h"
#include "PuzzleTypeWithRotation.h"
#include "PuzzlePieceRotation.h"

#include <map>

class PuzzlePiecesMapWithRotate : public PuzzlePieceMapInterface {
protected:
    map<PuzzleTypeWithRotation,vector<PuzzlePieceRotation>> typesMap;
public:
    explicit PuzzlePiecesMapWithRotate(vector<PuzzlePiece>& pieces);
    explicit PuzzlePiecesMapWithRotate() = default;
    void toBuckets(vector<PuzzlePiece>& pieces);
    PuzzlePiece* nextPiece(PuzzleRequirement& req) override;
};


#endif //AP_JIGSAWGAME_PUZZLEPIECESMAPWITHROTATE_H
