/*****************************************
 * Fecha 01-03-2022
 * Autor: Valeria Bermúdez
 * Materia: Computación Paralela y Distribuida
 * Tema: Implementación Posix (LIbrary)
 * Modulo del principal para miltiplicar dos matrices sin variables globales.
 * Se requiere que el diseño sea modular.
 * El modulo implementará los hilos que harán el cálculo del producto de la matrix
 * ******************************************/

#include "modulo.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

//Funcion para cada thread calcula un solo elemento sobre la matriz resultado

/*Se pasa como argumento el puntero al vector de datos
* El vector de datos será la porción enviada para el cálculo de elemento sobre la matriz resultado. 
*/
void *multiplicacion(void *arg){
    //La variable "datos" del tipo entero, apunta al vector argumentos
    int *datos=(int *)arg; 
    int i=0,k=0;
    // variable que contena el primer valor del v
    int x = datos[0];
    for (i=1; i<=x;i++){
        k+=datos[i]*datos[i+x];
    }
    int *p= (int *)malloc(sizeof(int));
    *p = k;
    //Se usa para terminar el hilo u retornar el valor pasado como puntero
    pthread_exit(p);
}
