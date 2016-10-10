#include "lista.h"

void lista_create(tlista * l){
    *l = NULL;
}

int lista_addEnd(tlista * l,const tinfo * d){
    tnodo * nd = (tnodo *)malloc(sizeof(tnodo));
    if(!nd){
        return 0;
    }
    nd->info = *d;
    nd->sig = NULL;

    while(*l){
        l =  &(*l)->sig;
    }

    *l = nd;

    return 1;
}

int lista_addFst(tlista * l,const tinfo * d){
    tnodo * n = (tnodo *)malloc(sizeof(tnodo));
    n->info=*d;
    n->sig=*l;
    *l = n;
}

int lista_delete(tlista * l,const tinfo * d, int (*cmp)(tinfo *,tinfo *)){
    while(*l){
        if(!cmp(d,&(*l)->info)){
            printf("found");
            return 1;
        }
        l = &(*l)->sig;
    }
    return 0;
}

int lista_addSorted(tlista * l,const tinfo * d, int (*cmp)(tinfo *,tinfo *)){

    tnodo * n = (tnodo *)malloc(sizeof(tnodo));
    if(!n){
        return 0;
    }
    n->info = *d;

    while(*l && cmp(d,&(*l)->info)>=0){
        l = &(*l)->sig;
    }

    n->sig = *l;
    *l = n;

    return 1;
}

void lista_sort(tlista * l, int (*cmp)(tinfo *,tinfo *)){
    tlista * p = l;
    tnodo * aux;

    int marca = 1;

    while(marca){
        marca = 0;
        l = p;
        while(*l && (*l)->sig){
            if(cmp(&(*l)->info, &(*l)->sig->info)>0 ){
                marca = 1;
                /* swap */
                aux = *l;
                *l = (*l)->sig;
                aux->sig = (*l)->sig;
                (*l)->sig = aux;
            }
            l = &(*l)->sig;
        }
    }
}

int lista_empty(const tlista * l){
    return (*l)==NULL;
}

void lista_clear(tlista * l){
    tnodo * aux;
    tlista * p = l;
    while(*l){
        aux = *l;
        l = &(*l)->sig;
        free(aux);
    }
    *p = NULL;
}

int lista_pull(tlista * l, tinfo * d){
    if(!(*l)){
        return 0;
    }
    tnodo * eliminar = *l;
    *d = (*l)->info;
    *l = eliminar->sig;
    free(eliminar);
    return 1;
}
