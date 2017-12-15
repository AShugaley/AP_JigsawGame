//
// Created by okleinfeld on 12/13/17.
//

#ifndef AP_JIGSAWGAME_JIGSAWSOLUTIONEXISTSROTATIONSALLOWD_H
#define AP_JIGSAWGAME_JIGSAWSOLUTIONEXISTSROTATIONSALLOWD_H


#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <cmath>
#include <algorithm>

#include "NaiveSolutionExistenceCheck.h"
#include "PuzzlePiece.h"

using namespace std;

class JigsawSolutionExistsRotationsAllowed : public NaiveSolutionExistenceCheck {
protected:
    int numPieces;
    vector<PuzzlePiece> puzzlePieces;
    vector<string> errorMessages;
    virtual bool isSumEdgesZero();
public:
    explicit JigsawSolutionExistsRotationsAllowed(vector<PuzzlePiece>& puzzlePieces);
    bool checkIfPuzzleIsLegal() override;
    void writeToFileFailedTests(string& outputFile) override;
};


#endif //AP_JIGSAWGAME_JIGSAWSOLUTIONEXISTSROTATIONSALLOWD_H
