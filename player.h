//
// Created by rufus on 26.01.18.
//

#ifndef MILL_PLAYER_H
#define MILL_PLAYER_H


typedef struct player{
    int pawns;
    int in_stash;
    char *name;
} *Player;

Player init_player(char *name);
void player_reset(Player p);
#endif //MILL_PLAYER_H
