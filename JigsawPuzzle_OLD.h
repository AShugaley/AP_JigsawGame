

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


class JigsawPuzzleOLD {
protected:

    int numOfElements;
    string outputFile;
    bool cannotComputeSolution;
    map<int, string> wrongFormatLines;
    list<int> missingElementsIDs;
    list<int> wrongElementsIDs;
    PuzzlePiecesMap piecesMap;
    
    //pieces vector
    vector<PuzzlePiece> correctInputPieces;
    
    //solution matrix
    vector<vector<int> > solutionMatrix;

    //args to be initialized when we solve the puzzle
    int lastRowIndex;
    int lastColIndex;

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
    bool isSumHorizontalEdgesZero();
    bool isSumVerticalEdgesZero();
    vector<int> hasAllCorners();


    //Function for the solution algorithm
    pair<int,int> getNextPos(int i, int j);
    vector<pair<int,int> > getPossibleDimensions(int numOfPieces);
    PuzzleRequirement getReq(int i, int j);
    void initSolMatrix();

public:
    //constructors
    explicit JigsawPuzzleOLD(string& inputFilePath, string& outputFilePath);
    explicit JigsawPuzzleOLD(vector<PuzzlePiece> pieces);

    //getters
    //PuzzleMatrix& getSolutionMatrix() {return *(this->solutionMatrix);}
    int getSolutionMatrixNumRows() {return this->lastRowIndex + 1;}
    int getSolutionMatrixNumCols(){return this->lastColIndex + 1;}
    vector<PuzzlePiece> getCorrectInputPieces() {return correctInputPieces;};

    //checks if a game is initialized properly
    bool isInitialized(){return !cannotComputeSolution;}

    //checks if a game is solvable in theory (trivial checks)
    bool isLegalPuzzle();

    //runs the algorithm to solve game
    virtual bool initSolveGame();
    bool solveRec(pair<int,int> nextPos);
    bool initSolve();

    //helper func
    static vector<string> split(const string&, char delimiter);
};


#endif //ADVANCEDOOP_HW1_JIGSAWPUZZLE_H
