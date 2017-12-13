//
// Created by okleinfeld on 12/13/17.
//

#ifndef AP_JIGSAWGAME_JIGSAWPUZZLEROTATIONS_H
#define AP_JIGSAWGAME_JIGSAWPUZZLEROTATIONS_H

#include "JigsawPuzzle.h"
#include "PuzzlePiecesMapWithRotate.h"

class JigsawPuzzleRotations : public JigsawPuzzle{
protected:
    PuzzlePiecesMapWithRotate piecesMap;
    bool solveRec(pair<int,int> nextPos) override;
public:
    explicit JigsawPuzzleRotations(vector<PuzzlePiece> pieces);
    bool solveGame() override;
};


#endif //AP_JIGSAWGAME_JIGSAWPUZZLEROTATIONS_H
