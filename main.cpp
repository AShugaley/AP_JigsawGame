#include <iostream>
#include "JigsawPuzzle.h"

using namespace std;

int main() {
    string path = "test_files/input_can_solve.txt";
    JigsawPuzzle p(path);
    p.solveGame();
//    auto *p = new PuzzlePiece(1, 0 ,0 ,0, 0);
//    cout << *p << endl;
    return 0;
}