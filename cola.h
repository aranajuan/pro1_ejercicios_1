#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "persona_adapter.h"

typedef struct nodo{
	tinfo info;
	struct nodo * sig;
}tnodo;

typedef struct{
    tnodo * fst;
    tnodo * lst;
}tcola;

void cola_create(tcola *);

int cola_full(const tcola *);

int cola_add(tcola *,const tinfo *);

int cola_empty(const tcola *);

int cola_get(tcola *,tinfo *);

#endif
