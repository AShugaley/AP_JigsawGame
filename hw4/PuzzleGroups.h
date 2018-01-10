//
// Created by okleinfeld on 1/10/18.
//

#ifndef AP_JIGSAWGAME_PUZZLEGROUPS_H
#define AP_JIGSAWGAME_PUZZLEGROUPS_H

#include <map>
#include <iostream>
#include "AbstractPuzzlePiece.h"

using namespace std;

template <typename T>
using deref_iter_t = std::remove_reference_t <decltype(*std::declval<T>())>;

template <class Iterator>
class PuzzleGroups{
protected:
    using T = deref_iter_t<Iterator>;
    map<T, vector<T*>> groups;
public:
    PuzzleGroups(Iterator begin, Iterator end);
    void addPairToGroup(pair<T,T*> pair);
    void addPuzzlePiecesToMap(T* piece);
    vector<T*> get(T condition) {
        auto iter = this->groups.find(condition);
        if (iter != this->groups.end())
            return iter->second;
        else
            return vector<T *>();
    }
};

template <class Iterator>
PuzzleGroups<Iterator>::PuzzleGroups(Iterator begin, Iterator end) {
    while (begin != end){
        this->addPuzzlePiecesToMap(&(*begin));
        begin++;
    }
}


template <class Iterator>
void PuzzleGroups<Iterator>::addPairToGroup(pair<T, T*> pair) {
    bool keyExists = this->groups.find(pair.first) != this->groups.end();
    if (keyExists){
        auto& ConditionVector = this->groups[pair.first];
        ConditionVector.push_back(pair.second);
    }
    else{
        this->groups[pair.first] = vector<T*>(1, pair.second);
    }
}

template <class Iterator>
void PuzzleGroups<Iterator>::addPuzzlePiecesToMap(T* piece) {
    vector<T> possibleGroups = piece->getAllPosibleGroups();
    for (auto group : possibleGroups){
        this->addPairToGroup(pair<T, T*>(group, piece));
    }
}

template <class Iterator>
PuzzleGroups<Iterator> groupPuzzlePieces(Iterator begin, Iterator end){
    return PuzzleGroups<Iterator>(begin, end);
}


#endif //AP_JIGSAWGAME_PUZZLEGROUPS_H
