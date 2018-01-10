#include <iostream>
#include <list>
#include "Puzzle2dPiece.h"

using namespace std;

int main() {
//    BoundedInt<-3,3> i(2);
//    int j = i;
//    cout << j << endl;
//    cout << i << endl;
    Puzzle2dPiece<5> piece = {1,2,3,0};
    for (auto& e : piece){
        cout << e << endl;
    }
//    cout << piece << endl;
//    list<Puzzle2dPiece<5>> pieces = {{0, 3, 2, -5}, {0, -2, 2, -5}};
//    for (auto& p : pieces){
//        cout << p << endl;
//    }
    return 0;
}