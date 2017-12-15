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
    if (valid){
        validCommandParsing = true;
    }
}


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
    bool rotationAllowed = this->rotate;

    if (rotationAllowed){
        JigsawSolutionExistsRotationsAllowed puzzleCheck = JigsawSolutionExistsRotationsAllowed(pieces);
        bool checkResult = puzzleCheck.checkIfPuzzleIsLegal();
        if (!checkResult){
            puzzleCheck.writeToFileFailedTests(outputFilename);
            return false;
        }

        JigsawPuzzleRotations puzzle = JigsawPuzzleRotations(pieces);
        bool solved = puzzle.solveGame();
        puzzle.printSolutionToFile(outputFilename);
        return solved;
    }

    else{

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
