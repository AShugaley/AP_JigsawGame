#include <iostream>
#include "JigsawPuzzle.h"
#include "gameFlow.h"

using namespace std;

int main(int argc, char* argv[]){ // or char** argv
    if(argc != 3){
        printf("Wrong number of arguments");
        return 0;
    }
    return gameFlow::simpleMainFlow(argv[1], argv[2]);
}



/*
 
 
 known issues:
 1. doesn't work for one long row; long column should be fine -> check
 2. check 1x1 puzzle
 
 todo:
 5. add constructors && desctructors
 9. testing
 
 
 6. check memory leaks
 8. test on nova
 */
