#include "cola_est.h"


void cola_create(tcola * c){
    c->fst = 0;
    c->lst = -1;
    c->cant=0;
}

int cola_full(const tcola * c){
    return c->cant == COLA_SIZE;
}

int cola_add(tcola * c,const tinfo * d){
    if ( c->cant == COLA_SIZE){
        return 0;
    }
    c->cant++;
    c->lst++;
    if(c->lst == COLA_SIZE){
        c->lst = 0;
    }
    c->info[c->lst]=*d;
}

int cola_empty(const tcola * c){
    return c->cant == 0;
}

tinfo cola_get(tcola * c){
    if(c->cant == 0)
        return;
    c->cant--;

    tinfo i = c->info[c->fst];

    c->fst++;
    if(c->fst == COLA_SIZE){
        c->fst = 0;
    }

    return i;
}
