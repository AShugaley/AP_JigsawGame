//
//  JigsawSolutionThread.h
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 23/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef JigsawSolutionThread_h
#define JigsawSolutionThread_h
#define DELAY = 50


#include "SolutionAlgorithmRunningSuite.h"
#include <chrono>

#include <future>

class JigsawSolutionThread{
public:
    unique_ptr<SolutionAlgorithmRunningSuite> solution;
    unique_ptr<JigsawGameInterface> game;
    future<pair<bool,unique_ptr<JigsawGameInterface> > > f;
    std::chrono::milliseconds span;
    
public:
    
    JigsawSolutionThread(unique_ptr<SolutionAlgorithmRunningSuite> solution, future<pair<bool,unique_ptr<JigsawGameInterface> > > &f);
    bool isFinished();
    bool isSolved();
    unique_ptr<JigsawGameInterface> getGame();
    unique_ptr<PuzzlePieceMapInterface> getPiecesMap();
    
};

#endif /* JigsawSolutionThread_h */
