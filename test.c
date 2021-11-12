#include <stdlib.h>
#include <stdio.h>

int main(){
    char *filename = "test.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL){
        //Archivo inexistente
        perror("Could not open file");
        return 1;
    } else {
        // Comandos para probar los inputs y escribir un .txt con el output
        system("a.exe < test.txt");
        system("a.exe < test.txt > results.txt");
    }
    
    return 0;
}