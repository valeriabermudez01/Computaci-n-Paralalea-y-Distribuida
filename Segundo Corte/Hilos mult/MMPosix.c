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

/*Se declaran las variables GLOBALES para todo el programa */
int N,Nthreads;
double **Ma, **Mb, **Mc;

int main(int argc, char* argv[]){
	/* Se capturan las variables size y número de hilos */
	N 	 = atof(argv[1]);
	Nthreads = atof(argv[2]);
	
	/* Creación y reserva de Mem para cada Matriz */
	Ma = ReservaMEM(N);
	Mb = ReservaMEM(N);
	Mc = ReservaMEM(N);

	IniciarMatriz(Ma,Mb,Mc,N);
	
	printMatrizH(Ma,N);
	printMatrizH(Mb,N);
	printMatrizH(Mc,N);
	return 0;
}
