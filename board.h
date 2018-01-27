//
// Created by rufus on 25.01.18.
//

#ifndef MILL_BOARD_H
#define MILL_BOARD_H

#include <stdlib.h>
#include "player.h"
#define PLACE 0
#define CHOSE 1
#define DESTROY 2
#define MOVE 4
#define END 5
#define FIRST 0
#define SECOND 1

static int graph[67][4];

void init_graph();

int move_check(int x,int y,int last_x,int last_y);

typedef struct board{
    int tab[7][7];
    unsigned int state,turn;
    int update;
    Player player[2];
    char *error;
    int last_x,last_y;
} *Board;

Board init_board();

void clicked(Board board,int x,int y);
int update(Board board,int x,int y);
#endif //MILL_BOARD_H
