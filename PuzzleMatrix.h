//
// Created by okleinfeld on 11/17/17.
//

#ifndef AP_JIGSAWGAME_PUZZLEMATRIX_H
#define AP_JIGSAWGAME_PUZZLEMATRIX_H

#include "PuzzlePiece.h"
#include <vector>

using namespace std;


class PuzzleMatrix {
private:
    vector<PuzzlePiece> arr;
    int rowSize;
public:
    PuzzleMatrix(int numElements);
    void add(int i, int j, PuzzlePiece p);
    PuzzlePiece remove(int i, int j);
    PuzzlePiece get(int i, int j);
    void printRange(std::ostream &os, int numRealRows, int numRealCols);
};


#endif //AP_JIGSAWGAME_PUZZLEMATRIX_H
