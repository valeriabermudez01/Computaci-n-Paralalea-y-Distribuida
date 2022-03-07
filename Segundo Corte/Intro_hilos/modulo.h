/*****************************************
 * Fecha 01-03-2022
 * Autor: Valeria Bermúdez
 * Materia: Computación Paralela y Distribuida
 * Tema: Implementación Posix (LIbrary)
 * Interfaz del modulo para miltiplicar dos matrices sin variables globales.
 * Se requiere que el diseño sea modular.
 * El modulo implementará los hilos que harán el cálculo del producto de la matrix
 * ******************************************/
#ifndef MODULO_H_INCLIDED
#define MODULO_H_INCLIDED

/*Prototipos de las funciones a presentar como interfaz del modulo.c */

#include "modulo.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

//Funcion para cada thread calcula un solo elemento sobre la matriz resultado

/*Se pasa como argumento el puntero al vector de datos
* El vector de datos será la porción enviada para el cálculo de elemento sobre la matriz resultado. 
*/
void *multiplicacion(void *arg);

#endif
