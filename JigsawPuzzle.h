

#ifndef ADVANCEDOOP_HW1_JIGSAWPUZZLE_H
#define ADVANCEDOOP_HW1_JIGSAWPUZZLE_H

/* A class representing a Jigsaw game.
 
   Includes the fields representing the game, the solution algorithm, and the initialization input/output functions.
 */

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <fstream>
#include <list>
#include <math.h>
#include <algorithm>
#include <stdexcept>

#include "PuzzlePiecesMap.h"


#define OUTPUT_FILE_NOT_OPEN "Could not open an output file. Program operation Failed" << endl
#define CANNOT_READ_INPUT_FILE "Could not open/read the input file" << endl
#define INVALID_FIRST_LINE "The first line of the file is not valid. It should follow the format: NumElements=<positive integer>" << endl


using namespace std;



/*
 A JigsawPuzzle with rotate capabilities.
 
 
 Algorithm:
    sort pieces into buckets (according to type)
    find all possible dimensions of the solution (i.e. 8*4, 16*2, 31*1...)
    for dim in dimensions:
        find the order of the positions we want to fill.
            //we go in a spiral, so, for a matrix like:
            //1 3 4
            //4 8 2
            //9 7 6
            //the order will be 1,3,4,2,6,7,9,4. This way we fill the frame first, and minimilize late 'returns'
        for pos in positions_to_fill:
            find the requirement (o(1))
            find a matching piece from PuzzlePiecesMap (o(1))
                recursion
 */
class JigsawPuzzle {
protected:

    int numOfElements;
    string outputFile;
    
    //initilization and input checking
    bool cannotComputeSolution;
    map<int, string> wrongFormatLines;
    list<int> missingElementsIDs;
    list<int> wrongElementsIDs;
    
    
    //the buckets
    PuzzlePiecesMap piecesMap;

    
    //order of positions to fill
    //we go in a spiral, so, for a matrix like:
    //1 3 4
    //4 8 2
    //9 7 6
    //the order will be 1,3,4,2,6,7,9,4. This way we fill the frame first, and minimilize late 'returns'
    vector<pair<int,int> > positionsToFill;
    void Spiral( int m, int n); //this generates the spiral





    // initialization functions for the parsing stage
    int readFirstLine(ifstream& openInputFileStream);
    void readPuzzlePieceLine(string& line);
    void validatePuzzlePiece(PuzzlePiece& piece);
    void updateMissingIDs();
    void updateWrongElementsIDs();
    void writeErrorsToOutput(ofstream& openOutputFileStream);
    bool printSolutionToFile(bool solved);
    
    
    
    //trivial checks
    bool hasEnoughEdges();
    bool isSumEdgesZero();
    virtual bool isSumHorizontalEdgesZero();
    virtual bool isSumVerticalEdgesZero();
    vector<int> hasAllCorners();


    //Functions for the solution algorithm
    pair<int,int> getNextPos(int i, int j); //get the next position to fill
    virtual PuzzlePiece* getNextPiece(PuzzleRequirement req); //get the next piece from PuzzlePiecesMap
    vector<pair<int,int> > getPossibleDimensions(int numOfPieces); //get all possible frame dimensions
    PuzzleRequirement getReq(int i, int j); //get requirement for a place in the solutionMatrix
    void initSolMatrix(); //init the solution matrix

public:
    //args to be initialized when we solve the puzzle
    int lastRowIndex;
    int lastColIndex;
    
    
    //pieces vector
    vector<PuzzlePiece> correctInputPieces;
    //solution matrix
    vector<vector<int> > solutionMatrix;
    
    //constructors
    explicit JigsawPuzzle(string& inputFilePath, string& outputFilePath);
    explicit JigsawPuzzle(vector<PuzzlePiece> pieces);
    explicit JigsawPuzzle(){}

    //getters
    //PuzzleMatrix& getSolutionMatrix() {return *(this->solutionMatrix);}
    int getSolutionMatrixNumRows() {return this->lastRowIndex + 1;}
    int getSolutionMatrixNumCols(){return this->lastColIndex + 1;}
    vector<PuzzlePiece> getCorrectInputPieces() {return correctInputPieces;};

    //checks if a game is initialized properly
    bool isInitialized(){return !cannotComputeSolution;}

    //checks if a game is solvable in theory (trivial checks)
    virtual bool isLegalPuzzle();

    //runs the algorithm to solve game
    virtual bool initSolveGame();
    bool beginMainAlgo();
    virtual bool solveRec(pair<int,int> nextPos);
    virtual bool initSolve();

    //helper func
    static vector<string> split(const string&, char delimiter);
};


#endif //ADVANCEDOOP_HW1_JIGSAWPUZZLE_H
