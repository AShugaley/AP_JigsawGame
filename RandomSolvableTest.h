//
// Created by okleinfeld on 12/13/17.
//

#ifndef AP_JIGSAWGAME_RANDOMSOLVABLETEST_H
#define AP_JIGSAWGAME_RANDOMSOLVABLETEST_H

#include <ctime>
#include <random>
#include <chrono>
#include "PuzzlePiece.h"
#include "JigsawPuzzleRotations.h"
#include "SolutionAlgorithm.h"
#include "JigsawParser.h"
#include "SolutionAlgorithm.h"
#include "Factory.h"

using namespace std;


class RandomSolvableTest {
private:
    vector<PuzzlePiece> puzzlePieces;
    void generateRandomPuzzle(int x, int y);
public:
    RandomSolvableTest(int x, int y);
    bool solvePuzzle();
    static void runRandomTests(int x, int y, int numOfTests);
};



#endif //AP_JIGSAWGAME_RANDOMSOLVABLETEST_H
