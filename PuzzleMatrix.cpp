//
// Created by okleinfeld on 11/17/17.
//

#include "PuzzleMatrix.h"


PuzzleMatrix::PuzzleMatrix(int numElements){
    this->row = numElements;
    this->arr = *(new vector<PuzzlePiece> (numElements*numElements));
}

void PuzzleMatrix::add(int i, int j, PuzzlePiece p){
    this->arr[i * row + j] = p;
}

PuzzlePiece PuzzleMatrix::remove(int i, int j){
    PuzzlePiece p = this->get(i, j);
    this->arr.erase(this->arr.begin() + i * row + j);
    return p;

}

PuzzlePiece PuzzleMatrix::get(int i, int j){
    return this->arr[i * row + j];
}