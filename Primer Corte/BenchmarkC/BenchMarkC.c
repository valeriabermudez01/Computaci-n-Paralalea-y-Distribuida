/* Universidad Sergio Arboleda 
	Fecha : 08-02-2022
	Autor : Valeria Berm�dez
	Materia : Parallel Computing
	Tema : Implementaci�n Benchmark en C
*/


/*Interfaces*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>


/*CONSTANTS*/
struct timespec inicio, fin;

/* Se crea una variable con un valor alto 
   para reservar memoria */
#define DATA_SZ (1024*1024*64*3)

/* Se reserva el espacio de memoria seg�n el valor */
static double MEM_CHUNK[DATA_SZ];


/* -------------------------------------Funciones ------------------------------------*/

void sampleStart(){
	clock_gettime(CLOCK_MONOTONIC, &inicio);	
}


void sampleEnd(){
	clock_gettime(CLOCK_MONOTONIC, &fin);	
	double totalTime;
	totalTime = (fin.tv_sec - inicio.tv_sec)*1e9;
	totalTime = (totalTime + (fin.tv_nsec - inicio.tv_nsec))*1e-9;
	printf ("\nTotal time: %f seg \n", totalTime);
}


double randNumber(){
    float min = 0.001, max = 9.999;
    static int first = -1;
    if(first = (first < 0)){
       srand(time(NULL) + getpid());
    }
    if(min >= max){
        return errno = EDOM, NAN;
    }
    return min + (float)rand()/((float)RAND_MAX/(max-min));
}

/* Se crea la funci�n para inicializar las matrices */
void InitMatrix(int SZ, double *Ma, double *Mb, double *Mr){
    int i,j,k;
    for(i=0; i < SZ; ++i){
        for(j=0;j<SZ;++j){
            Ma[j+i*SZ] = randNumber();
            Mb[j+i*SZ] = randNumber();
            Mr[j+i*SZ] = 0.0;
        }
    }
}


/*Se implementa la impresi�n (para efectos de validaci�n) */
void printMatrix(int SZ, double *M){
	int i,j,k;
    for(i=0;i<SZ;++i){
        for(j=0;j<SZ;++j){
            printf("%f  ", M[j+i*SZ]);
        }
        printf("\n");
    }
}

/*	@brief: Multiply matrices
	@param size: Size of matrix
	@param a: Matriz A to multiply
	@param b: Matriz B to multiply
	@param c: Total matrix of multiplication
    ---
*/
void matrixMultiply (int size, double *Ma, double *Mb, double *Mr){
	int i, j, k;
	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j){
		/*Necesita puteros auxiliares*/
		double *pA, *pB;
		double sumaAuxiliar = 0.0;
		pA = Ma + i;
		pB = Mb + j;
			for(k = 0; k < size; ++k, pA += size, pB++){
				sumaAuxiliar += (*pA * *pB);
			}
			Mr[j*size+i] = sumaAuxiliar;
		}
	}
}


/* Se implementa paso a paso benchmark Multiplicaci�n de Matrices
   Algoritmo cl�sico (filas x columnas)de matrices
   de igual dimensi�n */

int main(int argc, char *argv[]) {	
	/*Se captura la dimensi�n de la matriz*/
	int N = (int) atof(argv[1]); /*Captura el argumento*/

	/*Apuntamos los vectores (creaci�n) al espacio de 
	  memoria reservado con dimensi�n NxN*/
	double *Ma, *Mb, *Mr;
    Ma=MEM_CHUNK;
    Mb=Ma+N*N;
    Mr=Mb+N*N;
    
 	InitMatrix(N, Ma, Mb, Mr);
	sampleStart();
	matrixMultiply(N, Ma, Mb, Mr);
	sampleEnd();
	
    return 0;
}

