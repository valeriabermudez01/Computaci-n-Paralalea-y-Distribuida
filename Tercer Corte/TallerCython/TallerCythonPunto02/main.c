/* Universidad Sergio Arboleda 
	Fecha : 21-04-2022
	Autor : Valeria Bermúdez
	Materia : Parallel Computing
	Tema : Taller Cython Punto 2 : Principal
*/

/*Interfaces*/
#include "cfib.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(int argc, char **argv) {
    int arg=-1, numiter=-1, i;
    clock_t t;
    if (argc != 3) {
        printf("Wrong number of arguments,expecting 2 (got %d)\n.", argc-1);
        return 1;
    }
    arg = atoi(argv[1]);
    numiter = atoi(argv[2]);
    t = clock();
    for (i=0; i<numiter; ++i) {
        cfib(arg);
    }
    t = clock() - t;
    printf("%f\n", ((float)t) / 1000000/
    numiter * 1e9);
    return 0;
}
