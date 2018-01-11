//
// Created by okleinfeld on 1/10/18.
//

#ifndef AP_JIGSAWGAME_PUZZLE3DPIECE_H
#define AP_JIGSAWGAME_PUZZLE3DPIECE_H

#include "AbstractPuzzlePiece.h"

#define JOKER numeric_limits<int>::min()

template <int K>
class Puzzle3dPiece : public AbstractPuzzlePiece<K>{
private:
    static const unsigned numEdges = 6;
public:
    Puzzle3dPiece(std::initializer_list<int> edges);
    vector<Puzzle3dPiece<K>> getAllPosibleGroups();
};

template <int K>
Puzzle3dPiece<K>::Puzzle3dPiece(std::initializer_list<int> edges) : AbstractPuzzlePiece<K>(edges){
    if (this->edges.size() != 6){
        throw std::invalid_argument("Each Puzzle3d Piece must have exactly 6 edges");
    }
}

template <int K>
vector<Puzzle3dPiece<K>> Puzzle3dPiece<K>::getAllPosibleGroups() {
    unsigned numPossibleGroups = (unsigned) 0x01 << this->numEdges;
    unsigned leftMask = numPossibleGroups >> 1;
    unsigned topMask = numPossibleGroups >> 2;
    unsigned rightMask = numPossibleGroups >> 3;
    unsigned bottomMask = numPossibleGroups >> 4;
    unsigned frontMask = numPossibleGroups >> 5;
    unsigned backMask = numPossibleGroups >> 6;

    int left;
    int top;
    int right;
    int bottom;
    int front;
    int back;

    vector<Puzzle3dPiece<K>> pieceGroup;

    for (unsigned i = 0; i < numPossibleGroups; i++) {
        left = this->edges[0];
        top = this->edges[1];
        right = this->edges[2];
        bottom = this->edges[3];
        front = this->edges[4];
        back = this->edges[5];

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
        if (i & frontMask){
            front = JOKER;
        }
        if (i & backMask){
            back = JOKER;
        }

        pieceGroup.push_back({left, top, right, bottom, front, back});
    }
    return pieceGroup;
}


#endif //AP_JIGSAWGAME_PUZZLE3DPIECE_H
