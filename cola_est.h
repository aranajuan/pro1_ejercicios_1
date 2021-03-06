#ifndef COLA_EST_H_INCLUDED
#define COLA_EST_H_INCLUDED

#include "persona_adapter.h"

#define COLA_SIZE 4

typedef struct{
    tinfo info[COLA_SIZE];
    int fst;
    int lst;
    int cant;
}tcola;

void cola_create(tcola *);

int cola_full(const tcola *);

int cola_add(tcola *,const tinfo *);

int cola_empty(const tcola *);

int cola_get(tcola *, tinfo *);


#endif // COLA_EST_H_INCLUDED
