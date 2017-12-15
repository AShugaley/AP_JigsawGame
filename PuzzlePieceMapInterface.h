//
// Created by okleinfeld on 12/15/17.
//

#ifndef AP_JIGSAWGAME_PUZZLEPIECEMAPINTERFACE_H
#define AP_JIGSAWGAME_PUZZLEPIECEMAPINTERFACE_H

#include "PuzzlePiece.h"
#include "PuzzleRequirement.h"


class PuzzlePieceMapInterface {
public:
    virtual PuzzlePiece* nextPiece(PuzzleRequirement& req) = 0;
    virtual ~PuzzlePieceMapInterface() = 0;
};


#endif //AP_JIGSAWGAME_PUZZLEPIECEMAPINTERFACE_H
