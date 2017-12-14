COMP = g++
OBJS = main.o gameFlow.o JigsawPuzzleRotations.o JigsawPuzzle.o PuzzlePiecesMapWithRotate.o PuzzlePiecesMap.o \
PuzzleRequirement.o PuzzleTypeWithRotation.o JigsawSolutionExistsRotationsAllowed.o JigsawSolutionExistsChecks.o \
JigsawParser.o PuzzleType.o PuzzlePiece.o
EXEC = ex2
CPP_COMP_FLAG = -std=c++11 -Wall -Wextra \
-Werror -pedantic-errors -DNDEBUG

$(EXEC): $(OBJS)
	$(COMP) $(OBJS) -o $@
#a rule for building a simple c++ source file
#use g++ -MM main.cpp to see dependencies

main.o: gameFlow.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
gameFlow.o: gameFlow.h JigsawParser.h JigsawSolutionExistsChecks.h JigsawSolutionExistsRotationsAllowed.h JigsawPuzzle.h JigsawPuzzleRotations.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
JigsawPuzzleRotations.o: JigsawPuzzleRotations.h JigsawPuzzle.h PuzzlePiecesMapWithRotate.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
JigsawPuzzle.o: JigsawPuzzle.h PuzzlePiecesMap.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
PuzzlePiecesMapWithRotate.o: PuzzlePiecesMapWithRotate.h PuzzlePiecesMap.h PuzzleTypeWithRotation.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
PuzzlePiecesMap.o: PuzzlePiecesMap.h PuzzleRequirement.h PuzzlePiece.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
PuzzleRequirement.o: PuzzleRequirement.h PuzzleType.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
PuzzleTypeWithRotation.o: PuzzleTypeWithRotation.h PuzzleType.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
JigsawSolutionExistsRotationsAllowed.o: JigsawSolutionExistsRotationsAllowed.h JigsawSolutionExistsChecks.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
JigsawSolutionExistsChecks.o: JigsawSolutionExistsChecks.h PuzzlePiece.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
JigsawParser.o: JigsawParser.h PuzzlePiece.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
PuzzleType.o: PuzzleType.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
PuzzlePiece.o: PuzzlePiece.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
clean:
	rm -f $(OBJS) $(EXEC)
