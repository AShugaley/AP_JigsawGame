//
//  jigsawElem.h
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 04/11/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef jigsawElem_h
#define jigsawElem_h
#include <stdio.h>

class jigsawElem{
    int leftEdge, topEdge, rightEdge, botEdge;
    int idNumber;
    
public:
    jigsawElem(int idNumber, int leftEdge, int topEdge, int rightEdge, int botEdge) : idNumber(idNumber), leftEdge(leftEdge), topEdge(topEdge), rightEdge(rightEdge), botEdge(botEdge) {}
    
    
    bool isTopLeftCorner(){ return ((leftEdge == 0)&&(topEdge == 0));}
    bool isTopRightCorner(){ return ((rightEdge == 0)&&(topEdge == 0));}
    bool isBotLeftCorner(){ return ((leftEdge == 0)&&(botEdge == 0));}
    bool isBotRightCorner(){ return ((rightEdge == 0)&&(botEdge == 0));}
    int countStraightEdges(){return (leftEdge==0) + (topEdge==0) + (rightEdge==0) + (botEdge==0);}
    int sumEdges(){return leftEdge + rightEdge + topEdge + botEdge;}

    
};
#endif /* jigsawElem_h */
