//
// Created by okleinfeld on 1/10/18.
//

#ifndef AP_JIGSAWGAME_PUZZLEGROUPS_H
#define AP_JIGSAWGAME_PUZZLEGROUPS_H

#include <map>
#include "PuzzleCondition.h"
#include "Puzzle2dPiece.h"

#define JOKER numeric_limits<int>::min()

using namespace std;

template <int K, class Iterator>
class PuzzleGroups{
private:
    map<PuzzleCondition<K>, vector<Puzzle2dPiece<K>* > > groups;
public:
    PuzzleGroups(Iterator begin, Iterator end);
    void addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K>*> pair);
    void addPuzzlePiecesToMap(Puzzle2dPiece<K>* piece);
    vector<Puzzle2dPiece<K>*> get(PuzzleCondition<K> condition);
};

template <int K, class Iterator>
PuzzleGroups<K, Iterator>::PuzzleGroups(Iterator begin, Iterator end){
    while (begin != end){
        Puzzle2dPiece<K>* piece = &(*begin);
        this->addPuzzlePiecesToMap(piece);
//        PuzzleCondition<K> cond = {piece->edges[0], piece->edges[1], piece->edges[2], piece->edges[3]};
//        this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));
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
    cond = {JOKER, piece->edges[1], piece->edges[2], piece->edges[3]};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    cond = {piece->edges[0], JOKER, piece->edges[2], piece->edges[3]};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    cond = {piece->edges[0], piece->edges[1], JOKER, piece->edges[3]};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    cond = {piece->edges[0], piece->edges[1], piece->edges[2],JOKER};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    // Joker on 2 edges - 6 options

    cond = {JOKER, JOKER, piece->edges[2], piece->edges[3]};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    cond = {JOKER, piece->edges[1], JOKER, piece->edges[3]};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    cond = {JOKER, piece->edges[1], piece->edges[2], JOKER};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    cond = {piece->edges[0], JOKER, JOKER, piece->edges[3]};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    cond = {piece->edges[0], JOKER, piece->edges[2], JOKER};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    cond = {piece->edges[0], piece->edges[1], JOKER, JOKER};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    // Joker on 3 edges - 4 options

    cond = {JOKER, JOKER, JOKER, piece->edges[3]};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    cond = {piece->edges[0],JOKER, JOKER, JOKER};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    cond = {JOKER, piece->edges[1], JOKER, JOKER};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    cond = {JOKER, JOKER, piece->edges[2], JOKER};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));

    // Joker on 4 edges - 1 option

    cond = {JOKER, JOKER, JOKER, JOKER};
    this->addPairToGroup(pair<PuzzleCondition<K>, Puzzle2dPiece<K> *>(cond, piece));
};

template <int K, class Iterator>
vector<Puzzle2dPiece<K>*> PuzzleGroups<K, Iterator>::get(PuzzleCondition<K> condition){
    auto iter = this->groups.find(condition);
    if (iter != this->groups.end()) {
        return iter->second;
    }
    else{
        return vector<Puzzle2dPiece<K>*>();
    }
}

template <int K, class Iterator>
PuzzleGroups<K, Iterator> groupPuzzlePieces(Iterator begin, Iterator end){
    return PuzzleGroups(begin, end);
};


#endif //AP_JIGSAWGAME_PUZZLEGROUPS_H
