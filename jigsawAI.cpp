//
//  jigsawAI.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 01/11/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include "jigsawAI.hpp"




/*

 
 a module resposible for the naive algoritem, all functions static

 
 
 functions:
 solvePuzzle
 
 
 
 
 
 
 _____________________________
 below is a suggestion to the general flow of the program, some of it will be implemented in other classes, and not here - this is the idea only!
 
 _____________________________
 

THE ALGORITEM (suggestion):

brute force.

first, check if we have enough stright edges (numberOfStrightEdges%2==0 && numberOfStrightEdges > numberOfPieces + 3) => not sure about the last part, we might have a better boudary.

then, check if we have all 4 corners (in order)

check sumOfEdges == 0
 
 
now the actual solution: 
 
    the idea: simply iterate until we find a valid piece (for the next position) - if yes, remove it from the set of pieces and try to find the next piece (recursion). If the set is empty at some point - we found a solution. If all iterations are over - there's no solution.

try to solve:
    for pieces.each
        if piece.isValidTL-corner
            temp = currentPiece
            pieces.remove(currentPiece)
            recursiveAlgo(pieces)
            pueces.add(temp)
        
 
 
 
 recursiveAlgo(pieces)
    if(pieces.empty)
        return (we found a solution!) => need to save the order somewhere
    for pieces.each
        if(isValidNextPiece(game, currentPiece)
            temp = currentPiece
            pieces.remove(currentPiece)
            recursiveAlgo(pieces)
            pueces.add(temp)


*/
