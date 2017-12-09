//
//  tests.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 03/12/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
// a

#include "tests.hpp"
#include "ctime"

#include <random>


vector<PuzzlePiece> tests::generateRandomPuzzle(int x, int y){
    vector<PuzzlePiece> pieces;
    vector<vector<int> > edges = vector< std::vector<int> >(x*y, std::vector<int>(4));
    
    
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(1.0, 2.0);
    
    for(int i = 0; i<y; i++){
        edges[i][1] = 0;
        edges[x*y-i-1][3] = 0;
    }
    for(int i = 0; i<x; i++){
        edges[i*y][0] = 0;
        edges[i*y+y-1][2] = 0;
    }
    for(int i = 0; i<x; i++){
        for(int j = 0; j<y-1;j++){
            double rnd = dis(gen);
            if(rnd > 1.5)
                rnd = 1;
            else
                rnd = -1;
            edges[i*y+j][2] = rnd;
            edges[i*y+j+1][0] = -rnd;
        }
    }
    for(int i = 0; i<x-1; i++){
        for(int j = 0; j<y;j++){
            double rnd = dis(gen);
            if(rnd > 1.5)
                rnd = 1;
            else
                rnd = -1;
            edges[i*y+j][3] = rnd;
            edges[i*y+j+y][1] = -rnd;
        }
    }
//    for(int i = 0; i<x*y;i++){
//        cout<<edges[i][0]<<edges[i][1]<<edges[i][2]<<edges[i][3]<<endl;
//    }
//    cout<<endl;

    random_shuffle(edges.begin(),edges.end());

    for(int i = 0; i<x*y;i++){
        pieces.push_back(PuzzlePiece(i+1,edges[i][0], edges[i][1], edges[i][2], edges[i][3]));
    }
    return pieces;
}








bool tests::solvePuzzle(vector<PuzzlePiece> pieces){
    return JigsawPuzzleAdvanced(pieces).initSolveGame()();
}





bool tests::runTests(int x, int y, int numOfTests){
    double avgRunTime = 0;
    double totalRunTime = 0;
    int numOfSolved = 0;
    

    
    for(int i = 0; i<numOfTests; i++){
        vector<PuzzlePiece> toSolve = generateRandomPuzzle(x, y);
//        for(int j = 0; j<toSolve.size(); j++){
//            cout << toSolve[j];
//            cout << endl;
//        }
        //cout << "test: " << i << endl;
        time_t t1 = std::time(nullptr);
        bool solved = solvePuzzle(toSolve);
        time_t t2 = std::time(nullptr);
        totalRunTime+= (t2-t1);
        if(solved)
            numOfSolved++;
    }
    cout << "Solved " << numOfSolved << " out of " << numOfTests << " tests, of size: " << x << "," << y <<endl;
    avgRunTime = totalRunTime/numOfTests;
    cout << "Avg running time per test = " << avgRunTime << endl;
    cout << "Total running time = " << totalRunTime << endl;
    
    return false;
}
