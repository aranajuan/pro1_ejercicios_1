#include "lista_test.h"

int run(){
    int i;
    tinfo d;
    FILE * pantalla = stdout;
    printf("------Listas------\n");

    tlista lista;

    lista_create(&lista);

    /**
    * Para cargar de archivo
**/
    FILE * archivo_r = fopen("personas_data","rb");

    fread(&d,sizeof(tinfo),1,archivo_r);
    while(!feof(archivo_r)){
        lista_addEnd(&lista, &d);
        fread(&d,sizeof(tinfo),1,archivo_r);
    }

    /**
    * Para ingresar a manopla
    FILE * archivo = fopen("personas_data","wb");

    for(i = 0 ; i < 3 ; i++){
        d = info_get();
        cola_add(&cola, &d);
    }
**/
    lista_sort(&lista,info_compare);
    while(!lista_empty(&lista)){
        lista_pull(&lista,&d);
        info_show(&d,pantalla,0);
        //info_show(&d,archivo,1); // guardar en archivo
    }

    return 1;

}
