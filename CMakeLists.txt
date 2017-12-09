cmake_minimum_required(VERSION 3.8)
project(AP_JigsawGame)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        JigsawPuzzle.h
        JigsawPuzzle.cpp
        PuzzlePiece.h
        PuzzlePiece.cpp
        gameFlow.cpp
        gameFlow.h
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
        test_files/test1.in
        test_files/test2.in
        test_files/test3.in
        test_files/test4.in
        )

add_executable(AP_JigsawGame ${SOURCE_FILES})