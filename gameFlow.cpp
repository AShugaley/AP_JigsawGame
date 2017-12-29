//
//  gameFlow.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 01/11/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include "gameFlow.h"

using namespace std;

gameFlow::gameFlow(int argc, char* argv[]){
    bool valid = this->parseCommandLineArgs(argc, argv);
    if (valid){ //if the command line args are fine
        validCommandParsing = true;
    }
}


bool gameFlow::runMainFlow(){

    string inputFilename(this->infile);
    string outputFilename(this->outfile);

    JigsawParser parser = JigsawParser(inputFilename, outputFilename); //parse the game
    bool validParsing = parser.isInitialized(); //check if parsing worked
    if (!validParsing){ //if not - write the errors
        if (!parser.fileError()){
            parser.writeErrorsToOutput();
        }
        return false;
    }

    vector<PuzzlePiece> pieces = parser.getCorrectInputPieces(); //get the pieces vector from the game
    bool rotationAllowed = this->rotate; //check if we are in rotation mode
    int numOfThreads = this->numOfThreads;
    Factory factory = Factory(rotationAllowed); //deside in which mode do we start the game

    unique_ptr<NaiveSolutionExistenceCheck> solutionChecker = factory.getSolutionExistenceChecker(pieces); //
    bool puzzleValid = solutionChecker->checkIfPuzzleIsLegal(); //check trivial
    if (!puzzleValid){
        solutionChecker->writeToFileFailedTests(outputFilename);
        return false;
    }

    unique_ptr<JigsawGameInterface> game = factory.getJigsawGame(pieces); //now the game itself
    unique_ptr<PuzzlePieceMapInterface> piecesMap = factory.getPuzzleMap(pieces);

    SolutionAlgorithm solutionAlgorithm = SolutionAlgorithm(std::move(game), std::move(piecesMap),pieces);
    bool solved = solutionAlgorithm.solveGame(numOfThreads,rotationAllowed); //now we solve the game
    solutionAlgorithm.printSolutionToFile(outputFilename, solved); //and print to file
    return solved;
}

bool gameFlow::parseCommandLineArgs(int argc, char* argv[]){
    if (argc < 3 || argc > 6){
        cout << WRONG_ARGS << endl;
        return false;
    }
    string rotationFlagString = ROTATION_FLAG;
    string threadsFlagName = THREADS_FLAG;
    int otherChars = 0;
    
    for(int i = 1; i<argc; i++){
        if (rotationFlagString.compare(argv[i]) == 0){
            this->rotate = true;
            continue;
        }
        if(threadsFlagName.compare(argv[i]) == 0){
            char* nextArg = argv[++i];
            for(int j = 0; j < (int) strlen(nextArg) - 1; j++){
                if(!isdigit(nextArg[j])){
                    cout << USAGE_MSG << endl;
                    return false;
                }
            }
            this->numOfThreads = atoi(nextArg);
            continue;
        }
        
        otherChars++;
        if(otherChars == 1)
            this->infile = argv[i];
        if(otherChars == 2)
            this->outfile = argv[i];
        if(otherChars > 2){
            cout <<  WRONG_ARGS << endl;
            return false;
        }
    }
    return true;
}

bool gameFlow::getValidCommandParsing(){
    return this->validCommandParsing;
}
