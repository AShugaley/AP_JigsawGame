//
// Created by okleinfeld on 12/15/17.
//

#include "SolutionAlgorithm.h"


SolutionAlgorithm::SolutionAlgorithm(unique_ptr<JigsawGameInterface> game, unique_ptr<PuzzlePieceMapInterface> piecesMap,vector<PuzzlePiece> pieces){
    this->game = std::move(game);
    this->piecesMap = std::move(piecesMap);
    this->pieces = pieces;
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
}


bool SolutionAlgorithm::solveGame(int numOfThreads, bool rotate){
    bool solved = false;
    int puzzleSize = this->game->getPuzzleSize();
    vector<pair<int,int> > possibleDimensions = this->getPossibleDimensions(puzzleSize);
    
    if(numOfThreads == 1){
        SolutionAlgorithmRunningSuite SA = SolutionAlgorithmRunningSuite(std::move(game), std::move(piecesMap));
        solved = SA.solveGame(possibleDimensions);
        this->game = std::move(SA.game);
        this->piecesMap = std::move(SA.piecesMap);
        return solved;
    }
    Factory factory = Factory(rotate); //deside in which mode do we start the game
    vector<JigsawSolutionThread> threads;
    int currentNumOfThreads = 1;
    std::chrono::milliseconds span (50);
    while(!possibleDimensions.empty() || !threads.empty()){
        while((currentNumOfThreads < numOfThreads) && !possibleDimensions.empty()){
            
            
        //    threads.push_back(JigsawSolutionThread(SA, f));
            future<pair<bool,unique_ptr<JigsawGameInterface> > > f;
            threads.push_back(JigsawSolutionThread(std::unique_ptr<SolutionAlgorithmRunningSuite>(new SolutionAlgorithmRunningSuite(factory.getJigsawGame(pieces), factory.getPuzzleMap(pieces))), f));
           // JigsawSolutionThread t =
            //std::unique_ptr<SolutionAlgorithmRunningSuite>(new SolutionAlgorithmRunningSuite(factory.getJigsawGame(pieces), factory.getPuzzleMap(pieces)));
            
     
            pair<int,int> p = possibleDimensions.back();
            possibleDimensions.pop_back();
    
            threads.back().f = std::async(std::launch::async, &SolutionAlgorithmRunningSuite::solveGamePair,SolutionAlgorithmRunningSuite(factory.getJigsawGame(pieces), factory.getPuzzleMap(pieces)) , p.first, p.second);
            //threads.push_back(JigsawSolutionThread(SA, f));
            currentNumOfThreads++;

        }
        int i = 0;
        for(auto it = threads.begin(); it < threads.end(); it++,i++ ){
            auto &t = threads[i];
            if(t.isFinished()){
                if(t.isSolved()){
                    this->game = t.getGame();
                    //this->piecesMap = t.getPiecesMap();
                    return true;
                }
                else{
                    threads.erase(threads.begin()+i);
                    currentNumOfThreads--;
                    i--;
                    //break;
                }
            }
        }
    }
    return 0;
}

void SolutionAlgorithm::printSolutionToFile(string& outputFilePath, bool solved){
    this->game->printSolutionToFile(outputFilePath, solved);
}
