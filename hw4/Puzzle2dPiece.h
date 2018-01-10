//
// Created by okleinfeld on 1/10/18.
//

#ifndef PUZZLETEMPLATE_PUZZLE2DPIECE_H
#define PUZZLETEMPLATE_PUZZLE2DPIECE_H

#include "BoundedInt.h"
#include <vector>
#include <ostream>

template <int K>
class Puzzle2dPiece{
private:
    std::vector<BoundedInt<-K,K>> edges;
public:
    Puzzle2dPiece(std::initializer_list<int> edges);
    template <int K_val>
    friend std::ostream& operator << (std::ostream& os, const Puzzle2dPiece<K_val>& piece);
};

template <int K>
Puzzle2dPiece<K>::Puzzle2dPiece(std::initializer_list<int> edges) {
    int numEdges = 0;
    for (auto& e : edges) {
        this->edges.emplace_back(e);
        numEdges++;
    }
    if (numEdges != 4){
        throw std::invalid_argument("Each Puzzle2d Piece must have exactly 4 edges");
    }
}

template <int K>
std::ostream& operator << (std::ostream& os, const Puzzle2dPiece<K>& piece){
    os << "(" << piece.edges[0] << ", " << piece.edges[1] << ", " << piece.edges[2] << ", " << piece.edges[3] << ")";
    return os;
}


#endif //PUZZLETEMPLATE_PUZZLE2DPIECE_H
