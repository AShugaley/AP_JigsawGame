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
        return 0; // failed to open/read input file OR file was illegal in format
    }
    if(!game.isLegalPuzzle()){
        return 0; //puzzle illegal (puzzle cannot be solved due to something like missing corner etc)
    }
    if(!game.initSolveGame()){
        return 0; //puzzle cannot be solved as there's no solution.
    }
    
    return 1; // all ok, info is already in output file.
}




/*
 
 
 there are 3 different errors:
 
 1. input file format - cannot be open/missing ID's/too many ID's/wrong format
        this is checked at the constructor, verify by isInitialized()
 
 
 2. puzzle has no solution - not enough edges, missing corners, sum != 0
        this is checked in isLegalPuzzle()
 
 
 3. puzzle has no solution - our algorithm did not find one
        this is checked in solveGame
 
 all three parts will write their output directly to stdout
 
 */
