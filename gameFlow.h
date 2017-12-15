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

#define WRONG_ARGS "Error: you need to supply input file representing a puzzle game and an output file. '-rotate' flag is optional"

using namespace std;

class gameFlow {
private:
    char* infile;
    char* outfile;
    bool validCommandParsing = false;
    bool rotate = false;

public:
    gameFlow(int argc, char* argv[]);
    bool runMainFlow();
    bool parseCommandLineArgs(int argc, char* argv[]);
    bool rotateCommandExists(int argc, char* argv[]);
    bool getValidCommandParsing();
};


#endif /* gameFlow_h */
