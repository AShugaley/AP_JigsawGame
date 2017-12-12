//
//  gameFlow.h
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 17/11/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef gameFlow_h
#define gameFlow_h

/* 
 A module responsible for the game flow. Essentially, this is simply an extension to main.c
 */

#include "JigsawParser.h"
#include "JigsawSolutionExistsChecks.h"
#include "JigsawPuzzle.h"

class gameFlow {
private:
    char* infile;
    char* outfile;
public:
    gameFlow(char* input, char* output);
    static bool runMainFlow(char *infile, char *outfile);
    bool runMainFlow();
};


#endif /* gameFlow_h */
