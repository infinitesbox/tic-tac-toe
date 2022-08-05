#ifndef BOARD
#define BOARD

#define BOARD_SQUARES_SIZE 9

struct Board
{
    char *squares;
    int rounds;
    char token;
};
typedef struct Board Board;

struct BoardWinner
{
    int has_winner;
    char token;
};
typedef struct BoardWinner BoardWinner;

Board *board_create();
void board_delete(Board *board);
BoardWinner *board_board_winner_create();
void board_board_winner_delete();
int board_init(Board *board, char *squares, int rounds, char token);
void board_reset(Board *board);
void board_show(Board *board);
int board_get_index_from_position(int row, int column);
int board_put_token(Board *board, int index, char token);
void board_has_winner(Board *board, BoardWinner *boardWinner);
int board_next_round(Board *board);
char board_get_token(Board *board);

#endif