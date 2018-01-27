//
// Created by rufus on 25.01.18.
//

#ifndef MILL_MY_BUTTON_H
#define MILL_MY_BUTTON_H

#include <gtk/gtk.h>
#include "board.h"

typedef struct my_button{
    char *assets[3];
    Board board;
    GtkWidget *event_box;
    GtkWidget *image;
    int x,y,state;
} *Button;

Button init_button(Board board,int x,int y, char *assets[3]);

#endif //MILL_MY_BUTTON_H
