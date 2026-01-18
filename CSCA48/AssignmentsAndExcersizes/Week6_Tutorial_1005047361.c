#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define BOARD_SIZE 5
#define TRUE 0
#define FALSE 1

int lost = 0;

char board[BOARD_SIZE][BOARD_SIZE];
typedef struct GameBoard{
  char game_board;
  struct GameBoard *next;
}Game_Board;

void build_board();
void build_gboard();
void create_mines();
void print_board();
void print_fullboard();
void start();
int play_game();
int check_win_game();
void check_for_mine(int, int);
int check_for_nearby_mines(int, int);

int main ()
{
    puts("Welcome to the Minesweeper Game\nCreated by: Abdullah Bin Shams\nFor the enthusiastic students of CSCA48\n\n");
    start();

    return 0;
}
Game_Board *newtile (char tile){
    Game_Board *NewCmdNode =(Game_Board *)calloc(1, sizeof(Game_Board));
    
}
void build_board()
{
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++)
        for(j = 0; j < BOARD_SIZE; j++)
            board[i][j] = '-';
    create_mines();
}

void build_gboard()
{

    int i, j;
    int row, col;
    for(i = 0; i < BOARD_SIZE; i++)
        for(j = 0; j < BOARD_SIZE; j++)
            game_board[i][j] = '-';

    for(col = 0; col < BOARD_SIZE; col++)
        printf("%d ", col + 1);

    printf("\n");

    for(row = 0; row < BOARD_SIZE; row++)
    {
        for(col = 0; col < BOARD_SIZE; col++)
        {
            printf("%c ", game_board[row][col]);
        }
        printf(" %d ", row + 1);
        printf("\n");
    }
}

void create_mines()
{
    int i, random;
    srand(time(0));

    for (i = 0; i < BOARD_SIZE; i++)
    {
        random = rand() % (BOARD_SIZE);
        board[random][i] = '*';
    }
}

void print_board()
{
    int row, col;
    for(col = 0; col < BOARD_SIZE; col++)
        printf("%d ", col + 1);
    printf("\n");
        for(row = 0; row < BOARD_SIZE; row++)
    {
        for(col = 0; col < BOARD_SIZE; col++)
        {
            printf("%c ", game_board[row][col]);
        }
        printf(" %d ", row + 1);
        printf("\n");
    }
}

/* Print the full board showing mines */
void print_fullboard()
{
    int row, col;

    for(col = 0; col < BOARD_SIZE; col++)
        printf("%d ", col + 1);
    printf("\n");
        for(row = 0; row < BOARD_SIZE; row++)
    {
        for(col = 0; col < BOARD_SIZE; col++)
        {
            printf("%c ", board[row][col]);
        }
        printf(" %d ", row + 1);
        printf("\n");
    }
}

int play_game()
{
    int r_selection = 0, c_selection = 0,
        nearbymines = 0, nearbymines2 = 0,
        nearbymines3 = 0, nearbymines4 = 0,
        nearbymines5 = 0, nearbymines6 = 0,
        nearbymines7 = 0, nearbymines8 = 0,
        i = 0;
    do {
    printf("\nMake a selection (ie. row [space] col): ");
    scanf("%d %d", &r_selection,&c_selection);
    printf("\n \n");
    } while(r_selection < 1 || r_selection > BOARD_SIZE || c_selection < 1 || r_selection > BOARD_SIZE);

    check_for_mine(r_selection - 1, c_selection - 1);

    if(lost == 1)
        return -1;

    nearbymines = check_for_nearby_mines(r_selection - 1, c_selection - 1);
    game_board[r_selection - 1][c_selection - 1] = (char)( ((int)'0') + nearbymines );

    if(nearbymines == 0)
    {
        if(c_selection != BOARD_SIZE)
        {
            i = 0;
            while(nearbymines == 0 && (c_selection - 1 + i) < BOARD_SIZE)
            {
                nearbymines = check_for_nearby_mines(r_selection - 1, (c_selection - 1 + i));
                if(nearbymines != -1)
                {
                game_board[r_selection - 1][(c_selection - 1) + i] = (char) ( ((int)'0') + nearbymines );
                i++;
                }
            }
                if(r_selection != 1)
                {
                    i = 0;
                    while(nearbymines5 == 0 && (c_selection - 1 + i) < BOARD_SIZE && (r_selection - 1 - i) > 0)
                    {
                        nearbymines5 = check_for_nearby_mines((r_selection - 1 - i), (c_selection - 1 + i));
                        if(nearbymines5 != -1)
                        {
                        game_board[(r_selection - 1) - i][(c_selection - 1) + i] = (char) ( ((int)'0') + nearbymines5);
                        i++;
                        }
                    }
                }
                if(r_selection != BOARD_SIZE)
                {
                    i = 0;
                    while(nearbymines6 == 0 && (r_selection - 1 + i) < BOARD_SIZE && (c_selection - 1 + i) < BOARD_SIZE )
                    {
                        // This is checking elements to the diagonal-dright
                        nearbymines6 = check_for_nearby_mines((r_selection - 1 + i), (c_selection - 1 + i));
                        if(nearbymines != -1)
                        {
                        game_board[(r_selection - 1) + i][(c_selection - 1) + i] = (char) ( ((int)'0') + nearbymines6);
                        i++;
                        }
                    }
                }
        }

        if(r_selection != BOARD_SIZE)
        {
            i = 0;
            while(nearbymines2 == 0 && (r_selection - 1 + i) < BOARD_SIZE)
            {
                nearbymines2 = check_for_nearby_mines((r_selection - 1 + i), c_selection - 1);
                if(nearbymines2 != -1)
                {
                game_board[(r_selection - 1) + i][c_selection - 1] = (char) ( ((int)'0') + nearbymines2 );
                i++;
                }
            }

            if(c_selection != BOARD_SIZE)
            {
                i = 0;
                while(nearbymines7 == 0 && (r_selection - 1 + i) < BOARD_SIZE && (c_selection - 1 - i) > 0)
                {
                    nearbymines7 = check_for_nearby_mines((r_selection - 1 + i), (c_selection - 1 - i));
                    if(nearbymines != -1)
                    {
                    game_board[(r_selection - 1) + i][(c_selection - 1) - i] = (char) ( ((int)'0') + nearbymines7);
                    i++;
                    }
                }
            }
        }

        if(r_selection != 1)
        {
            i = 0;
            while(nearbymines3 == 0 && (r_selection - i) > 0)
            {
                nearbymines3 = check_for_nearby_mines((r_selection - 1 - i), c_selection - 1);
                if(nearbymines3 != -1)
                {
                game_board[(r_selection - 1) - i][c_selection - 1] = (char) ( ((int)'0') + nearbymines3 );
                i++;
                }
            }
            if(c_selection != BOARD_SIZE)
            {
                while(nearbymines8 == 0 && (c_selection - 1 - i) > 0 && (r_selection - 1 - i) > 0)
                {
                    nearbymines8 = check_for_nearby_mines((r_selection - 1 - i), (c_selection - 1 - i));
                    if(nearbymines8 != -1)
                    {
                    game_board[(r_selection - 1) - i][(c_selection - 1) - i] = (char) ( ((int)'0') + nearbymines8);
                    i++;
                    }
                }
            }
        }

        if(c_selection != 1)
        {
            i = 0;
            while(nearbymines4 == 0 && (c_selection - i) > 0)
            {
                nearbymines4 = check_for_nearby_mines(r_selection - 1, (c_selection - 1 - i));
                if(nearbymines4 != -1)
                {
                game_board[r_selection - 1][(c_selection - 1) - i] = (char) ( ((int)'0') + nearbymines4 );
                i++;
                }
            }
        }
    }

    if(check_win_game() == TRUE)
    {
        print_fullboard();
        printf("\n\nCongratulations!!\n\n");
    }

    return 0;
}

void check_for_mine(int r_select, int c_select)
{
    if(board[r_select][c_select] == '*')
    {
        printf("\nYou've hit a mine! You lose!\n");
        print_fullboard();
        getchar(); getchar();
        lost = 1;
    }
}

int check_for_nearby_mines(int r_select, int c_select)
{
    int nearby_mine_count = 0;

    if(board[r_select][c_select] == '*')
    {
        return -1;
    }
    // Check for mines below and to the right.
    if(r_select < (BOARD_SIZE - 1) && c_select < (BOARD_SIZE - 1))
    {
        // Check for mine below
        if(board[r_select + 1][c_select] == '*')
            nearby_mine_count++;
        // Check for mine to the right.
        if(board[r_select][c_select + 1] == '*')
            nearby_mine_count++;
        // Check for mine diagonal-dright.
        if(board[r_select + 1][c_select + 1] == '*')
            nearby_mine_count++;

        // Check whether the columns to the left can be checked
        if(c_select != 0)
        {
            // Check for mine diagonal-dleft
            if(board[r_select + 1][c_select - 1] == '*')
                nearby_mine_count++;
            // Check for mine to the left
            if(board[r_select][c_select - 1] == '*')
                nearby_mine_count++;
        }
        // Check whether the rows above can be checked
        if(r_select != 0)
        {
            // Check for mine above
            if(board[r_select - 1][c_select] == '*')
                nearby_mine_count++;
            // Check for mine diagonal-uright
            if(board[r_select - 1][c_select + 1] == '*')
                nearby_mine_count++;
            // Check whether columns to the left can be checked
            if(c_select != 0)
            {
                // Check for mine diagonal-uleft
                if(board[r_select - 1][c_select - 1] == '*')
                    nearby_mine_count++;
            }
        }
    }
    // Check if selection is in last row
    if(r_select == (BOARD_SIZE - 1) && c_select != (BOARD_SIZE - 1))
    {
        // Check for mine above
            if(board[r_select - 1][c_select] == '*')
                nearby_mine_count++;
        // Check for mine diagonal-uright
            if(board[r_select - 1][c_select + 1] == '*')
                nearby_mine_count++;
    }
    // Check if selection is in last column
    if(c_select == (BOARD_SIZE - 1) && r_select != (BOARD_SIZE - 1))
    {
        // Check for mine to the left
            if(board[r_select][c_select - 1] == '*')
                nearby_mine_count++;
        // Check for mine diagonal-dleft
            if(board[r_select + 1][c_select - 1] == '*')
                nearby_mine_count++;
    }
    // Check whether selection is last in element
    if(r_select == (BOARD_SIZE - 1) && c_select == (BOARD_SIZE - 1))
    {
        // Check for mine to the left
            if(board[r_select][c_select - 1] == '*')
                nearby_mine_count++;
        // Check for mine diagonal-dleft
            if(board[r_select - 1][c_select - 1] == '*')
                nearby_mine_count++;
        // Check for mine above
            if(board[r_select - 1][c_select] == '*')
                nearby_mine_count++;
    }

    return nearby_mine_count;
}

int check_win_game()
{
    int row, col;

    for(row = 0; row < BOARD_SIZE; row++)
        for(col = 0; col < BOARD_SIZE; col++)
        {
            if(game_board[row][col] == '-' && board[row][col] != '*')
                return FALSE;
        }

    return TRUE;
}

void start()
{
    lost = 0;
    build_board();
    build_gboard();

    do
    {
    play_game();
    print_board();
    } while(lost != 1);
    print_fullboard();
}
