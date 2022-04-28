/* Universidad Sergio Arboleda 
	Fecha : 21-04-2022
	Autor : Valeria Bermúdez
	Materia : Parallel Computing
	Tema : Taller Cython Punto 2 : Función de Fibonacci
*/

/*Interfaces*/
#include "cfib.h"

double cfib(int n) {
     int i;
     double a=0.0, b=1.0, tmp;
     for (i=0; i<n; ++i) {
         tmp = a; a = a + b; b = tmp;
     }
     return a;
}
