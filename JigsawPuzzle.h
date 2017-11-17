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

using namespace std;


class JigsawPuzzle {
private:
    int numOfElements;
    bool cannotComputeSolution;
    string outputFile;
    map<int, string> wrongFormatLines;
    list<int> missingElementsIDs;
    list<int> wrongElemnetsIDs;
    vector<PuzzlePiece> correctInputPieces;
//    vector<PuzzlePiece> solutionOutput;

    int readFirstLine(ifstream& openInputFileStream);
    void readPuzzlePieceLine(string& line);
    void validatePuzzlePiece(PuzzlePiece& piece);
    void updateMissingIDs();
    void updateWrongElementsIDs();
    void writeErrorsToOutput(ofstream& openOutputFileStream);


public:
    explicit JigsawPuzzle(string& filePath);
//    JigsawPuzzle(JigsawPuzzle& puzzle);
//    ~JigsawPuzzle();
//    vector<PuzzlePiece> getInputPieces() const;
//    vector<PuzzlePiece> getSolution() const = delete;
    static vector<string> split(const string&, char delimiter);
};


#endif //ADVANCEDOOP_HW1_JIGSAWPUZZLE_H
