cmake_minimum_required(VERSION 3.8)
project(AP_JigsawGame)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        JigsawPuzzle.h
        JigsawPuzzle.cpp
        PuzzlePiece.h
        PuzzlePiece.cpp
        solution.txt
        test_files/error_input_file_1.txt
        test_files/error_input_file_2.txt
        test_files/error_input_file_3.txt
        main.cpp PuzzleMatrix.cpp PuzzleMatrix.h)

add_executable(AP_JigsawGame ${SOURCE_FILES})