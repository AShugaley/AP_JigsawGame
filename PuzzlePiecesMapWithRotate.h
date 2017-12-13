//
// Created by okleinfeld on 12/13/17.
//

#ifndef AP_JIGSAWGAME_PUZZLEPIECESMAPWITHROTATE_H
#define AP_JIGSAWGAME_PUZZLEPIECESMAPWITHROTATE_H

#include "PuzzlePiecesMap.h"

class PuzzlePiecesMapWithRotate : public PuzzlePiecesMap {
    explicit PuzzlePiecesMapWithRotate(vector<PuzzlePiece>& pieces);
    explicit PuzzlePiecesMapWithRotate() = default;
    void toBuckets(vector<PuzzlePiece>& pieces) override;
};


#endif //AP_JIGSAWGAME_PUZZLEPIECESMAPWITHROTATE_H
