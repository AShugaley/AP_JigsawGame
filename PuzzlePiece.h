//
// Created by okleinfeld on 12/15/17.
//

#ifndef AP_JIGSAWGAME_ABSTRACTPUZZLEPIECE_H
#define AP_JIGSAWGAME_ABSTRACTPUZZLEPIECE_H

#include <string>
#include <iostream>

class PuzzlePiece {
protected:
    int ISD;
    int leftEdge, topEdge, rightEdge, bottomEdge;
    bool used;

public:
    //constructors and destructor
    PuzzlePiece(int ISD, int l, int t, int r, int b);
    PuzzlePiece(const PuzzlePiece& otherPiece);
    virtual ~PuzzlePiece() = default;

    //getters
    int getISD() const;
    int getLeftEdge() const;
    int getTopEdge() const;
    int getRightEdge() const;
    int getBottomEdge() const;
    bool isUsed()const ;

    //queries functions
    virtual bool isTopLeftCorner();
    virtual bool isTopRightCorner();
    virtual bool isBotLeftCorner();
    virtual bool isBotRightCorner();
    virtual int countStraightEdges();
    virtual int edgesSum();

    //Setters and operations
    void setUsed(bool newUsedStatus);
    virtual void print(std::ostream &os) const;
    virtual bool lessThan(const PuzzlePiece &p) const;

    // override output stream (print) operator
    friend void operator<<(std::ostream &os, const PuzzlePiece& p);
    friend bool operator<(const PuzzlePiece& p1, const PuzzlePiece& p2);

};


#endif //AP_JIGSAWGAME_ABSTRACTPUZZLEPIECE_H
