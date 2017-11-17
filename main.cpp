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
    return 0;
}



/*
 
 
 known issues:
 1. doesn't work for one long row; long column should be fine -> check
 
 
 
 todo:
 1. check what happens to 1x1 puzlle
 2. verify flow
 3. print solution
 5. add constructors && desctructors
 6. check memory leaks
 7. clean code
 
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
