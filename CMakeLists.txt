cmake_minimum_required(VERSION 3.8)
project(AP_JigsawGame)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        JigsawPuzzle_OLD.h
        JigsawPuzzle_OLD.cpp
        PuzzlePiece.h
        PuzzlePiece.cpp
        gameFlowRegular.cpp
        gameFlowRegular.h
        main.cpp
        PuzzlePiecesMap.cpp
        PuzzlePiece.h
        PuzzleRequirement.cpp
        PuzzleRequirement.h
        PuzzleType.h
        PuzzleType.cpp
        tests.hpp
        tests.cpp
        test_files/error_input_file_1.txt
        test_files/error_input_file_2.txt
        test_files/error_input_file_3.txt
        test_files/in1-format-error.txt
        test_files/in1-Solvable.txt
        test_files/in1-Unsolvable.txt
        test_files/in2-format-error.txt
        test_files/in2-Solvable.txt
        test_files/in2-Unsolvable.txt
        test_files/in3-format-error.txt
        test_files/in3-Solvable.txt
        test_files/in3-Unsolvable.txt
        test_files/in4-format-error.txt
        test_files/in4-Solvable.txt
        test_files/in4-Unsolvable.txt
        test_files/in5-format-error.txt
        test_files/in5-Solvable.txt
        test_files/in5-Unsolvable.txt
        test_files/in6-format-error.txt
        test_files/in6-Solvable.txt
        test_files/in7-format-error.txt
        JigsawParser.cpp JigsawParser.h JigsawSolutionExistsChecks.cpp JigsawSolutionExistsChecks.h JigsawPuzzle.cpp JigsawPuzzle.h)

add_executable(AP_JigsawGame ${SOURCE_FILES})