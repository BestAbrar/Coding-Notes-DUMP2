/**
 * Exercise 11 - Simple Sudoku Solver
 *
 * Please read the comments below carefully, they describe your task in detail.
 * Any clarifications and corrections will be posted to Piazza so please keep
 * an eye on the forum!
 *
 * Starter code: Mustafa Quraish, 2020
 */

#include <stdio.h>

#ifndef __testing__
int mem_matrix[9][9];
void set_mem_matrix(){
  for(int *a=&mem_matrix[0][0];a<=&mem_matrix[8][8];a++)
    *a=0;
}
void set_mem(int *mem){
  for(int a=0;a<9;a++)
    *(mem+a)=-1;
}

int in_mem(int mem[],int value){
  for(int a=0;a<9;a++){
    if (mem[a]==value)
      return 1;
  }
  return 0;
}
int isSafe(int grid[9][9], int a, int b, int num){
    for (int x = 0; x <= 8; x++){
        if (grid[a][x] == num)
            return 0;
    }
    for (int x = 0; x <= 8; x++){
        if (grid[x][b] == num)
            return 0;
    }
    int starta = a - a % 3,
                 startb = b - b % 3;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (grid[i + starta][j + startb] == num)
                return 0;
        }
    }
    return 1;
}
/**
 * Prints out the sudoku in an easy-to-view format. Feel free to change
 * this function if you need to help you debug.
 */

void print_sudoku(int sudoku[9][9])
{
  printf("The Sudoku contains:\n");
  printf("+-------+-------+-------+\n");
  for (int j = 0; j < 9; j++)
  {
    printf("| ");
    for (int i = 0; i < 9; i++)
    {
      printf("%d ", sudoku[j][i]);
      if (i % 3 == 2)
        printf("| ");
    }
    printf("\n");
    if (j % 3 == 2)
      printf("+-------+-------+-------+\n");
  }
}
#endif

/*****************************************************************************/

/**
 * This function checks if the current sudoku grid (not necessarily
 * complete) is valid. This means that (ignoring the 0s), each a, bumn
 * and 3x3 subgrid should not repeat any digits 1-9.
 *
 * Returns 1 if the sudoku is valid, or 0 if it's not.
 */
int is_valid_sudoku(int sudoku[9][9])
{
  int mem[9];
  set_mem(mem);
  int *p = NULL;
  p=mem;
  for (int a=0;a<9;a++){//horizontal lines
    for (int b=0;b<9;b++){
      if(sudoku[a][b]>9||sudoku[a][b]<0)
        return 0;
      if(in_mem(mem,sudoku[a][b]))
        return 0;
      if(sudoku[a][b]){
        *p=sudoku[a][b];
        p++;
      }
    }
    set_mem(mem);
    p=mem;
  }
  for (int a=0;a<9;a++){//vertical lines
    for (int b=0;b<9;b++){
      if(in_mem(mem,sudoku[b][a]))
        return 0;
      if(sudoku[b][a]){
        *p=sudoku[b][a];
        p++;
      }
    }
    set_mem(mem);
    p=mem;
  }
  for(int c=0;c<3;c++){
  for(int a = 3*c;a<3*(c+1);a++){
    for (int d=0;d<3;d++){
    for (int b=3*d;b<3*(d+1);b++){
      if(in_mem(mem,sudoku[b][a]))
        return 0;
      if(sudoku[b][a]){
        *p=sudoku[b][a];
        p++;
      }
    }
    }
    set_mem(mem);
    p=mem;
  }
  }
  return 1; // Fix this to return the correct value!
}

/**
 * Given a (possibly partially) completed sudoku grid, try and solve the
 * sudoku. The `sudoku` array should be changed to contain the solution if
 * one exists. None of digits in the input grid should be changed.
 *
 * NOTE: The empty spots are denoted with 0s in them.
 *
 * Refer to the handout for more discussion on how to implement this.
 *
 * Return 1 if the sudoku was solved, and update the `sudoku` parameter.
 * Return 0 if it's not possible to solve the sudoku, and leave the input
 *    `sudoku` array unchanged in this case.
 */
int solve_sudoku_recursion(int sudoku[9][9],int a,int b){
 if (a == 8 && b == 9)
     return 1;
 if (b == 9){
     a++;
     b = 0;
 }
 if (sudoku[a][b] > 0)
     return solve_sudoku_recursion(sudoku, a, b + 1);
 for (int num = 1; num <= 9; num++){
     if (isSafe(sudoku, a, b, num)==1){
         sudoku[a][b] = num;
         if (solve_sudoku_recursion(sudoku, a, b + 1)==1)
             return 1;
     }
     sudoku[a][b] = 0;
 }
 return 0;
}
int solve_sudoku(int sudoku[9][9])
{

  solve_sudoku_recursion(sudoku,0,0);
  set_mem_matrix();
  if (is_valid_sudoku(sudoku))
    return 1;
  return 0; // Fix this to return the correct value!
}

#ifndef __testing__

int main()
{
  /**
   * This example is the one from the Wiki, but your solution should be able
   * to handle any solvable sudoku. The time to solve different puzzles may
   * vary, but ideally it should not take more than a second for this one.
   */

  int sudoku_grid[9][9] = {
      {5, 3, 0, 0, 7, 0, 0, 0, 0},
      {6, 0, 0, 1, 9, 5, 0, 0, 0},
      {0, 9, 8, 0, 0, 0, 0, 6, 0},
      {8, 0, 0, 0, 6, 0, 0, 0, 3},
      {4, 0, 0, 8, 0, 3, 0, 0, 1},
      {7, 0, 0, 0, 2, 0, 0, 0, 6},
      {0, 6, 0, 0, 0, 0, 2, 8, 0},
      {0, 0, 0, 4, 1, 9, 0, 0, 5},
      {0, 0, 0, 0, 8, 0, 0, 7, 9}};

  print_sudoku(sudoku_grid);
  int solved = solve_sudoku(sudoku_grid);

  printf("\nsolve_sudoku() return value: %d\n\n", solved);

  /* Look at the handout to see the solution for this! */
  print_sudoku(sudoku_grid);

  return 0;
}

#endif
