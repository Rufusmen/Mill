//
// Created by rufus on 25.01.18.
//

#include <stdio.h>
#include "board.h"

int check(Board board, int x, int y, int turn) {
    int a = 10 * x + y;
    if (graph[a][2] == -1) {
        for (int i = 0; i < 2; i++) {
            int _x = graph[a][i] / 10, _y = graph[a][i] % 10;
            if ((board->tab[_x][_y] == turn) && board->tab[_x * 2 - x][_y * 2 - y] == turn)return 1;
        }
    } else if (graph[a][3] == -1) {
        int _x1 = graph[a][0] / 10, _y1 = graph[a][0] % 10, _x2 = graph[a][1] / 10, _y2 = graph[a][1] % 10;
        if (board->tab[_x1][_y1] == turn && board->tab[_x2][_y2] == turn)return 1;
        _x1 = graph[a][2] / 10;
        _y1 = graph[a][2] % 10;
        if ((board->tab[_x1][_y1] == turn) && board->tab[_x1 * 2 - x][_y1 * 2 - y] == turn)return 1;

    } else {
        int _x1 = graph[a][0] / 10, _y1 = graph[a][0] % 10, _x2 = graph[a][3] / 10, _y2 = graph[a][3] % 10;
        if (board->tab[_x1][_y1] == turn && board->tab[_x2][_y2] == turn)return 1;
        _x1 = graph[a][1] / 10;
        _y1 = graph[a][1] % 10;
        _x2 = graph[a][2] / 10;
        _y2 = graph[a][2] % 10;
        if (board->tab[_x1][_y1] == turn && board->tab[_x2][_y2] == turn)return 1;
    }
    return 0;
}

void init_graph() {
    for (int i = 0; i < 67; i++)for (int j = 0; j < 4; j++)graph[i][j] = -1;
    graph[0][0] = 3;
    graph[0][1] = 30;
    graph[3][0] = 0;
    graph[3][1] = 6;
    graph[3][2] = 13;
    graph[6][0] = 3;
    graph[6][1] = 36;
    graph[11][0] = 13;
    graph[11][1] = 31;
    graph[13][0] = 3;
    graph[13][1] = 11;
    graph[13][2] = 15;
    graph[13][3] = 23;
    graph[15][0] = 13;
    graph[15][0] = 35;
    graph[22][0] = 23;
    graph[22][1] = 32;
    graph[23][0] = 24;
    graph[23][1] = 22;
    graph[23][2] = 13;
    graph[24][0] = 23;
    graph[24][1] = 34;
    graph[30][0] = 0;
    graph[30][1] = 60;
    graph[30][2] = 31;
    graph[31][0] = 11;
    graph[31][1] = 30;
    graph[31][2] = 32;
    graph[31][3] = 51;
    graph[32][0] = 22;
    graph[32][1] = 42;
    graph[32][2] = 31;
    graph[34][0] = 24;
    graph[34][1] = 44;
    graph[34][2] = 35;
    graph[35][0] = 15;
    graph[35][1] = 34;
    graph[35][2] = 36;
    graph[35][3] = 55;
    graph[36][0] = 6;
    graph[36][1] = 66;
    graph[36][2] = 35;
    graph[42][0] = 32;
    graph[42][1] = 43;
    graph[43][0] = 42;
    graph[43][1] = 44;
    graph[43][2] = 53;
    graph[44][0] = 34;
    graph[44][1] = 43;
    graph[51][0] = 31;
    graph[51][1] = 53;
    graph[53][0] = 43;
    graph[53][1] = 51;
    graph[53][2] = 55;
    graph[53][3] = 63;
    graph[55][0] = 35;
    graph[55][1] = 53;
    graph[60][0] = 30;
    graph[60][1] = 63;
    graph[63][0] = 66;
    graph[63][1] = 60;
    graph[63][2] = 53;
    graph[66][0] = 36;
    graph[66][1] = 63;
}

int check_mills(Board board, int turn) {
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++) {
            if (board->tab[i][j] == turn && !check(board, i, j, turn))return 1;
        }
    return 0;
}

int move_check(int x, int y, int last_x, int last_y) {
    int a = 10 * x + y;
    int b = 10 * last_x + last_y;
    for (int i = 0; i < 4; i++)if (graph[b][i] == a)return 1;
    return 0;
}

Board init_board() {
    Board board = malloc(sizeof(struct board));
    for (int i = 0; i < 7; i++)for (int j = 0; j < 7; j++)board->tab[i][j] = -1;
    for (int i = 0; i < 7; i++)if (i != 3)board->tab[i][3] = 0;
    for (int i = 0; i < 7; i++)if (i != 3)board->tab[3][i] = 0;
    for (int i = 0; i < 7; i++)if (i != 3)board->tab[i][i] = 0;
    for (int i = 0; i < 7; i++)if (i != 3)board->tab[i][6 - i] = 0;
    board->update = 0;
    board->state = PLACE;
    board->turn = FIRST;
    board->player[FIRST] = init_player("p1");
    board->player[SECOND] = init_player("p2");
    return board;
}

int can_move(int x, int y, Board board) {
    int a = 10 * x + y;
    for (int i = 0; i < 4; i++) {
        if (graph[a][i] != -1) {
            int new_x = graph[a][i] / 10;
            int new_y = graph[a][i] % 10;
            if (board->tab[new_x][new_y] == 0)return 1;
        }
    }
    return 0;
}

void clicked(Board board, int x, int y) {
    switch (board->state) {
        case PLACE: {
            if (board->tab[x][y] == 0) {
                board->update = board->turn + 1;
                board->tab[x][y] = board->turn + 1;
                board->player[board->turn]->in_stash--;
                if (check(board, x, y, board->turn + 1)) {
                    board->state = DESTROY;
                } else {
                    board->turn++;
                    board->turn %= 2;
                    if (board->player[board->turn]->in_stash > 0)board->state = PLACE;
                    else board->state = CHOSE;
                }
                printf("%d %d\n", board->turn, board->player[board->turn]->in_stash);
            } else {
                board->update = -1;
                board->error = "Other pawn";
                printf("%s\n", board->error);
            }
            break;
        }
        case CHOSE: {
            if (board->tab[x][y] == board->turn + 1) {
                board->tab[x][y] = 0;
                board->update = 0;
                board->player[board->turn]->in_stash++;
                if (board->player[board->turn]->pawns == 3)board->state = PLACE;
                else {
                    if (can_move(x, y, board)) {
                        board->last_x = x;
                        board->last_y = y;
                        board->state = MOVE;
                    } else {
                        board->update = -1;
                        board->error = "You can't move this pawn";
                        printf("%s\n", board->error);
                    }
                }
            } else {
                board->update = -1;
                board->error = "You must chose your pawn";
                printf("%s\n", board->error);
            }
            break;
        }
        case DESTROY: {
            if (board->tab[x][y] == ((board->turn + 1) % 2) + 1) {
                if (check(board, x, y, ((board->turn + 1) % 2) + 1)) {
                    if (check_mills(board, ((board->turn + 1) % 2) + 1)) {
                        board->update = -1;
                        board->error = "You can't destroy this pawn";
                        printf("%s\n", board->error);
                    }
                    else{
                        board->tab[x][y] = 0;
                        board->update = 0;
                        board->turn++;
                        board->turn %= 2;
                        board->player[board->turn]->pawns--;
                        if (board->player[board->turn]->pawns < 3)board->update = 3 + board->turn;
                        if (board->player[board->turn]->in_stash > 0)board->state = PLACE;
                        else board->state = CHOSE;
                    }
                } else {
                    board->tab[x][y] = 0;
                    board->update = 0;
                    board->turn++;
                    board->turn %= 2;
                    board->player[board->turn]->pawns--;
                    if (board->player[board->turn]->pawns < 3)board->update = 3 + board->turn;
                    if (board->player[board->turn]->in_stash > 0)board->state = PLACE;
                    else board->state = CHOSE;
                }
            } else {
                board->update = -1;
                board->error = "You must chose enemy pawn";
                printf("%s\n", board->error);
            }
            break;
        }
        case MOVE: {
            if (board->tab[x][y] == 0) {
                if (move_check(x, y, board->last_x, board->last_y)) {
                    board->update = board->turn + 1;
                    board->tab[x][y] = board->turn + 1;
                    board->player[board->turn]->in_stash--;
                    if (check(board, x, y, board->turn + 1)) {
                        board->state = DESTROY;
                    } else {
                        board->turn++;
                        board->turn %= 2;
                        board->state = CHOSE;
                    }
                } else {
                    board->update = -1;
                    board->error = "You can move only to the next field";
                    printf("%s\n", board->error);
                }
            } else {
                board->update = -1;
                board->error = "Other pawn";
                printf("%s\n", board->error);
            }
            break;
        }
    }
}

int update(Board board, int x, int y) {
    int update = board->update;
    board->update = 0;
    printf("%d\n", update);
    return update;
}