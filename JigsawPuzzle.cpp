//
// Created by okleinfeld on 12/12/17.
//

#include "JigsawPuzzle.h"

JigsawPuzzle::JigsawPuzzle(vector<PuzzlePiece> pieces){
    this->puzzlePieces = pieces;
    this->piecesMap = PuzzlePiecesMap(this->puzzlePieces);
    this->lastColIndex = -1;
    this->lastRowIndex = -1;
    this->numPieces = (int) this->puzzlePieces.size();
    this->puzzleSolvedSuccessfully = false;
}


vector<vector<int>>& JigsawPuzzle::getSolutionMatrix(){
    return this->solutionMatrix;
}

int JigsawPuzzle::getSolutionMatrixNumRows(){
    return this->lastRowIndex + 1;
}
int JigsawPuzzle::getSolutionMatrixNumCols() {
    return this->lastColIndex + 1;
}


void JigsawPuzzle::initSolMatrix(){
    this->solutionMatrix = std::vector< std::vector<int> >((size_t) this->lastRowIndex + 1, std::vector<int>((size_t) this->lastColIndex + 1));
    for (int i = 0; i < this->lastRowIndex+1; i++)
        for (int j = 0; j < this->lastColIndex+1; j++)
            this->solutionMatrix[i][j] = -1;
}

PuzzleRequirement JigsawPuzzle::getReq(int i, int j){
    int l, r, t,b;

    if(j==0){
        l = 0;
    } else {
        if(this->solutionMatrix[i][j-1] == -1)
            l = JOKER;
        else
            l =  (-1)*this->puzzlePieces[this->solutionMatrix[i][j-1] - 1].getRightEdge();
    }

    if(i==0) {
        t = 0;
    } else{
        if(this->solutionMatrix[i-1][j] == -1)
            t = JOKER;
        else
            t =  (-1)*this->puzzlePieces[this->solutionMatrix[i-1][j] - 1].getBottomEdge();
    }

    if(j==lastColIndex) {
        r = 0;
    } else{
        if(this->solutionMatrix[i][j+1] == -1)
            r = JOKER;
        else
            r =  (-1)*this->puzzlePieces[this->solutionMatrix[i][j+1] - 1].getLeftEdge();
    }

    if(i==lastRowIndex) {
        b = 0;
    } else{
        if(this->solutionMatrix[i+1][j] == -1)
            b = JOKER;
        else
            b =  (-1)*this->puzzlePieces[this->solutionMatrix[i+1][j] - 1].getTopEdge();
    }

    return PuzzleRequirement(l,t,r,b);
}

vector<pair<int,int> > JigsawPuzzle::getPossibleDimensions() {
    int numOfPieces = this->numPieces;
    vector<pair<int, int> > dim;
    for (int i = 1; i <= sqrt(numOfPieces); i++) {
        if (numOfPieces % i == 0) {
            dim.emplace_back(std::pair<int, int>(i, numOfPieces / i));
            if (i != (numOfPieces / i))
                dim.emplace_back(std::pair<int, int>(numOfPieces / i, i));
        }
    }

    std::random_shuffle(dim.begin(), dim.end());
    return dim;
}

pair<int,int> JigsawPuzzle::getNextPos(int i, int j){
    if(j!=lastColIndex){
        return pair<int,int>(i,j+1);
    }
    if(i!=lastRowIndex){
        return pair<int,int>(i+1,0);
    }
    return pair<int,int>(-1,-1);
}

bool JigsawPuzzle::solveRec(pair<int,int> nextPos){
    int i = nextPos.first;
    int j = nextPos.second;
    if (i ==-1 || j ==-1){
        return true;
    }
    PuzzleRequirement req = getReq(i, j);
    PuzzlePiece* p = this->piecesMap.nextPiece(req);
    while(p!=nullptr){
        this->solutionMatrix[i][j] = p->getISD();
        if(solveRec(getNextPos(i, j)))
            return true;
        else{
            this->solutionMatrix[i][j] = -1;
            p->setUsed(false);
            req.addFalseType(PuzzleType(p->getLeftEdge(), p->getTopEdge(), p->getRightEdge(), p->getBottomEdge()));
            p = this->piecesMap.nextPiece(req);
        }
    }
    return false;
}

bool JigsawPuzzle::solveGame(){
    vector<pair<int,int> > possibleDimensions = getPossibleDimensions();
    pair<int,int> topLeftCorner = pair<int,int>(0,0);
    for( auto& p : possibleDimensions){
        this->lastRowIndex = p.first-1;
        this->lastColIndex = p.second-1;
        initSolMatrix();
        if(solveRec(topLeftCorner) == true){
            this->puzzleSolvedSuccessfully = true;
            return true;
        }
    }

    this->lastRowIndex = -1;
    this->lastColIndex = -1;
    return false;
}

bool JigsawPuzzle::printSolutionToFile(string& outputFile){
    ofstream outputFileStream;
    outputFileStream.open(outputFile);
    if (!outputFileStream.is_open()){
        cout << OUTPUT_FILE_NOT_OPEN;
        return false;
    }
    if(this->puzzleSolvedSuccessfully){
        for(int i = 0; i <= this->lastRowIndex; i++){
            for(int j =0; j <= this->lastColIndex; j++){
                int currentPieceISD = this->solutionMatrix[i][j];
                int currentPieceVectorIndex = currentPieceISD -1;

                outputFileStream << currentPieceISD;
                if(this->puzzlePieces[currentPieceVectorIndex].getAngle() != 0){
                    outputFileStream << " [" << puzzlePieces[currentPieceVectorIndex].getAngle() << "]";
                }

                if (j != this->lastColIndex){
                    outputFileStream << " ";
                }
            }
            outputFileStream << endl;
        }

    } else{
        outputFileStream << "Cannot solve puzzle: it seems that there is no proper solution" << endl;
    }
    outputFileStream.close();
    return true;

}