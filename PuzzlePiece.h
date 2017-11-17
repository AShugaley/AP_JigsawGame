//
// Created by okleinfeld on 11/15/17.
//

#ifndef ADVANCEDOOP_HW1_PUZZLEPIECE_H
#define ADVANCEDOOP_HW1_PUZZLEPIECE_H

#include <string>
#include <iostream>

class PuzzlePiece {
    int ISD;
    int leftEdge;
    int topEdge;
    int rightEdge;
    int bottomEdge;

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
    virtual bool isTopLeftCorner() const;
};

std::ofstream& operator<<(std::ostream &os, const PuzzlePiece& p);
bool operator < (const PuzzlePiece& p1, const PuzzlePiece& p2);


#endif //ADVANCEDOOP_HW1_PUZZLEPIECE_H
