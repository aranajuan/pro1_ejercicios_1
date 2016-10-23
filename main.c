#include<stdio.h>
#include "lista_test.h";
#include "persona_adapter.h"
int main(){
    printf("------Iniciando------\n");
    //run();

    /* TXT TO BIN */
    FILE * txt = fopen("personas_data_text","r");
    FILE * bin = fopen("personas_data","wb");
    char tmp[200];
    tinfo d;

    if(!txt || !bin){ return 1; }

    while(fgets(tmp,42,txt)){
        info_load_txt(tmp,&d);
        info_show(&d,bin,1);
        info_show(&d,stdout,0);
    }

    printf("--------FIN----------\n");
}
