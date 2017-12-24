#include "gameFlow.h"
#include "RandomSolvableTest.h"

using namespace std;

int main(int argc, char* argv[]) {
    RandomSolvableTest t = *new RandomSolvableTest(6,6);
    t.runRandomTests(6,6,10);
    return 0;
    
    
    
    gameFlow game = gameFlow(argc, argv);
    bool validArgs = game.getValidCommandParsing();
    if (validArgs){
        game.runMainFlow();
    }
}
