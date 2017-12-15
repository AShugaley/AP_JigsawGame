//
// Created by okleinfeld on 12/15/17.
//

#ifndef AP_JIGSAWGAME_JIGSAWPUZZLEROTATIONS_H
#define AP_JIGSAWGAME_JIGSAWPUZZLEROTATIONS_H

#include <fstream>

#include "JigsawPuzzleAbstract.h"
#include "PuzzlePieceRotation.h"


class JigsawPuzzleRotations : JigsawPuzzleAbstract{
protected:
    vector<PuzzlePieceRotation> puzzlePieces;
public:
    explicit JigsawPuzzleRotations(vector<PuzzlePiece> pieces);

    void updatePuzzlePieceInSolution(int i, int j, PuzzlePiece& p) override;
    void revertPuzzlePieceFromSolution(int i, int j, PuzzlePiece& p) override;
    PuzzleRequirement getReq(int i, int j) override;
    void printSolutionToFile(std::string& outputFilePath, bool solved) override;
};


#endif //AP_JIGSAWGAME_JIGSAWPUZZLEROTATIONS_H
