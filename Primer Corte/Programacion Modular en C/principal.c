/* Universidad Sergio Arboleda
 * Autor:Valeria Bermudez
 * Fecha:10-02-2022
 * Materia:Parallel Computing
 * Tema:Programacion modular en C
 * Fichero:Principal*/

/* Se presenta la cabecera del Mòdulo */
#include "funciones.h"
#include <stdio.h>

int main(){
	int a = 10 , b = 2, resultado;
	printf("Programa principal\n");
	printf("Llamada a la funciòn\n");
	resultado = Sumar(a, b);
	printf("Resultado de la funciòn: %d \n", resultado);

	return 0;
}
