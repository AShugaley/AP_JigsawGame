#include <iostream>
#include "JigsawPuzzle.h"
#include "gameFlow.h"

using namespace std;

int main(int argc, char* argv[]){ // or char** argv
    if(argc != 3){
        cout << "Wrong number of arguments" << endl;
        return 0;
    }
    return gameFlow::simpleMainFlow(argv[1], argv[2]);
}



/*
 
 known issues:
 1. problem with format-error (in4+in5)
 2. problem with puzzle size - check in7-format-error.txt
 3. in6-solvable & in1-unsolvable do not work - don't know why

 todo:
 9. more testing
 6. check memory leaks
 8. test on nova
 
 
 */
