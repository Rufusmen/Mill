//
// Created by rufus on 25.01.18.
//

#include "my_button.h"

void click(GtkWidget *event_box, GdkEventButton *event, gpointer data) {
    clicked(((Button) data)->board, ((Button) data)->x, ((Button) data)->y);
    int x = update(((Button) data)->board);
    if (x >= 0) {
        gtk_image_set_from_file(((Button) data)->image, ((Button) data)->assets[x]);
    } else {

    }
}

Button init_button(Board board, int x, int y, char *assets[3]) {
    Button button = malloc(sizeof(struct my_button));
    button->board = board;
    button->x = x;
    button->y = y;
    button->state = 0;
    button->event_box = gtk_event_box_new();
    button->image = gtk_image_new();
    button->assets[0] = assets[0];
    button->assets[1] = assets[1];
    button->assets[2] = assets[2];
    gtk_container_add(GTK_CONTAINER(button->event_box), button->image);
    g_signal_connect (G_OBJECT(button->event_box), "button_press_event", G_CALLBACK(click), button);
    return button;
}
