COMP = g++
OBJS = main.o gameFlow.o JigsawPuzzle.o PuzzlePiece.o
EXEC = ex1
CPP_COMP_FLAG = -std=c++11 -Wall -Wextra \
-Werror -pedantic-errors -DNDEBUG

$(EXEC): $(OBJS)
	$(COMP) $(OBJS) -o $@
#a rule for building a simple c++ source file
#use g++ -MM main.cpp to see dependencies

main.o: JigsawPuzzle.h gameFlow.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
gameFlow.o: gameFlow.h JigsawPuzzle.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
JigsawPuzzle.o: JigsawPuzzle.h PuzzlePiece.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
PuzzlePiece.o: PuzzlePiece.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
clean:
	rm -f $(OBJS) $(EXEC)
