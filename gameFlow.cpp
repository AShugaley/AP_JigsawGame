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
    bool rotationAllowed = this->rotate; //check if we are in the rotation mode

    if (rotationAllowed){ //start the solving algo in rotation mode
        JigsawSolutionExistsRotationsAllowed puzzleCheck = JigsawSolutionExistsRotationsAllowed(pieces); //create new check puzzle
        bool checkResult = puzzleCheck.checkIfPuzzleIsLegal(); //check trivical issues
        if (!checkResult){
            puzzleCheck.writeToFileFailedTests(outputFilename);
            return false;
        }

        JigsawPuzzleRotations puzzle = JigsawPuzzleRotations(pieces); //create new puzzle
        bool solved = puzzle.solveGame(); //run the algo for solution
        puzzle.printSolutionToFile(outputFilename); //print the solution of 'Can't solve"
        return solved;
    }

    else{ //start the algo in calssic mode
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
    }
}

bool gameFlow::rotateCommandExists(int argc, char* argv[]){
    string rotateCommandString = "-rotate";
    for (int i = 1; i < argc; i++){
        if (rotateCommandString.compare(argv[i]) == 0){
            return true;
        }
    }
    return false;
}

bool gameFlow::parseCommandLineArgs(int argc, char* argv[]){
    if (argc < 3 || argc > 4){
        cout << WRONG_ARGS << endl;
        return false;
    }

    if (argc == 4){
        bool rotateExists = this->rotateCommandExists(argc, argv);
        if (!rotateExists){
            cout <<  WRONG_ARGS << endl;
            return false;
        }

        this->rotate = true;
        string rotationFlagString = "-rotate";
        if (rotationFlagString.compare(argv[1]) == 0){
            this->infile = argv[2];
            this->outfile = argv[3];

        } else if (rotationFlagString.compare(argv[2]) == 0){
            this->infile = argv[1];
            this->outfile = argv[3];

        } else{
            this->infile = argv[1];
            this->outfile = argv[2];
        }
    }

    else{
        this->infile = argv[1];
        this->outfile = argv[2];
    }

    return true;
}

bool gameFlow::getValidCommandParsing(){
    return this->validCommandParsing;
}
