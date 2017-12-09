#include "gameFlow.h"
#include "tests.hpp"

using namespace std;

int main(int argc, char* argv[]){
//    gameFlow game = gameFlow();
//    game.simpleMainFlow(argv[1], argv[2]);
      //tests::runTests(7, 7, 50);
    tests::runTests(7, 7, 10,true);
    tests::runTests(4, 4, 10,true);
    tests::runTests(4, 8, 10,true);
    tests::runTests(10, 10, 10,true);
//    tests::runTests(32, 1, 50);
//    tests::runTests(1, 32, 50);
//    tests::runTests(5, 5, 50);
//    tests::runTests(6, 6, 50);
//    tests::runTests(7, 6, 50);
//    tests::runTests(32, 1, 20);
//    tests::runTests(1, 32, 20);
//    tests::runTests(2, 10, 10);
//    tests::runTests(10, 2, 10);

//    if(argc < 3 || argc > 4){
//        cout << "Wrong number of arguments" << endl;
//        return 0;
//    }
//    
     return gameFlow::simpleMainFlow(argv, argc);
}




//sort input pieces into buckets (according to type)
//find all posible dimensions
//  for dimenshion
        //solve (fill lines one by one, topLeft to botRight):
//          get requierment (what type should fit in the current place) - 0(1)
//                 get matching piece per type - 0(1)
                        //if stuch (no maching piece) go back
