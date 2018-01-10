//
// Created by okleinfeld on 1/10/18.
//

#ifndef PUZZLETEMPLATE_PUZZLE2DPIECE_H
#define PUZZLETEMPLATE_PUZZLE2DPIECE_H

#include "BoundedInt.h"
#include <vector>
#include <ostream>

using namespace std;

template <int K>
class Puzzle2dPiece{
public:
    vector<BoundedInt<-K,K>> edges;
    Puzzle2dPiece(std::initializer_list<int> edges);
    const typename vector<BoundedInt<-K,K> >::iterator begin() {return this->edges.begin();}
    const typename vector<BoundedInt<-K,K> >::iterator end() {return this->edges.end();}

    template <int K_val>
    friend ostream& operator << (ostream& os, const Puzzle2dPiece<K_val>& piece);
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
std::ostream& operator << (ostream& os, const Puzzle2dPiece<K>& piece){
    os << "(" << piece.edges[0] << ", " << piece.edges[1] << ", " << piece.edges[2] << ", " << piece.edges[3] << ")";
    return os;
}



#endif //PUZZLETEMPLATE_PUZZLE2DPIECE_H
