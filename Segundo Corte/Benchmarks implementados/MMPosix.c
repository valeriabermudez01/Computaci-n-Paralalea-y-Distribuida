/*****************************************
 * Fecha 15-03-2022
 * Autor: Valeria Bermúdez
 * Materia: Computación Paralela y Distribuida
 * Tema: Implementación Posix (LIbrary)
 * Programa para miltiplicar dos matrices con variables globales.
 * Se requiere que el diseño sea modular.
 * El modulo implementará las funciones para 
 *el cálculo del producto de la matrix : 
 *1.- Creacion de variables doble puntero para matrices 
   principal Global.
 *2.- Función Reserva de Memoria para las matrices de doble puntero
 *3.- Función de inicialización de las matrices
 *4.- Función para el producto de matrices:
     Se dividido la matriz A por porciones , a ser enviadas a cada hilo.
  -->El número de hilos será enviada al ejecutar
  -->La dimensión de la matriz será enviada al ejecutar
 *5.- La dimensión de la matriz siempre será cuadrada (NxN)
 *6.- Se necesita función para impresión de matrices(doble puntero).
 *******************************************/
#include "modulo.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>




int main(int argc, char* argv[]){

	if(argc !=3){
		printf("./Exe N<dimMatriz> Nth<numHilos> \n\n");
		return -1;
	}

	/* Se capturan las variables size y número de hilos */
	int N 	 = atof(argv[1]);
	int Nthreads = atof(argv[2]);
	
	/* Se crea el pool de hilos */
	pthread_t *hilosExec;
	/*Se reserva memoria para los hilos*/
	hilosExec = (pthread_t *)malloc(Nthreads *sizeof(pthread_t));
	
	/* Creación y reserva de Mem para cada Matriz */
	double **Ma = ReservaMEM(N);
	double **Mb = ReservaMEM(N);
	double **Mc = ReservaMEM(N);

	IniciarMatriz(Ma,Mb,Mc,N);
	
	  /*Init of pointer type struct to send multiple data to the thread*/
    	struct data *params = (struct data *)malloc(sizeof(struct data));
    
	if(N < 4){
		printf("Matriz A: \n");
		printMatrizH(Ma,N);
		printf("Matriz B: \n");
		printMatrizH(Mb,N);
	}
	
	sampleStart();
	/*Se reparte la tarea a cada hilo ,al usar la función
	* funcion pthread_create(&tinfo[tnum].thread_id,&attr,
				  &thread_start,&tinfo[tnum]); */
	for (int i = 0; i < Nthreads; ++i){
        	int *idThread = (int *)malloc(sizeof(int));
        	*idThread = i;

        	/* Estructura para enviar varias variables a los hilos */
        	/* Asignación de variables a la estructura*/
        	params->size = N;
        	params->nTh  = Nthreads;
        	params->MA   = Ma;
        	params->MB   = Mb;
        	params->MC   = Mc;
        	params->idTh = idThread;

        	pthread_create(&hilosExec[i], NULL, multMM, (void *)params);
    }
    
	/*Espero a que todos los hilos terminen */

	for(int i=0; i <Nthreads; ++i){
		pthread_join(hilosExec[i], NULL);
	}

	sampleEnd();
	free(hilosExec);
		
	if(N < 4){
		printf("Matriz C \n");
		printMatrizH(Mc,N);
	}
	
	
	
	return 0;
}


