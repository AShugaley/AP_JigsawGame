//
// Created by okleinfeld on 12/12/17.
//

#ifndef AP_JIGSAWGAME_JIGSAWPARSER_H
#define AP_JIGSAWGAME_JIGSAWPARSER_H

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


#define OUTPUT_FILE_NOT_OPEN "Could not open an output file. Program operation Failed" << endl
#define CANNOT_READ_INPUT_FILE "Could not open/read the input file" << endl
#define CANNOT_WRITE_OUTPUTFILE "Could not open or write to the input file" << endl
#define INVALID_FIRST_LINE "The first line of the file is not valid. It should follow the format: NumElements=<positive integer>" << endl

using namespace std;
/*
 * A class responsible for the parsing of the game from the solution file
 */
class JigsawParser {

private:
    int readFirstLine(ifstream &openInputFileStream);
    void readPuzzlePieceLine(string& line);
    void updateMissingIDs();
    void updateRedundantElementsIDs();
    void validatePuzzlePiece(PuzzlePiece& piece);

protected:
    int numOfElements;
    string outputFile;
    bool cannotComputeSolution;
    bool fileOperationsError;
    map<int, string> wrongFormatLines;
    list<int> missingElementsIDs;
    list<int> redundantElementsIDs;
    vector<PuzzlePiece> correctInputPieces;

public:

    explicit JigsawParser(string& inputFilePath, string& outputFilePath);
    bool isInitialized(); //returns True iff a game is initialized properly - i.e we can try and compute a solution
    bool fileError();
    void writeErrorsToOutput();
    vector<PuzzlePiece> getCorrectInputPieces();

};

vector<string> split(const string &s, char delimiter);


#endif //AP_JIGSAWGAME_JIGSAWPARSER_H
