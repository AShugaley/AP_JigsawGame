#include <iostream>
#include "JigsawPuzzle.h"

using namespace std;

int main() {
    PuzzleMatrix mat(64);
    PuzzlePiece p(1, 0, 0, 0, 0);
    mat.add(0, 5, p);
    PuzzlePiece j = mat.get(0, 5);
    cout << j;
//    string path = "test_files/input_can_solve.txt";
//    JigsawPuzzle p(path);
//    p.solveGame();
//    auto *p = new PuzzlePiece(1, 0 ,0 ,0, 0);
//    cout << *p << endl;
    return 0;
}