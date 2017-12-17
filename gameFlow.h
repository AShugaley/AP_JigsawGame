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
#include "JigsawSolutionExistsChecks.h"
#include "JigsawSolutionExistsRotationsAllowed.h"
#include "JigsawPuzzle.h"
#include "JigsawPuzzleRotations.h"

#define WRONG_ARGS "Error: you need to supply input file representing a puzzle game and an output file. '-rotate' flag is optional"


/**
 * Class for holding the flow function, is the container of the game, runs the parsing and then the algo
 */
using namespace std;

class gameFlow {
private:
    char* infile;
    char* outfile;
    bool validCommandParsing = false; //check if format is ok
    bool rotate = false; //isRotations = true?

public:
    gameFlow(int argc, char* argv[]);
    
    //the main function of the flow
    bool runMainFlow();
    
    bool parseCommandLineArgs(int argc, char* argv[]); //parse the command line args
    bool rotateCommandExists(int argc, char* argv[]); //check if "-rotate" applies
    bool getValidCommandParsing(); //getter
};


#endif /* gameFlow_h */
