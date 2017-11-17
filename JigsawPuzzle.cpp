//
// Created by okleinfeld on 11/15/17.
//

#include "JigsawPuzzle.h"

#define OUTPUT_FILE_NOT_OPEN "Could not open an output file. Program operation Failed" << endl
#define CANNOT_READ_INPUT_FILE "Could not open/read the input file" << endl
#define INVALID_FIRST_LINE "The first line of the file is not valid. It should follow the format: NumElements=<positive integer>" << endl

JigsawPuzzle::JigsawPuzzle(string& filePath): outputFile("solution.txt"), cannotComputeSolution(false) {
    ifstream inputFile;
    inputFile.open(filePath);
    ofstream outputFile;
    outputFile.open(this->outputFile);

    if (!outputFile.is_open()){
        cout << OUTPUT_FILE_NOT_OPEN;
        this->cannotComputeSolution = true;
        return;
    }

    if (!inputFile.is_open()) {
        outputFile << CANNOT_READ_INPUT_FILE;
        this->cannotComputeSolution = true;
        outputFile.close();
        return;
    }

    int numElements = JigsawPuzzle::readFirstLine(inputFile);
    if (numElements == -1){
        outputFile << INVALID_FIRST_LINE;
        this->cannotComputeSolution = true;
        outputFile.close();
        return;
    }

    this->numOfElements = numElements;

    string line;
    while (std::getline(inputFile, line)){
        JigsawPuzzle::readPuzzlePieceLine(line);
    }

    inputFile.close();

    for (PuzzlePiece& p : this->correctInputPieces){
        this->validatePuzzlePiece(p);
    }

    updateMissingIDs();
    updateWrongElementsIDs();

    if (this->missingElementsIDs.empty() && this->wrongElemnetsIDs.empty() && this->wrongFormatLines.empty() ){
        outputFile.close();
        return;
    }
    else{
        this->cannotComputeSolution = true;

        writeErrorsToOutput(outputFile);
        outputFile.close();
    }

//    for (int m : this->missingElementsIDs){
//        cout << "missing element number: " << m << endl;
//    }
//
//    for (int m : this->wrongElemnetsIDs){
//        cout << "wrong elements number: " << m << endl;
//    }

}


int JigsawPuzzle::readFirstLine(ifstream &openInputFileStream) {
    string line;
    std::getline(openInputFileStream, line);
    vector<string> lineWords = JigsawPuzzle::split(line, '=');
    if (lineWords.size() != 2){
        return -1;
    }

    string firstWord = lineWords[0];
    firstWord.erase(std::remove(firstWord.begin(), firstWord.end(), ' '), firstWord.end());
    if (firstWord != "NumElements"){
        return -1;
        // File should start with the word "NumElements"
    }

    string secondWord = lineWords[1];
    secondWord.erase(std::remove(secondWord.begin(), secondWord.end(), ' '), secondWord.end());
    if (secondWord.empty()) {
        return -1;
        // The second token in the file's first line must contains a number
    }
    try {

        int numElements = std::stoi(secondWord);
        if (numElements <= 0) {
            return -1;
            // The number representing the number of elements must be a positive integer
        }
        else {

            return numElements;
        }


    }
    catch (std::invalid_argument& ia){
        return -1;
        // the argument for number of elements is not a valid integer
    }
}

vector<string> JigsawPuzzle::split(const string &s, char delimiter) {
    vector<string> words;
    stringstream streamStr(s);
    string currentWord;

    while (getline(streamStr, currentWord, delimiter)){
        words.push_back(currentWord);
    }

    return words;
}

void JigsawPuzzle::readPuzzlePieceLine(string& line){
    vector<string> pieceInfo = JigsawPuzzle::split(line, ' ');

    try {

        int ISD = std::stoi(pieceInfo[0]);

        if (pieceInfo.size() != 5){
            this->wrongFormatLines.insert({ISD, line});
            return;
        }

        int l = std::stoi(pieceInfo[1]);
        int t = std::stoi(pieceInfo[2]);
        int r = std::stoi(pieceInfo[3]);
        int b = std::stoi(pieceInfo[4]);

        PuzzlePiece piece(ISD, l, t, r, b);
        this->correctInputPieces.push_back(piece);

        // if no fatal error always insert into correctInput list.
        // will duplicate to wrongFormat list later.
    }

    catch (std::invalid_argument& ia){
        this->wrongFormatLines.insert({-1, line});
    }

}

void JigsawPuzzle::validatePuzzlePiece(PuzzlePiece& piece){
    int id = piece.getISD();
    int l = piece.getLeftEdge();
    int t = piece.getTopEdge();
    int r = piece.getRightEdge();
    int b = piece.getBottomEdge();
    int edges[4] = {l, t, r, b};
    for (int e : edges){
        if (e < -1 || e > 1){
            stringstream line;
            piece.print(line);
            this->wrongFormatLines.insert({id, line.str()});
            break;
        }
    }
}

void JigsawPuzzle::updateMissingIDs(){
    vector<PuzzlePiece>& pieces = this->correctInputPieces;
    std::sort(pieces.begin(), pieces.end());
    unordered_map<int, int> mapIDs;
    for (PuzzlePiece& p : pieces){
        auto iter = mapIDs.find(p.getISD());
        if (iter == mapIDs.end()){
            mapIDs.insert({p.getISD(), 1});
        }
        else{
            iter->second = iter->second + 1;
        }
    }
    for (int i = 1; i <= this->numOfElements; i++){
        auto iter = mapIDs.find(i);
        if (iter == mapIDs.end()){
            this->missingElementsIDs.push_back(i);
        }
    }
}

void JigsawPuzzle::updateWrongElementsIDs(){
    vector<PuzzlePiece>& pieces = this->correctInputPieces;
    for (PuzzlePiece& p : pieces){
        int pieceID = p.getISD();
        if (pieceID > this->numOfElements){
            this->wrongElemnetsIDs.push_back(pieceID);
        }
    }
}

void JigsawPuzzle::writeErrorsToOutput(ofstream& openOutputFileStream){
    if (!this->missingElementsIDs.empty()){
        list<int>& missingList = this->missingElementsIDs;
        long missSize = this->missingElementsIDs.size();
        openOutputFileStream << "Missing puzzle element(s) with the following IDs: ";
        for (int i = 0; i < missSize; i++){
            if (i != missSize-1){
                auto iter = std::next(missingList.begin(), i);
                openOutputFileStream << *iter << ",";
            }
            else{
                auto iter = std::next(missingList.begin(), i);
                openOutputFileStream << *iter << endl;
            }
        }
    }
    if (!this->wrongElemnetsIDs.empty()){
        list<int>& wrongList = this->wrongElemnetsIDs;
        long wrongSize = this->wrongElemnetsIDs.size();
        openOutputFileStream << "Puzzle of size " << wrongSize << " cannot have the following IDs: ";
        for (int i = 0; i < wrongSize; i++){
            if (i != wrongSize-1){
                auto iter = std::next(wrongList.begin(), i);
                openOutputFileStream << *iter << ",";
            }
            else{
                auto iter = std::next(wrongList.begin(), i);
                openOutputFileStream << *iter << endl;
            }
        }
    }
    if (!this->wrongFormatLines.empty()){
        map<int, string>& wrongLines = this->wrongFormatLines;
        for (auto iter = wrongLines.begin(); iter != wrongLines.end();){
            if (iter->first != -1){
                openOutputFileStream << "Puzzle ID " << iter->first << " has wrong data: " << iter->second << endl;
            }
            iter++;
        }
        for (auto iter = wrongLines.begin(); iter != wrongLines.end();){
            if (iter->first == -1){
                openOutputFileStream << "The following line has wrong data and/or wrong Puzzle ID: " << iter->second << endl;
            }
            iter++;
        }
    }
}