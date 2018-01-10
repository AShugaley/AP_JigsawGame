//
// Created by okleinfeld on 1/10/18.
//

#ifndef AP_JIGSAWGAME_ABSTRACTPUZZLEPIECE_H
#define AP_JIGSAWGAME_ABSTRACTPUZZLEPIECE_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

template <int K>
class AbstractPuzzlePiece{
protected:
    vector<int> edges;
public:
    AbstractPuzzlePiece() = default;
    AbstractPuzzlePiece(std::initializer_list<int> edgesList);
    virtual ~AbstractPuzzlePiece() = default;
    const typename vector<int>::iterator begin() {return this->edges.begin();}
    const typename vector<int>::iterator end() {return this->edges.end();}
    virtual void print(ostream& os) const;
    virtual bool operator<(const AbstractPuzzlePiece<K> otherPiece) const;

    template <int K_val>
    friend ostream& operator << (ostream& os, const AbstractPuzzlePiece<K_val>& piece);
};

template <int K>
AbstractPuzzlePiece<K>::AbstractPuzzlePiece(std::initializer_list<int> edgesList) {
    int numEdges = 0;
    for (auto& e : edgesList) {
        if ((e > K || e < -K) && e != numeric_limits<int>::min()) {
            throw std::invalid_argument("Each edge value must by in range[-K,K]");
        }
        this->edges.emplace_back(e);
        numEdges++;
    }
}

template <int K>
void AbstractPuzzlePiece<K>::print(ostream &os) const {
    os << "(";
    int index = 0;
    for (auto& edge : this->edges){
        if (index == 0){
            os << edge;
        }
        else{
            os << "," << edge;
        }
        index++;
    }
    os << ")";
}

template <int K>
bool AbstractPuzzlePiece<K>::operator<(const AbstractPuzzlePiece<K> otherPiece) const {
    int numEdges = (int) otherPiece.edges.size();
    for (int i = 0; i < numEdges; i++){
        auto thisEdge = this->edges[i];
        auto otherEdge = otherPiece.edges[i];
        if (thisEdge != otherEdge){
            return thisEdge < otherEdge;
        }
    }
    return this->edges[numEdges-1] < otherPiece.edges[numEdges-1];
}

template <int K>
std::ostream& operator << (ostream& os, const AbstractPuzzlePiece<K>& piece){
    piece.print(os);
    return os;
}




#endif //AP_JIGSAWGAME_ABSTRACTPUZZLEPIECE_H
