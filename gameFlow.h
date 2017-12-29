//
//  gameFlow.h
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 17/11/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef gameFlow_h
#define gameFlow_h



#include "JigsawParser.h"
#include "SolutionAlgorithm.h"
#include "Factory.h"
#include <ctype.h>

#define ROTATION_FLAG "-rotate"
#define THREADS_FLAG "-threads"
#define USAGE_MSG "Error: The argument after -threads flag has to be a natural number\n"
#define WRONG_ARGS "Error: Wrong arguments. You need to supply input file representing a puzzle game and an output file. '-rotate' and -threads flags are optional\n"

using namespace std;
/**
* Class for holding the flow function, is the container of the game, runs the parsing and then the algorithm
*/
class gameFlow {
private:
    char* infile;
    char* outfile;
    bool validCommandParsing = false; //check if format is ok
    bool rotate = false; //isRotations = true?
    int numOfThreads = 4; 

public:
    gameFlow(int argc, char* argv[]);
    
    
    bool runMainFlow(); //the main function of the flow
    bool parseCommandLineArgs(int argc, char* argv[]); //parse the command line args
    bool getValidCommandParsing(); //getter
};


#endif /* gameFlow_h */
