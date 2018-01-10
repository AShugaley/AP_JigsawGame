#include <iostream>
#include <map>
#include <list>
#include "Puzzle2dPiece.h"
#include "PuzzleCondition.h"
#include "PuzzleGroups.h"

using namespace std;

int main() {
    list<Puzzle2dPiece<5>> pieces = {{0, 3, 2, -5}, {0, -2, 2, -5}};
    auto groups = groupPuzzlePieces(pieces.begin(), pieces.end());
//    PuzzleGroups<5, list<Puzzle2dPiece<5>>::iterator> pGroup (pieces.begin(), pieces.end());
//    auto piecesCondition = pGroup.get({0, 3, JOKER, JOKER});
//    for (auto piece_ptr : piecesCondition){
//        cout << *piece_ptr << endl;
    }
//    map<PuzzleCondition<3>, int> groups;
//    groups[{1,1,1,1}] = 5;
//    bool a = groups.find({1,1,1,1}) == groups.end();
//    cout << a << endl;
//    vector<Puzzle2dPiece<3>*> v;
//    vector<Puzzle2dPiece<3>> k(1,{1,1,1,1});
//    for (auto& p : k){
//        cout << p << endl;
//    }
//    groups.find({1,1,1,1});
//    BoundedInt<-3,3> i(2);
//    BoundedInt<-3,3> k;
//    BoundedIntCondition<-4,4> l(std::numeric_limits<int>::min());
//    cout << l << endl;
//    int j = i;
//    cout << j << endl;
//    cout << i << endl;
//    Puzzle2dPiece<5> piece = {1,2,3,0};
//    for (auto& e : piece){
//        cout << e << endl;
//    }
//    cout << piece << endl;
//    for (auto& p : pieces){
//        cout << p << endl;
//    }
//    PuzzleCondition<5> c = {numeric_limits<int>::min(), -2, 3, 3};
    return 0;
}