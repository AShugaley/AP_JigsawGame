#include "gameFlowRegular.h"
#include "tests.hpp"

#define WROGN_ARGS "Error: you need to suply only input file representing a puzzle game and an output file"

using namespace std;

int main(int argc, char* argv[]){
    if (argc != 3){
        cout << WROGN_ARGS << endl;
        return -1;
    }

    char* inputFileName = argv[1];
    char* outputFileName = argv[2];
    gameFlow game = gameFlow(inputFileName, outputFileName);
    bool res = game.runMainFlow();
//    game.runMainFlow(argv[1], argv[2]);

//    tests::runTests(7, 7, 50);
//    tests::runTests(4, 8, 50);
//    tests::runTests(32, 1, 50);
//    tests::runTests(1, 32, 50);
//    tests::runTests(5, 5, 50);
//    tests::runTests(6, 6, 50);
//    tests::runTests(7, 6, 50);
//    tests::runTests(32, 1, 20);
//    tests::runTests(1, 32, 20);
//    tests::runTests(2, 10, 10);
//    tests::runTests(10, 2, 10);

//    if(argc != 3){
//        cout << "Wrong number of arguments" << endl;
//        return 0;
//    }
//    return gameFlow::runMainFlow(argv[1], argv[2]);
}
