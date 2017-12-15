//
// Created by okleinfeld on 11/15/17.
//

#ifndef ADVANCEDOOP_HW1_PUZZLEPIECE_H
#define ADVANCEDOOP_HW1_PUZZLEPIECE_H

#include <string>
#include <iostream>

class PuzzlePiece {
protected:
    int ISD;
    int leftEdge, topEdge, rightEdge, bottomEdge;
    int rotateAngle;
    bool used;

public:
    //constructors
    PuzzlePiece(int ISD, int l, int t, int r, int b);
    PuzzlePiece(const PuzzlePiece& otherPiece);

    //getters
    int getISD() const;
    int getLeftEdge() const;
    int getTopEdge() const;
    int getRightEdge() const;
    int getBottomEdge() const;
    int getAngle() const;
    bool isUsed()const ;

    //Setters and operations
    void rotate(); //rotates 90 degrees clockwise
    void setUsed(bool newUsedStatus);
    void resetAngle();

    // defined to enable ths use of polymorphism in global operators - "<<" and "<"
    // in this way we can override this functions in sub class and the global operations will use the correct implementation
    virtual void print(std::ostream &os) const;
    virtual bool lessThan(const PuzzlePiece &p) const;

    //queries functions
    bool isTopLeftCorner();
    bool isTopRightCorner();
    bool isBotLeftCorner();
    bool isBotRightCorner();
    int countStraightEdges();
    int edgesSum();

};

// override output stream (print) operator
void operator<<(std::ostream &os, const PuzzlePiece& p);
bool operator<(const PuzzlePiece& p1, const PuzzlePiece& p2);


#endif //ADVANCEDOOP_HW1_PUZZLEPIECE_H
