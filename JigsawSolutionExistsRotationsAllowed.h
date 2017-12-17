//
// Created by okleinfeld on 12/13/17.
//

#ifndef AP_JIGSAWGAME_JIGSAWSOLUTIONEXISTSROTATIONSALLOWD_H
#define AP_JIGSAWGAME_JIGSAWSOLUTIONEXISTSROTATIONSALLOWD_H

#include "JigsawSolutionExistsChecks.h"
/* Extension of JigsawSolutionExistsChecks for rotations, will make some checks in a different manner (for instance corners can be rotated) */

class JigsawSolutionExistsRotationsAllowed : public JigsawSolutionExistsChecks {
public:
    explicit JigsawSolutionExistsRotationsAllowed(vector<PuzzlePiece>& puzzlePieces);
    bool checkIfPuzzleIsLegal() override;
};


#endif //AP_JIGSAWGAME_JIGSAWSOLUTIONEXISTSROTATIONSALLOWD_H
