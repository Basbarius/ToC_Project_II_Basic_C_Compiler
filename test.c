#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

int main(int argc, char *argv[]){

    const char* str1 = "a.exe < ";
    char buffer[MAX];
    int i;
    
    for(i = 1; i < argc; i++){
        strcat(strcpy(buffer, str1), argv[i]);

        char *filename = argv[i];
        FILE *fp = fopen(filename, "r");

        if (fp == NULL){
            //Archivo inexistente
            printf("\nCould not open file %s: ", argv[i]);
            perror("");
            printf("\n");
            return 1;
        } else {
            // Comandos para probar los inputs y escribir un .txt con el output
            printf("\nFile: %s\n", argv[i]);
            system(buffer);
        }
    }
    return 0;
}