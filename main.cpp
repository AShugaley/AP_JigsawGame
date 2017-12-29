#include "gameFlow.h"
#include "RandomSolvableTest.h"

using namespace std;

int main(int argc, char* argv[]) {
//    RandomSolvableTest t = *new RandomSolvableTest(8,8);
//    t.runRandomTests(8,8,10);
//    return 0;
    
    
    
    gameFlow game = gameFlow(argc, argv);
    bool validArgs = game.getValidCommandParsing();
    if (validArgs){
        game.runMainFlow();
    }
}
