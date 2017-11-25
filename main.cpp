#include <iostream>
#include "JigsawPuzzle.h"
#include "gameFlow.h"

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 3){
        cout << "Wrong number of arguments" << endl;
        return 0;
    }
    return gameFlow::simpleMainFlow(argv[1], argv[2]);
}