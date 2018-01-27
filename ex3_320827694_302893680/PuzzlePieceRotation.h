//
// Created by okleinfeld on 12/15/17.
//

#ifndef AP_JIGSAWGAME_PUZZLEPIECEROTATION_H
#define AP_JIGSAWGAME_PUZZLEPIECEROTATION_H

#include "PuzzlePiece.h"

class PuzzlePieceRotation : public PuzzlePiece{
protected:
    int rotationAngle;
public:
    //constructors
    explicit PuzzlePieceRotation(int ISD, int l, int t, int r, int b);
    PuzzlePieceRotation(const PuzzlePieceRotation& otherPiece);
    explicit PuzzlePieceRotation(const PuzzlePiece& otherPiece);

    //getters
    int getAngle() const;

    //Setters and operations
    void rotate();
    void resetAngle();
};


#endif //AP_JIGSAWGAME_PUZZLEPIECEROTATION_H
