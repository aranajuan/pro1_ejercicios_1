#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"

typedef struct{
	char nombre[50];
	int dni;
	int legajo;
	int edad;
} tpersona;


tpersona persona_get();

void persona_show(const tpersona *,FILE *, int);

int persona_compare(const tpersona *,const tpersona *);

#endif
