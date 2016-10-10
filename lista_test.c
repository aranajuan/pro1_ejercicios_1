#include "lista_test.h"

int run(){
    int i;
    tinfo d;
    char liner[42];
    FILE * pantalla = stdout;
    printf("------Listas------\n");

    tlista lista;

    lista_create(&lista);

    /**
    * Para cargar de archivo
**/
    FILE * archivo_r = fopen("personas_data_text","r");


    while(fgets(liner,42,archivo_r)){
        info_load_txt(liner,&d);
        lista_addEnd(&lista, &d);
    }

    /**
    * Para ingresar a manopla*
    FILE * archivo = fopen("personas_data_text","w");

    for(i = 0 ; i < 3 ; i++){
        d = info_get();
        lista_addEnd(&lista, &d);
    }
*/

    lista_sort(&lista,info_compare);
    while(!lista_empty(&lista)){
        lista_pull(&lista,&d);
        info_show(&d,pantalla,0);
        //info_show(&d,archivo,1); // guardar en archivo
    }

    return 1;

}
