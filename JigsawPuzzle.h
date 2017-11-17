//
// Created by okleinfeld on 11/15/17.
//

#ifndef ADVANCEDOOP_HW1_JIGSAWPUZZLE_H
#define ADVANCEDOOP_HW1_JIGSAWPUZZLE_H

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
    vector<PuzzlePiece> correctInputPieces;
    PuzzleMatrix* solutionMatrix;
    int lastRowIndex;
    int lastColIndex;
//    vector<PuzzlePiece> solutionOutput;

    int readFirstLine(ifstream& openInputFileStream);
    void readPuzzlePieceLine(string& line);
    void validatePuzzlePiece(PuzzlePiece& piece);
    void updateMissingIDs();
    void updateWrongElementsIDs();
    void writeErrorsToOutput(ofstream& openOutputFileStream);
    bool isMoveValid(PuzzlePiece& p, int row, int col);
    void transferAvailableToSolution(int i, int j, int k);
    void transferSolutionToAvailable(int i, int j, int k);
    bool solveGameRec(int i, int j);
    bool hasEnoughEdges();
    bool isSumEdgesZero();
    bool hasAllCorners();



public:
    explicit JigsawPuzzle(string& filePath);
//    JigsawPuzzle(JigsawPuzzle& puzzle);
//    ~JigsawPuzzle();
//    vector<PuzzlePiece> getInputPieces() const;
//    vector<PuzzlePiece> getSolution() const = delete;
    static vector<string> split(const string&, char delimiter);
    bool solveGame();
    bool isInitilized(){return cannotComputeSolution;}
    bool isLegalPuzzle(){return hasEnoughEdges() && isSumEdgesZero() && hasAllCorners();}
    bool initSolveGame(){ return solveGame(); }
};


#endif //ADVANCEDOOP_HW1_JIGSAWPUZZLE_H
