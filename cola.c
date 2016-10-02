#include "cola.h"

void cola_create(tcola * c){
	c->fst = NULL;
	c->lst = NULL;
}

int cola_full(const tcola * c){
    tnodo * n = (tnodo *)malloc(sizeof(tnodo));
    if(n){
        free(n);
        return 0;
    }
    return 1;
}

int cola_add(tcola * c,const tinfo * d ){
    tnodo * n = (tnodo *)malloc(sizeof(tnodo));
    if(!n){
        return 0;
    }
    n->info = *d;
    n->sig = NULL;

    if(!c->fst){
        c->fst = n;
        c->lst = n;
        return 1;
    }

    c->lst->sig = n;
    c->lst = n;

    return 1;
}

int cola_empty(const tcola * c){
    return c->fst == NULL;
}

tinfo cola_get(tcola * c){
    if(!c->fst)
        return;

    tnodo * i = c->fst;
    tinfo d = i->info;

    c->fst = c->fst->sig;
    free(i);

    return d;
}
