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



/* 
 A JigsawPuzzle with rotate capabilities; algorithm works essentily the same way, aside from the fact
 that when we call getNextPiece, the puzzlePiecesMap will try and rotate frames (instead of just checking)
 */
class JigsawPuzzleRotate: public JigsawPuzzle{
private:
    //hide piecesMap with a newer version
    PuzzlePiecesMapRotate piecesMap;
    
    
    //overriding the getNextPiece functio to prevent slicing
    virtual PuzzlePiece* getNextPiece(PuzzleRequirement req) override{
        return this->piecesMap.nextPiece(req);
    }
    
    
    
public:
    //constructor
    JigsawPuzzleRotate(string& inputFilePath, string& outputFilePath): JigsawPuzzle(inputFilePath, outputFilePath){}
    //sepcial const for tests
    JigsawPuzzleRotate(vector<PuzzlePiece> pieces): JigsawPuzzle(pieces){}
    
    //overriding functions - vertical & horizontal is irrelevant if we rotate
    virtual bool isLegalPuzzle() override;
    
    //overriding solutions
    bool initSolve() override;
    
};
#endif /* JigsawPuzzleRotate_h */
