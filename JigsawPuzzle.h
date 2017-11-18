//
// Created by okleinfeld on 11/15/17.
//

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
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include "PuzzlePiece.h"
#include "PuzzleMatrix.h"

using namespace std;



class JigsawPuzzle {
private:
    int numOfElements;
    bool cannotComputeSolution;
    string outputFile;
    map<int, string> wrongFormatLines;
    list<int> missingElementsIDs;
    list<int> wrongElementsIDs;
    
    //pieces vector
    vector<PuzzlePiece> correctInputPieces;
    
    //solution matrix
    PuzzleMatrix* solutionMatrix;
    
    //args to be initialized when we solve the puzzle
    int lastRowIndex;
    int lastColIndex;

    //constructor & initiliziton functions
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
    void transferSolutionToAvailable(int i, int j, int k);
    
    /* Solution algorithem
     
     
     We utilize a brute force approach with some optimizations. 
     
     In a nutshell, this is the algorithem:
        start with an empty solution matrix, it will be filled on the go. If we reach a solution, stop - the matrix is the answer. If we reach a dead end (no pieces can be put in the next place) go up unltil more possibilities become available.
     
     */

    bool solveGame();
    bool solveGameRec(int i, int j); // <i,j> = location of the last piece we insterted.
    void printSolutionToFile();
    
    //trivial checks
    bool hasEnoughEdges();
    bool isSumEdgesZero();
    bool hasAllCorners();




public:
    
    //constructor
    explicit JigsawPuzzle(string& inputFilePath, string& outputFilePath);

    //helper func
    static vector<string> split(const string&, char delimiter);
    
    //getters
    PuzzleMatrix& getSolutionMatrix() {return *(this->solutionMatrix);}
    int getSolutionMatrixNumRows() {return this->lastRowIndex + 1;}
    int getSolutionMatrixNumCols(){return this->lastColIndex + 1;}
    
    //checks if a game is initilized properly
    bool isInitialized(){return cannotComputeSolution;}
    
    //checks if a game is solvable in theory (trivial checks)
    bool isLegalPuzzle(){return hasEnoughEdges() && isSumEdgesZero() && hasAllCorners();}
    
    //runs the algo to solve game
    bool initSolveGame(){
        if(solveGame()) {
            printSolutionToFile();
            return true;
        }
        return false;
    }
};


#endif //ADVANCEDOOP_HW1_JIGSAWPUZZLE_H
