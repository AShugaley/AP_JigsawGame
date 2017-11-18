//
// Created by okleinfeld on 11/17/17.
//

#include "PuzzleMatrix.h"


PuzzleMatrix::PuzzleMatrix(int numElements){
    this->rowSize = numElements;
    this->arr = *(new vector<PuzzlePiece> (numElements*numElements));
}

void PuzzleMatrix::add(int i, int j, PuzzlePiece p){
    this->arr[i * rowSize + j] = p;
}

PuzzlePiece PuzzleMatrix::remove(int i, int j){
    PuzzlePiece p = this->get(i, j);
    this->arr[i * rowSize + j] = *new PuzzlePiece();
    return p;

}

PuzzlePiece PuzzleMatrix::get(int i, int j){
    return this->arr[i * rowSize + j];
}

void PuzzleMatrix::printRange(std::ostream &os, int numRealRows, int numRealCols){
    for (int i = 0; i < numRealRows+1; i++){
        for (int j = 0; j < numRealCols+1; j++){
            if (j == 0){
                os << this->get(i, j).getISD();
            } else{
                os << " " << this->get(i, j).getISD();
            }
        }

        if (i != numRealRows){
            os << endl;
        }
    }
}

