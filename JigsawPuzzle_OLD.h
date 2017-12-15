//
// Created by okleinfeld on 12/12/17.
//

#ifndef AP_JIGSAWGAME_JIGSAWPUZZLE_H
#define AP_JIGSAWGAME_JIGSAWPUZZLE_H


#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <fstream>
#include <list>
#include <cmath>
#include <algorithm>
#include <stdexcept>

#include "PuzzlePiecesMap.h"

#define OUTPUT_FILE_NOT_OPEN "Could not open an output file. Program operation Failed" << endl

class JigsawPuzzle_OLD {
protected:
    int numPieces;
    vector<PuzzlePiece> puzzlePieces;
    PuzzlePiecesMap piecesMap;
    vector<vector<int> > solutionMatrix;
    int lastRowIndex;
    int lastColIndex;
    bool puzzleSolvedSuccessfully;

    //Function for the solution algorithm
    virtual pair<int,int> getNextPos(int i, int j);
    virtual vector<pair<int,int> > getPossibleDimensions();
    virtual PuzzleRequirement getReq(int i, int j);
    virtual void initSolMatrix();
    virtual bool solveRec(pair<int,int> nextPos);

public:

    explicit JigsawPuzzle_OLD(vector<PuzzlePiece> pieces);
    explicit JigsawPuzzle_OLD() = default;
    virtual bool solveGame();
    vector<vector<int>>& getSolutionMatrix();
    int getSolutionMatrixNumRows();
    int getSolutionMatrixNumCols();
    virtual bool printSolutionToFile(string& outputFile);
    virtual ~JigsawPuzzle_OLD() = default;

};


#endif //AP_JIGSAWGAME_JIGSAWPUZZLE_H
