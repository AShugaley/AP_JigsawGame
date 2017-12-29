#include "gameFlow.h"
#include "RandomSolvableTest.h"

using namespace std;

int main(int argc, char* argv[]) {
//    RandomSolvableTest t = *new RandomSolvableTest(5,5);
//    t.runRandomTests(5,5,10);
//    return 0;
    
    
    
    gameFlow game = gameFlow(argc, argv);
    bool validArgs = game.getValidCommandParsing();
    if (validArgs){
        game.runMainFlow();
    }
}
