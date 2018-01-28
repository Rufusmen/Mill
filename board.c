//
// Created by rufus on 25.01.18.
//

#include <stdio.h>
#include <gtk/gtk.h>
#include "board.h"
#include "logger.h"

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
    graph[15][1] = 35;
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

Board init_board(GtkWidget *info, GtkWidget *score) {
    Board board = malloc(sizeof(struct board));
    for (int i = 0; i < 7; i++)for (int j = 0; j < 7; j++)board->tab[i][j] = -1;
    for (int i = 0; i < 7; i++)if (i != 3)board->tab[i][3] = 0;
    for (int i = 0; i < 7; i++)if (i != 3)board->tab[3][i] = 0;
    for (int i = 0; i < 7; i++)if (i != 3)board->tab[i][i] = 0;
    for (int i = 0; i < 7; i++)if (i != 3)board->tab[i][6 - i] = 0;
    board->info = info;
    board->score = score;
    board->update = 0;
    board->last_y = -1;
    board->last_x = -1;
    board->state = PLACE;
    board->turn = FIRST;
    board->player[FIRST] = init_player("White");
    board->player[SECOND] = init_player("Black");
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

void end(Board board) {
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "Game over");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 100);
    GtkWidget *label = gtk_label_new("<span foreground=\"red\" size=\"100000\">Game Over</span>");
    gtk_label_set_use_markup(GTK_LABEL (label), TRUE);
    char buff[40];
    if (board->player[0]->pawns < 3)sprintf(buff, "Player: %s wins", board->player[1]->name);
    else sprintf(buff, "<span size=\"50000\">Player: <i>%s</i> wins</span>", board->player[0]->name);
    GtkWidget *label2 = gtk_label_new(buff);
    gtk_label_set_use_markup(GTK_LABEL (label2), TRUE);
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(box), label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), label2, TRUE, TRUE, 0);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(close), window);
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_show_all(window);
    gtk_main();
}

void clicked(Board board, int x, int y) {
    switch (board->state) {
        case PLACE: {
            if (board->last_x == x && board->last_y == y) {
                board->tab[x][y] = board->turn + 1;
                board->update = board->turn + 1;
                board->player[board->turn]->in_stash--;
                board->state = CHOSE;
                board->last_x = board->last_y = -1;
            } else if (board->tab[x][y] == 0) {
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
            } else {
                board->update = -1;
                board->error = "<span size=\"x-large\" foreground=\"red\">Other pawn</span>";
                logger_log(LOGGER_LOG_LEVEL_WARN, board->error);
            }
            break;
        }
        case CHOSE: {
            if (board->tab[x][y] == board->turn + 1) {
                board->tab[x][y] = 0;
                board->update = 0;
                board->player[board->turn]->in_stash++;
                if (board->player[board->turn]->pawns == 3) {
                    board->state = PLACE;
                    board->last_x = x;
                    board->last_y = y;
                } else {
                    if (can_move(x, y, board)) {
                        board->state = MOVE;
                        board->last_x = x;
                        board->last_y = y;
                    } else {
                        board->update = -1;
                        board->error = "<span size=\"x-large\" foreground=\"red\">You can't move this pawn</span>";
                        logger_log(LOGGER_LOG_LEVEL_WARN, board->error);
                    }
                }
            } else {
                board->update = -1;
                board->error = "<span size=\"x-large\" foreground=\"red\">You must chose your pawn</span>";
                logger_log(LOGGER_LOG_LEVEL_WARN, board->error);
            }
            break;
        }
        case DESTROY: {
            if (board->tab[x][y] == ((board->turn + 1) % 2) + 1) {
                if (check(board, x, y, ((board->turn + 1) % 2) + 1)) {
                    if (check_mills(board, ((board->turn + 1) % 2) + 1)) {
                        board->update = -1;
                        board->error = "<span size=\"x-large\" foreground=\"red\">You can't destroy this pawn</span>";
                        logger_log(LOGGER_LOG_LEVEL_WARN, board->error);
                    } else {
                        board->tab[x][y] = 0;
                        board->update = 0;
                        board->turn++;
                        board->turn %= 2;
                        board->player[board->turn]->pawns--;
                        if (board->player[board->turn]->pawns < 3) {
                            board->update = 0;
                            board->state = END;
                        } else if (board->player[board->turn]->in_stash > 0)board->state = PLACE;
                        else board->state = CHOSE;
                    }
                } else {
                    board->tab[x][y] = 0;
                    board->update = 0;
                    board->turn++;
                    board->turn %= 2;
                    board->player[board->turn]->pawns--;
                    if (board->player[board->turn]->pawns < 3) {
                        board->update = 0;
                        board->state = END;
                    } else if (board->player[board->turn]->in_stash > 0)board->state = PLACE;
                    else board->state = CHOSE;
                }
            } else {
                board->update = -1;
                board->error = "<span size=\"x-large\" foreground=\"red\">You must chose enemy pawn</span>";
                logger_log(LOGGER_LOG_LEVEL_WARN, board->error);
            }
            break;
        }
        case MOVE: {
            if (board->last_x == x && board->last_y == y) {
                board->tab[x][y] = board->turn + 1;
                board->update = board->turn + 1;
                board->last_x = board->last_y = -1;
                board->player[board->turn]->in_stash--;
                board->state = CHOSE;
            } else if (board->tab[x][y] == 0) {
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
                    board->error = "<span size=\"x-large\" foreground=\"red\">You can move only to the next field</span>";
                    logger_log(LOGGER_LOG_LEVEL_WARN, board->error);
                }
            } else {
                board->update = -1;
                board->error = "<span size=\"x-large\" foreground=\"red\">Other pawn</span>";
                logger_log(LOGGER_LOG_LEVEL_WARN, board->error);
            }
            break;
        }
        case END: {

        }
    }
}

int update(Board board) {
    int update = board->update;
    board->update = 0;
    if (update != -1)
        switch (board->state) {
            case PLACE: {
                board->error = "<span size=\"x-large\">Chose where you want to place your pawn</span>";
                logger_log(LOGGER_LOG_LEVEL_INFO, board->error);
                break;
            }
            case MOVE: {
                board->error = "<span size=\"x-large\">Chose where you want to move your pawn</span>";
                logger_log(LOGGER_LOG_LEVEL_INFO, board->error);
                break;
            }
            case CHOSE: {
                board->error = "<span size=\"x-large\">Chose pawn which you want to move</span>";
                logger_log(LOGGER_LOG_LEVEL_INFO, board->error);
                break;
            }
            case DESTROY: {
                board->error = "<span size=\"x-large\">Chose enemy pawn which you want to destroy</span>";
                logger_log(LOGGER_LOG_LEVEL_INFO, board->error);
                break;
            }
            case END: {
                board->error = "<span size=\"x-large\">Game ends</span>";
                logger_log(LOGGER_LOG_LEVEL_INFO, board->error);
                end(board);
            }
        }
    gtk_label_set_text(GTK_LABEL(board->info), board->error);
    gtk_label_set_use_markup(GTK_LABEL (board->info), TRUE);
    char buff[100];
    sprintf(buff, "<span size=\"x-large\">Turn: %s \t\t\t Pawns: \tWhite: %d \tBlack: %d </span>",
            board->player[board->turn]->name, board->player[0]->pawns, board->player[1]->pawns);
    gtk_label_set_text(GTK_LABEL(board->score), buff);
    gtk_label_set_use_markup(GTK_LABEL (board->score), TRUE);

    return update;
}

void reset(Board board){
    for (int i = 0; i < 7; i++)for (int j = 0; j < 7; j++)board->tab[i][j] = -1;
    for (int i = 0; i < 7; i++)if (i != 3)board->tab[i][3] = 0;
    for (int i = 0; i < 7; i++)if (i != 3)board->tab[3][i] = 0;
    for (int i = 0; i < 7; i++)if (i != 3)board->tab[i][i] = 0;
    for (int i = 0; i < 7; i++)if (i != 3)board->tab[i][6 - i] = 0;
    board->update = 0;
    board->last_y = -1;
    board->last_x = -1;
    board->state = PLACE;
    board->turn = FIRST;
    player_reset(board->player[FIRST]);
    player_reset(board->player[SECOND]);
}