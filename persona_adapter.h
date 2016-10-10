#ifndef PERSONA_ADAPTER_H_INCLUDED
#define PERSONA_ADAPTER_H_INCLUDED

#include "persona.h"

typedef tpersona tinfo;

tinfo info_get();

void info_show(const tinfo *, FILE *, int);

int info_compare(const tinfo *,const tinfo *);

void info_load_txt(const char *, tinfo *);

#endif // PERSONA_ADAPTER_H_INCLUDED
