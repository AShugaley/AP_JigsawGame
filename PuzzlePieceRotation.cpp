//
// Created by okleinfeld on 12/15/17.
//

#include "PuzzlePieceRotation.h"

PuzzlePieceRotation::PuzzlePieceRotation(int ISD, int l, int t, int r, int b):
        PuzzlePiece(ISD, l, t, r, b), rotationAngle(0) {;}

PuzzlePieceRotation::PuzzlePieceRotation(const PuzzlePieceRotation& otherPiece):
        PuzzlePiece(otherPiece), rotationAngle(otherPiece.rotationAngle) {;}


int PuzzlePieceRotation::getAngle() const {
    return this->rotationAngle;
}

void PuzzlePieceRotation::rotate(){
    // switch edges place
    int temp = topEdge;
    topEdge = leftEdge;
    leftEdge = bottomEdge;
    bottomEdge = rightEdge;
    rightEdge = temp;

    // update the current angle
    if(rotationAngle == 270){
        rotationAngle = 0;
    }
    else{
        rotationAngle+= 90;
    }
}

void PuzzlePieceRotation::resetAngle(){
    while(this->rotationAngle != 0)
        rotate();
}