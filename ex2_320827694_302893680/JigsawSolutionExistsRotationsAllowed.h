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
#include "PuzzlePieceRotation.h"
using namespace std;
/* Extension of NaiveSolutionExistenceCheck for rotations, will try to check for legality with rotations */
class JigsawSolutionExistsRotationsAllowed : public NaiveSolutionExistenceCheck {
protected:
    int numPieces;
    vector<PuzzlePiece> puzzlePieces;
    vector<string> errorMessages;
    virtual bool isSumEdgesZero();
    virtual bool hasEnoughEdges();
public:
    explicit JigsawSolutionExistsRotationsAllowed(vector<PuzzlePiece>& puzzlePieces);
    bool checkIfPuzzleIsLegal() override;
    void writeToFileFailedTests(string& outputFile) override;
};


#endif //AP_JIGSAWGAME_JIGSAWSOLUTIONEXISTSROTATIONSALLOWD_H
