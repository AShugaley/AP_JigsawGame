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

public:
    PuzzlePiece(int ISD, int l, int t, int r, int b);
    PuzzlePiece();
    const int getISD() const;
    int getLeftEdge() const;
    int getTopEdge() const;
    int getRightEdge() const;
    int getBottomEdge() const;
    
    virtual void print(std::ostream &os) const;
    virtual bool lessThan(const PuzzlePiece& p) const;
    
    bool isTopLeftCorner(){ return ((leftEdge == 0)&&(topEdge == 0));}
    bool isTopRightCorner(){ return ((rightEdge == 0)&&(topEdge == 0));}
    bool isBotLeftCorner(){ return ((leftEdge == 0)&&(bottomEdge == 0));}
    bool isBotRightCorner(){ return ((rightEdge == 0)&&(bottomEdge == 0));}
    int countStraightEdges(){return (leftEdge==0) + (topEdge==0) + (rightEdge==0) + (bottomEdge==0);}
    int sumEdges(){ return leftEdge + rightEdge + topEdge + bottomEdge;}

};

std::ofstream& operator<<(std::ostream &os, const PuzzlePiece& p);
bool operator < (const PuzzlePiece& p1, const PuzzlePiece& p2);


#endif //ADVANCEDOOP_HW1_PUZZLEPIECE_H
