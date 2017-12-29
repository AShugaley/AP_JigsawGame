//
//  JigsawSolutionThread.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 23/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include "JigsawSolutionThread.h"

JigsawSolutionThread::JigsawSolutionThread(unique_ptr<SolutionAlgorithmRunningSuite> solution, future<pair<bool,unique_ptr<JigsawGameInterface> > > &f){
    this->solution = std::move(solution);
    this->f = std::move(f);
    span = std::chrono::milliseconds (10);

}


bool JigsawSolutionThread::isFinished(){
    return this->f.wait_for(span)!=std::future_status::timeout;
}
bool JigsawSolutionThread::isSolved(){
    auto p = f.get();
    this->game = move(p.second);
    return p.first;
}
unique_ptr<JigsawGameInterface> JigsawSolutionThread::getGame(){
    return move(this->game);
}
unique_ptr<PuzzlePieceMapInterface> JigsawSolutionThread::getPiecesMap(){
    return move(this->solution->piecesMap);
}
