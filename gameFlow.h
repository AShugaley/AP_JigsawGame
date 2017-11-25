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
 A module responisble for the game flow. Essentially, this is simply an extension to main.c
 */


#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <unordered_map>
#include "JigsawPuzzle.h"

class gameFlow {
public:
    static bool simpleMainFlow(char* infile, char* outfile);
    
};


#endif /* gameFlow_h */
