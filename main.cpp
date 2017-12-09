#include <iostream>
#include "JigsawPuzzle.h"
#include "gameFlow.h"
#include "PuzzleRequirement.h"
#include "tests.hpp"
#include "PuzzlePiecesMap.h"
using namespace std;

int main(int argc, char* argv[]){
    string inputFilename(argv[1]);
    string outputFilename(argv[2]);
    JigsawPuzzle puzzle = JigsawPuzzle(inputFilename, outputFilename);
    PuzzlePiecesMap map = PuzzlePiecesMap(puzzle.getCorrectInputPieces());
    
    tests::tests::runTests(2,2,10);
//    tests::tests::runTests(4, 8, 50);
//    tests::tests::runTests(32, 1, 50);
//    tests::tests::runTests(1, 32, 50);
//    tests::tests::runTests(5, 5, 50);
//    tests::tests::runTests(6, 6, 50);
//    tests::tests::runTests(7, 6, 50);
//   // tests::tests::runTests(32, 1, 20);
    //tests::tests::runTests(1, 32, 20);
//    tests::tests::runTests(2, 10, 10);
//    tests::tests::runTests(10, 2, 10);

//    if(argc != 3){
//        cout << "Wrong number of arguments" << endl;
//        return 0;
//    }
//    return gameFlow::simpleMainFlow(argv[1], argv[2]);
}






/*
 
 totaly, we have 3^4 pieces types = 81
 about 2^4 of those are not a frame pieces = 16

 in any case, we first create a valid frame.
 then we fill it out. 
 

 
 
 alright - we have a 4D map - 4*4*4*4.
 Then we sort the pieces (each can be in more than one bucket).
 
 now we do the actual function, in two steps:
 first we create a frame, if OK - we jump in.
 
 Essentially we have two parts:
    function that is responisble for determing what is the next puzzle loc
    function that is resposible for finding the right piece to go there. 
 
 
 
 MAYBE add a puzzlepieces class:
 holds a vector of pieces, 
 manages the sort
 determines next piece.
 

 
 
 
CLASS PUZZLEGAME
 SOLVE():
    SOLVE(i,j) // i.j = next loc
        if(i, j == -1,-1)
            return true;
        req = getRequierment(i,j)
        p = nextPiece(req)
        while(p!=NULL)
            add_to_map(P)
            if(solve(get_next_pos(i,j)) //rec
                return true
            //else
            remove_from_map(P)
            p.used = 0;
            req = adjReq(p)
            p = nextPiece(req)
    return false;
 
 
 
 GET_NEXT_pos:
 i,j,lastrow,lastcol
 i, j++
 j++,i
 -1,-1
 
 
 GET_REQ(i,j)
    return waht is requred for the next pos in map,
    l, t, r, b = depending on sit
    return req(i,t,r,b)
 
 
 
 
CLASS REQUERMENT V
    vector<REQ> falseREQ's
    int l,t,r,b
 
    REQ(l,t,r,b,EMPTY)

    ADJ_REQ(puzzlePiece)
        falseREQ.push_back(req(l,t,r,b)
        //add false req to vector of bad req's
 
 
CLASS PIECES
    4DMAP of pieces
    //or map <REQ,VECTOR<PIECES>> ???????????, then need to overload = for req's (ignore false)
 
    PUZZLEPIECES(vector<puzzlepiece> v)
        createMAP
        sort(v)
 
    sort(v): //here we'll add the rotation (need to think how)
        for p in v:
            add to *,*,*,*
            add to l,*,*,*
            .
            .
            .
            add to l,t,r,b
    
    nextPiece(p,req)
        l,t,r,b = req
        for p in MAP(l,t,r,b)
            if(p->used == 0)
                if(req->isValid(p)
                    p->used = 1
                    return p
 
 
 


 
CLASS PUZZLEPIECE:
    add used
 
 
 
 
 
 
 
 
 
 
 
 


*/
