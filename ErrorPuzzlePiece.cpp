//
// Created by okleinfeld on 11/15/17.
//

#include "ErrorPuzzlePiece.h"

ErrorPuzzlePiece::ErrorPuzzlePiece(int ISD, int left, int top, int right, int bottom, vector<string> &redundant)
        :PuzzlePiece(ISD, left, top, right, bottom){
    this->redundantPieces = redundant;
}

void ErrorPuzzlePiece::print(std::ostream &os) const override{
    PuzzlePiece::print(os);
    for (int i = 0; i < this->redundantPieces.size(); i++){
        if (i != this->redundantPieces.size() -1){
            os << this->redundantPieces[i];
            os << " ";
        }
        else{
            os << this->redundantPieces[i];
        }
    }
    os << std::endl;
}

