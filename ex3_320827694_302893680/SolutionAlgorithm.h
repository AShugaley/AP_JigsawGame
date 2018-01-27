//
// Created by okleinfeld on 12/15/17.
//

#ifndef AP_JIGSAWGAME_SOLUTIONALGORITHM_H
#define AP_JIGSAWGAME_SOLUTIONALGORITHM_H

#include <cmath>
#include <memory>
#include <algorithm>
#include <future>
#include <chrono>

#include "Factory.h"
#include "JigsawSolutionThread.h"

using namespace std;

class SolutionAlgorithm {
protected:
    unique_ptr<JigsawGameInterface> game;
    unique_ptr<PuzzlePieceMapInterface> piecesMap;
    vector<PuzzlePiece> pieces;
public:
    SolutionAlgorithm(unique_ptr<JigsawGameInterface> game, unique_ptr<PuzzlePieceMapInterface> piecesMap, vector<PuzzlePiece> pieces);
    virtual bool solveGame(int numOfThreads, bool rotate);
    virtual vector<pair<int,int> > getPossibleDimensions(int size);
    virtual void printSolutionToFile(string& outputFilePath, bool solved);
    virtual bool SolveForOneThread(vector<pair<int,int> > possibleDimensions);
};


#endif //AP_JIGSAWGAME_SOLUTIONALGORITHM_H
