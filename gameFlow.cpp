//
//  gameFlow.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 01/11/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include "gameFlow.h"

using namespace std;

bool gameFlow::simpleMainFlow(char* argv[], int argc){
    bool rotate = false;
    bool first = true;
    string inputFilename;
    string outputFilename;
    for(int i = 1; i<argc;i++){
        if(strcmp(argv[i], "-rotate") == 0){
            rotate = true;
        }
        else{
            if(first){
                inputFilename = argv[i];
                first = false;
            }
            else{
                outputFilename = argv[i];
            }
        }
    }
    JigsawPuzzleRotate game(inputFilename,outputFilename);
    
    if(!game.isInitialized()){
        return false; // failed to open/read input file OR file was illegal in format
    }
//    if(!game.isLegalPuzzle()){
//        return false; //puzzle illegal (puzzle cannot be solved due to something like missing corner etc)
//    }
    if(!game.initSolveGame()){
        return false; //puzzle cannot be solved as there's no solution.
    }
    return true; // all ok, info is already in output file.
}
