#include "persona.h"

tpersona persona_get(){
	tpersona p;
	printf("+Nueva persona:\n");
	printf("___ Nombre:");
	gets(p.nombre);
	printf("___ DNI   :");
	scanf("%d",&p.dni);
	printf("___ Legajo:");
	scanf("%d",&p.legajo);
	printf("___ Edad  :");
	scanf("%d",&p.edad);
	FLUSH()
	return p;
}


void persona_show(const tpersona * p ,FILE * fp, int bin){
    if(!bin)
        fprintf(fp,"%-20s %.8d %.6d %-3d\n",p->nombre,p->dni,p->legajo,p->edad);
    else
        fwrite(p,sizeof(tpersona),1,fp);
}

int persona_compare(const tpersona * p1,const tpersona * p2){
    return p1->dni > p2->dni;
}
