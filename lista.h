#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "persona_adapter.h"

typedef struct nodo{
    tinfo info;
    struct nodo * sig;
}tnodo, *tlista;


void lista_create(tlista *);

int lista_addEnd(tlista *,const tinfo *);

int lista_addFst(tlista *,const tinfo *);

int lista_delete(tlista *,const tinfo *, int (*) (tinfo *,tinfo *));

int lista_addSorted(tlista *,const tinfo *, int (*)(tinfo *,tinfo *));

void lista_sort(tlista *, int (*)(tinfo *,tinfo *));

int lista_empty(const tlista *);

void lista_clear(tlista *);

int lista_pull(tlista *, tinfo *);

#endif // LISTA_H_INCLUDED
