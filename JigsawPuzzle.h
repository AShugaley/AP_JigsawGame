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


/*
 * The main class, representing a Jigsaw Game
 *
 * Includes mostly the solution algorithm functions, as well as some auxillary ones
 */
class JigsawPuzzle {
protected:
    int numPieces; //number of puzzle pieces
    vector<PuzzlePiece> puzzlePieces; //vector of all correct pieces
    PuzzlePiecesMap piecesMap; //the map (the tree according to piece type), for fast search
    vector<vector<int> > solutionMatrix; //the currect solution matrix, 2D index matrix
    //current last row/col indexes
    int lastRowIndex;
    int lastColIndex;
    bool puzzleSolvedSuccessfully; //if solved

    //Function for the solution algorithm
    virtual pair<int,int> getNextPos(int i, int j); // next location in the matrix to check (e.g. <0,0>)
    virtual vector<pair<int,int> > getPossibleDimensions(); //get all possible solution dimension (i.e. for 16 pieces: <4,4>,<2,8>,<8,2>,<1,16>,<16,1>
    virtual PuzzleRequirement getReq(int i, int j); //get the requirement for a location in the matrix
    virtual void initSolMatrix(); //init the matrix
    virtual bool solveRec(pair<int,int> nextPos); //solve the game - recursive algo

public:
    //c'tors and d'tors
    explicit JigsawPuzzle(vector<PuzzlePiece> pieces);
    explicit JigsawPuzzle() = default;
    virtual ~JigsawPuzzle() = default;
    
    //init the solution algo
    virtual bool solveGame();
    
    //getters
    vector<vector<int>>& getSolutionMatrix();
    int getSolutionMatrixNumRows();
    int getSolutionMatrixNumCols();
    
    //print to file
    virtual bool printSolutionToFile(string& outputFile);
    

};


#endif //AP_JIGSAWGAME_JIGSAWPUZZLE_H
