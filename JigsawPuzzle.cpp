//
// Created by okleinfeld on 11/15/17.
//

#include "JigsawPuzzle.h"

#define OUTPUT_FILE_NOT_OPEN "Could not open an output file. Program operation Failed" << endl
#define CANNOT_READ_INPUT_FILE "Could not open/read the input file" << endl
#define INVALID_FIRST_LINE "The first line of the file is not valid. It should follow the format: NumElements=<positive integer>" << endl

JigsawPuzzle::JigsawPuzzle(string& filePath): outputFile("solution.txt"), cannotComputeSolution(false), lastRowIndex(-1), lastColIndex(-1) {
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

    if (this->missingElementsIDs.empty() && this->wrongElementsIDs.empty() && this->wrongFormatLines.empty() ){
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
//    for (int m : this->wrongElementsIDs){
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
            this->wrongElementsIDs.push_back(pieceID);
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
    if (!this->wrongElementsIDs.empty()){
        list<int>& wrongList = this->wrongElementsIDs;
        long wrongSize = this->wrongElementsIDs.size();
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

bool JigsawPuzzle::isMoveValid(PuzzlePiece& p, int row, int col){
    int l = p.getLeftEdge();
    int t = p.getTopEdge();
    int r = p.getRightEdge();
    int b = p.getBottomEdge();

    if (row == 0 && t != 0) return false;
    if (col == 0 && l != 0) return false;
    if (col == this->lastColIndex && r != 0) return false;
    if (row == this->lastRowIndex && b != 0) return false;

    bool noUpPiece = row == 0;
    bool noLeftPiece = col == 0;

    return ( (noUpPiece)  || (this->solutionMatrix->get(row-1, col).getBottomEdge() == -t) ) &&
            ( (noLeftPiece)  || (this->solutionMatrix->get(row, col-1).getRightEdge() == -l) );
}

bool JigsawPuzzle::solveGame(){
    this->solutionMatrix = new PuzzleMatrix(this->numOfElements);
    int i = 0;
    int j = 0;
    bool sol = false;
    for (int k = 0; k < this->correctInputPieces.size(); k++){
        if (this->correctInputPieces[k].isTopLeftCorner()){
            this->transferAvailableToSolution(i, j, k);
            sol = this->solveGameRec(i, j);
            if (sol == true){
                return true;
            }
            else{
                this->transferSolutionToAvailable(i, j, k);
            }
        }
    }
    return false;
}

void JigsawPuzzle::transferAvailableToSolution(int i, int j, int k){
    this->solutionMatrix->add(i, j, this->correctInputPieces[k]);
    this->correctInputPieces.erase(this->correctInputPieces.begin() + k);
}

void JigsawPuzzle::transferSolutionToAvailable(int i, int j, int k){
    this->correctInputPieces.insert(this->correctInputPieces.begin() + k, this->solutionMatrix->remove(i, j));
}

bool JigsawPuzzle::solveGameRec(int i, int j){

    // stop criterion

    if(i==this->lastRowIndex && j==lastColIndex){
        return true;
    }

    // if possible, try to start a new line

    if( this->lastColIndex == j || ( this->solutionMatrix->get(i, j).getRightEdge() == 0 && this->lastColIndex == -1 )){

        for (int k = 0; k < this->correctInputPieces.size(); k++){
            if (this->numOfElements % (j+1) == 0 && this->isMoveValid(this->correctInputPieces[k], i+1, 0)){

                this->lastColIndex = j; // last index is now set to j
                this->lastRowIndex = (this->numOfElements / (j+1)) -1; // j is always a divider because numOfElements mod j == 0

                this->transferAvailableToSolution(i+1, 0, k);
                bool sol = this->solveGameRec(i+1, 0);
                if (sol == true){
                    return true;
                }
                else{
                    this->transferSolutionToAvailable(i+1, 0, k);

                    if (i == 0){
                        // if we got back to the first row - now again number of elements in a row is unknown
                        this->lastColIndex = -1;
                        this->lastRowIndex = -1;

                    }
                }
            }
        }
    }

    if (this->lastColIndex == j){
        return false;
        // we had to start a new line but we didn't find a valid piece for it
    }

    // try to put a piece to the right of the current piece and continue the current row

    for (int k = 0; k < this->correctInputPieces.size(); k++) {

        if (this->isMoveValid(this->correctInputPieces[k], i, j+1)) {
            this->transferAvailableToSolution(i, j+1, k);
            bool sol = this->solveGameRec(i, j+1);
            if (sol == true) {
                return true;
            } else {
                this->transferSolutionToAvailable(i, j+1, k);
            }
        }
    }

    return false;
    // didn't find any matching piece
}

PuzzleMatrix& JigsawPuzzle::getSoulutionMatrix(){
    return *(this->solutionMatrix);
}

int JigsawPuzzle::getSolutionMatrixNumRows(){
    return this->lastRowIndex + 1;
}

int JigsawPuzzle::getSolutionMatrixNumCols(){
    return this->lastColIndex + 1;
}

bool JigsawPuzzle::hasAllCorners(){
    bool tr = false, tl = false , br = false , bl = false;
    
    for(int i = 0; i<this->numOfElements; i++){
        if(correctInputPieces[i].isTopRightCorner()){
            tr = true;
        }
        if(correctInputPieces[i].isTopLeftCorner()){
            tl = true;
        }
        if(correctInputPieces[i].isBotRightCorner()){
            br = true;
        }
        if(correctInputPieces[i].isBotLeftCorner()){
            bl = true;
        }
    }
    return tr && tl && br && bl;
}


bool JigsawPuzzle::hasEnoughEdges(){
    int count = 0;
    for(int i = 0; i<this->numOfElements; i++){
        count += correctInputPieces[i].countStraightEdges();
    }
    return count >= (correctInputPieces.size() + 3); //change to sqr root
}

bool JigsawPuzzle::isSumEdgesZero(){
    int sum = 0;
    for(int i = 0; i<this->numOfElements; i++){
        sum += correctInputPieces[i].sumEdges();
    }
    
    return sum == 0;
}
