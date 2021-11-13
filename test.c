#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

int main(int argc, char *argv[]){

    const char* str1 = "a.exe < ";
    char buffer[MAX];
    int i;
    char c;
    FILE *filename;
    
    for(i = 1; i < argc; i++){
        strcat(strcpy(buffer, str1), argv[i]);

        // FILE *filename = argv[i];
        // FILE *fp = fopen(filename, "r");
        
        filename = fopen (argv[i], "rb");

        if (!filename){
            //Archivo inexistente
            printf("\nCould not open file %s: ", argv[i]);
            perror("");
            printf("\n");
            fclose (filename);
            return 1;
        } else {
            printf("\nFile: %s\n", argv[i]);
            // Imprimir lo que contiene el fichero
            while (!feof (filename)) {
                c = getc (filename);
                printf ("%c", c);
            }
            printf("\n\n");
            // Comandos para probar los inputs
            system(buffer);
        }
    }
    fclose (filename);
    return 0;
}