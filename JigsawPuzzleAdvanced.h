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

using namespace std;



class JigsawPuzzleAdvanced: public JigsawPuzzle{
private:
    //override -> prints with angle
    bool printSolutionToFile(bool solved);

    
    
public:
    //constructor
    explicit JigsawPuzzleAdvanced(string& inputFilePath, string& outputFilePath): JigsawPuzzle(inputFilePath, outputFilePath){}
    //sepcial const for tests
    explicit JigsawPuzzleAdvanced(vector<PuzzlePiece> pieces);

};





#endif /* JigsawPuzzleAdvanced_h */
