#include <stdio.h>
#include <gtk/gtk.h>
#include "board.h"
#include "my_button.h"
#include "logger.h"
#include "fifo.h"

Button button_board[7][7];
char *assets[7][7][3];
PipesPtr pipes=NULL;

void change(int x,int y,int state){
    gtk_image_set_from_file(GTK_IMAGE(button_board[x][y]->image),assets[x][y][state]);
}

static gboolean read_pipe(gpointer board){
    if(((Board)board)->turn==((Board)board)->color)return 1;
    char buff[15];
    if(getStringFromPipe((((Board)board)->pipes),buff,15)){
        int x=buff[0]-'0';
        int y=buff[2]-'0';
        int state=buff[4]-'0';
        unsigned int turn = (unsigned int) (buff[6] - '0');
        int state2=buff[8]-'0';
        int pawns = buff[10]-'0';
        int stash = buff[12]-'0';
        printf("%s\n",buff);
        if(x<0||y<0||state<0||turn<0||state2<0)
            return 1;
        int other = (((Board)board)->color+1)%2;
        ((Board)board)->player[other]->pawns=pawns;
        ((Board)board)->player[other]->in_stash=stash;
        ((Board)board)->turn=turn;
        ((Board)board)->tab[x][y]=state;
        ((Board)board)->state= (unsigned int) state2;
        if(state2==DESTROY)((Board)board)->player[((Board)board)->color]->pawns--;
        change(x,y,state);
        update((Board)board);
    }
    return 1;
}

void close_app() {
    gtk_main_quit();
    logger_log(LOGGER_LOG_LEVEL_DEBUG, "App close");
    logger_close();
    if(pipes!=NULL)closePipes(pipes);
    exit(0);
}

void restart_app(GtkWidget *event_box, GdkEventButton *event, gpointer data) {
    reset((Board)data);
    for(int i=0;i<7;i++)for(int j=0;j<7;j++)if(button_board[i][j]!=NULL)gtk_image_set_from_file(GTK_IMAGE(button_board[i][j]->image),assets[i][j][0]);
    update((Board)data);
}

void set_grid(GtkWidget *grid, Board board) {
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++) {
            if (board->tab[i][j] == 0) {
                button_board[i][j] = init_button(board, i, j, assets[i][j]);
                gtk_image_set_from_file(GTK_IMAGE(button_board[i][j]->image), assets[i][j][0]);
                gtk_grid_attach(GTK_GRID(grid), button_board[i][j]->event_box, j, i, 1, 1);
            } else {
                GtkWidget *image = gtk_image_new_from_file(assets[i][j][0]);
                gtk_grid_attach(GTK_GRID(grid), image, j, i, 1, 1);
            }
        }
}

void init_assets() {
    assets[0][0][0] = "../Assets/Corner_R_D.png";
    assets[0][0][1] = "../Assets/Corner_R_D_White.png";
    assets[0][0][2] = "../Assets/Corner_R_D_Black.png";
    assets[0][1][0] = "../Assets/Line_RL.png";
    assets[0][2][0] = "../Assets/Line_RL.png";
    assets[0][3][0] = "../Assets/Trio_U.png";
    assets[0][3][1] = "../Assets/Trio_U_White.png";
    assets[0][3][2] = "../Assets/Trio_U_Black.png";
    assets[0][4][0] = "../Assets/Line_RL.png";
    assets[0][5][0] = "../Assets/Line_RL.png";
    assets[0][6][0] = "../Assets/Corner_L_D.png";
    assets[0][6][1] = "../Assets/Corner_L_D_White.png";
    assets[0][6][2] = "../Assets/Corner_L_D_Black.png";
    assets[1][0][0] = "../Assets/Line_UD.png";
    assets[1][1][0] = "../Assets/Corner_R_D.png";
    assets[1][1][1] = "../Assets/Corner_R_D_White.png";
    assets[1][1][2] = "../Assets/Corner_R_D_Black.png";
    assets[1][2][0] = "../Assets/Line_RL.png";
    assets[1][3][0] = "../Assets/Cross.png";
    assets[1][3][1] = "../Assets/Cross_White.png";
    assets[1][3][2] = "../Assets/Cross_Black.png";
    assets[1][4][0] = "../Assets/Line_RL.png";
    assets[1][5][0] = "../Assets/Corner_L_D.png";
    assets[1][5][1] = "../Assets/Corner_L_D_White.png";
    assets[1][5][2] = "../Assets/Corner_L_D_Black.png";
    assets[1][6][0] = "../Assets/Line_UD.png";
    assets[2][0][0] = "../Assets/Line_UD.png";
    assets[2][1][0] = "../Assets/Line_UD.png";
    assets[2][2][0] = "../Assets/Corner_R_D.png";
    assets[2][2][1] = "../Assets/Corner_R_D_White.png";
    assets[2][2][2] = "../Assets/Corner_R_D_Black.png";
    assets[2][3][0] = "../Assets/Trio_D.png";
    assets[2][3][1] = "../Assets/Trio_D_White.png";
    assets[2][3][2] = "../Assets/Trio_D_Black.png";
    assets[2][4][0] = "../Assets/Corner_L_D.png";
    assets[2][4][1] = "../Assets/Corner_L_D_White.png";
    assets[2][4][2] = "../Assets/Corner_L_D_Black.png";
    assets[2][5][0] = "../Assets/Line_UD.png";
    assets[2][6][0] = "../Assets/Line_UD.png";
    assets[3][0][0] = "../Assets/Trio_L.png";
    assets[3][0][1] = "../Assets/Trio_L_White.png";
    assets[3][0][2] = "../Assets/Trio_L_Black.png";
    assets[3][1][0] = "../Assets/Cross.png";
    assets[3][1][1] = "../Assets/Cross_White.png";
    assets[3][1][2] = "../Assets/Cross_Black.png";
    assets[3][2][0] = "../Assets/Trio_R.png";
    assets[3][2][1] = "../Assets/Trio_R_White.png";
    assets[3][2][2] = "../Assets/Trio_R_Black.png";
    assets[3][3][0] = "../Assets/Mid.png";
    assets[3][4][0] = "../Assets/Trio_L.png";
    assets[3][4][1] = "../Assets/Trio_L_White.png";
    assets[3][4][2] = "../Assets/Trio_L_Black.png";
    assets[3][5][0] = "../Assets/Cross.png";
    assets[3][5][1] = "../Assets/Cross_White.png";
    assets[3][5][2] = "../Assets/Cross_Black.png";
    assets[3][6][0] = "../Assets/Trio_R.png";
    assets[3][6][1] = "../Assets/Trio_R_White.png";
    assets[3][6][2] = "../Assets/Trio_R_Black.png";
    assets[4][0][0] = "../Assets/Line_UD.png";
    assets[4][1][0] = "../Assets/Line_UD.png";
    assets[4][2][0] = "../Assets/Corner_R_U.png";
    assets[4][2][1] = "../Assets/Corner_R_U_White.png";
    assets[4][2][2] = "../Assets/Corner_R_U_Black.png";
    assets[4][3][0] = "../Assets/Trio_U.png";
    assets[4][3][1] = "../Assets/Trio_U_White.png";
    assets[4][3][2] = "../Assets/Trio_U_Black.png";
    assets[4][4][0] = "../Assets/Corner_L_U.png";
    assets[4][4][1] = "../Assets/Corner_L_U_White.png";
    assets[4][4][2] = "../Assets/Corner_L_U_Black.png";
    assets[4][5][0] = "../Assets/Line_UD.png";
    assets[4][6][0] = "../Assets/Line_UD.png";
    assets[5][0][0] = "../Assets/Line_UD.png";
    assets[5][1][0] = "../Assets/Corner_R_U.png";
    assets[5][1][1] = "../Assets/Corner_R_U_White.png";
    assets[5][1][2] = "../Assets/Corner_R_U_Black.png";
    assets[5][2][0] = "../Assets/Line_RL.png";
    assets[5][3][0] = "../Assets/Cross.png";
    assets[5][3][1] = "../Assets/Cross_White.png";
    assets[5][3][2] = "../Assets/Cross_Black.png";
    assets[5][4][0] = "../Assets/Line_RL.png";
    assets[5][5][0] = "../Assets/Corner_L_U.png";
    assets[5][5][1] = "../Assets/Corner_L_U_White.png";
    assets[5][5][2] = "../Assets/Corner_L_U_Black.png";
    assets[5][6][0] = "../Assets/Line_UD.png";
    assets[6][0][0] = "../Assets/Corner_R_U.png";
    assets[6][0][1] = "../Assets/Corner_R_U_White.png";
    assets[6][0][2] = "../Assets/Corner_R_U_Black.png";
    assets[6][1][0] = "../Assets/Line_RL.png";
    assets[6][2][0] = "../Assets/Line_RL.png";
    assets[6][3][0] = "../Assets/Trio_D.png";
    assets[6][3][1] = "../Assets/Trio_D_White.png";
    assets[6][3][2] = "../Assets/Trio_D_Black.png";
    assets[6][4][0] = "../Assets/Line_RL.png";
    assets[6][5][0] = "../Assets/Line_RL.png";
    assets[6][6][0] = "../Assets/Corner_L_U.png";
    assets[6][6][1] = "../Assets/Corner_L_U_White.png";
    assets[6][6][2] = "../Assets/Corner_L_U_Black.png";
}

int main(int argc, char **argv) {
    logger_log(LOGGER_LOG_LEVEL_DEBUG, "App start...");
    char *title= "Mill";
    if(argc > 1){
        pipes = initPipes(argc,argv);
        title = argv[1];
    }
    init_assets();
    init_graph();
    gtk_init(&argc, &argv);
    GtkWidget *label1 = gtk_label_new("Score:");
    GtkWidget *label2 = gtk_label_new("INFO");
    Board board = init_board(label2, label1,pipes,argv[1]);
    update(board);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), title);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(close_app), NULL);
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *box2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    GtkWidget *restart = gtk_button_new_with_label("restart");
    if(pipes==NULL)g_signal_connect(GTK_BUTTON(restart), "clicked", G_CALLBACK(restart_app), board);
    gtk_box_pack_start(GTK_BOX(box2), label1, TRUE, TRUE, 0);
    if(pipes==NULL)gtk_box_pack_start(GTK_BOX(box2), restart, TRUE, TRUE, 0);
    GtkWidget *grid = gtk_grid_new();
    set_grid(grid, board);
    gtk_box_pack_start(GTK_BOX(box), box2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), grid, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), label2, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_show_all(window);
    if(pipes!=NULL)g_timeout_add(100,read_pipe,board);
    gtk_main();
    logger_log(LOGGER_LOG_LEVEL_DEBUG, "App close");
    logger_close();
    closePipes(pipes);
}