//
//  main.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 01/11/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include <iostream>
#include "gameFlow.h"


int main(int argc, const char * argv[]) {
    char const *in = "/Users/alexs/dev/APEX1/AdvProgEX1/AdvProgEX1/test_files/in4.txt";
    char const *out = "/Users/alexs/dev/APEX1/AdvProgEX1/AdvProgEX1/test_files/test4.txt";
    gameFlow::simpleMainFlow(in,out);
}



/*
 
 so essentially we have
 
 jigSaw input+output to files
 jigSaw algo
 
 algo will be implemented as a CLASS, which can then be inherited by better versions of the algo
 
 input/output in a class, represent the game by a set of jigsawElem's

 
 
 the basic game flow will be implemented in a seperate file (gameFlow) - this will include functions for all basic flows (starting from one). This function or set of functions will be resposible for, you know, the event loop
 
 
 
 so-> main calles gameFlow -> calles input, AI, output. 
 
 in the future -> a new AI inhereting from the current one, a new game flow (just one func)

*/




