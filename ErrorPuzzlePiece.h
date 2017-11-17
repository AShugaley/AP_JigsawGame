//
// Created by okleinfeld on 11/15/17.
//

#ifndef ADVANCEDOOP_HW1_ERRORPUZZLEPIECE_H
#define ADVANCEDOOP_HW1_ERRORPUZZLEPIECE_H

#include "PuzzlePiece.h"
#include <vector>

using namespace std;

class ErrorPuzzlePiece: public PuzzlePiece {
private:
    vector<string> redundantPieces;
public:
    ErrorPuzzlePiece(int ISD, int left, int top, int right, int bottom, vector<string> &redundant);
    void print(std::ostream &os) const override;
};


#endif //ADVANCEDOOP_HW1_ERRORPUZZLEPIECE_H
