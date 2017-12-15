#include "gameFlow.h"


#include "JigsawPuzzleAbstract.h"

using namespace std;

int main(int argc, char* argv[]) {
    gameFlow game = gameFlow(argc, argv);
    bool validArgs = game.getValidCommandParsing();
    if (validArgs){
        game.runMainFlow();
    }
}
