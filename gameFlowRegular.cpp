//
//  gameFlow.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 01/11/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include "gameFlowRegular.h"

using namespace std;

gameFlow::gameFlow(char* input, char* output): infile(input), outfile(output){}

bool gameFlow::runMainFlow(){
    string inputFilename(this->infile);
    string outputFilename(this->outfile);

    JigsawParser parser = JigsawParser(inputFilename, outputFilename);
    bool validParsing = parser.isInitialized();
    if (!validParsing){
        if (!parser.fileError()){
            parser.writeErrorsToOutput();
        }
        return false;
    }

    vector<PuzzlePiece> pieces = parser.getCorrectInputPieces();
    JigsawSolutionExistsChecks puzzleCheck = JigsawSolutionExistsChecks(pieces);
    bool checkResult = puzzleCheck.checkIfPuzzleIsLegal();
    if (!checkResult){
        puzzleCheck.writeToFileFailedTests(outputFilename);
        return false;
    }

    JigsawPuzzle puzzle = JigsawPuzzle(pieces);
    bool solved = puzzle.solveGame();
    puzzle.printSolutionToFile(outputFilename);

    return solved;



//    JigsawPuzzleOLD game(inputFilename,outputFilename);
//
//    if(!game.isInitialized()){
//        return false; // failed to open/read input file OR file was illegal in format
//    }
//    if(!game.isLegalPuzzle()){
//        return false; //puzzle illegal (puzzle cannot be solved due to something like missing corner etc)
//    }
//    if(!game.initSolveGame()){
//        return false; //puzzle cannot be solved as there's no solution.
//    }
//    return true; // all ok, info is already in output file.
}