#include <stdio.h>
#include <gtk/gtk.h>
#include "board.h"
#include "my_button.h"

Button button_board[7][7];
char *assets[7][7][3];

void set_grid(GtkWidget *grid, Board board) {
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++) {
            if (board->tab[i][j] == 0) {
                button_board[i][j] = init_button(board,i,j,assets[i][j]);
                gtk_image_set_from_file(button_board[i][j]->image,assets[i][j][0]);
                gtk_grid_attach(GTK_GRID(grid),button_board[i][j]->event_box,j,i,1,1);
            } else {
                GtkWidget * image=gtk_image_new_from_file(assets[i][j][0]);
                gtk_grid_attach(GTK_GRID(grid),image,j,i,1,1);
            }
        }
}

void init_assets(){
    assets[0][0][0]="../Assets/Corner_R_D.png";
    assets[0][0][1]="../Assets/Corner_R_D_White.png";
    assets[0][0][2]="../Assets/Corner_R_D_Black.png";
    assets[0][1][0]="../Assets/Line_RL.png";
    assets[0][2][0]="../Assets/Line_RL.png";
    assets[0][3][0]="../Assets/Trio_U.png";
    assets[0][3][1]="../Assets/Trio_U_White.png";
    assets[0][3][2]="../Assets/Trio_U_Black.png";
    assets[0][4][0]="../Assets/Line_RL.png";
    assets[0][5][0]="../Assets/Line_RL.png";
    assets[0][6][0]="../Assets/Corner_L_D.png";
    assets[0][6][1]="../Assets/Corner_L_D_White.png";
    assets[0][6][2]="../Assets/Corner_L_D_Black.png";
    assets[1][0][0]="../Assets/Line_UD.png";
    assets[1][1][0]="../Assets/Corner_R_D.png";
    assets[1][1][1]="../Assets/Corner_R_D_White.png";
    assets[1][1][2]="../Assets/Corner_R_D_Black.png";
    assets[1][2][0]="../Assets/Line_RL.png";
    assets[1][3][0]="../Assets/Cross.png";
    assets[1][3][1]="../Assets/Cross_White.png";
    assets[1][3][2]="../Assets/Cross_Black.png";
    assets[1][4][0]="../Assets/Line_RL.png";
    assets[1][5][0]="../Assets/Corner_L_D.png";
    assets[1][5][1]="../Assets/Corner_L_D_White.png";
    assets[1][5][2]="../Assets/Corner_L_D_Black.png";
    assets[1][6][0]="../Assets/Line_UD.png";
    assets[2][0][0]="../Assets/Line_UD.png";
    assets[2][1][0]="../Assets/Line_UD.png";
    assets[2][2][0]="../Assets/Corner_R_D.png";
    assets[2][2][1]="../Assets/Corner_R_D_White.png";
    assets[2][2][2]="../Assets/Corner_R_D_Black.png";
    assets[2][3][0]="../Assets/Trio_D.png";
    assets[2][3][1]="../Assets/Trio_D_White.png";
    assets[2][3][2]="../Assets/Trio_D_Black.png";
    assets[2][4][0]="../Assets/Corner_L_D.png";
    assets[2][4][1]="../Assets/Corner_L_D_White.png";
    assets[2][4][2]="../Assets/Corner_L_D_Black.png";
    assets[2][5][0]="../Assets/Line_UD.png";
    assets[2][6][0]="../Assets/Line_UD.png";
    assets[3][0][0]="../Assets/Trio_L.png";
    assets[3][0][1]="../Assets/Trio_L_White.png";
    assets[3][0][2]="../Assets/Trio_L_Black.png";
    assets[3][1][0]="../Assets/Cross.png";
    assets[3][1][1]="../Assets/Cross_White.png";
    assets[3][1][2]="../Assets/Cross_Black.png";
    assets[3][2][0]="../Assets/Trio_R.png";
    assets[3][2][1]="../Assets/Trio_R_White.png";
    assets[3][2][2]="../Assets/Trio_R_Black.png";
    assets[3][3][0]="../Assets/Mid.png";
    assets[3][4][0]="../Assets/Trio_L.png";
    assets[3][4][1]="../Assets/Trio_L_White.png";
    assets[3][4][2]="../Assets/Trio_L_Black.png";
    assets[3][5][0]="../Assets/Cross.png";
    assets[3][5][1]="../Assets/Cross_White.png";
    assets[3][5][2]="../Assets/Cross_Black.png";
    assets[3][6][0]="../Assets/Trio_R.png";
    assets[3][6][1]="../Assets/Trio_R_White.png";
    assets[3][6][2]="../Assets/Trio_R_Black.png";
    assets[4][0][0]="../Assets/Line_UD.png";
    assets[4][1][0]="../Assets/Line_UD.png";
    assets[4][2][0]="../Assets/Corner_R_U.png";
    assets[4][2][1]="../Assets/Corner_R_U_White.png";
    assets[4][2][2]="../Assets/Corner_R_U_Black.png";
    assets[4][3][0]="../Assets/Trio_U.png";
    assets[4][3][1]="../Assets/Trio_U_White.png";
    assets[4][3][2]="../Assets/Trio_U_Black.png";
    assets[4][4][0]="../Assets/Corner_L_U.png";
    assets[4][4][1]="../Assets/Corner_L_U_White.png";
    assets[4][4][2]="../Assets/Corner_L_U_Black.png";
    assets[4][5][0]="../Assets/Line_UD.png";
    assets[4][6][0]="../Assets/Line_UD.png";
    assets[5][0][0]="../Assets/Line_UD.png";
    assets[5][1][0]="../Assets/Corner_R_U.png";
    assets[5][1][1]="../Assets/Corner_R_U_White.png";
    assets[5][1][2]="../Assets/Corner_R_U_Black.png";
    assets[5][2][0]="../Assets/Line_RL.png";
    assets[5][3][0]="../Assets/Cross.png";
    assets[5][3][1]="../Assets/Cross_White.png";
    assets[5][3][2]="../Assets/Cross_Black.png";
    assets[5][4][0]="../Assets/Line_RL.png";
    assets[5][5][0]="../Assets/Corner_L_U.png";
    assets[5][5][1]="../Assets/Corner_L_U_White.png";
    assets[5][5][2]="../Assets/Corner_L_U_Black.png";
    assets[5][6][0]="../Assets/Line_UD.png";
    assets[6][0][0]="../Assets/Corner_R_U.png";
    assets[6][0][1]="../Assets/Corner_R_U_White.png";
    assets[6][0][2]="../Assets/Corner_R_U_Black.png";
    assets[6][1][0]="../Assets/Line_RL.png";
    assets[6][2][0]="../Assets/Line_RL.png";
    assets[6][3][0]="../Assets/Trio_D.png";
    assets[6][3][1]="../Assets/Trio_D_White.png";
    assets[6][3][2]="../Assets/Trio_D_Black.png";
    assets[6][4][0]="../Assets/Line_RL.png";
    assets[6][5][0]="../Assets/Line_RL.png";
    assets[6][6][0]="../Assets/Corner_L_U.png";
    assets[6][6][1]="../Assets/Corner_L_U_White.png";
    assets[6][6][2]="../Assets/Corner_L_U_Black.png";
}

int main(int argc, char **argv) {
    init_assets();
    init_graph();
    Board board = init_board();
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "Zaczynamy z GTK+ 3.0");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *label1 = gtk_label_new("Score:");
    GtkWidget *label2 = gtk_label_new("INFO");
    GtkWidget *grid = gtk_grid_new();
    set_grid(grid, board);
    gtk_box_pack_start(GTK_BOX(box), label1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), grid, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), label2, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_show_all(window);
    gtk_main();
}