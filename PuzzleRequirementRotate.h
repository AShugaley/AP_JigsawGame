//
//  PuzzleRequirementRotate.h
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 09/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#ifndef PuzzleRequirementRotate_h
#define PuzzleRequirementRotate_h

#include "PuzzleRequirement.h"

#endif /* PuzzleRequirementRotate_h */

/* an extension of PuzzleRequirement for rotations */
class PuzzleRequirementRotate: public PuzzleRequirement{
public:

    PuzzleRequirementRotate(int l, int t, int r, int b) : PuzzleRequirement(l,t,r,b){}
 
};
