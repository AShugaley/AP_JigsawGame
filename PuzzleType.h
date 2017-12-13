//
//  PuzzleType.h
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef PuzzleType_h
#define PuzzleType_h

class PuzzleType{
/**
 * Class for representing a puzzle pieces type - determined only by the piece's shape
 * ignoring the piece ID. i.e, different pieces with the same l,t,r,b data will have the same type
 */
protected:
    int l, t, r, b;
public:
    PuzzleType(int l, int t, int r, int b) : l(l), t(t), r(r), b(b){}
    PuzzleType() = default;
    virtual ~PuzzleType() = default;
    int getTop() const {return t;}
    int getLeft() const {return l;}
    int getRight() const {return r;}
    int getBot() const {return b;}
    bool operator==(const PuzzleType& otherType) const ;
    bool operator<(const PuzzleType& otherType) const ;
};

#endif /* PuzzleType_h */
