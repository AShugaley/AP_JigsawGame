//
// Created by okleinfeld on 12/13/17.
//

#ifndef AP_JIGSAWGAME_PUZZLETYPEWITHROTATION_H
#define AP_JIGSAWGAME_PUZZLETYPEWITHROTATION_H

#include "PuzzleType.h"

/* 
 * Extension of PuzzleType for rotations
 * includes the rotatation functions
 */


class PuzzleTypeWithRotation : public PuzzleType{
protected:
    int rotationAngle;
public:
    PuzzleTypeWithRotation(int l, int t, int r, int b);
    PuzzleTypeWithRotation();
    int getRotationAngle() const;
    void rotate(); //rotate 90 degrees colckwise
    void resetRotation(); //returns the piece to original angle
};


#endif //AP_JIGSAWGAME_PUZZLETYPEWITHROTATION_H
