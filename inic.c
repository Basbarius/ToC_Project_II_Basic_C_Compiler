/*****    inc.c    **************/

#include "global.h"

struct entrada palsclave[] = {
     "if" , IF,
     "then" , THEN,
     "while" , WHILE,
     "do" , DO,
     "begin" , BEGIN,
     "end" , END,
     ":=" , ASI,
     "div", DIV,
     "mod", MOD,
    0,      0
 };
inic()        /* carga las palabras clave en la tabla de símbolos */
{
     struct entrada *p;
     for (p = palsclave; p ->complex; p++)
          inserta(p->aplex, p->complex);
}
