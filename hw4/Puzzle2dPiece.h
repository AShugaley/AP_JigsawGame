//
// Created by okleinfeld on 1/10/18.
//

#ifndef AP_JIGSAWGAME_PUZZLE2DPIECE_H
#define AP_JIGSAWGAME_PUZZLE2DPIECE_H

#include "AbstractPuzzlePiece.h"

#define JOKER numeric_limits<int>::min()

template <int K>
class Puzzle2dPiece : public AbstractPuzzlePiece<K>{
private:
    static const unsigned numEdges = 4;
public:
    Puzzle2dPiece(std::initializer_list<int> edges);
    vector<Puzzle2dPiece<K>> getAllPosibleGroups();
};

template <int K>
Puzzle2dPiece<K>::Puzzle2dPiece(std::initializer_list<int> edges) : AbstractPuzzlePiece<K>(edges){
    if (this->edges.size() != 4){
        throw std::invalid_argument("Each Puzzle2d Piece must have exactly 4 edges");
    }
}

template <int K>
vector<Puzzle2dPiece<K>> Puzzle2dPiece<K>::getAllPosibleGroups() {
    unsigned numPossibleGroups = (unsigned) 0x01 << this->numEdges;
    unsigned leftMask = numPossibleGroups >> 1;
    unsigned topMask = numPossibleGroups >> 2;
    unsigned rightMask = numPossibleGroups >> 3;
    unsigned bottomMask = numPossibleGroups >> 4;

    int left;
    int top;
    int right;
    int bottom;

    vector<Puzzle2dPiece<K>> pieceGroup;

    for (unsigned i = 0; i < numPossibleGroups; i++) {
        left = this->edges[0];
        top = this->edges[1];
        right = this->edges[2];
        bottom = this->edges[3];

        if (i & leftMask) {
            left = JOKER;
        }
        if (i & topMask) {
            top = JOKER;
        }
        if (i & rightMask) {
            right = JOKER;
        }
        if (i & bottomMask) {
            bottom = JOKER;
        }

        pieceGroup.push_back({left, top, right, bottom});
    }
    return pieceGroup;
}



#endif //AP_JIGSAWGAME_PUZZLE2DPIECE_H
