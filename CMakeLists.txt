cmake_minimum_required(VERSION 3.8)
project(AP_JigsawGame)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")

set(SOURCE_FILES
        gameFlow.cpp
        gameFlow.h
        main.cpp
        PuzzlePiecesMap.cpp
        PuzzleRequirement.cpp
        PuzzleRequirement.h
        alex_test_files/error_input_file_1.txt
        alex_test_files/error_input_file_2.txt
        alex_test_files/error_input_file_3.txt
        alex_test_files/in1-format-error.txt
        alex_test_files/in1-Solvable.txt
        alex_test_files/in1-Unsolvable.txt
        alex_test_files/in2-format-error.txt
        alex_test_files/in2-Solvable.txt
        alex_test_files/in2-Unsolvable.txt
        alex_test_files/in3-format-error.txt
        alex_test_files/in3-Solvable.txt
        alex_test_files/in3-Unsolvable.txt
        alex_test_files/in4-format-error.txt
        alex_test_files/in4-Solvable.txt
        alex_test_files/in4-Unsolvable.txt
        alex_test_files/in5-format-error.txt
        alex_test_files/in5-Solvable.txt
        alex_test_files/in5-Unsolvable.txt
        alex_test_files/in6-format-error.txt
        alex_test_files/in6-Solvable.txt
        alex_test_files/in7-format-error.txt
        JigsawParser.cpp JigsawParser.h JigsawSolutionExistsChecks.cpp JigsawSolutionExistsChecks.h RandomSolvableTest.cpp RandomSolvableTest.h PuzzlePiecesMapWithRotate.cpp PuzzlePiecesMapWithRotate.h PuzzleTypeWithRotation.cpp PuzzleTypeWithRotation.h JigsawSolutionExistsRotationsAllowed.cpp JigsawSolutionExistsRotationsAllowed.h PuzzlePiece.cpp PuzzlePiece.h PuzzlePieceRotation.cpp PuzzlePieceRotation.h PuzzleType.cpp PuzzleType.h PuzzlePieceMapInterface.h SolutionAlgorithm.cpp SolutionAlgorithm.h JigsawGameInterface.h JigsawPuzzleAbstract.cpp JigsawPuzzleAbstract.h JigsawPuzzle.cpp JigsawPuzzle.h JigsawPuzzleRotations.cpp JigsawPuzzleRotations.h NaiveSolutionExistenceCheck.h Factory.cpp Factory.h
        JigsawSolutionThread.h JigsawSolutionThread.cpp
        SolutionAlgorithmRunningSuite.h SolutionAlgorithmRunningSuite.cpp)

add_executable(AP_JigsawGame ${SOURCE_FILES})