/* Fecha : 03-02-2022
   Autor : Valeria Bermúdez Galván
   Materia : Computación Paralela y Distribuida
   Tema : Construcción del Primer Benchmark
   Benchmark : Aplicación de Juguete que permite evaluar rendimiento de un aspecto en específico de la computadora */
   
   
#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include<time.h>
#include <chrono>
#include <unistd.h>
#include <math.h>

using namespace std;

//CONSTANTS
struct timespec inicio, fin;

/* ----------------------------- -------Funciones ------------------------------------*/
/*	@brief: Get the init time*/
void sampleStart(){
	clock_gettime(CLOCK_MONOTONIC, &inicio);	
}

/*	@brief: Get the end time */
void sampleEnd(){
	clock_gettime(CLOCK_MONOTONIC, &fin);	
	double totalTime;
	totalTime = (fin.tv_sec - inicio.tv_sec)*1e9;
	totalTime = (totalTime + (fin.tv_nsec - inicio.tv_nsec))*1e-9;
	cout << "\nTotal time: " << totalTime << " seg";
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


	/*Función que genera un valor aleatorio */
double randomNumber(double fMin, double fMax){
	double f = (double)rand() / RAND_MAX;
	return fMin + f* (fMax -fMin);
}

	/* Función Multiplicación Matrices:
		Se requiere multiplicar las dos matrices : Adicionalmente 
		los ingenieros deben verificar y validar que realmente 
		se cumpla el algoritmo de multiplicación */
vector<vector<double>> MultiMatriz(vector<vector<double>> Ma,
								   vector<vector<double>> Mb){
	int i, j, k;
	vector<vector<double>> MT (Ma.size(), vector<double> (Ma.size(),0));;
	
	for(i = 0; i<Ma.size(); ++i){
		for(j = 0; j<Ma.size(); ++j){
			for(k = 0; k<Ma.size(); ++k){
				MT[i][j] += Ma[i][k]*Mb[k][j];
			}
		}
	}	
}
		




/* Función Inicialización : Se requiere inicializar las matrices
   	con números aleatorios */
vector<vector<double>> InicializacionMatriz(int size){
	int i, j;
	vector<vector<double>> MI(size, vector<double> (size,0)); 
    	
	for (i=0; i<size; ++i){
		for (j=0; j<size; ++j){
			MI[i][j] = randNumber();
		}
	}
	return MI;	
}



/* Se requiere implementar una aplicación que multiplique dos matrices
   Las matrices deben ser de doble precisión
   El algoritnmo a usar será el clásico (filas por columnas) */

int main(int argc, char** argv) {
	int k;
	int N = atoi(argv[1]); 
	
	/* Se usa la clase vector para crear las matrices */
	vector<vector<double>> M1(N,vector<double>(N,0));
	vector<vector<double>> M2(N,vector<double>(N,0));
	vector<vector<double>> MR(N,vector<double>(N,0));
	
	//Matrix init
	M1 = InicializacionMatriz(N);
	M2 = InicializacionMatriz(N);
	
			
	sampleStart();
	MultiMatriz(M1, M2);
	sampleEnd();
	return 0;
	
}
