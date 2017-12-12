//
// Created by okleinfeld on 12/12/17.
//

#ifndef AP_JIGSAWGAME_JIGSAWSOLUTIONEXISTSCHECKS_H
#define AP_JIGSAWGAME_JIGSAWSOLUTIONEXISTSCHECKS_H


#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <cmath>
#include <algorithm>
#include <stdexcept>

#include "PuzzlePiece.h"

#define WRONG_NUM_EDGES "Cannot solve puzzle: wrong number of straight edges"
#define NO_CORNER_TL "Cannot solve puzzle: missing corner element: <TL>"
#define NO_CORNER_TR "Cannot solve puzzle: missing corner element: <TR>"
#define NO_CORNER_BL "Cannot solve puzzle: missing corner element: <BL>"
#define NO_CORNER_BR "Cannot solve puzzle: missing corner element: <BR>"
#define SUM_TOTAL_EDGES_WRONG "Cannot solve puzzle: sum of edges is not zero"
#define SUM_HOR_EDGES_WRONG "Cannot solve puzzle: sum of horizontal edges is not zero"
#define SUM_VER_EDGES_WRONG "Cannot solve puzzle: sum of vertical edges is not zero"
#define OUTPUT_FILE_NOT_OPEN "Could not open an output file. Program operation Failed" << endl


using namespace std;

class JigsawSolutionExistsChecks {
private:
    vector<PuzzlePiece> puzzlePieces;
    int numPieces;
    vector<string> errorMessages;


protected:
    virtual vector<int> hasAllCorners();
    virtual bool hasEnoughEdges();
    virtual bool isSumEdgesZero();
    virtual bool isSumHorizontalEdgesZero();
    virtual bool isSumVerticalEdgesZero();

public:
    explicit JigsawSolutionExistsChecks(vector<PuzzlePiece>& puzzlePieces);
    bool checkIfPuzzleIsLegal();
    void writeToFileFailedTests(string& outputFile);


};


#endif //AP_JIGSAWGAME_JIGSAWSOLUTIONEXISTSCHECKS_H
