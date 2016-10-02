#ifndef PERSONA_ADAPTER_H_INCLUDED
#define PERSONA_ADAPTER_H_INCLUDED

#include "persona.h"

typedef tpersona tinfo;

tinfo info_get();

void info_show(tinfo *, FILE *, int);

int info_compare(const tinfo *,const tinfo *);

#endif // PERSONA_ADAPTER_H_INCLUDED
