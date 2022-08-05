#include <stdio.h>
#include "game.h"
#include "board.h"

int game_play()
{
    Board *board = board_create();
    BoardWinner *boardWinner = board_board_winner_create();

    int is_finished = 0;
    
    board_show(board);
    
    while(is_finished != 1)
    {
        int row = 0;
        printf("Choose the row:\n");
        scanf("%d", &row);

        int column = 0;
        printf("Choose the column:\n");
        scanf("%d", &column);

        int token = board_get_token(board);

        int index = board_get_index_from_position(row, column);
        if(index == -1) continue;

        int status = board_put_token(board, index, token);
        if(status == -1) continue;

        board_show(board);
        
        board_has_winner(board, boardWinner);

        if(boardWinner->has_winner == 1)
        {
            printf("We have a winner!\n");
            printf("Winner: %c\n", boardWinner->token);
            printf("Win in %d rounds!\n", board->rounds);
            is_finished = 1;
            break;
        }

        is_finished = board_next_round(board);
        if(is_finished == 1)
        {
            printf("No Winner - Game Over!");
            return 1;
        }
    }

    board_board_winner_delete(boardWinner);
    board_delete(board);

    return -1;
}