//
// Created by okleinfeld on 12/15/17.
//

#include "PuzzlePiece.h"


PuzzlePiece::PuzzlePiece(int ISD, int l, int t, int r, int b) :
        ISD(ISD), leftEdge(l), topEdge(t), rightEdge(r), bottomEdge(b), used(false), rotationAngle(0){}

PuzzlePiece::PuzzlePiece(const PuzzlePiece& otherPiece){
    this->ISD = otherPiece.ISD;
    this->leftEdge = otherPiece.leftEdge;
    this->topEdge = otherPiece.topEdge;
    this->rightEdge = otherPiece.rightEdge;
    this->bottomEdge = otherPiece.bottomEdge;
    this->used = otherPiece.used;
    this->rotationAngle = otherPiece.rotationAngle;
}

int PuzzlePiece::getISD() const {
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

bool PuzzlePiece::isUsed() const {
    return used;
}

void PuzzlePiece::setUsed(bool newUsedStatus) {
    used = newUsedStatus;
}

void PuzzlePiece::print(std::ostream &os) const{
    os << this->ISD << " " << this->leftEdge << " " << this->topEdge << " " << this->rightEdge << " " << this->bottomEdge;
}

bool PuzzlePiece::lessThan(const PuzzlePiece& p) const{
    return this->getISD() < p.getISD();
}

bool PuzzlePiece::isTopLeftCorner(){
    return leftEdge == 0 && topEdge == 0;
}
bool PuzzlePiece::isTopRightCorner() {
    return rightEdge == 0 && topEdge == 0;
}
bool PuzzlePiece::isBotLeftCorner() {
    return leftEdge == 0 && bottomEdge == 0;
}
bool PuzzlePiece::isBotRightCorner(){
    return rightEdge == 0 && bottomEdge == 0;
}
int PuzzlePiece::countStraightEdges(){
    return (leftEdge == 0) + (topEdge == 0) + (rightEdge == 0) + (bottomEdge == 0);
}
int PuzzlePiece::edgesSum(){
    return leftEdge + rightEdge + topEdge + bottomEdge;
}

void PuzzlePiece::rotate(){
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

void PuzzlePiece::resetAngle(){
    while(this->rotationAngle != 0)
        rotate();
}

void operator<<(std::ostream &os, const PuzzlePiece& p){
    p.print(os);
}

bool operator < (const PuzzlePiece& p1, const PuzzlePiece& p2){
    return p1.lessThan(p2);
}
