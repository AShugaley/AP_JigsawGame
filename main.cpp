#include <iostream>
#include "JigsawPuzzle.h"
#include "gameFlow.h"
#include "tests.hpp"
using namespace std;

int main(int argc, char* argv[]){
    
    tests::tests::runTests(6, 5, 100);
//tests::tests::runTests(1, 1, 200);
   // tests::tests::runTests(32, 1, 20);
    //tests::tests::runTests(1, 32, 20);
//    tests::tests::runTests(2, 10, 10);
//    tests::tests::runTests(10, 2, 10);

//    if(argc != 3){
//        cout << "Wrong number of arguments" << endl;
//        return 0;
//    }
//    return gameFlow::simpleMainFlow(argv[1], argv[2]);
}
