/*****     error.c      ********************/

#include "global.h"

error(m)      /* genera todos los mensajes de error */
      char *m;
{
      fprintf(stderr, "linea %d: %s\n", numlinea, m);
      exit(1);    /* terminación sin éxito */ 
}
