//
// Created by okleinfeld on 12/13/17.
//

#ifndef AP_JIGSAWGAME_PUZZLETYPEWITHROTATION_H
#define AP_JIGSAWGAME_PUZZLETYPEWITHROTATION_H

#include "PuzzleType.h"

class PuzzleTypeWithRotation : public PuzzleType{
protected:
    int rotationAngle;
public:
    PuzzleTypeWithRotation(int l, int t, int r, int b);
    PuzzleTypeWithRotation();
    int getRotationAngle() const;
    void rotate();
    void resetRotation(); //returns the piece to original angle
    bool operator==(const PuzzleTypeWithRotation& otherType) const ;
    bool operator<(const PuzzleTypeWithRotation& otherType) const ;
};


#endif //AP_JIGSAWGAME_PUZZLETYPEWITHROTATION_H
