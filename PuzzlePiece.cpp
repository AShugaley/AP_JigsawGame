//
// Created by okleinfeld on 11/15/17.
//

#include "PuzzlePiece.h"

PuzzlePiece::PuzzlePiece(const int ISD, int l, int t, int r, int b) :
        ISD(ISD), leftEdge(l), topEdge(t), rightEdge(r), bottomEdge(b){}

const int PuzzlePiece::getISD() const {
    return this->ISD;
}

int PuzzlePiece::getLeftEdge() const {
    return this->leftEdge;
}

int PuzzlePiece::getTopEdge() const {
    return this->topEdge;
}

int PuzzlePiece::getRightEdge() const {
    return this->rightEdge;
}
int PuzzlePiece::getBottomEdge() const {
    return this->bottomEdge;
}

void PuzzlePiece::print(std::ostream &os) const{
    os << this->ISD << " " << this->leftEdge << " " << this->topEdge << " " << this->rightEdge << " " << this->bottomEdge;
}

bool PuzzlePiece::lessThan(const PuzzlePiece& p) const{
    return this->getISD() < p.getISD();
}


std::ofstream& operator<<(std::ostream &os, const PuzzlePiece& p){
    p.print(os);
}

bool operator < (const PuzzlePiece& p1, const PuzzlePiece& p2){
    return p1.lessThan(p2);
}
