//
// Created by okleinfeld on 12/15/17.
//

#ifndef AP_JIGSAWGAME_ABSTRACTPUZZLETYPE_H
#define AP_JIGSAWGAME_ABSTRACTPUZZLETYPE_H


class PuzzleType {
/**
 * Class for representing a puzzle pieces type - determined only by the piece's shape
 * ignoring the piece ID. i.e, different pieces with the same l,t,r,b data will have the same type
 * always includes only expilicit numbers (-1,0,1), without JOKERS (*)
 */
protected:
    int l, t, r, b; //left, top, right, bot
public:
    // constructors and destructor
    PuzzleType(int l, int t, int r, int b);
    PuzzleType() = default;
    virtual ~PuzzleType() = default;

    // getters
    int getTop() const;
    int getLeft() const;
    int getRight() const;
    int getBot() const;

    // operations
    bool operator==(const PuzzleType& otherType) const ;
    bool operator<(const PuzzleType& otherType) const ;
};


#endif //AP_JIGSAWGAME_ABSTRACTPUZZLETYPE_H
