//
// Created by okleinfeld on 12/15/17.
//

#include "SolutionAlgorithm.h"


SolutionAlgorithm::SolutionAlgorithm(JigsawGameInterface *game, PuzzlePieceMapInterface* piecesMap)
        : game(game), piecesMap(piecesMap) {;}



bool SolutionAlgorithm::solveRec(pair<int,int> nextPos){
    int i = nextPos.first;
    int j = nextPos.second;
    if (i ==-1 || j ==-1){
        return true;
    }
    PuzzleRequirement req = game->getReq(i, j);
    PuzzlePiece* p = piecesMap->nextPiece(req);
    while(p!=nullptr){
        game->updatePuzzlePieceInSolution(0, 0, p);
        bool solved = solveRec(game->getNextPos(i,j));
        if (solved){
            return true;
        }
        else{
            req.addFalseType(PuzzleType(p->getLeftEdge(), p->getTopEdge(), p->getRightEdge(), p->getBottomEdge()));
            game->revertPuzzlePieceFromSolution(0, 0, p);
            p = piecesMap->nextPiece(req);
        }
    }
    return false;
}


vector<pair<int,int> > SolutionAlgorithm::getPossibleDimensions(int size){
    vector<pair<int, int> > dim;
    for (int i = 1; i <= sqrt(size); i++) {
        if (size % i == 0) {
            dim.emplace_back(std::pair<int, int>(i, size / i));
            if (i != (size / i))
                dim.emplace_back(std::pair<int, int>(size / i, i));
        }
    }

    std::random_shuffle(dim.begin(), dim.end());
    return dim;
};


bool SolutionAlgorithm::solveGame(){
    int puzzleSize = this->game->getPuzzleSize();
    vector<pair<int,int> > possibleDimensions = this->getPossibleDimensions(puzzleSize);
    pair<int,int> topLeftCorner = pair<int,int>(0,0);
    for (auto& p : possibleDimensions){
        this->game->initiateSolutionTry(p);
        if(solveRec(topLeftCorner) == true){
            return true;
        }
    }
    return false;
}