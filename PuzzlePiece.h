//
// Created by okleinfeld on 11/15/17.
//

#ifndef ADVANCEDOOP_HW1_PUZZLEPIECE_H
#define ADVANCEDOOP_HW1_PUZZLEPIECE_H

#include <string>
#include <iostream>

class PuzzlePiece {
    int ISD;
    int leftEdge, topEdge, rightEdge, bottomEdge;
    int rotateAngle;
    bool used;

public:
    //constructors
    PuzzlePiece(int ISD, int l, int t, int r, int b);

    //getters
    int getISD() const {return this->ISD;}
    int getAngle() const {return this->rotateAngle;}
    int getLeftEdge() const {return this->leftEdge;}
    int getTopEdge() const {return this->topEdge;}
    int getRightEdge() const {return this->rightEdge;}
    int getBottomEdge() const {return this->bottomEdge;}
    bool isUsed() const {return used;};

    //Setters and operations
    void rotate(); //rotates 90 degrees clockwise
    void setUsed(bool newUsedStatus) {used = newUsedStatus;};
    virtual void print(std::ostream &os) const;
    virtual bool lessThan(const PuzzlePiece& p) const;

    //checks about the element
    bool isTopLeftCorner(){ return ((leftEdge == 0)&&(topEdge == 0));}
    bool isTopRightCorner(){ return ((rightEdge == 0)&&(topEdge == 0));}
    bool isBotLeftCorner(){ return ((leftEdge == 0)&&(bottomEdge == 0));}
    bool isBotRightCorner(){ return ((rightEdge == 0)&&(bottomEdge == 0));}
    int countStraightEdges(){return (leftEdge==0) + (topEdge==0) + (rightEdge==0) + (bottomEdge==0);}
    int sumEdges(){ return leftEdge + rightEdge + topEdge + bottomEdge;}


void operator<<(std::ostream &os, const PuzzlePiece& p);
bool operator<(const PuzzlePiece& p1, const PuzzlePiece& p2);


#endif //ADVANCEDOOP_HW1_PUZZLEPIECE_H
