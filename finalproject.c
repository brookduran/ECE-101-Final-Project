//Brooklynn Bluto
//7 Dec 2026
/*

    EXTRA CREDIT:
    (must be fully functioning for any extra credit pts)

        a) (4 points) Random placement of treasures and traps
            When the game starts, the program must randomly place all four treasures with the
            following policies:
                
                - The entire treasures and traps must remain inside the 10 × 10 board.
                - All Treasures and Traps cannot overlap.
                - The program must randomly choose horizontal or vertical orientation.
                - Every occupied location must be stored in the corresponding Treasure struct.
                - If a randomly generated position is invalid, the program must try another position.
        
        b) (2 points) Lives
            The player starts a game with 3 lives.
            If the player discovers a Trap, it costs one life. When
            number of lives reaches 0, the game is over

        c) (2 points) Direction Hint
            Give the player a hint on which direction the nearest undiscovered treasure is. 
            Possible directions are NORTH (top of the map), SOUTH, EAST (on the right side of the map),
            WEST, NORTH-EAST, NORTH-WEST, SOUTH-EAST SOUTH-WEST.

        d) (4 points) Treasure Radar
            Indicate whether a treasure is within a certain distance.
            
                Because treasures occupy multiple cells,
                the radar should calculate the distance to the
                nearest undiscovered cell of any treasure.
                the radar does not identify the treasure's name, its exact location, its size, or the direction

                The distance is calculated using Manhattan distance which is
                    distance = |playerRow – treasureRow| + |playerCol – treasureCol|
*/
/*
    Algorithm

    will need - 

        int xx = rand() % 3; for choosing map 1,2, or 3 
        (will return 1,2, or 3)


        treasure struct (must use given)

        display map function -  INCOMPLETE
		~~ display welcome function - COMPLETE
        display game-over function - INCOMPLETE
        ~~ display status function -  COMPLETE
        choose/generate map function -  INCOMPLETE
        discover coordinate function -  INCOMPLETE
        activate trap function -  INCOMPLETE
            include life deduction
        activate treasure function -  INCOMPLETE
        activate hint function -  INCOMPLETE
        take in coords function -  INCOMPLETE
            takes in the coords,
            checks if they're in bounds,
            checks if they're already discovered,
            calls the necessary functions based on what's found
        

        2D array for game board:
        !!!!One 2D array for the full map!!!!
        !!!!One 2D array for the players discoveries!!!
            10 x 10
            a symbol for an "undiscovered" cell - .
            a symbol for "investigated but empty" cell - O

        1D array for treasure
            I think I'm gonna have it such that 
            [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
            [G,G,S,S,S,A,A,A,A,D, D, D, D, T, T, T]

            I think I'll also have one full treasure array
            and one "discovered" treasure array


    map:
        10 x 10 (100 cells)

        Undiscovered Map
        
            0   1   2   3   4   5   6   7   8   9
          |---------------------------------------|
        0 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        1 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        2 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        3 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        4 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        5 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        6 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        7 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        8 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        9 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        

        Map 1 (given)

            0   1   2   3   4   5   6   7   8   9
          |---------------------------------------|
        0 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        1 | . | . | G | G | . | . | T | . | . | . |
          |---------------------------------------|
        2 | . | . | . | . | . | . | . | A | . | . |
          |---------------------------------------|
        3 | . | T | . | . | . | . | . | A | . | . |
          |---------------------------------------|
        4 | . | . | S | . | . | . | . | A | . | . |
          |---------------------------------------|
        5 | . | . | S | . | T | . | . | A | . | . |
          |---------------------------------------|
        6 | . | . | S | . | . | . | . | . | . | . |
          |---------------------------------------|
        7 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        8 | . | . | . | D | D | D | D | . | . | . |
          |---------------------------------------|
        9 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|

        - Golden Idol (G) are at cell (1,2) and (1,3)
        - Silver Chest (S) are at cell (4,2), (5,2), (6,2)
        - Ancient Artifact (A) are at cell (2,7), (3,7), (4,7), (5,7)
        - Diamond Vault (D) are at cell (8,3), (8,4), (8,5), (8,6)
        - Trap (T) is at cell (1,6)
        - Trap (T) is at cell (3,1)
        - Trap (T) is at cell (5,4)

        !!TO MAKE!! Map 2

            0   1   2   3   4   5   6   7   8   9
          |---------------------------------------|
        0 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        1 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        2 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        3 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        4 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        5 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        6 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        7 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        8 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        9 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|

        !!TO MAKE!! Map 3

            0   1   2   3   4   5   6   7   8   9
          |---------------------------------------|
        0 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        1 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        2 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        3 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        4 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        5 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        6 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        7 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        8 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|
        9 | . | . | . | . | . | . | . | . | . | . |
          |---------------------------------------|

        treasure:
            Treasure must occupy consecutive cells | or - but not / or \

            Treasure/Trap       Symbol  Size     Value
            Golden Idol         G       2 cells  100 pts
            Silver Chest        S       3 cells  150 pts
            Ancient Artifact    A       4 cells  200 pts
            Diamond Vault       D       4 cells  200 pts
            Trap                T       1 cell   -50 pts
            Trap                T       1 cell   -50 pts
            Trap                T       1 cell   -50 pts

        Rules:

            @ Start - Score: 0, Moves: 25
            Player selects 1 location per move
                cannot be out of bound
            Valid move investigates one unexplored cell
                a location CANNOT be investigated twice
            Empty cell earns 0 pts
            Treaure cell reveals part of treasure, but
                doesn't award the full treasure value
                until it's fully discovered
            Games ends when - 
                a) player quits (enters -1 for row and column)
                b) used up all 25 moves
                c) finds all 4 treasures

            When game ends, results and hidden map are displayed.
        
        Accepted Input:

            0-9 for row
            0-9 for column
            or -1 for row AND column to quit
                but if only one of them is -1,
                out of bounds
            
            if out of bounds,
                don't subtract a move,
                enter a new value

            if the entered value is already discovered,
                error message,
                don't subtract move,
                enter new value

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Treasure_s{
    char name[30];
    char symbol;
    int size; //number of cells used for the treasure or trap
    int value; //points for each treasure or trap
    int row[4]; //location (row) of the cells for the treasure or trap
    int col[4]; //location (column) of the cells for the treasure or trap
    int discoveredCells; //number of cells that the player has discovered so far
    int complete; //used when the entire treasure or trap is discovered
} Treasure;

/*
    display map function -  INCOMPLETE
    display game-over function - INCOMPLETE
    display status function -  INCOMPLETE
    choose/generate map function -  INCOMPLETE
    discover coordinate function -  INCOMPLETE
        takes in the coords,
        checks if they're in bounds,
        checks if they're already discovered,
        calls the necessary functions based on what's found
    activate trap function -  INCOMPLETE
        include life deduction
    activate treasure function -  INCOMPLETE
    activate hint function -  INCOMPLETE
*/
void display_welcome ();
void display_stats ();
void display_menu ();
void display_map ();
void display_game_over ();
int is_game_over();
void generate_map ();
void discover_coordinate ();
void activate_trap ();
void activate_treasure ();
void activate_hint ();

int main(void) {

    // initiallize random numbers
    srand(time(NULL)); 

    // initialize board
	Treasure map[10][10];
    // initialize treasures
    // randomly place treasures (or generate map)

    // initializing stats
    int score = 0, moves = 25;
    int hints_remaining = 3;
    int x_coord_entered = 0, y_coord_entered = 0;
    char command_entered = ' ';

    // display instructions

    /* GAME LOOP */
    // display board
    // display status
    // get player input
    // validate input
    // investigate location
    // update score/status
    // check game-over condition
    // |
    //display final results

    return 0;
}

void display_welcome (){

    printf("======================================================\n");
    printf(" Welcome to Treasure Hunt - The Lost Island\n");
    printf("======================================================\n");
    printf("Your mission is to find\n");
    printf("Golden Idol (2 cells) - 100 points\n");
    printf("Silver Chest (3 cells) - 150 points\n");
    printf("Ancient Artifact (4 cells) - 200 points");
    printf("Diamond Vault (4 cells) - 200 points");
    printf("xxx xxx Beware of Traps xxx xxx");

}

void display_stats (int score, int moves_remaining, int hints_remaining){

    printf("Score: %d\n", score);
    printf("Moves Remaining: %d\n", moves_remaining);
    printf("Hint Uses Remaining: %d", hints_remaining);

}

void display_menu (){

	printf("Enter command:\n");
	/*Menu Choice Options*/
	// R = Radar
	// I = Investigate
	// H = Hint
	printf("R = Radar\n");
	printf("I = Investigate\n");
	printf("H = Hint\n");

}

/*general function arg order*/
/*coords (x, y), full map, discovered map, treasure arrays, modified values, const values*/

void display_map (Treasure map[10][10]){

/*

		0   1   2   3   4   5   6   7   8   9
		|---------------------------------------|
	0   | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |
		|---------------------------------------|
	1   | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |
		|---------------------------------------|
	2   | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |
		|---------------------------------------|
	3   | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |
		|---------------------------------------|
	4   | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |
		|---------------------------------------|
	5   | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |
		|---------------------------------------|
	6   | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |
		|---------------------------------------|
	7   | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |
		|---------------------------------------|
	8   | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |
		|---------------------------------------|
	9   | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |
		|---------------------------------------|

*/

	printf("	0   1   2   3   4   5   6   7   8   9\n");
	printf("	|---------------------------------------|\n");

	for (int i = 0; i < 10; i ++){

		printf("%d   ", i);

		for (int j = 0; j < 10; j ++){

			printf("| %c ", map[i][j]);

		}

		printf("|\n");

	}

	printf("	|---------------------------------------|\n");


}

/*general function arg order*/
/*coords (x, y), full map, discovered map, treasure arrays, modified values, const values*/

void display_game_over ();
int is_game_over(Treasure* all_treasures[15], Treasure* discovered_treasures[15], int moves, int lives){

	int notComplete = 0;

	for (int i = 0; i < 13; i++){ //check up until the traps [G,G,S,S,S,A,A,A,A,D,D,D,D,T,T,T] so 0 to 12

		if(all_treasures[i]->complete != 1){

			notComplete++;

		}

	}

	if(notComplete == 0 || moves == 0 || lives == 0){ //if all treasures were complete (except for traps), out of moves, or out of lives

		return 1; // game over

	}
	else{

		return 0; // game not over

	}

}
void generate_map (int num, Treasure* map[10][10], Treasure* all_treasures[16]){

/*
	Map 1 (given)

		0   1   2   3   4   5   6   7   8   9
		|---------------------------------------|
	0 | . | . | . | . | . | . | . | . | . | . |
		|---------------------------------------|
	1 | . | . | G | G | . | . | T | . | . | . |
		|---------------------------------------|
	2 | . | . | . | . | . | . | . | A | . | . |
		|---------------------------------------|
	3 | . | T | . | . | . | . | . | A | . | . |
		|---------------------------------------|
	4 | . | . | S | . | . | . | . | A | . | . |
		|---------------------------------------|
	5 | . | . | S | . | T | . | . | A | . | . |
		|---------------------------------------|
	6 | . | . | S | . | . | . | . | . | . | . |
		|---------------------------------------|
	7 | . | . | . | . | . | . | . | . | . | . |
		|---------------------------------------|
	8 | . | . | . | D | D | D | D | . | . | . |
		|---------------------------------------|
	9 | . | . | . | . | . | . | . | . | . | . |
		|---------------------------------------|

		- Golden Idol (G) are at cell (1,2) and (1,3)
        - Silver Chest (S) are at cell (4,2), (5,2), (6,2)
        - Ancient Artifact (A) are at cell (2,7), (3,7), (4,7), (5,7)
        - Diamond Vault (D) are at cell (8,3), (8,4), (8,5), (8,6)
        - Trap (T) is at cell (1,6)
        - Trap (T) is at cell (3,1)
        - Trap (T) is at cell (5,4)
*/

	if(num == 1){ //map 1 (required to be exactly as given)

		//making entire map empty first
		for(int i = 0; i < 10; i ++){

			for (int j = 0; j < 10; j ++){

				*map[i][j]->name = "Empty";
				map[i][j]->symbol = '.'; // empty
				*map[i][j]->row = i;
				*map[i][j]->col = j;
				map[i][j]->value = 0;

			}

		}
		/*
		[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
		[G,G,S,S,S,A,A,A,A,D, D, D, D, D, T, T, T]
		*/

		*all_treasures[0]->name = "Golden Idol";
		*all_treasures[0]->row = 1; //G
		*all_treasures[0]->col = 2;
		all_treasures[0]->symbol = 'G';
		all_treasures[0]->value = 100;
		all_treasures[0]->size = 2;


		*all_treasures[1]->name = "Golden Idol";
		*all_treasures[1]->row = 1; //G
		*all_treasures[1]->col = 3;
		all_treasures[1]->symbol = 'G';
		all_treasures[1]->value = 100;
		all_treasures[1]->size = 2;

		*all_treasures[2]->name = "Silver Chest";
		*all_treasures[2]->row = 4; //S
		*all_treasures[2]->col = 2;
		all_treasures[2]->symbol = 'S';
		all_treasures[2]->value = 150;
		all_treasures[2]->size = 3;

		*all_treasures[3]->name = "Silver Chest";
		*all_treasures[3]->row = 5; //S
		*all_treasures[3]->col = 2;
		all_treasures[3]->symbol = 'S';
		all_treasures[3]->value = 150;
		all_treasures[3]->size = 3;

		*all_treasures[4]->name = "Silver Chest";
		*all_treasures[4]->row = 6; //S
		*all_treasures[4]->col = 2;
		all_treasures[4]->symbol = 'S';
		all_treasures[4]->value = 150;
		all_treasures[4]->size = 3;

		*all_treasures[5]->name = "Ancient Artifact";
		*all_treasures[5]->row = 2; //A
		*all_treasures[5]->col = 7;
		all_treasures[5]->symbol = 'A';
		all_treasures[5]->value = 200;
		all_treasures[5]->size = 4;

		*all_treasures[6]->name = "Ancient Artifact";
		*all_treasures[6]->row = 3; //A
		*all_treasures[6]->col = 7;
		all_treasures[6]->symbol = 'A';
		all_treasures[6]->value = 200;
		all_treasures[6]->size = 4;

		*all_treasures[7]->name = "Ancient Artifact";
		*all_treasures[7]->row = 4; //A
		*all_treasures[7]->col = 7;
		all_treasures[7]->symbol = 'A';
		all_treasures[7]->value = 200;
		all_treasures[7]->size = 4;

		*all_treasures[8]->name = "Ancient Artifact";
		*all_treasures[8]->row = 5; //A
		*all_treasures[8]->col = 7;
		all_treasures[8]->symbol = 'A';
		all_treasures[8]->value = 200;
		all_treasures[8]->size = 4;

		*all_treasures[9]->name = "Diamond Vault";
		*all_treasures[9]->row = 8; //D
		*all_treasures[9]->col = 3;
		all_treasures[9]->symbol = 'D';
		all_treasures[9]->value = 200;
		all_treasures[9]->size = 4;

		*all_treasures[10]->name = "Diamond Vault";
		*all_treasures[10]->row = 8; //D
		*all_treasures[10]->col = 4;
		all_treasures[10]->symbol = 'D';
		all_treasures[10]->value = 200;
		all_treasures[10]->size = 4;

		*all_treasures[11]->name = "Diamond Vault";
		*all_treasures[11]->row = 8; //D
		*all_treasures[11]->col = 5;
		all_treasures[11]->symbol = 'D';
		all_treasures[11]->value = 200;
		all_treasures[11]->size = 4;

		*all_treasures[12]->name = "Diamond Vault";
		*all_treasures[12]->row = 8; //D
		*all_treasures[12]->col = 6;
		all_treasures[12]->symbol = 'D';
		all_treasures[12]->value = 200;
		all_treasures[12]->size = 4;

		*all_treasures[13]->name = "Trap";
		*all_treasures[13]->row = 1; //T
		*all_treasures[13]->col = 6;
		all_treasures[13]->symbol = 'T';
		all_treasures[13]->value = -50;
		all_treasures[13]->size = 1;

		*all_treasures[14]->name = "Trap";
		*all_treasures[14]->row = 3; //T
		*all_treasures[14]->col = 1;
		all_treasures[14]->symbol = 'T';
		all_treasures[14]->value = -50;
		all_treasures[14]->size = 1;

		*all_treasures[15]->name = "Trap";
		*all_treasures[15]->row = 5; //T
		*all_treasures[15]->col = 4;
		all_treasures[15]->symbol = 'T';
		all_treasures[15]->value = -50;
		all_treasures[15]->size = 1;

		//put treasure in map

		for (int i = 0; i < 16; i ++){

			map[*all_treasures[i]->row][*all_treasures[i]->col]->symbol = all_treasures[i]->symbol;
			*map[*all_treasures[i]->row][*all_treasures[i]->col]->name = all_treasures[i]->name;
			map[*all_treasures[i]->row][*all_treasures[i]->col]->value = all_treasures[i]->value;
			*map[*all_treasures[i]->row][*all_treasures[i]->col]->row = all_treasures[i]->row;
			*map[*all_treasures[i]->row][*all_treasures[i]->col]->col= all_treasures[i]->col;
			map[*all_treasures[i]->row][*all_treasures[i]->col]->size = all_treasures[i]->size;

		}

	}
	else if (num == 2){ //map 2



	}
	else if (num == 3){ //map 3



	}
	else { //randomly generate map

		//random coords from 0 to 9
		int rand_x = 0, rand_y = 0;

		for (int i = 0; i < 16; i++){

			rand_x = rand() % 10; //rand() % (N + 1)
			rand_y = rand() % 10;

			if (i == 0 || i == 1){// G

				*all_treasures[i]->name = "Golden Idol";
				*all_treasures[i]->row = rand_x; //G
				*all_treasures[i]->col = rand_y;
				all_treasures[i]->symbol = 'G';
				all_treasures[i]->value = 100;
				all_treasures[i]->size = 2;

			}
			else if (i >= 2 && i <= 4){// S

				*all_treasures[i]->name = "Silver Chest";
				*all_treasures[i]->row = rand_x; //S
				*all_treasures[i]->col = rand_y;
				all_treasures[i]->symbol = 'S';
				all_treasures[i]->value = 150;
				all_treasures[i]->size = 3;

			}
			else if (i >= 5 && i <= 8){// A

				*all_treasures[i]->name = "Ancient Artifact";
				*all_treasures[i]->row = rand_x; //A
				*all_treasures[i]->col = rand_y;
				all_treasures[i]->symbol = 'A';
				all_treasures[i]->value = 200;
				all_treasures[i]->size = 4;

			}
			else if (i >= 9 && i <= 12){// D

				*all_treasures[i]->name = "Diamond Vault";
				*all_treasures[i]->row = rand_x; //D
				*all_treasures[i]->col = rand_y;
				all_treasures[i]->symbol = 'D';
				all_treasures[i]->value = 200;
				all_treasures[i]->size = 4;

			}
			else if (i >= 13 && i <= 15){// T

				*all_treasures[i]->name = "Trap";
				*all_treasures[i]->row = rand_x; //T
				*all_treasures[i]->col = rand_y;
				all_treasures[i]->symbol = 'T';
				all_treasures[i]->value = -50;
				all_treasures[i]->size = 1;

			}

		}

		//populate map here

		//making entire map empty first
		for(int i = 0; i < 10; i ++){

			for (int j = 0; j < 10; j ++){

				*map[i][j]->name = "Empty";
				map[i][j]->symbol = '.'; // empty
				*map[i][j]->row = i;
				*map[i][j]->col = j;
				map[i][j]->value = 0;

			}

		}

		//populate treasures
		for (int i = 0; i < 16; i ++){

			map[*all_treasures[i]->row][*all_treasures[i]->col]->symbol = all_treasures[i]->symbol;
			*map[*all_treasures[i]->row][*all_treasures[i]->col]->name = all_treasures[i]->name;
			map[*all_treasures[i]->row][*all_treasures[i]->col]->value = all_treasures[i]->value;
			*map[*all_treasures[i]->row][*all_treasures[i]->col]->row = all_treasures[i]->row;
			*map[*all_treasures[i]->row][*all_treasures[i]->col]->col= all_treasures[i]->col;
			map[*all_treasures[i]->row][*all_treasures[i]->col]->size = all_treasures[i]->size;

		}

	}

}
void discover_coordinate (int x, int y, Treasure map[10][10], int* valid){ //makes valid 0 or 1 to show if the coords were accepted



	if(map[x][y].symbol != 'O'){ //if the coordinate is undiscovered



		*valid = 1;

	}
	else {

		printf("This location is already entered\n");

		*valid = 0;

	}

}

/*general function arg order*/
/*coords (x, y), full map, discovered map, treasure arrays, modified values, const values*/

void activate_trap (int x, int y, Treasure* full_map[10][10], Treasure* discovered_map[10][10], Treasure* all_treasures[], Treasure* discovered_treasures[], int* score){

	if (full_map[x][y]->symbol == 'T'){

		printf("@@@ TRAP HIT!!! @@@\n");
		printf("Value: -50\n");

		*discovered_map[x][y]->name = "Trap";
		*discovered_map[x][y]->row = x; //T
		*discovered_map[x][y]->col = y;
		discovered_map[x][y]->symbol = 'T';
		discovered_map[x][y]->value = -50;
		discovered_map[x][y]->size = 1;

		int found = 0;
		for(int i = 13; i <= 15; i ++){

			if (discovered_treasures[i]->complete == 0 && found == 0){ 

				//add to discovered treasures and mark complete (traps complete immediately after found)
				discovered_treasures[i]->complete = 1;
				*discovered_treasures[i]->name = "Trap";
				*discovered_treasures[i]->row = x; //T
				*discovered_treasures[i]->col = y;
				discovered_treasures[i]->symbol = 'T';
				discovered_treasures[i]->value = -50;
				discovered_treasures[i]->size = 1;

				found ++;

			}

		}

		for(int i = 13; i <= 15; i ++){

			if (discovered_treasures[i]->complete == 0 && found == 0){

				all_treasures[i]->complete = 1; // mark complete in all_treasures

				found ++;

			}

		}

		*score -= 50;
		discovered_map[x][y]->discoveredCells ++;

	}

}
void activate_treasure (){ 

	// treasures only complete after all of their section is found
	//ex. both G, all 3 S, all 4 A, etc.

	//check which symbol is at the given coord
	//check how many others of the symbol have been discovered in discovered_treasures
	//add treasure to discovered_treasures
	//if all of its kind have now been found,
		//mark all of its kind complete
		//add to score
		//display completion message
	
}

/*general function arg order*/
/*coords (x, y), full map, discovered map, treasure arrays, modified values, const values*/

void activate_hint (int x, int y, Treasure full_map[10][10], Treasure discovered_map[10][10], int* hints_left){

	int distance = 0;

	printf("================================\n");
	printf("HINTs\n");
	printf("================================\n");

	if (*hints_left > 0){

		printf("Your current location: (%d,%d)\n", x, y);
		printf("The nearest treasure is\n");

		// DETERMINE HINT HERE

		*hints_left--;

		printf("Hint uses remaining: %d", hints_left);

	}
	else {

		printf("No hints remaining.\n");

	}

	printf("================================\n");

}