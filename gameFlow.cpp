//
//  gameFlow.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 01/11/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include "gameFlow.h"

using namespace std;

bool gameFlow::simpleMainFlow(char*  infile, char*  outfile){
    string inputFilename(infile);
    string outputFilename(outfile);
    JigsawPuzzle game(inputFilename,outputFilename);
    
    if(!game.isInitialized()){
        return false; // failed to open/read input file OR file was illegal in format
    }
    if(!game.isLegalPuzzle()){
        return false; //puzzle illegal (puzzle cannot be solved due to something like missing corner etc)
    }
    if(!game.initSolveGame()){
        return false; //puzzle cannot be solved as there's no solution.
    }
    return true; // all ok, info is already in output file.
}