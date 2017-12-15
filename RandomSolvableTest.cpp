//
// Created by okleinfeld on 12/13/17.
//

#include "RandomSolvableTest.h"


RandomSolvableTest::RandomSolvableTest(int x, int y){
    this->generateRandomPuzzle(x, y);
}


void RandomSolvableTest::generateRandomPuzzle(int x, int y){
    vector<vector<int> > edges = std::vector<vector<int> >((unsigned long) x*y, vector<int>(4));


    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(1.0, 2.0);

    for(int i = 0; i < y; i++){
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
            edges[i*y+j][2] = (int) rnd;
            edges[i*y+j+1][0] = (int) -rnd;
        }
    }
    for(int i = 0; i<x-1; i++){
        for(int j = 0; j<y;j++){
            double rnd = dis(gen);
            if(rnd > 1.5)
                rnd = 1;
            else
                rnd = -1;
            edges[i*y+j][3] = (int) rnd;
            edges[i*y+j+y][1] = (int) -rnd;
        }
    }

    random_shuffle(edges.begin(),edges.end());

    for(int i = 0; i<x*y;i++){
        this->puzzlePieces.emplace_back(PuzzlePiece(i+1,edges[i][0], edges[i][1], edges[i][2], edges[i][3]));
    }
}


bool RandomSolvableTest::solvePuzzle(){
    JigsawPuzzle puzzle = JigsawPuzzle(this->puzzlePieces);
    bool solved = puzzle.solveGame();
    return solved;
}

void RandomSolvableTest::runRandomTests(int x, int y, int numOfTests){
    chrono::duration<double> totalRunTime = chrono::duration<double>(0);
    int numOfSolved = 0;

    auto startComputation = chrono::system_clock::now();

    for(int i = 0; i< numOfTests; ++i){
        RandomSolvableTest test = RandomSolvableTest(x, y);

        auto startTest = chrono::system_clock::now();
        bool solved = test.solvePuzzle();
        auto endTest = chrono::system_clock::now();
        chrono::duration<double> totalTestTime = endTest-startTest;
        cout << "Solved test number " << i << " in " << totalTestTime.count() << " seconds." << endl;
        totalRunTime += totalTestTime;
        if(solved)
            numOfSolved++;
    }

    cout << "Solved " << numOfSolved << " out of " << numOfTests << " tests, of size: " << x << "," << y <<endl;
    cout << "Avg running time per test = " << totalRunTime.count() / double(numOfTests) << endl;
    cout << "Total running time = " << totalRunTime.count() << endl;
    cout << "--------- end of test -----------" << endl;

}