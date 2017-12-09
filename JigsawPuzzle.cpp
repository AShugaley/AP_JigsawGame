
#include "JigsawPuzzle.h"


JigsawPuzzle::JigsawPuzzle(vector<PuzzlePiece> pieces){
    this->correctInputPieces = pieces;
    this->piecesMap = PuzzlePiecesMap(correctInputPieces);
    this->cannotComputeSolution = false;
    this->lastColIndex = -1;
    this->lastRowIndex = -1;
    this->numOfElements = (int)pieces.size();
}


JigsawPuzzle::JigsawPuzzle(string& inputFilePath, string& outputFilePath) : outputFile(outputFilePath), cannotComputeSolution(false),lastRowIndex(-1), lastColIndex(-1) ,piecesMap(PuzzlePiecesMap()){
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
                if(this->correctInputPieces[this->solutionMatrix[i][j]-1].getAngle() != 0){
                    outputFile << "[" << correctInputPieces[this->solutionMatrix[i][j]-1].getAngle() << "]" << " ";
                }
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
    vector<int> corners = vector<int>(4,0);
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
    return printSolutionToFile(initSolve());
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


// Helper function for solving game algorithm

pair<int,int> JigsawPuzzle::getNextPos(int i, int j){
    for(int k = 0; k<numOfElements-1;k++)
        if(this->positionsToFill[k] == pair<int,int>(i,j))
            return positionsToFill[k+1];
    return pair<int,int>(-1,-1);
}




void JigsawPuzzle::Spiral( int m, int n){
    while (!this->positionsToFill.empty())
    {
        this->positionsToFill.pop_back();
    }
    int i, k = 0, l = 0;
    
    /*  k - starting row index
     m - ending row index
     l - starting column index
     n - ending column index
     i - iterator
     */
    
    while (k < m && l < n){
        for (i = l; i < n; ++i){
            this->positionsToFill.push_back(pair<int,int>(k,i));
        }
        k++;
        
        for (i = k; i < m; ++i){
            this->positionsToFill.push_back(pair<int,int>(i,n-1));
        }
        n--;
        
        if ( k < m){
            for (i = n-1; i >= l; --i){
                this->positionsToFill.push_back(pair<int,int>(m-1,i));
            }
            m--;
        }
        
        /* Print the first column from the remaining columns */
        if (l < n){
            for (i = m-1; i >= k; --i){
                this->positionsToFill.push_back(pair<int,int>(i,l));
                // printf("%d ", a[i][l]);
            }
            l++;
        }
    }
}

vector<pair<int,int> > JigsawPuzzle::getPossibleDimensions(int numOfPieces) {
    vector<pair<int, int> > dim;
    for (int i = 1; i <= sqrt(numOfPieces); i++) {
        if (numOfPieces % i == 0) {
            dim.push_back(std::pair<int, int>(i, numOfPieces / i));
            if (i != (numOfPieces / i))
                dim.push_back(std::pair<int, int>(numOfPieces / i, i));
        }
    }

    std::random_shuffle(dim.begin(), dim.end());
    return dim;
}

PuzzleRequirement JigsawPuzzle::getReq(int i, int j){
    int l, r, t,b;

    if(j==0){
        l = 0;
    } else {
        if(this->solutionMatrix[i][j-1] == -1)
            l = JOKER;
        else
            l =  (-1)*this->correctInputPieces[this->solutionMatrix[i][j-1] - 1].getRightEdge();
    }

    if(i==0) {
        t = 0;
    } else{
        if(this->solutionMatrix[i-1][j] == -1)
            t = JOKER;
        else
            t =  (-1)*this->correctInputPieces[this->solutionMatrix[i-1][j] - 1].getBottomEdge();
    }

    if(j==lastColIndex) {
        r = 0;
    } else{
        if(this->solutionMatrix[i][j+1] == -1)
            r = JOKER;
        else
            r =  (-1)*this->correctInputPieces[this->solutionMatrix[i][j+1] - 1].getLeftEdge();
    }

    if(i==lastRowIndex) {
        b = 0;
    } else{
        if(this->solutionMatrix[i+1][j] == -1)
            b = JOKER;
        else
            b =  (-1)*this->correctInputPieces[this->solutionMatrix[i+1][j] - 1].getTopEdge();
    }

    return PuzzleRequirement(l,t,r,b);
}

void JigsawPuzzle::initSolMatrix(){
    this->solutionMatrix = std::vector< std::vector<int> >((size_t) this->lastRowIndex + 1, std::vector<int>((size_t) this->lastColIndex+1));
    for (int i = 0; i < this->lastRowIndex+1; i++)
        for (int j = 0; j < this->lastColIndex+1; j++)
            this->solutionMatrix[i][j] = -1;

}

// Solving the game algorithm part

bool JigsawPuzzle::initSolve(){
    this->piecesMap = PuzzlePiecesMap(this->correctInputPieces);
    return beginMainAlgo();
}

bool JigsawPuzzle::beginMainAlgo(){
    vector<pair<int,int> > possibleDimensions = getPossibleDimensions(this->numOfElements);
    pair<int,int> topLeftCorner = pair<int,int>(0,0);
    for( auto& p : possibleDimensions){
        this->lastRowIndex = p.first-1;
        this->lastColIndex = p.second-1;
        initSolMatrix();
        Spiral(lastRowIndex+1, lastColIndex+1);
        if(solveRec(topLeftCorner) == true)
            return true;
    }
    this->lastRowIndex = -1;
    this->lastColIndex = -1;
    return false;
}

bool JigsawPuzzle::solveRec(pair<int,int> nextPos){
    int i = nextPos.first;
    int j = nextPos.second;
    if(i ==-1 || j ==-1){
        return true;
    }
    PuzzleRequirement req = getReq(i, j);
    PuzzlePiece* p = getNextPiece(req);
    while(p!=nullptr){
        this->solutionMatrix[i][j] = p->getISD();
        if(solveRec(getNextPos(i, j)))
            return true;
        else{
            this->solutionMatrix[i][j] = -1;
            p->setUsed(false);
            req.addFalseType(PuzzleType(p->getLeftEdge(), p->getTopEdge(), p->getRightEdge(), p->getBottomEdge())); //we can add all 4 false types -> or change req
            p->resetRotation();
            p = getNextPiece(req);
        }
    }
    return false;


}

 PuzzlePiece* JigsawPuzzle::getNextPiece(PuzzleRequirement req){
     return this->piecesMap.nextPiece(req);
 }

