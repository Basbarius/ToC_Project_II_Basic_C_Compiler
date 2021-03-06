/*     analizsint.c    */

#include "global.h"
int preanalisis;

/* analiza sintacticamente y tradice la lista de la expresion */
analsint(){
    preanalisis = analex();
    while (preanalisis != FIN){
        if(preanalisis == PROP){
            prop(); parea(';');
        }
        else{
            expr(); parea(';');
        }
    }
}

prop(){
    if(preanalisis == PROP && tablasimb[valcomplex].complex != ID)
        emite(PROP, valcomplex);
    switch(tablasimb[valcomplex].complex){
            case IF:
                parea(PROP); expr(); 
                if(tablasimb[valcomplex].complex == THEN){
                    emite(PROP, valcomplex);
                    parea(PROP);
                    prop();
                }
                else{
                    error ("no hay un then correspondiente");
                }
                break;
            case WHILE:
                parea(PROP); expr(); 
                if(tablasimb[valcomplex].complex == DO){
                    emite(PROP, valcomplex);
                    parea(PROP);
                    prop();
                }
                else{
                    error ("no hay un do correspondiente");
                }
                break;
            case BEGIN:
                parea(PROP); opc_props(); 
                if(tablasimb[valcomplex].complex == END){
                    emite(PROP, valcomplex);
                    parea(PROP);
                }
                else{
                    error ("no hay un end correspondiente");
                }
                break;
            case ID:
                preanalisis = ASI;
                factor();
                parea(':');parea('=');
                expr();
                emite(ASIOP, NINGUNO);
                break;
            default:
                error("Error de sintaxis");
    }

}

opc_props(){
    if(tablasimb[valcomplex].complex == END)
        return;
    else{
        prop_list();
    }
}

prop_list(){
    while(tablasimb[valcomplex].complex != END){
        prop();
        parea(';');
    }
}

expr(){

    int t;
    termino();
    while (1){
        switch(preanalisis){
            case '=': 
                t = preanalisis;
                parea(preanalisis); expr(); emite(t, NINGUNO);
                continue;
            case '<':
                t = preanalisis;
                parea(preanalisis); 
                if(preanalisis == '>'){
                    parea(preanalisis);
                    t = NOTEQUAL;
                }else if(preanalisis == '='){
                    parea (preanalisis);
                    t = SOE;
                }
                expr(); emite(t, NINGUNO);
                continue;
            case '>':
                t = preanalisis;
                parea(preanalisis); 
                if(preanalisis == '='){
                    parea (preanalisis);
                    t = GOE;
                }
                expr(); emite(t, NINGUNO);
                continue;
            case '+': case '-': 
                t = preanalisis;
                parea(preanalisis); 
                termino();
                emite(t, NINGUNO);
                continue;
            default:
                return;
        }
    }
}

termino(){
    int t;
    factor();
    while (1){
        switch (preanalisis){
            case '*': case '/': case DIV: case MOD:
                t = preanalisis;
                parea(preanalisis); factor(); emite(t, NINGUNO);
                continue;
            default:
                return;
        }
    }
}

factor(){
    switch (preanalisis){
        case '(':
            parea('('); expr(); parea(')'); break;
        case NUM:
            emite(NUM, valcomplex); parea(NUM); break;
        case ID:
            emite(ID, valcomplex); parea(ID); break;
        case ASI:
            emite(ASI, valcomplex); parea(ASI); break;
        default:
            printf("error aqui %d", preanalisis);
            error("error de sintaxis");   
    }
}

parea (t)
   int t;
{
   if (preanalisis == t){
      preanalisis = analex();
   }
   else{
      error("error de sintaxis");
   }
}