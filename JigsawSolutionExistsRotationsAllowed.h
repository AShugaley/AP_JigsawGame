//
// Created by okleinfeld on 12/13/17.
//

#ifndef AP_JIGSAWGAME_JIGSAWSOLUTIONEXISTSROTATIONSALLOWD_H
#define AP_JIGSAWGAME_JIGSAWSOLUTIONEXISTSROTATIONSALLOWD_H

#include "JigsawSolutionExistsChecks.h"

class JigsawSolutionExistsRotationsAllowed : public JigsawSolutionExistsChecks {
public:
    explicit JigsawSolutionExistsRotationsAllowed(vector<PuzzlePiece>& puzzlePieces);
    bool checkIfPuzzleIsLegal() override;
//    vector<int> hasAllCorners() override;
};


#endif //AP_JIGSAWGAME_JIGSAWSOLUTIONEXISTSROTATIONSALLOWD_H
