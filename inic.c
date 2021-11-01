/*****    inc.c    **************/

#include "global.h"

struct entrada.palsclave[] = {
     "div", DIV,
     "mod", MOD,
    0,      0
 };
inic()        /* carga las palabras clave en la tabla de símbolos */
{
     struct entrada *p;
     for (p = palscave; p ->complex; p++)
          inserta(p->aplex, p->complex);
}
