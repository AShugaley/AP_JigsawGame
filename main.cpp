#include "gameFlow.h"

using namespace std;

int main(int argc, char* argv[]) {
    gameFlow game = gameFlow(argc, argv); //init new gameFlow
    bool validArgs = game.getValidCommandParsing(); //check CL args
    if (validArgs){ //if the args are ok - run the main flow
        game.runMainFlow();
    }
}
