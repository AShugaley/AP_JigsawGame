//
// Created by okleinfeld on 12/15/17.
//

#ifndef AP_JIGSAWGAME_JIGSAWGAMEINTERFACE_H
#define AP_JIGSAWGAME_JIGSAWGAMEINTERFACE_H

#include "PuzzlePiece.h"
#include "PuzzleRequirement.h"

class JigsawGameInterface {
public:
    virtual void initiateSolutionTry(pair<int, int> solutionDimension) = 0;
    virtual void updatePuzzlePieceInSolution(int i, int j, PuzzlePiece &p) = 0;
    virtual void revertPuzzlePieceFromSolution(int i, int j, PuzzlePiece &p) = 0;
    virtual void printSolutionToFile(std::string &outputFilePath, bool solved) = 0;
    virtual pair<int,int> getNextPos(int i, int j) = 0;
    virtual PuzzleRequirement getReq(int i, int j) = 0;
    virtual int getPuzzleSize() = 0;

    virtual ~JigsawGameInterface() = 0;
};


#endif //AP_JIGSAWGAME_JIGSAWGAMEINTERFACE_H
