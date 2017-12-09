//
//  JigsawPuzzleAdvanced.h
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 03/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef JigsawPuzzleAdvanced_h
#define JigsawPuzzleAdvanced_h

#include "JigsawPuzzle.h"
#include "PuzzlePiecesMap.h"

using namespace std;



class JigsawPuzzleAdvanced: public JigsawPuzzle{
private:
    
    vector<pair<int,int> > moves;
    int currentMove;
    PuzzlePiecesMap piecesMap;
    //override -> prints with angle
    bool printSolutionToFile(bool solved);
    pair<int,int> getNextPos(int i, int j);
    bool solveRec(pair<int,int> nextPos);
    bool initSolve();
    void Spiral( int X, int Y);
    vector<pair<int,int> > getPossibleDimensions(int numOfPieces);
    PuzzleRequirement getReq(int i, int j);
    void initSolMatrix();
    
    
    
public:
    //override
    bool initSolveGame() override;
    //constructor
    explicit JigsawPuzzleAdvanced(string& inputFilePath, string& outputFilePath);
    //sepcial const for tests
    explicit JigsawPuzzleAdvanced(vector<PuzzlePiece> pieces);

};





#endif /* JigsawPuzzleAdvanced_h */
