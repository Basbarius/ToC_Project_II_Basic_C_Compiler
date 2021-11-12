# ToC_Project_II_Basic_C_Compiler
Second project of Theory of Computation course. A basic C compiler

Primero se realiza la compilacion con el siguiente comando:
gcc analizlex.c analizint.c emisor.c simbolos.c inic.c error.c  principal.c

Una vez que nos genero el "a.exe" se realiza la compilacion de "test.c" con el siguiente comando:
gcc test.c -o test.exe

Esto nos genera un "test.exe". 
Finalmente se utilza el comando "test.exe" para observar el output en la consola.
