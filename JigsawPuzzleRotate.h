//
//  JigsawPuzzleRotate.h
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef JigsawPuzzleRotate_h
#define JigsawPuzzleRotate_h


#include "JigsawPuzzle.h"
#include "PuzzlePiecesMapRotate.h"

using namespace std;

class JigsawPuzzleRotate: public JigsawPuzzle{
private:
    //hide
    PuzzlePiecesMapRotate piecesMap;
    virtual PuzzlePiece* getNextPiece(PuzzleRequirement req) override{
        return this->piecesMap.nextPiece(req);
    }
    
    
    
public:
    //constructor
    JigsawPuzzleRotate(string& inputFilePath, string& outputFilePath): JigsawPuzzle(inputFilePath, outputFilePath){}
    //sepcial const for tests
    JigsawPuzzleRotate(vector<PuzzlePiece> pieces): JigsawPuzzle(pieces){}
    
    bool initSolve() override;
    
};
#endif /* JigsawPuzzleRotate_h */
