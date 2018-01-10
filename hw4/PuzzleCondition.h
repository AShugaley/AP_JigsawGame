//
// Created by okleinfeld on 1/10/18.
//

#ifndef AP_JIGSAWGAME_PUZZLECONDITION_H
#define AP_JIGSAWGAME_PUZZLECONDITION_H

#include "BoundedIntCondition.h"
#include <vector>

using namespace std;

template <int K>
class PuzzleCondition {
private:
    vector<BoundedIntCondition<-K, K>> edges;
public:
    PuzzleCondition() = default;
    PuzzleCondition(std::initializer_list<int> edges);
//    PuzzleCondition<K>& operator=(const PuzzleCondition<K>& otherCond);
//    PuzzleCondition<K>& operator=(std::initializer_list<int> edges);
    bool operator <(const PuzzleCondition& cond) const;

};


template <int K>
PuzzleCondition<K>::PuzzleCondition(std::initializer_list<int> edges) {
    int numEdges = 0;
    for (auto& e : edges) {
        this->edges.emplace_back(e);
        numEdges++;
    }
    if (numEdges != 4){
        throw std::invalid_argument("Each Puzzle Condition must have exactly 4 edges/conditions");
    }
}

template <int K>
bool PuzzleCondition<K>::operator<(const PuzzleCondition<K>& cond) const{
    if (this->edges[0] != cond.edges[0]){
        return this->edges[0] < cond.edges[0];
    }
    if (this->edges[1] != cond.edges[1]){
        return this->edges[1] < cond.edges[1];
    }
    if (this->edges[2] != cond.edges[2]){
        return this->edges[2] < cond.edges[2];
    }
    return this->edges[3] < cond.edges[3];
}

//template <int K>
//PuzzleCondition<K>& PuzzleCondition<K>::operator=(const PuzzleCondition<K>& otherCond){
//    this->edges[0] = otherCond.edges[0];
//    this->edges[1] = otherCond.edges[1];
//    this->edges[2] = otherCond.edges[2];
//    this->edges[3] = otherCond.edges[3];
//    return *this;
//}
//
//template <int K>
//PuzzleCondition<K>& PuzzleCondition<K>::operator=(std::initializer_list<int> edges){
//    PuzzleCondition<K> tmpPuzzleCond(edges);
//    this->edges[0] = tmpPuzzleCond.edges[0];
//    this->edges[1] = tmpPuzzleCond.edges[1];
//    this->edges[2] = tmpPuzzleCond.edges[2];
//    this->edges[3] = tmpPuzzleCond.edges[3];
//    return *this;
//}


#endif //AP_JIGSAWGAME_PUZZLECONDITION_H
