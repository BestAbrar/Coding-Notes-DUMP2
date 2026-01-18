"""CSCA08: Functions for the tic-tac-toe game.

Instructions (READ THIS FIRST!)
===============================

Make sure that the files tictactoe_game.py and a1_checker.py are in the same
folder as this file (tictactoe_functions.py).

Copyright and Usage Information
===============================

This code is provided solely for the personal and private use of students
taking the course CSC108/CSCA08 at the University of Toronto. Copying for
purposes other than this use is expressly prohibited. All forms of distribution
of this code, whether as given or with any changes, are expressly prohibited.

All of the files in this folder are:
Copyright (c) 2022 the University of Toronto CSC108/CSCA08 Teaching Team.
"""


EMPTY_CELL = '-'


def is_between(value: int, min_value: int, max_value: int) -> bool:
    """Return True if and only if value is between min_value and max_value.

    Precondition: min_value < max_value

    >>> is_between(1, 0, 2)
    True
    >>> is_between(0, 2, 3)
    False
    >>> is_between(1, 1, 3)
    False
    """
    return min_value < value < max_value

def game_board_full(game_board:str) -> bool:
    """Checks if board is full, if no more EMPTY_CELL's on board return true

    >>> game_board_full('XOXO')
    True
    >>> game_board_full('-X-O')
    False
    """
    
    return game_board.find(EMPTY_CELL)== -1

def get_board_size(game_board:str) -> int:
    """ Return the lenght of the side of a playable game board as an intiger

    >>> get_board_size('XOXO')
    2
    >>> get_board_size('XOXOXOXOX')
    3
    """
    
    return int(len(game_board)**.5)

def make_new_board(size:int)-> str:
    """return representation of a new board as a string with size^2 number of
    EMPTY_CELL characters
    
    >>> make_new_board(2)
    '----'
    >>> make_new_board(3)
    '---------'
    """
    
    return EMPTY_CELL*size**2

def get_string_index(row:int,column:int,size:int)-> int:
    """return index of the string version of a board game corrisonding
    to a spesific cell
    Ex. X* O = XOOX
        O  X   -

    >>> get_string_index(1,1,2)
    0
    >>> get_string_index(2,2,2)
    3
    """
    return (row-1)*size+column-1
def change_cell(symbol:str, row:int, column:int, game_board:str)-> str:
    """Replace character in a cell with one-character string 'symbol' and
    return updated gameboard

    >>> change_cell('X',1,1,'----')
    'X---'
    >>> change_cell('X',2,2,'----')
    '---X'
    >>> change_cell('X',1,2,'----')
    '-X--'
    """
    temp = ''
    size = get_board_size(game_board)
    string_index= get_string_index(row, column, size)
    if string_index==0:
        game_board = symbol+game_board[string_index+1:len(game_board)]
    if string_index==len(game_board)-1:
        game_board = game_board[:string_index]+symbol
    else:
        temp = game_board[:string_index]+symbol
        temp += game_board[string_index+1:len(game_board)]
        return temp
    return game_board


def get_line(game_board:str, direction:str, position:int)-> int:
    """Return a string corresponding to the row, column, or diagnols of the
    gameboard
    Ex. X - O
        - X O = 'X-O-XO--X'
        - - X

    >>> get_line('X-O-XO--X','down',1)
    'X--'
    >>> get_line('X-O-XO--X','across',1)
    'X-O'
    >>> get_line('X-O-XO--X','up_diagonal',1)
    '-XO'
    >>> get_line('X-O-XO--X','down_diagonal',1)
    'XXX'
    """
    
    temp=''
    
    size=get_board_size(game_board)
    if direction == 'across':
        index = get_string_index(position,1,size)
        return game_board[index:index+size]
    elif direction == 'down':
        return game_board[position-1::size]
    elif direction == 'down_diagonal':
        return game_board[0::size+1]
    elif direction == 'up_diagonal':
        return game_board[(size**2-size):size-2:-(size-1)]
    return None
