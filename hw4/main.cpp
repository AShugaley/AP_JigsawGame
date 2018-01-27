
#include "ex4headers.h"

using namespace std;



/*
 #####################
 COMPILATION COMMAND: 
 g++ -std=c++14 -Wall -Wextra -Werror -pedantic-errors -DNDEBUG main.cpp -o hw4_main
 #####################
 */
 
 
int main() {
    auto joker = numeric_limits<int>::min();
    list<Puzzle3dPiece<5>> pieces = {{1, 1, 1, 1,1,1}, {0, 1, 1, 1,1,1}};
    auto groups = groupPuzzlePiecesWithRotate(pieces.begin(), pieces.end());
    auto some_pieces = groups.get({1, 1, 1, 1,joker,1});
    for (auto piece_ptr : some_pieces){
        cout << *piece_ptr << endl;
    }
    
    
    
    list<Puzzle3dPiece<5>> pieces2 = {{1, 1, 1, 1,1,1}, {0, 1, 1, 1,1,1}};
    auto groups2 = groupPuzzlePiecesWithRotate(pieces2.begin(), pieces2.end());
    auto some_pieces2 = groups2.get({1, 0, 1, 1,1,1});
    for (auto piece_ptr : some_pieces2){
        cout << *piece_ptr << endl;
    }
    
    list<Puzzle2dPiece<5>> pieces3 = {{1, 1, 1, 1}, {0, 1, 1, 1}};
    auto groups3 = groupPuzzlePiecesWithRotate(pieces3.begin(), pieces3.end());
    auto some_pieces3 = groups3.get({1, 1, 0, 1});
    for (auto piece_ptr : some_pieces3){
        cout << *piece_ptr << endl;
    }
    
    
    list<Puzzle2dPiece<5>> pieces4 = {{1, 1, 1, 1}, {0, 1, 1, 1}};
    auto groups4 = groupPuzzlePiecesWithRotate(pieces4.begin(), pieces4.end());
    auto some_pieces4 = groups4.get({1, 1, 1, 1});
    for (auto piece_ptr : some_pieces4){
        cout << *piece_ptr << endl;
    }
    
    
    
//    auto joker = numeric_limits<int>::min();
//    list<Puzzle3dPiece<1>> pieces = {{0, 1, 1, 1, -1, -1}, {0, -1, 1, 1, 1, 1}};
//    auto groups = groupPuzzlePieces(pieces.begin(), pieces.end());
//    auto some_pieces = groups.get({0, joker, 1, 1, joker, joker});
//    for (auto piece_ptr : some_pieces){
//        cout << *piece_ptr << endl;
//    }
    return 0;
}
