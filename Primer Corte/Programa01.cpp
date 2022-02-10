/* Fecha : 01-02-2022 
 * Autor : Valeria Bermúdez Galván
 * Materia : Computación Paralela y Distribuida 
 * Tema : Mini Benchmark (Aplicación de juguete para medir rendimiento)
 */

/* Se delcaran las interfaces */
#include <iostream>

/*Se define una constante */
#define size 32768

/*Se declara el espacio de dominio */
using namespace std;

/* Loop para determinar el tiempo de acceso de datos */
int main() {
	int matrix[size][size];
	for(int i = 0; i<size; i++) {
		for(int j = 0; j<size; j++) {
			matrix[i][j] = 47;
		}
	}
	return 0;
}
