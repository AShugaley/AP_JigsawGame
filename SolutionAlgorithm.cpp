//
// Created by okleinfeld on 12/15/17.
//

#include "SolutionAlgorithm.h"


SolutionAlgorithm::SolutionAlgorithm(unique_ptr<JigsawGameInterface> game, unique_ptr<PuzzlePieceMapInterface> piecesMap){
    this->game = std::move(game);
    this->piecesMap = std::move(piecesMap);
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


bool SolutionAlgorithm::solveGame(int numOfThreads){
//    bool solved = false;
//    int puzzleSize = this->game->getPuzzleSize();
//    vector<pair<int,int> > possibleDimensions = this->getPossibleDimensions(puzzleSize);
//    
//    if(numOfThreads == 1){
//        SolutionAlgorithmRunningSuite SA = SolutionAlgorithmRunningSuite(game.get(), piecesMap.get());
//        solved = SA.solveGame(possibleDimensions);
//
//        return solved;
//    }
//    
//    while(!possibleDimensions.empty()){
//        while(numOfThreads > 0){
//           // JigsawGameInterface * games = game.get();
//    
//           // SolutionAlgorithmRunningSuite SA = SolutionAlgorithmRunningSuite(game.get(), piecesMap.get());
//        }
//    }
//    
//
    return 0;
}

void SolutionAlgorithm::printSolutionToFile(string& outputFilePath, bool solved){
    this->game->printSolutionToFile(outputFilePath, solved);
}
