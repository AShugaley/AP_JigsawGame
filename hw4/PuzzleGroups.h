//
// Created by okleinfeld on 1/10/18.
//

#ifndef AP_JIGSAWGAME_PUZZLEGROUPS_H
#define AP_JIGSAWGAME_PUZZLEGROUPS_H

#include <map>
#include "PuzzleCondition.h"
#include "Puzzle2dPiece.h"

using namespace std;

template <int K, class Iterator>
class PuzzleGroups{
private:
    map<PuzzleCondition<K>, vector<Puzzle2dPiece<K>* > > groups;
public:
    PuzzleGroups(Iterator begin, Iterator end);
    void addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K>*> pair);
    void addPuzzlePiecesToMap(Puzzle2dPiece<K>* piece);
};

template <int K, class Iterator>
PuzzleGroups<K, Iterator>::PuzzleGroups(Iterator begin, Iterator end){
    while (begin != end){
        Puzzle2dPiece<K>* piece = &(*begin);
        PuzzleCondition<K> cond = {piece->edges[0], piece->edges[1], piece->edges[2], piece->edges[3]};
        this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

//        cout << *piece << endl;
        begin++;
    }
};

template <int K, class Iterator>
void PuzzleGroups<K, Iterator>::addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *> pair) {
    bool keyExists = this->groups.find(pair.first) != this->groups.end();
    if (keyExists){
        auto& vectorValue = this->groups[pair.first];
        vectorValue.push_back(pair.second);
    }
    else{
        this->groups[pair.first] = vector<Puzzle2dPiece<K> *>(1, pair.second);
    }
}

template <int K, class Iterator>
void PuzzleGroups<K, Iterator>::addPuzzlePiecesToMap(Puzzle2dPiece<K>* piece){
    PuzzleCondition<K> cond;

    // Exact condition
    cond = {piece->edges[0], piece->edges[1], piece->edges[2], piece->edges[3]};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    // Joker on 1 edge - 4 options
    cond = {numeric_limits::min(), piece->edges[1], piece->edges[2], piece->edges[3]};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    cond = {piece->edges[0], numeric_limits::min(), piece->edges[2], piece->edges[3]};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    cond = {piece->edges[0], piece->edges[1], numeric_limits::min(), piece->edges[3]};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    cond = {piece->edges[0], piece->edges[1], piece->edges[2], numeric_limits::min()};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    // Joker on 2 edges - 6 options


    // Joker on 3 edges - 4 options

    


    // Joker on 4 edges - 1 option

    cond = {numeric_limits::min(), numeric_limits::min(), numeric_limits::min(), numeric_limits::min()};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));
};


#endif //AP_JIGSAWGAME_PUZZLEGROUPS_H
