//
// Created by okleinfeld on 1/10/18.
//

#ifndef AP_JIGSAWGAME_PUZZLEGROUPS_H
#define AP_JIGSAWGAME_PUZZLEGROUPS_H

#include <map>
#include <iostream>
#include "AbstractPuzzlePiece.h"
#include <algorithm>

using namespace std;

template <typename T>
using deref_iter_t = std::remove_reference_t <decltype(*std::declval<T>())>;

template <class Iterator>
class PuzzleGroups{
protected:
    using T = deref_iter_t<Iterator>;
    map<T, vector<T*>> groups;
public:
    PuzzleGroups(Iterator begin, Iterator end, bool rotate);
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
PuzzleGroups<Iterator>::PuzzleGroups(Iterator begin, Iterator end, bool rotate) {
    while (begin != end){
        auto piece = &(*begin);
        if(!rotate){
            this->addPuzzlePiecesToMap(piece);
        }
        else{
            vector<vector<int> > shapes;
            for(unsigned i = 0; i< piece->numEdges; i++){
                piece->rotate();
                if(!(std::find(shapes.begin(), shapes.end(), piece->edges) != shapes.end())) {
                    shapes.push_back(piece->edges);
                    this->addPuzzlePiecesToMap(piece);
                }
            }
        }
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
    return PuzzleGroups<Iterator>(begin, end, false);
}

template <class Iterator>
PuzzleGroups<Iterator> groupPuzzlePiecesWithRotate(Iterator begin, Iterator end){
    return PuzzleGroups<Iterator>(begin, end, true);
}



#endif //AP_JIGSAWGAME_PUZZLEGROUPS_H
