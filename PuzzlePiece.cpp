//
// Created by okleinfeld on 11/15/17.
//

#include "PuzzlePiece.h"

PuzzlePiece::PuzzlePiece(const int ISD, int l, int t, int r, int b) :
ISD(ISD), leftEdge(l), topEdge(t), rightEdge(r), bottomEdge(b), origLeftEdge(l), origTopEdge(t), origRightEdge(r),origBottomEdge(b), rotateAngle(0), used(false) {}

PuzzlePiece:: PuzzlePiece(){;}


void PuzzlePiece::print(std::ostream &os) const{
    os << this->ISD << " " << this->leftEdge << " " << this->topEdge << " " << this->rightEdge << " " << this->bottomEdge;
}


bool PuzzlePiece::lessThan(const PuzzlePiece& p) const{
    return this->getISD() < p.getISD();
}


void operator<<(std::ostream &os, const PuzzlePiece& p){
    p.print(os);
}

bool operator < (const PuzzlePiece& p1, const PuzzlePiece& p2){
    return p1.lessThan(p2);
}

void PuzzlePiece::rotate(){
    if(rotateAngle == 270)
        rotateAngle = 0;
    else
        rotateAngle+= 90;
    int temp = topEdge;
    topEdge = leftEdge;
    leftEdge = bottomEdge;
    bottomEdge = rightEdge;
    rightEdge = temp;
    
}
