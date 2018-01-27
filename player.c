//
// Created by rufus on 26.01.18.
//

#include <stdlib.h>
#include "player.h"

Player init_player(char *name){
    Player p = malloc(sizeof(struct player));
    p->name=name;
    p->pawns=9;
    p->in_stash=p->pawns;
    return p;
}