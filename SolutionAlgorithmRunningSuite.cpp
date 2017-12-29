//
//  SolutionAlgorithmRunningSuite.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 23/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include "SolutionAlgorithmRunningSuite.h"


SolutionAlgorithmRunningSuite::SolutionAlgorithmRunningSuite(unique_ptr<JigsawGameInterface> game, unique_ptr<PuzzlePieceMapInterface> piecesMap){
    this->game = std::move(game);
    this->piecesMap = std::move(piecesMap);
}


bool SolutionAlgorithmRunningSuite::solveRec(pair<int,int> nextPos){
    int i = nextPos.first;
    int j = nextPos.second;
    if (i ==-1 || j ==-1){
        return true;
    }
    PuzzleRequirement req = game->getReq(i, j);
    PuzzlePiece* p = piecesMap->nextPiece(req);
    while(p!=nullptr){
        game->updatePuzzlePieceInSolution(i, j, p);
        bool solved = solveRec(game->getNextPos(i,j));
        if (solved){
            return true;
        }
        else{
            req.addFalseType(PuzzleType(p->getLeftEdge(), p->getTopEdge(), p->getRightEdge(), p->getBottomEdge()));
            game->revertPuzzlePieceFromSolution(i, j, p);
            p = piecesMap->nextPiece(req);
        }
    }
    return false;
}



bool SolutionAlgorithmRunningSuite::solveGame(vector<pair<int,int> > possibleDimensions){
    pair<int,int> topLeftCorner = pair<int,int>(0,0);
    for (auto& p : possibleDimensions){
        this->game->initiateSolutionTry(p);
        if(solveRec(topLeftCorner) == true){
            return true;
        }
    }
    return false;
}

pair<bool,unique_ptr<JigsawGameInterface> > SolutionAlgorithmRunningSuite::solveGamePair(int i, int j){
    pair<int,int> topLeftCorner = pair<int,int>(0,0);
    this->game->initiateSolutionTry(pair<int,int>(i,j));
    if(solveRec(topLeftCorner) == true){
        return pair<bool,unique_ptr<JigsawGameInterface> >(true, move(this->game));
       // return true;
    }

    return pair<bool,unique_ptr<JigsawGameInterface> >(false,nullptr);
}
