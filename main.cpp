#include <iostream>
#include "JigsawPuzzle.h"
#include "gameFlow.h"
#include "tests.hpp"
using namespace std;

int main(int argc, char* argv[]){
    
    tests::tests::runTests(8, 4, 2);
    tests::tests::runTests(4, 8, 2);
//tests::tests::runTests(1, 1, 200);
   // tests::tests::runTests(32, 1, 20);
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
        p = nextPiece(NULL, req)
        while(p!=NULL)
            add_to_map(P)
            bool solve = solve(get_next_i, get next_j)
            if solve {return true}
            //else
            remove_from_map(P)
            p.used = 0;
            req = adjReq(p,req)
            p = nextPiece(p, req)
    return false;
 
 
 
 GET_NEXT_I()
    return next i, -1 if solved
 
 
 GET_NEXT_J()
    return next j, -1 if solved
 
 
 GET_REQ(i,j)
    return waht is requred for the next pos in map,
    l, t, r, b = depending on sit
    return req(i,t,r,b)
 
 
 
 
CLASS REQUERMENT
    vector<REQ> falseREQ's
    int l,t,r,b
 
    REQ(l,t,r,b,EMPTY)

    ADJ_REQ(puzzlePiece)
        falseREQ.push_back(req(l,t,r,b)
        add false req to vector of bad req's
 
 
CLASS PUZZLEPIECES
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
