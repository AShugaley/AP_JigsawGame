//
//  PuzzlePieces.h
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef PuzzlePieces_h
#define PuzzlePieces_h

#include "PuzzleRequirement.h"
#include "PuzzlePiece.h"
#include <map>

using namespace std;

class PuzzlePiecesMap{
protected:
    map<PuzzleType,vector<PuzzlePiece>> typesMap;
public:
    // Empty c'tor - used to initialize empty map that doesn't contain any values yet
    explicit PuzzlePiecesMap();

    //Vector of Puzzle pieces c'tor - also insert the vector's content into the map
    //Uses the helper function toBuckets
    explicit PuzzlePiecesMap(vector<PuzzlePiece>& pieces);

    // Virtual destructor
    virtual ~PuzzlePiecesMap() = default;

    // Helper function to insert vector's content into the map (mapping using each piece's type)
    virtual void toBuckets(vector<PuzzlePiece>& pieces);

    // Getter function for the types map
    virtual map<PuzzleType, vector<PuzzlePiece>>& getTypesMap();

    // helper function for the solving algorithm - given a requirement returns a pointer
    // to a puzzle piece that satisfies the requirement. if there isn't any - return nullptr
    virtual PuzzlePiece* nextPiece(PuzzleRequirement& req);

};

#endif /* PuzzlePieces_h */
