#include<stdio.h>
#include "persona_adapter.h"
#include "cola.h"

int run(){
    int i;
    tinfo d;
    FILE * fp = fopen("test.txt","wb");
    printf("------Colas------\n");

    tcola cola;
    cola_create(&cola);

    for(i = 0 ; i < 2 ; i++){
        d = info_get();
        cola_add(&cola, &d);
    }

    while(!cola_empty(&cola)){
        d = cola_get(&cola);
        info_show(&d,fp,1);
    }
    return 1;

}
