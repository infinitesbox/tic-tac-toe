#include <stdio.h>
#include <stdlib.h>
#include "board.h" 

Board *board_create()
{
    Board *board = (Board*) malloc(sizeof(*board));
    if(board == NULL)
    {
        printf("Board: There is no enough memory.\n");
        return NULL;
    }
   
    board->squares = (char*) malloc(sizeof(char*) * BOARD_SQUARES_SIZE);
    if(board->squares == NULL)
    {
        printf("Board: There is no enough memory.\n");
        return NULL;
    }

    board_reset(board);

    return board;
}

void board_delete(Board *board)
{
    free(board->squares);
    free(board);
}

BoardWinner *board_board_winner_create()
{
    BoardWinner *boardWinner = (BoardWinner*) malloc(sizeof(*boardWinner));
    if(boardWinner == NULL)
    {
        printf("BoardWinner: There is no enough memory.\n");
        return NULL;
    }

    boardWinner->token = '-';
    boardWinner->has_winner = 0;

    return boardWinner;
}

void board_board_winner_delete(BoardWinner *boardWinner)
{
    free(boardWinner);
}

int board_init(Board *board, char *squares, int rounds, char token)
{
    board = (Board*) malloc(sizeof(*board));
    int index;
    if(board == NULL)
    {
        printf("Board: There is no enough memory.\n");
        return -1;
    }

    for(index = 0; index < BOARD_SQUARES_SIZE; index++)
        board->squares[index] = squares[index];

    board->rounds = rounds;
    board->token = token;

    return 0;
}

void board_reset(Board *board)
{
    int index;
    for(index = 0; index < BOARD_SQUARES_SIZE; index++)
        board->squares[index] = '-';
    
    board->rounds = 1;
    board->token = '-';
}

void board_show(Board *board)
{
    int index;
    for(index = 0; index < BOARD_SQUARES_SIZE; index++)
    {
        printf("[%c]", board->squares[index]);
        if((index + 1) % 3 == 0) 
            printf("\n");
    }
}

int board_get_index_from_position(int row, int column)
{
    if(row > 3 || column > 3)
    {
        printf("Board: Row and Column values must be less or equal than 3!");
        return -1;
    }

    if(row < 1 || column < 1)
    {
        printf("Board: Row and Column values must be more or equal than 1!");
        return -1;
    }

    int start_index = 0;

    if(row == 2) start_index = 3;
    if(row == 3) start_index = 6;
    
    int index = start_index + (column - 1);

    return index;
}

int board_put_token(Board *board, int index, char token)
{
    if(board->squares[index] == '-')
    {
        board->squares[index] = token;
        board->token = token;
        return 0;
    }
    else
    {
        printf("Have already a token!");
        return -1;
    }
}

void board_has_winner(Board *board, BoardWinner *boardWinner)
{
    // rows
    if(board->squares[0] != '-' && board->squares[0] == board->squares[1] && board->squares[1] == board->squares[2])
    {
        boardWinner->has_winner = 1;
        boardWinner->token = board->squares[0];
        return;
    }

    if(board->squares[3] != '-' && board->squares[3] == board->squares[4] && board->squares[4] == board->squares[5])
    {
        boardWinner->has_winner = 1;
        boardWinner->token = board->squares[3];
        return;
    }

    if(board->squares[6] != '-' && board->squares[6] == board->squares[7] && board->squares[7] == board->squares[8])
    {
        boardWinner->has_winner = 1;
        boardWinner->token = board->squares[6];
        return;
    }

    // columns
    if(board->squares[0] != '-' && board->squares[0] == board->squares[3] && board->squares[3] == board->squares[6])
    {
        boardWinner->has_winner = 1;
        boardWinner->token = board->squares[0];
        return;
    }

    if(board->squares[1] != '-' && board->squares[1] == board->squares[4] && board->squares[4] == board->squares[7])
    {
        boardWinner->has_winner = 1;
        boardWinner->token = board->squares[1];
        return;
    }

    if(board->squares[2] != '-' && board->squares[2] == board->squares[5] && board->squares[5] == board->squares[8])
    {
        boardWinner->has_winner = 1;
        boardWinner->token = board->squares[2];
        return;
    }

    // diagonals
    if(board->squares[0] != '-' && board->squares[0] == board->squares[4] && board->squares[4] == board->squares[8])
    {
        boardWinner->has_winner = 1;
        boardWinner->token = board->squares[0];
        return;
    }

    if(board->squares[2] != '-' && board->squares[2] == board->squares[4] && board->squares[4] == board->squares[6])
    {
        boardWinner->has_winner = 1;
        boardWinner->token = board->squares[2];
        return;
    }

    boardWinner->has_winner = 0;
    boardWinner->token = '-';
}

int board_next_round(Board *board)
{
    board->rounds = board->rounds + 1;

    return board->rounds >= BOARD_SQUARES_SIZE;
}

char board_get_token(Board *board)
{
    if(board->rounds % 2 != 0)
        return 'X';
    else
        return 'O';
}

