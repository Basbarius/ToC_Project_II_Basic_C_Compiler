/*     emisor.c    */

#include "global.h"


/* genera la salida*/
emite(t, tval)
    int t, tval;
{


    switch (t){
    case '+': case '-': case '*': case '/': case '=': case '<': case '>':
        printf("%c\n", t); break;
    case DIV:
        printf("DIV\n"); break;
    case MOD:
        printf("MOD\n"); break;
    case NOTEQUAL:
        printf("<>\n"); break;
    case SOE:
        printf("<=\n"); break;
    case GOE:
        printf(">=\n"); break;
    case NUM:
        printf("insert %d\n", tval); break;
    case ID: 
        printf("valueOf %s\n", tablasimb[tval].aplex); break;
    case ASI: 
        printf("addressOf %s\n", tablasimb[tval].aplex); break;
    case PROP:
        printf("%s\n", tablasimb[tval].aplex); break;
    case ASIOP:
        printf(":=\n"); break;
    default:
        printf("complex %d, valcomplex %d\n", t, tval); break;
    }
}