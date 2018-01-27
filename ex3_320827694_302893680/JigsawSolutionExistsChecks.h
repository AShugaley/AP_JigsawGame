//
// Created by okleinfeld on 12/12/17.
//

#ifndef AP_JIGSAWGAME_JIGSAWSOLUTIONEXISTSCHECKS_H
#define AP_JIGSAWGAME_JIGSAWSOLUTIONEXISTSCHECKS_H


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
/* Extension of NaiveSolutionExistenceCheck for non rotation puzzle, will try to check for legality with rotations */

class JigsawSolutionExistsChecks : public NaiveSolutionExistenceCheck{
protected:
    int numPieces;
    vector<PuzzlePiece> puzzlePieces;
    vector<string> errorMessages;
    virtual vector<int> hasAllCorners();
    virtual bool hasEnoughEdges();
    virtual bool isSumEdgesZero();

public:
    explicit JigsawSolutionExistsChecks(vector<PuzzlePiece>& puzzlePieces);
    virtual bool checkIfPuzzleIsLegal() override;
    void writeToFileFailedTests(string& outputFile) override;


};


#endif //AP_JIGSAWGAME_JIGSAWSOLUTIONEXISTSCHECKS_H
