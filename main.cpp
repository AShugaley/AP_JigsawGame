#include "gameFlow.h"
#include "RandomSolvableTest.h"

using namespace std;

int main(int argc, char* argv[]) {
    gameFlow game = gameFlow(argc, argv);
    bool validArgs = game.getValidCommandParsing();
    if (validArgs){
        game.runMainFlow();
    }


//    string inputFileName = argv[1];
//    string outputFileName = argv[2];
//    JigsawParser parser = JigsawParser(inputFileName, outputFileName);
//    vector<PuzzlePiece> pieces = parser.getCorrectInputPieces();
//    JigsawPuzzleRotations puzzle = JigsawPuzzleRotations(pieces);
//    bool solved = puzzle.solveGame();



//    PuzzlePiecesMapWithRotate p_map = PuzzlePiecesMapWithRotate(pieces);
//    for (auto& p : p_map.getTypesMap()){
//        PuzzleType pType = p.first;
//        PuzzleTypeWithRotation pRot = p.first;

//        pType.getLeft();
//        PuzzleTypeWithRotation& pRot = dynamic_cast<PuzzleTypeWithRotation&>(pType);
//        pRot.rotate();
//        pType.rotate();
//        int newAngle = pType.getRotationAngle();
//        cout << "new angle is: " << newAngle << endl;
//    }


//    RandomSolvableTest::runRandomTests(4, 8, 50);
//    RandomSolvableTest::runRandomTests(32, 1, 50);
//    RandomSolvableTest::runRandomTests(1, 32, 50);
//    RandomSolvableTest::runRandomTests(5, 5, 50);
//    RandomSolvableTest::runRandomTests(6, 6, 50);
//    RandomSolvableTest::runRandomTests(2, 10, 50);
//    RandomSolvableTest::runRandomTests(10, 4, 50);
//    RandomSolvableTest::runRandomTests(10, 5, 50);

}