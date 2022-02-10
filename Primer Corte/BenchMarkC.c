/* Universidad Sergio Arboleda 
	Fecha : 08-02-2022
	Autor : Valeria Bermúdez
	Materia : Parallel Computing
	Tema : Implementación Benchmark en C
*/


#include <stdio.h>
#include <stdlib.h>

/* Se crea una variable con un valor alto 
   para reservar memoria */
#define DATA_SZ (1024*1024*64*3)

/* Se reserva el espacio de memoria según el valor */
static double MEM_CHUNK[DATA_SZ];

/* Se crea la función para inicializar las matrices */
void InitMatrix(int SZ, double *Ma, double *Mb, double *Mr){
	int i,j,k;
    for(i=0;i<SZ;++i){
        for(j=0;j<SZ;++j){
            Ma[j+i*SZ]=3.0*(i-j);
            Mb[j+i*SZ]=2.8*(i+j);
            Mr[j+i*SZ]=0.0;
        }
    }
}

/*Se implementa la impresión (para efectos de validación) */
void printMatrix(int SZ, double *M){
	int i,j,k;
    for(i=0;i<SZ;++i){
        for(j=0;j<SZ;++j){
            printf("%f  ", M[j+i*SZ]);
        }
        printf("\n");
    }
}
/* Se implementa paso a paso benchmark Multiplicación de Matrices
   Algoritmo clásico (filas x columnas)de matrices
   de igual dimensión */

int main(int argc, char *argv[]) {	
	/*Se captura la dimensión de la matriz*/
	int N = (int) atof(argv[1]); /*Captura el argumento*/
    printf("Valor ingresado %d\n",N);
	/*Apuntamos los vectores (creación) al espacio de 
	  memoria reservado con dimensión NxN*/
	double *Ma, *Mb, *Mr;
    Ma=MEM_CHUNK;
    Mb=Ma+N*N;
    Mr=Mb+N*N;
    
    InitMatrix(N,Ma,Mb,Mr);
    printf("\nMatriz A\n");
    printMatrix(N,Ma);
    printf("\nMatriz B\n");    
    printMatrix(N,Mb);
    
   for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            //Se declaran punteros auxiliares
            double *pA, *pB;
            double sumaAuxiliar=0;
            pA=Ma+(i*N);
            pB=Mb+j;        
            for(int k=0;k<N;k++,pA++,pB+=N){
                sumaAuxiliar+=(*pA * *pB);
            }
            Mr[i*N+j]=sumaAuxiliar;
        }
    }
	
    printf("\nMatriz resultante\n");
    printMatrix(N,Mr);
    return 0;
}

