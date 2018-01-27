Structurally, we have two objects (game_puzzle and game_piece, implemented in the relevant files), as well as additional container (game_flow) for the static game loop function.

All input/output is game specific and implemented in game_puzzle.

The Algorithm:
Overall, a brute force approach with certain improvements. We always start from the top left corner, and try to fill the first line as much as possible (we check the pieces for a straight top edge first). If we fail to extend the first line, we then try to find out if we can start a new line.

