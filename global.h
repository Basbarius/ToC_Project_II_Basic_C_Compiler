#include <stdio.h>

#include <ctype.h>


#define TAMBUFF 128
#define NINGUNO -1
#define FDC '\0'
#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define FIN 260
#define PROP 261
#define ASI 262
#define IF 263
#define THEN 264
#define WHILE 265
#define DO 266
#define BEGIN 267
#define END 268
#define ASIOP 269
#define NOTEQUAL 270
#define SOE 271
#define GOE 272

int valcomplex;
int numlinea;
struct entrada{
    char *aplex;
    int complex;
};

struct entrada tablasimb[];
