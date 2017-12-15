//
// Created by okleinfeld on 12/12/17.
//

#include "JigsawParser.h"


JigsawParser::JigsawParser(string& inputFilePath, string& outputFilePath) : outputFile(outputFilePath), cannotComputeSolution(false), fileOperationsError(false){
    ifstream inputFile;
    inputFile.open(inputFilePath);
    ofstream outputFile;
    outputFile.open(this->outputFile);

    if (!outputFile.is_open()){
        cout << CANNOT_WRITE_OUTPUT_FILE;
        this->fileOperationsError = true;
        this->cannotComputeSolution = true;
        return;
    }

    if (!inputFile.is_open()) {
        cout << CANNOT_READ_INPUT_FILE;
        this->fileOperationsError = true;
        this->cannotComputeSolution = true;
        outputFile.close();
        return;
    }

    int numElements = JigsawParser::readFirstLine(inputFile);
    if (numElements == -1){
        outputFile << INVALID_FIRST_LINE;
        this->fileOperationsError = true;
        this->cannotComputeSolution = true;
        outputFile.close();
        return;
    }

    this->numOfElements = numElements;

    string line;
    while (std::getline(inputFile, line)){
        JigsawParser::readPuzzlePieceLine(line);
    }

    inputFile.close();

    for (PuzzlePiece& p : this->correctInputPieces){
        this->validatePuzzlePiece(p);
    }

    // pieces value were valid - but check if all there no missing or redundant ids
    updateMissingIDs();
    updateRedundantElementsIDs();

    if (!this->missingElementsIDs.empty() || !this->redundantElementsIDs.empty() || !this->wrongFormatLines.empty()){
        this->cannotComputeSolution = true;
        // there are wrong format line/ redundant/missing elements.
        // in this case we cannot try to compute a solution for the puzzle
    }
}

bool JigsawParser::isInitialized(){
    return !this->cannotComputeSolution;
}

bool JigsawParser::fileError(){
    return this->fileOperationsError;
}


int JigsawParser::readFirstLine(ifstream &openInputFileStream) {
    string line;
    std::getline(openInputFileStream, line);
    vector<string> lineWords = split(line, '=');
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

void JigsawParser::readPuzzlePieceLine(string& line){
    vector<string> pieceInfo = split(line, ' ');

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


void JigsawParser::updateMissingIDs(){
    vector<PuzzlePiece>& pieces = this->correctInputPieces;
    std::sort(pieces.begin(), pieces.end());
    map<int, int> mapIDs;
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

void JigsawParser::updateRedundantElementsIDs(){
    vector<PuzzlePiece>& pieces = this->correctInputPieces;
    for (PuzzlePiece& p : pieces){
        int pieceID = p.getISD();
        if (pieceID > this->numOfElements){
            this->redundantElementsIDs.push_back(pieceID);
        }
    }
}

void JigsawParser::validatePuzzlePiece(PuzzlePiece& piece){
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


void JigsawParser::writeErrorsToOutput(){
    ofstream outputFile;
    outputFile.open(this->outputFile);

    if (!outputFile.is_open()){
        cout << "Could not open an output file. Program operation Failed" << endl;
        this->cannotComputeSolution = true;
        return;
    }

    // write all the needed errors

    if (!this->missingElementsIDs.empty()){
        list<int>& missingList = this->missingElementsIDs;
        long missSize = this->missingElementsIDs.size();
        outputFile << "Missing puzzle element(s) with the following IDs: ";
        for (int i = 0; i < missSize; i++){
            if (i != missSize-1){
                auto iter = std::next(missingList.begin(), i);
                outputFile << *iter << ", ";
            }
            else{
                auto iter = std::next(missingList.begin(), i);
                outputFile << *iter << endl;
            }
        }
    }

    if (!this->redundantElementsIDs.empty()){
        list<int>& wrongList = this->redundantElementsIDs;
        long wrongSize = this->redundantElementsIDs.size();
        outputFile << "Puzzle of size " << this->numOfElements << " cannot have the following IDs: ";
        for (int i = 0; i < wrongSize; i++){
            if (i != wrongSize-1){
                auto iter = std::next(wrongList.begin(), i);
                outputFile << *iter << ", ";
            }
            else{
                auto iter = std::next(wrongList.begin(), i);
                outputFile << *iter << endl;
            }
        }
    }
    if (!this->wrongFormatLines.empty()){
        map<int, string>& wrongLines = this->wrongFormatLines;
        for (auto iter = wrongLines.begin(); iter != wrongLines.end();){
            if (iter->first != -1){
                outputFile << "Puzzle ID " << iter->first << " has wrong data: " << iter->second << endl;
            }
            iter++;
        }
        for (auto iter = wrongLines.begin(); iter != wrongLines.end();){
            if (iter->first == -1){
                outputFile << "The following line has wrong data and/or wrong Puzzle ID: " << iter->second << endl;
            }
            iter++;
        }
    }
    outputFile.close();
}


vector<PuzzlePiece> JigsawParser::getCorrectInputPieces(){
    return this->correctInputPieces;
}


vector<string> split(const string &s, char delimiter) {
    vector<string> words;
    stringstream streamStr(s);
    string currentWord;

    while (getline(streamStr, currentWord, delimiter)){
        if (currentWord == ""){
            continue;
        }
        words.push_back(currentWord);
    }

    return words;
}

