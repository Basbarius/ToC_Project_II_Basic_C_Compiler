/*     analizsint.c    */

#include "global.h"
int preanalisis;

/* analiza sintacticamente y tradice la lista de la expresion */
analsint(){
    preanalisis = analex();
    while (preanalisis != FIN){
        expr(); parea(';');
    }
}

expr(){

    int t;
    termino();
    while (1)
        switch(preanalisis){
            case '+': case '-':
                t = preanalisis;
                parea(preanalisis); termino(); emite(t, NINGUNO);
                continue;
            default:
                return;
        }
}

termino(){
    int t;
    factor();
    while (1)
        switch (preanalisis){
            case '*': case '/': case DIV: case MOD:
                t = preanalisis;
                parea(preanalisis); factor(); emite(t, NINGUNO);
                continue;
            default:
                return;
        }
}

factor(){
    switch (preanalisis){
        case '(':
            parea('('); expr(); pare(')'); break;
        case NUM:
            emite(NUM, valcomplex); parea(NUM); break;
        case ID:
            emite(ID, valcomplex); parea(ID); break;
        default:
            error("error de sintaxis");   
}

parea(t){
    int t;
    if (preanalisis == t){
        preanalisis = analex();
    } else error ("error de sintaxix");
}