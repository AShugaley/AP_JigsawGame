cmake_minimum_required(VERSION 3.8)
project(AP_JigsawGame)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
#        PuzzlePiece.h
#        PuzzlePiece.cpp
#        gameFlow.cpp
#        gameFlow.h
#        main.cpp
#        PuzzlePiecesMap.cpp
#        PuzzlePiece.h
#        PuzzleRequirement.cpp
#        PuzzleRequirement.h
#        PuzzleType.h
#        PuzzleType.cpp
#        alex_test_files/error_input_file_1.txt
#        alex_test_files/error_input_file_2.txt
#        alex_test_files/error_input_file_3.txt
#        alex_test_files/in1-format-error.txt
#        alex_test_files/in1-Solvable.txt
#        alex_test_files/in1-Unsolvable.txt
#        alex_test_files/in2-format-error.txt
#        alex_test_files/in2-Solvable.txt
#        alex_test_files/in2-Unsolvable.txt
#        alex_test_files/in3-format-error.txt
#        alex_test_files/in3-Solvable.txt
#        alex_test_files/in3-Unsolvable.txt
#        alex_test_files/in4-format-error.txt
#        alex_test_files/in4-Solvable.txt
#        alex_test_files/in4-Unsolvable.txt
#        alex_test_files/in5-format-error.txt
#        alex_test_files/in5-Solvable.txt
#        alex_test_files/in5-Unsolvable.txt
#        alex_test_files/in6-format-error.txt
#        alex_test_files/in6-Solvable.txt
#        alex_test_files/in7-format-error.txt
#        JigsawParser.cpp JigsawParser.h JigsawSolutionExistsChecks.cpp JigsawSolutionExistsChecks.h JigsawPuzzle.cpp JigsawPuzzle.h RandomSolvableTest.cpp RandomSolvableTest.h PuzzlePiecesMapWithRotate.cpp PuzzlePiecesMapWithRotate.h PuzzleTypeWithRotation.cpp PuzzleTypeWithRotation.h JigsawPuzzleRotations.cpp JigsawPuzzleRotations.h JigsawSolutionExistsRotationsAllowed.cpp JigsawSolutionExistsRotationsAllowed.h
        hw4/BoundedInt.h
        hw4/Puzzle2dPiece.h
        hw4/main.cpp
        )

add_executable(AP_JigsawGame ${SOURCE_FILES})