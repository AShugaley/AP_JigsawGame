

#ifndef ADVANCEDOOP_HW1_JIGSAWPUZZLE_H
#define ADVANCEDOOP_HW1_JIGSAWPUZZLE_H

/* A calass represnting a Jigsaw game. 
 
   Includes the fields representing the game, the solution algorithem, and the initilizadion input/output functions.
 
 */

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <map>
#include <fstream>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <string>
#include "PuzzlePiece.h"


#define OUTPUT_FILE_NOT_OPEN "Could not open an output file. Program operation Failed" << endl
#define CANNOT_READ_INPUT_FILE "Could not open/read the input file" << endl
#define INVALID_FIRST_LINE "The first line of the file is not valid. It should follow the format: NumElements=<positive integer>" << endl
#define JOKER 100

using namespace std;


class JigsawPuzzle {
protected:
    int numOfElements;
    string outputFile;
    bool cannotComputeSolution;
    map<int, string> wrongFormatLines;
    list<int> missingElementsIDs;
    list<int> wrongElementsIDs;
    
    //pieces vector
    vector<PuzzlePiece> correctInputPieces;
    
    //solution matrix
   // PuzzleMatrix* solutionMatrix;
    vector<vector<int> > solutionMatrix;
    vector<int> unmatchedPieces;
    
    //args to be initialized when we solve the puzzle
    int lastRowIndex;
    int lastColIndex;

    //constructor & initialization functions
    int readFirstLine(ifstream& openInputFileStream);
    void readPuzzlePieceLine(string& line);
    void validatePuzzlePiece(PuzzlePiece& piece);
    void updateMissingIDs();
    void updateWrongElementsIDs();
    void writeErrorsToOutput(ofstream& openOutputFileStream);
    
    //checks if we can put a piece in <i,j>
    bool isMoveValid(PuzzlePiece& p, int row, int col);
    
    //move function between the pieces vector and the solution matrix
    void transferAvailableToSolution(int i, int j, int k);
    void transferSolutionToAvailable(int i, int j);
    
    /* Solution algorithem
     
     
     We utilize a brute force approach with some optimizations. 
     
     In a nutshell, this is the algorithem:
        start with an empty solution matrix, it will be filled on the go. If we reach a solution, stop - the matrix is the answer. If we reach a dead end (no pieces can be put in the next place) go up unltil more possibilities become available.
     
     */


    bool solveGameRec(int i, int j,vector<int> &currentSequanceCheck); // <i,j> = location of the last piece we insterted.
    
    bool printSolutionToFile(bool solved);
    
    bool checkBottomEdges(int j); //a special case when we have only one row
    bool solutionForOneElem(); //a special case when we have only one piece - only a 1x1 square is a valid solution
    bool checkOneRowSol(int j);  //a special case when we have only one row
    
    //trivial checks
    bool hasEnoughEdges();
    bool isSumEdgesZero();
    bool isSumHorizontalEdgesZero();
    bool isSumVerticalEdgesZero();
    vector<int> hasAllCorners();




public:
    
    //constructor
    explicit JigsawPuzzle(string& inputFilePath, string& outputFilePath);
    JigsawPuzzle(){};
    ~JigsawPuzzle(){
        //delete this->solutionMatrix;
    }

    
    
    //helper func
    static vector<string> split(const string&, char delimiter);
    
    //getters
    //PuzzleMatrix& getSolutionMatrix() {return *(this->solutionMatrix);}
    int getSolutionMatrixNumRows() {return this->lastRowIndex + 1;}
    int getSolutionMatrixNumCols(){return this->lastColIndex + 1;}
    
    //checks if a game is initilized properly
    bool isInitialized(){return !cannotComputeSolution;}
    
    //checks if a game is solvable in theory (trivial checks)
    bool isLegalPuzzle();
    
    //runs the algo to solve game
    bool initSolveGame();
    bool solveGame();
};


#endif //ADVANCEDOOP_HW1_JIGSAWPUZZLE_H
