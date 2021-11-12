# ToC_Project_II_Basic_C_Compiler
Second project of Theory of Computation course. A basic C compiler

Primero se realiza la compilacion con el siguiente comando:
gcc analizlex.c analizint.c emisor.c simbolos.c inic.c error.c  principal.c

Una vez que nos genero el "a.exe" se realiza la compilacion de "test.c" con el siguiente comando:
gcc test.c -o test

Esto nos genera un "test.exe". 
Finalmente se utilza el comando ".\test.exe test.txt test2.txt ... testn.txt" con todos los archivos que se desee hacer la prueba.

Por ejemplo:
.\test.exe test.txt test2.txt test3.txt
El primero archivo contiene un input correcto
El segundo archivo contiene un input incorrecto
El tercer archivo no existe

