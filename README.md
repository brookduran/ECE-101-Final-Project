In this final project, you will design and implement a single-player interactive game using
C programming language. The player explores a hidden 10 × 10 island map to find several
treasures and avoid traps. Each treasure can occupy multiple connected locations. There are also
a few traps that the player should avoid.
Your program must use both a 2D array to represent the game board and an array of
Treasure struct to store and manage information about each treasure and trap.

Game Concept
You are an explorer searching for treasures hidden on a mysterious island while avoiding
Traps on the islands. The island is represented by a 10 × 10 grid (a total of 100 cells). The
player does not know where the treasures or traps are located

Required Data Structures
2D Array
Your program must use a 2D array of size 10 x 10 to represent the island.
In addition to symbols used in 3 (Treasures and Traps), pick one symbol to represent
“undiscovered” cell and another symbol to represent “investigated but empty”.
For example (as you will see in the sample code execution): . is used for “undiscovered”
and O is used for “investigated but empty”.
Hint: you may want to use two 2D arrays. The first one is to keep what the player has
discovered and the second one is to keep the actual locations of treasures and traps.

5. Game Rules
 The player starts with a score of 0 and 25 moves.
 The player selects one location per move. The location cannot be out of bound.
 A valid move investigates one previously unexplored cell. A location cannot be
investigated twice.
 An empty cell earns 0 point. A trap cell results in losing 50 points if discovered.
 A treasure cell reveals part of a treasure but does not award the full treasure value
immediately. A treasure earns its full value only when every cell belonging to that
treasure has been discovered.
 The game ends when a) the player decides to quit (entering -1 for both row and column);
b) the player uses up all 25 moves; or c) the player finds all 4 treasures.
 When the game ends, the results and the hidden map must be displayed (See sample code
execution #1, #3 and #4).
