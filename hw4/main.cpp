#include <iostream>
#include <list>
#include <vector>
#include "Puzzle2dPiece.h"
#include "Puzzle3dPiece.h"
#include "PuzzleGroups.h"

using namespace std;

int main() {
//    list<Puzzle2dPiece<5>> pieces = {{0, 3, 2, -5}, {0, -2, 2, -5}};
//    auto groups = groupPuzzlePieces(pieces.begin(), pieces.end());
//    auto some_pieces = groups.get({0, 3, 2, numeric_limits<int>::min()});
//    for (auto piece_ptr : some_pieces){
//        cout << *piece_ptr << endl;
//    }
    auto joker = numeric_limits<int>::min();
    list<Puzzle3dPiece<1>> pieces = {{0, 1, 1, 1, -1, -1}, {0, -1, 1, 1, 1, 1}};
    auto groups = groupPuzzlePieces(pieces.begin(), pieces.end());
    auto some_pieces = groups.get({0, joker, 1, 1, joker, joker});
    for (auto piece_ptr : some_pieces){
        cout << *piece_ptr << endl;
    }
    return 0;
}