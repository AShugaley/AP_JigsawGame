//
// Created by okleinfeld on 12/15/17.
//

#ifndef AP_JIGSAWGAME_JIGSAWPUZZLEABSTRACT_H
#define AP_JIGSAWGAME_JIGSAWPUZZLEABSTRACT_H

#include "JigsawGameInterface.h"

#define OUTPUT_FILE_NOT_OPEN "Could not open an output file. Program operation Failed"
#define NO_SOLUTION_MESSAGE "Cannot solve puzzle: it seems that there is no proper solution"

class JigsawPuzzleAbstract : public JigsawGameInterface{
protected:
    int numPieces;
    vector<vector<int> > solutionMatrix;
    int lastRowIndex;
    int lastColIndex;
    virtual void initSolMatrix();

public:
    void initiateSolutionTry(pair<int, int> solutionDimension) override;
    pair<int,int> getNextPos(int i, int j) override;
    int getPuzzleSize() override;
};


#endif //AP_JIGSAWGAME_JIGSAWPUZZLEABSTRACT_H
