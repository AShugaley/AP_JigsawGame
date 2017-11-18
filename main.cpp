#include <iostream>
#include "JigsawPuzzle.h"
#include "gameFlow.h"

using namespace std;

int main() {
    string inputPath = "test_files/input_can_solve.txt";
    string outputPath = "solution.txt";
    JigsawPuzzle p(inputPath, outputPath);
    p.solveGame();
    PuzzleMatrix& m = p.getSolutionMatrix();
    m.printRange(cout, p.getSolutionMatrixNumRows(), p.getSolutionMatrixNumCols());

//    auto *p = new PuzzlePiece(1, 0 ,0 ,0, 0);
//    cout << *p << endl;
    return 0;
}



/*
 
 
 known issues:
 1. doesn't work for one long row; long column should be fine -> check
 2. check 1x1 puzzle
 
 todo:
 2. verify flow
 5. add constructors && desctructors
 6. check memory leaks
 7. clean code
 9. testing
 8. test on nova
 */



/*
 set puzzlePieces
 matrix solution
 int i
 int j
 
 
 
 isValid(puzzlePiece, row, col, lastRow, lastCol)
 if row == 0 && puzzlePiece->topEdge!= 0
 return false
 if col == 0 && puzzlePiece->leftEdge != 0
 return false
 if lastRow == i && puzzlePiece->bitPiece != 0
 if lastCol == j && puzzlePieve->rightPiece != 0
 return false
 
 
 return ((()||())&&(()||()))
 //return (((matrix[i][j-1]->rightEdge + puzzlePiece == 0)||(col==0))&&(()||())
 
 
 solveGame
 i = 0
 j = 0
 sol = false
 for(elem : pieces)
 if(isValid)
 moveElement(set,matrix)
 sol = recursion(i,j)
 if sol
 return true;
 else
 moveElement(matrix,set)
 return false;
 
 
 recursion(i,j):
 if(lastCol == j || matrix[i,j]->rightEdge == 0 && lastCol == -1))
 for(elem:Pieces)
 if(isValid(i++,0) && (numofelemts%j ==0))
 moveElem(set,matrix)
 sol = recursion(i++,0)
 if(sol)
 reurn true
 else
 moveElement(matrix,Set)
 
 if(lastCol == j)
 reuturn false
 
 
 for(elem:pieces)
 if(isValid(i,j++)
 moveElem(set,matrix)
 sol = recursion(i,j++)
 if(sol)
 reurn true
 else
 moveElement(matrix,Set)
 return false
 
 
 */
