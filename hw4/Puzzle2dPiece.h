//
// Created by okleinfeld on 1/10/18.
//

#ifndef AP_JIGSAWGAME_PUZZLE2DPIECE_H
#define AP_JIGSAWGAME_PUZZLE2DPIECE_H

#include "AbstractPuzzlePiece.h"

#define JOKER numeric_limits<int>::min()

template <int K>
class Puzzle2dPiece : public AbstractPuzzlePiece<K>{
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
    int left = this->edges[0];
    int top = this->edges[1];
    int right = this->edges[2];
    int bottom = this->edges[3];

    vector<Puzzle2dPiece<K>> pieceGroup;

    // Exact condition
    pieceGroup.push_back({left, top, right, bottom});

    // Joker on 1 edge - 4 options
    pieceGroup.push_back({JOKER, top, right, bottom});
    pieceGroup.push_back({left, JOKER, right, bottom});
    pieceGroup.push_back({left, top, JOKER, bottom});
    pieceGroup.push_back({left, top, right, JOKER});

    // Joker on 2 edges - 6 options
    pieceGroup.push_back({JOKER, JOKER, right, bottom});
    pieceGroup.push_back({JOKER, top, JOKER, bottom});
    pieceGroup.push_back({JOKER, top, right, JOKER});
    pieceGroup.push_back({left, JOKER, JOKER, bottom});
    pieceGroup.push_back({left, JOKER, right, JOKER});
    pieceGroup.push_back({left, top, JOKER, JOKER});

    // Joker on 3 edges - 4 options
    pieceGroup.push_back({JOKER, JOKER, JOKER, bottom});
    pieceGroup.push_back({left, JOKER, JOKER, JOKER});
    pieceGroup.push_back({JOKER, top, JOKER, JOKER});
    pieceGroup.push_back({JOKER, JOKER, right, JOKER});

    // Joker on 4 edges - 1 option
    pieceGroup.push_back({JOKER, JOKER, JOKER, JOKER});

    return pieceGroup;
}


#endif //AP_JIGSAWGAME_PUZZLE2DPIECE_H
