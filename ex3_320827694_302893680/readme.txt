THE STRUCTURE:

There are a bunch of classes, most exist in two version - classic, and extension (inhereting class) for rotateMode.

The main classes are:
	PuzzlePiece - puzzle element
	JigsawParser - parsing the input file
	PuzzleType - type of piece (e.g. 1,0,0,0)
	PuzzleRequirement - which puzzle we need (e.g. 1,*,*,* but not 1,0,0,0)
	PuzzlePiecesMap - a implementation of a tree/bucket structure for the requirements
	gameFlow - main game flow functions
	SolutionAlgorithm - the solve functions
	JigsawSolutionChecks - trivial checks (like corners)
	
We also have a few smaller, auxiliary classes, interfaces and factories to simplify the main parts of the code.


THE ALGORITHM:

 
1. We sort the puzzlePieces to a tree structure (implemented by a map). Each piece goes to ONE bucket, which represents specific type of piece (without JOKER’s, e.g. 1,0,0,0)

2. We decide the possible dimensions of the solution matrix (e.g. for 16 pieces - <1,16>, <4,4> etc), 

3. For each dimension, we create a matrix, and calculate the order of the positions that we want to fill, currently we operate in a spiral, so, for the following matrix:
1 2 3
4 5 6
7 8 9
We will fill the positions in the following order-> 1,2,3,6,9,8,7,4,5

4. For each position (according to this order), we calculate the requirement (per the current solution matrix), so for the first, top left corner it will be 0,0,*,*

5. We check if we have a piece that fits the req (this is essentially 0(1)

6. We move to the next position
‘
7. If stuck - go back and try another piece.

8. Eventually either a solution will be found, or we checked all comb’s - return false;

9. If solution exists, it’s in the solution matrix.




___________


Ofri Kleinfeld
Alexander Shugaley
2017

