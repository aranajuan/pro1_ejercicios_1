#include "persona_adapter.h"

tinfo info_get(){
    return persona_get();
}

void info_show(const tinfo * t, FILE * fp, int bin){
    persona_show(t,fp,bin);
}

int info_compare(const tinfo * i1,const tinfo * i2){
    return persona_compare((tpersona *)i1,(tpersona *)i2);
}
