//
//  jigsawGame.hpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 03/11/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef jigsawGame_h
#define jigsawGame_h

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

#include "jigsawElem.h"

class jigsawGame{
    int gameSize;
    bool gameInitilized;
    std::vector<jigsawElem> pieces;
    std::vector<std::vector<int> > solutionBoard;
    
public:
    jigsawGame(char* filename){
        gameInitilized = readGameFromFile(filename);
    }
    
    
    //initilize game and check for format errors
    bool readGameFromFile(char* filename);
    
    bool solveGame(); // solveGameWithNaiveAI() + writeSolutionToFile()
    bool isInitilized() {return gameInitilized;}
    bool isLegalPuzzle(); //{ return (isSumEdgesZero() && hasAllCorners() && hasEnoughEdges());)

    //setters + getters
    void setGameSize(int newSize){ gameSize = newSize; }
    int getGameSize(){ return gameSize; }
    
private:
    
    
    // check for obvious errors
    bool isSumEdgesZero();
    bool hasAllCorners();
    bool hasEnoughEdges();
    
    // write in format, @pre -> solutionBoard already has a valid solution
    void writeSolutionToFile();
    
    
    
    bool solveGameWithNaiveAI();
    
    //AI functions
    bool isValidNextPiece(jigsawElem candidate);

    
};






#endif /* jigsawGame_h */




/*
 
 a class represnting a Jigsaw game
 
 should include the following variables: set of pieces (jigsawElem), numOfPieces(int), solutionBoard (double array of jigsawElems[numOfPieces][numOfPieces])
 
 
 
 
 
 
 
 
 */
