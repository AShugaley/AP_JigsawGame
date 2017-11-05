//
//  gameFlow.h
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 01/11/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef gameFlow_h
#define gameFlow_h

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
#include "jigsawGame.h"


class gameFlow{
    public:

    static bool simpleMainFlow(const char* inputfilename,  const char* outputfilename);
};

#endif /* gameFlow_h */
