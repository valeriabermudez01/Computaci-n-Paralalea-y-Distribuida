/* Universidad Sergio Arboleda 
	Fecha : 08-02-2022
	Autor : Valeria Bermúdez
	Materia : Parallel Computing
	Tema : Implementación Benchmark en C
*/

/*Interfaces*/

#include "modulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>


/*CONSTANTS*/
struct timespec inicio, fin;

/* -------------------------------------Funciones ------------------------------------*/
/*Se obtiene el tiempo inicial */
void sampleStart(){
	clock_gettime(CLOCK_MONOTONIC, &inicio);	
}

/*Se obtiene el tiempo final */
void sampleEnd(){
	clock_gettime(CLOCK_MONOTONIC, &fin);	
	double totalTime;
	totalTime = (fin.tv_sec - inicio.tv_sec)*1e9;
	totalTime = (totalTime + (fin.tv_nsec - inicio.tv_nsec))*1e-9;
	printf ("\nTotal time: %f seg \n", totalTime);
}

/**
 * Función que genera un número aleatorio 
 * Retorna un número aleatorio entre 0.001 y 9.999 
*/
double randNumber(){
    float min = 0.001, max = 9.999;
    static int first = -1;
    if(first == (first < 0)){
       srand(time(NULL) + getpid());
    }
    if(min >= max){
        return errno = EDOM, NAN;
    }
    return min + (float)rand()/((float)RAND_MAX/(max-min));
}

/* Se crea la función para inicializar las matrices */
void InitMatrix(int SZ, double *Ma, double *Mb, double *Mr){
    int i,j;
    for(i=0; i < SZ; ++i){
        for(j=0;j<SZ;++j){
            Ma[j+i*SZ] = 3.9*(i-j);
            Mb[j+i*SZ] = 2.0*(j+i);
            Mr[j+i*SZ] = 0.0;
        }
    }
}

/* Se crea la función para inicializar las matrices */
void initMatrix(int SZ, double *Ma, double *Mb, double *Mr){
	int i, j;
	for(i=0; i<SZ; ++i){
		for(j=0;j<SZ;++j){
			Ma[j+i*SZ] = 3.0*(i-j);
			Mb[j+i*SZ] = 2.8*(j+i);
			Mr[j+i*SZ] = 0.0;
		}
	}
		
}

/*Se implementa la impresión (para efectos de validación) */
void printMatrix(int SZ, double *M){
	int i,j;
	for (i=0;i<SZ; ++i){
		for (j=0;j<SZ; ++j){
			printf("  %f  ",M[j+i*SZ]);
		}
		printf("\n");
	}
		printf("----------------------------");
		printf("\n");
		
		
}

/*	Multiplicación de matrices usando filas por columnas
	@param size: Tamaño de la matriz
	@param a: Matriz A para multiplicar
	@param b: Matriz B para multiplicar
	@param c: Matriz R resultado de la multiplicación
    ---
*/
void matrixMultiplyMM1c(int size, double *Ma, double *Mb, double *Mr){
	int i, j;
	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j){
		/*Necesita punteros auxiliares*/
		double *pA, *pB;
		double sumaAuxiliar = 0.0;
		pA = Ma + (i*size);
		pB = Mb + j;
			for(int k = 0; k < size; ++k, pA ++, pB+=size){
				sumaAuxiliar += (*pA * *pB);
			}
			Mr[i*size+j] = sumaAuxiliar;
		}
	}
}

/*	Multiplicación de matrices usando filas por filas
	@param size: Tamaño de la matriz
	@param a: Matriz A para multiplicar
	@param b: Matriz B para multiplicar
	@param c: Matriz R resultado de la multiplicación
    ---
*/
void matrixMultiplyMM1f(int size, double *Ma, double *Mb, double *Mr){
  int i, j;
	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j){
		/*Necesita punteros auxiliares*/
		double *pA, *pB;
		double sumaAuxiliar = 0.0;
		pA = Ma + (i*size);
		pB = Mb + (j*size);
			for(int k = 0; k < size; ++k, pA++, pB++){
				sumaAuxiliar += (*pA * *pB);
			}
			Mr[i*size+j] = sumaAuxiliar;
		}
	}
}

/*	Se implementa paso a paso benchmark Multiplicacion de matrices
	Algoritmo clasico (filas x columnas) de matrices
	de igual dimensión
*/

/****************** Función para posix (program using threads)**************************/

/*Función Reserva de Memoria para las matrices de doble puntero */
double ** ReservaMEM(int size){
	/* Reserva de memoria de dimension NxN de tipo double*/
	double *val = (double *) malloc(size*size*sizeof(double));

	/* Vector doble puntero reserva la dimension NxN*/
	double ** ptr = (double **) malloc(size*size*sizeof(double *));
	/*Iteración con el fin de que cada puntero se posicione en la reserva de memoria*/
	for (int i = 0; i < size; ++i)	{
		ptr[i] = &val[i*size];
	}
	return ptr;
}

/*	Función de inicialización de las matrices*/
void IniciarMatriz(double **Ma, double **Mb, double **Mc, int size){
	int i, j; /*Indices*/
	for (i = 0; i < size; ++i){
		for (j = 0; j < size; ++j){
			Ma[i][j] = 3.9*(i-j);
    			Mb[i][j] = 2.0*(j+i);
    			Mc[i][j] = 0.0;
		}
	}
}

/*Función para el producto de matrices*/
void printMatrizH(double **M, int size){
	int i, j; /*Indices*/
	for (i = 0; i < size; ++i)	{
		for (j = 0; j < size; ++j)	{
			printf("	%lf", M[i][j]);
		}
		printf("\n");
	}
	printf("----------------------------------------------\n");

}



/**
 * Estructura para enviar varias variables a los hilos 
 * size: Tamaño de la matriz
 * nTh: Número de hilos
 * idTh: ID del hilo 
 * MA: Matrix A
 * MB: Matrix B
 * MC: Matrix C (result of multiplication)
*/


/*Función a ser enviada a cada hilo , que realiza la
 * La multiplicación de matrices .La matriz A, se divide por
 * porciones , en función de la dimensión y del numero de hilos
 * que requiere el usuario.
 * Nota : La función será del tipo void , la cual retornará un 
 * warning potencial de riesgo.Por eso se retorna NULL*/
 
void *multMM(void *arg){
	/*arg : tiene el ID de hilo */
	int N 		=  ((struct data*)arg)->size;
	int Nthreads=  ((struct data*)arg)->nTh; 
	double **Ma =  ((struct data*)arg)->MA;
	double **Mb	=  ((struct data*)arg)->MB;
	double **Mc	=  ((struct data*)arg)->MC;
	int idTh	= *((struct data*)arg)->idTh; 	//Void pointer to integer 
	
	int i, j, k;
	int porcionSize, iniFila, finFila;
	double suma;
	/*Se determina la porcion a ser enviada a cada hilo */
	porcionSize = N /Nthreads;
	/*Se pasa el inicio de fila, según el Id del hilo */
	iniFila = idTh * porcionSize;
	/*Se pasa el fin de fila, según el Id del hilo */
	finFila =(idTh+1)* porcionSize;
	
	for(i = iniFila; i < finFila; ++i){
		for(j = 0; j < N; ++j){
			suma = 0.0;
			for(k = 0; k < N; ++k){
				suma += Ma[i][k] * Mb[k][j];
			}
			Mc[i][j] = suma;
		}
	}
	
	return NULL;
}
