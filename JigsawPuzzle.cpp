
#include "JigsawPuzzle.h"

#define OUTPUT_FILE_NOT_OPEN "Could not open an output file. Program operation Failed" << endl
#define CANNOT_READ_INPUT_FILE "Could not open/read the input file" << endl
#define INVALID_FIRST_LINE "The first line of the file is not valid. It should follow the format: NumElements=<positive integer>" << endl

JigsawPuzzle::JigsawPuzzle(string& inputFilePath, string& outputFilePath): outputFile(outputFilePath), cannotComputeSolution(false), lastRowIndex(-1), lastColIndex(-1) {
    ifstream inputFile;
    inputFile.open(inputFilePath);
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
                openOutputFileStream << *iter << ", ";
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
        openOutputFileStream << "Puzzle of size " << this->numOfElements << " cannot have the following IDs: ";
        for (int i = 0; i < wrongSize; i++){
            if (i != wrongSize-1){
                auto iter = std::next(wrongList.begin(), i);
                openOutputFileStream << *iter << ", ";
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


//function checks if we can put a piece in a certain place.
bool JigsawPuzzle::isMoveValid(PuzzlePiece& p, int row, int col){
    int l = p.getLeftEdge();
    int t = p.getTopEdge();
    int r = p.getRightEdge();
    int b = p.getBottomEdge();

    if (row == 0 && t != 0) return false; //first row must have a straight edge
    if (col == 0 && l != 0) return false; //first col must have a straight edge
    if (col == this->lastColIndex && r != 0) return false; //last row must have a straight edge
    if (row == this->lastRowIndex && b != 0) return false; //last col must have a straight edge

    bool noUpPiece = row == 0;
    bool noLeftPiece = col == 0;

    return ( (noUpPiece)  || (this->correctInputPieces[this->solutionMatrix[row-1][col] - 1].getBottomEdge() == -t) ) &&
            ( (noLeftPiece)  || (this->correctInputPieces[this->solutionMatrix[row][col-1] - 1].getRightEdge() == -l) );
}


//function solves the game
bool JigsawPuzzle::solveGame(){
    vector<int> currentSequenceCheck; //delete
    this->solutionMatrix = std::vector< std::vector<int> >(this->numOfElements, std::vector<int>(this->numOfElements));
    this->unmatchedPieces = vector<int>(this->numOfElements);
    if(this->numOfElements == 1){
        return this->solutionForOneElem();
    }
    for(int i = 0; i<this->numOfElements; i++)
        this->unmatchedPieces[i] = i+1;
    
    
    int i = 0;
    int j = 0;
    bool sol = false;
    
    
    for (unsigned k = 0; k < this->unmatchedPieces.size(); k++){
        if (this->correctInputPieces[this->unmatchedPieces[k]-1].isTopLeftCorner()){
            this->transferAvailableToSolution(i, j, k);
            currentSequenceCheck.push_back(correctInputPieces[k].getISD());  //debugging
            sol = this->solveGameRec(i, j,currentSequenceCheck);
            currentSequenceCheck.pop_back();  //debugging
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

bool JigsawPuzzle::solutionForOneElem(){
    if(this->correctInputPieces[0].isBotLeftCorner() && this->correctInputPieces[0].isTopRightCorner()){
        transferAvailableToSolution(0, 0, 0);
        this->lastColIndex = 0;
        this->lastRowIndex = 0;
        return true;
    }
    return false;
}



//moves piece from pieces vector to solution matrix
void JigsawPuzzle::transferAvailableToSolution(int i, int j, int k){
    this->solutionMatrix[i][j] = k+1;
    this->unmatchedPieces[k] = 0;
}


//moves piece from sol matrix to pieces vector
void JigsawPuzzle::transferSolutionToAvailable(int i, int j, int k){
    this->unmatchedPieces[this->solutionMatrix[i][j]-1] = solutionMatrix[i][j];
    this->solutionMatrix[i][j] = 0;
    
}

//the recursive part of the solution algorithm
bool JigsawPuzzle::solveGameRec(int i, int j,vector<int> &currentSequanceCheck){
    
//    debugging
//    for(auto i : currentSequanceCheck){
//        cout << i << ",";
//    }
//    cout << endl;
//    for(int i = 0; i<this->lastRowIndex; i++){
//        for(int j =0; j<this->lastColIndex;j++){
//            cout << this->solutionMatrix[i][j];
//            if(j!=this->lastColIndex-1)
//                cout << " ";
//        }
//        cout << endl;
//    }
//    cout << "ENDENDEND" << endl;
    
//    debugging
    
    // stop criterion -> no more pieces to put in place
    if(i==this->lastRowIndex && j==lastColIndex){
        return true;
    }

    if (this->lastColIndex != j){
        
        //first we try to go right
        for (unsigned k = 0; k < this->correctInputPieces.size(); k++) {
            if ((unmatchedPieces[k] !=  0) && this->isMoveValid(this->correctInputPieces[k], i, j+1)) {
                this->transferAvailableToSolution(i, j+1, k);
                
                
                if(j+1>this->numOfElements/2){
                    if (!(this->checkOneRowSol(i,j))) //special case - all in one row
                        return false;
                }
                currentSequanceCheck.push_back(correctInputPieces[k].getISD());//debugging
                bool sol = this->solveGameRec(i, j+1,currentSequanceCheck);
                currentSequanceCheck.pop_back();//debugging

                if (sol == true) {
                    return true;
                    
                } else {
                    this->transferSolutionToAvailable(i, j+1, k);
                }
            }
        }
    }
    //TODO: maybe here mean lastColIndex == j????
//    if((this->lastRowIndex != j) && (this->lastColIndex != -1))
    if (this->lastColIndex == i){
        return false; //we cannot start a new line
    }

    //couldn't go right - try to start a new line
    for (int k = 0; k < this->correctInputPieces.size(); k++){
        if (this->numOfElements % (j+1) == 0 && (unmatchedPieces[k] !=  0) && this->isMoveValid(this->correctInputPieces[k], i+1, 0) ){
            
            this->lastColIndex = j; // last index is now set to j
            this->lastRowIndex = (this->numOfElements / (j+1)) -1; // j+1 is always a divider because numOfElements mod j+1 == 0
            
            this->transferAvailableToSolution(i+1, 0, k);
            
            currentSequanceCheck.push_back(correctInputPieces[k].getISD()); //debugging
            bool sol = this->solveGameRec(i+1, 0,currentSequanceCheck);
            currentSequanceCheck.pop_back();
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

    return false;
    // didn't find any matching piece -> try again
}


bool JigsawPuzzle::checkOneRowSol(int i, int j){
    this->lastRowIndex = 0;
    this->lastColIndex = numOfElements-1;
    bool valid = this->checkBottomEdges(j);
    if(!valid){ //not a valid solution
        if(j <= this->numOfElements/2){
            this->lastRowIndex = -1; //reinitialize
            this->lastColIndex = -1; //reinitialize
        }
        return false;
    }
    return true;
}

bool JigsawPuzzle::checkBottomEdges(int j){
    for (int k = 0; k < j; k++){
        if(!(this->correctInputPieces[this->solutionMatrix[0][k]-1].getBottomEdge() == 0))
            return false;
    }
    return true;
    
}

bool JigsawPuzzle::printSolutionToFile(bool solved){
    ofstream outputFile;
    outputFile.open(this->outputFile);
    if (!outputFile.is_open()){
        cout << OUTPUT_FILE_NOT_OPEN;
        return false;
    }
    if(solved){
        for(int i = 0; i<=this->lastRowIndex; i++){
            for(int j =0; j<=this->lastColIndex;j++){
                outputFile << this->solutionMatrix[i][j];
                if(j!=this->lastColIndex)
                    outputFile << " ";
            }
            outputFile << endl;
        }
    }
    else
        outputFile << "Cannot solve puzzle: it seems that there is no proper solution" << endl;
    outputFile.close();
    return solved;
}

vector<int> JigsawPuzzle::hasAllCorners(){
    vector<int> corners = *new vector<int>(4,0);
    for(int i = 0; i<this->numOfElements; i++){
        if(correctInputPieces[i].isTopRightCorner()){
            corners[1] = 1;
        }
        if(correctInputPieces[i].isTopLeftCorner()){
            corners[0] = 1;
        }
        if(correctInputPieces[i].isBotRightCorner()){
            corners[3] = 1;
        }
        if(correctInputPieces[i].isBotLeftCorner()){
            corners[2] = 1;
        }
    }
    return corners;
}


bool JigsawPuzzle::hasEnoughEdges(){
    int count = 0;
    for(int i = 0; i<this->numOfElements; i++){
        count += correctInputPieces[i].countStraightEdges();
    }
    return ((count >= (sqrt(this->numOfElements))) && (count %2==0));
}


bool JigsawPuzzle::isSumEdgesZero(){
    int sum = 0;
    for(int i = 0; i<this->numOfElements; i++){
        sum += correctInputPieces[i].sumEdges();
    }
    
    return sum == 0;
}

bool JigsawPuzzle::isSumHorizontalEdgesZero(){
    int sum = 0;
    for(int i = 0; i < this->numOfElements; i++){
        sum += this->correctInputPieces[i].getTopEdge() + this->correctInputPieces[i].getBottomEdge();
    }

    return sum == 0;
}

bool JigsawPuzzle::isSumVerticalEdgesZero(){
    int sum = 0;
    for(int i = 0; i < this->numOfElements; i++){
        sum += this->correctInputPieces[i].getLeftEdge() + this->correctInputPieces[i].getRightEdge();
    }

    return sum == 0;
}

bool JigsawPuzzle::initSolveGame(){
    return printSolutionToFile(solveGame());

}

bool JigsawPuzzle::isLegalPuzzle(){
    ofstream outputFile;
    outputFile.open(this->outputFile);
    bool legal = true;
    if (!outputFile.is_open()){
        cout << OUTPUT_FILE_NOT_OPEN << endl;
        return false;
    }
    if(!hasEnoughEdges()){
        outputFile << "Cannot solve puzzle: wrong number of straight edges" << endl;
        legal = false;
    }
    vector<int> corners = hasAllCorners();
    if(!corners[0]){
        outputFile << "Cannot solve puzzle: missing corner element: <TL>" << endl;
        legal = false;
    }
    if(!corners[1]){
        outputFile << "Cannot solve puzzle: missing corner element: <TR>" << endl;
        legal = false;
    }
    if(!corners[2]){
        outputFile << "Cannot solve puzzle: missing corner element: <BL>" << endl;
        legal = false;
    }
    if(!corners[3]){
        outputFile << "Cannot solve puzzle: missing corner element: <BR>" << endl;
        legal = false;
    }
    
    if(!isSumEdgesZero()){
        outputFile << "Cannot solve puzzle: sum of edges is not zero" << endl;
        legal = false;

    } else {

        if(!isSumHorizontalEdgesZero()){
            outputFile << "Cannot solve puzzle: sum of horizontal edges is not zero" << endl;
            legal = false;
        }
        if(!isSumVerticalEdgesZero()){
            outputFile << "Cannot solve puzzle: sum of vertical edges is not zero" << endl;
            legal = false;
        }
    }

    outputFile.close();
    return legal;
}

