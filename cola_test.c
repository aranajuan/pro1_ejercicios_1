#include "cola_test.h"

int run(){
    int i;
    tinfo d;
    FILE * pantalla = stdout;
    printf("------Colas------\n");

    tcola cola;

    cola_create(&cola);

    /**
    * Para cargar de archivo
    **/
    FILE * archivo_r = fopen("personas_data","rb");
    fread(&d,sizeof(tinfo),1,archivo_r);
    while(!feof(archivo_r)){
        cola_add(&cola, &d);
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

    while(!cola_empty(&cola)){
        d = cola_get(&cola);
        info_show(&d,pantalla,0);
        //info_show(&d,archivo,1); // guardar en archivo
    }

    return 1;

}
