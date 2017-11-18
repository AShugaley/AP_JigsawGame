

#ifndef AP_JIGSAWGAME_PUZZLEMATRIX_H
#define AP_JIGSAWGAME_PUZZLEMATRIX_H


/*
 
 A simple matrix calss to represent our solution board
 
 */


#include "PuzzlePiece.h"
#include <vector>

using namespace std;


class PuzzleMatrix {
private:
    vector<PuzzlePiece> arr;
    int rowSize;
public:
    PuzzleMatrix(int numElements);
    ~PuzzleMatrix(){}
    void add(int i, int j, PuzzlePiece p);
    PuzzlePiece remove(int i, int j);
    PuzzlePiece get(int i, int j);
    void printRange(std::ostream &os, int numRealRows, int numRealCols);
};


#endif //AP_JIGSAWGAME_PUZZLEMATRIX_H
