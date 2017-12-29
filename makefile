COMP = g++
OBJS = main.o gameFlow.o SolutionAlgorithm.o Factory.o JigsawPuzzleRotations.o JigsawPuzzle.o \
JigsawPuzzleAbstract.o PuzzlePiecesMapWithRotate.o PuzzlePiecesMap.o JigsawSolutionExistsRotationsAllowed.o \
JigsawSolutionExistsChecks.o JigsawParser.o PuzzleTypeWithRotation.o PuzzleRequirement.o PuzzleType.o \
PuzzlePiece.o PuzzlePieceRotation.o JigsawSolutionThread.o SolutionAlgorithmRunningSuite.o
EXEC = ex3
CPP_COMP_FLAG = -std=c++11 -Wall -Wextra \
-Werror -pedantic-errors -DNDEBUG

$(EXEC): $(OBJS)
	$(COMP) $(OBJS) -o $@ -pthread
#a rule for building a simple c++ source file
#use g++ -MM main.cpp to see dependencies

main.o: gameFlow.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

gameFlow.o: gameFlow.h JigsawParser.h SolutionAlgorithm.h Factory.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

SolutionAlgorithm.o: SolutionAlgorithm.h Factory.h JigsawSolutionThread.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

Factory.o: Factory.h JigsawGameInterface.h PuzzlePieceMapInterface.h PuzzlePiece.h \
JigsawPuzzle.h JigsawPuzzleRotations.h PuzzlePiecesMap.h PuzzlePiecesMapWithRotate.h PuzzleRequirement.h \
NaiveSolutionExistenceCheck.h JigsawSolutionExistsChecks.h JigsawSolutionExistsRotationsAllowed.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

JigsawSolutionThread.o: JigsawSolutionThread.h SolutionAlgorithmRunningSuite.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

SolutionAlgorithmRunningSuite.o: SolutionAlgorithmRunningSuite.h JigsawGameInterface.h PuzzlePieceMapInterface.h \
PuzzlePiece.h PuzzleRequirement.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

JigsawPuzzleRotations.o: JigsawPuzzleRotations.h JigsawPuzzleAbstract.h PuzzlePieceRotation.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

JigsawPuzzle.o: JigsawPuzzle.h JigsawPuzzleAbstract.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

JigsawPuzzleAbstract.o: JigsawPuzzleAbstract.h JigsawGameInterface.h PuzzlePiece.h PuzzleRequirement.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

PuzzlePiecesMapWithRotate.o: PuzzlePiecesMapWithRotate.h PuzzlePieceMapInterface.h PuzzleTypeWithRotation.h PuzzlePieceRotation.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

PuzzlePiecesMap.o: PuzzlePiecesMap.h PuzzleRequirement.h PuzzlePiece.h PuzzlePieceMapInterface.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

JigsawSolutionExistsRotationsAllowed.o: JigsawSolutionExistsRotationsAllowed.h NaiveSolutionExistenceCheck.h PuzzlePiece.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

JigsawSolutionExistsChecks.o: JigsawSolutionExistsChecks.h NaiveSolutionExistenceCheck.h PuzzlePiece.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

JigsawParser.o: JigsawParser.h PuzzlePiece.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

PuzzleTypeWithRotation.o: PuzzleTypeWithRotation.h PuzzleType.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

PuzzleRequirement.o: PuzzleRequirement.h PuzzleType.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

PuzzlePieceRotation.o: PuzzlePieceRotation.h PuzzlePiece.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

PuzzleType.o: PuzzleType.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

PuzzlePiece.o: PuzzlePiece.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

clean:
	rm -f $(OBJS) $(EXEC)
