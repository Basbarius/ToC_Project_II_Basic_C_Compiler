#include "global.h"

char buflex[TAMBUFF];
int numlinea = 1;
int valcomplex = NINGUNO;

int analex(){
    int t,u,v;
    while(1){
        t = getchar();
        if(t == ' ' || t == '\t')
            ;
        else if(t == '\n')
            numlinea += 1;
        else if(isdigit(t)){
            ungetc(t, stdin);
            scanf("%d", &valcomplex);
            return NUM;
        }
        else if(isalpha(t)){
            int p, b = 0;
            int isProp = 0;
            while(isalnum(t)){
                buflex[b] = t;
                t = getchar();
                b += 1;
                if(b >= TAMBUFF)
                    error("Error del compilador");
            }
            while(1){
                if(t == ' ' || t == '\t'){
                    t = getchar();
                    continue;
                }
                if(t == ':')
                    isProp = 1;
                break;
            }
            buflex[b] = FDC;
            if(t != EOF)
                ungetc(t, stdin);
            p = busca(buflex);
            if(p == 0)
                p = inserta(buflex, ID);
            valcomplex = p;
            if(tablasimb[p].complex > 261 && tablasimb[p].complex < 269){
                isProp = 1;
            }
            if(isProp == 1)
                return PROP;
            return tablasimb[p].complex;
        }
        else if(t == EOF)
            return FIN;
        else{
            valcomplex = NINGUNO;
            return t;
        }
    }
}