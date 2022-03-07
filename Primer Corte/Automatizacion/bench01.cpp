/*Universidad Sergio Arboleda
*Fecha: 03-02-2022
*Autor: Valeria Bermudez
*Materia: Computación Paralela y Distribuida
*Tema: Construcción del Primer Benchmark
*Benchmark: Aplicación de juguete que permite evaluar rendimiento de un aspecto 
*en específico de la computadora
*/
/*Se declaran las interfaces */
#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <time.h>
#include <chrono>
/* Se requiere implementar una aplicacion que multiplique dos matrices, El algoritmo a usar sera el clasico (Filas por columnas) */
using namespace std;

/*Se crea la función para imprimir matrices*/

void imprimirMatriz(vector<vector<double>> M){
	int i,j;
	for(i=0;i<M.size();++i){
		for(j=0;j<M.size();++j){
			cout << M[i][j] << "\t";	
		}
		cout << "\n";
	}			
}

/*Funcion se genera la aleatoriedad*/

double randomNumer(double fMin, double fMax){
	double f= (double)rand()/RAND_MAX;
	return fMin+f*(fMax-fMin);
}

/*Se crea la función para inicializar las matrices*/
vector<vector<double>> InicializarMatriz(vector<vector<double>> M){
	int i,j;
	float limInf = 0.001, limSup = 9.999;
	vector<vector<double>> Minicializada(M.size(), vector<double> (M.size(),0));
	/*random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(limInf, limSup);*/
	for(i=0;i<M.size();++i){
		for(j=0;j<M.size();++j){
			Minicializada[i][j] = randomNumer(limInf,limSup);	
		}
	}	
	return Minicializada;
}

	/*Funcion multiplicacion amatrices:
	*Se requiere multiplicar las dos matrices: Adicionalmente se debe verificar y validar que 
	*realmente se cumpla el algoritmo de multiplicación
	*/
	
vector<vector<double>> MultiplicarMatrices(vector<vector<double>> Ma, vector<vector<double>> Mb){
	int i,j,k;
	vector<vector<double>> Mresult(Ma.size(), vector<double> (Ma.size(),0));
	/*Hacemos una puna de prieba para tomar tiempo inicial*/
	auto startTime=chrono::high_resolution_clock::now();
	for(i=0;i<Ma.size();++i)
		for(j=0;j<Ma.size();++j)
			for(k=0;k<Ma.size();++k)
			Mresult[i][j]+= Ma[i][k]*Mb[k][j];
	/*Hacemos una puna de prieba para tomar tiempo final*/
	auto endTime=chrono::high_resolution_clock::now();
	chrono::duration<double, milli> tiempoTotal=endTime-startTime;
	cout << "Tiempo: " << tiempoTotal.count() << "ms\n";
	
	return Mresult;
}	
int main(int argc, char** argv) {
	int i,j,k;
	int N = atoi(argv[1]);
	
	/* Se usa la clase vector para crear las matrices */
	
	vector<vector<double>> M1(N, vector<double> (N,0));
	vector<vector<double>> M2(N, vector<double> (N,0));
	vector<vector<double>> MR(N, vector<double> (N,0));
	/*Se inicializan las matrices */
	M1 = InicializarMatriz(M1);
	M2 = InicializarMatriz(M2);
	
	/*Se multiplican las matrices */
	MR = MultiplicarMatrices(M1,M2);
	
		
			
	return 0;
	

}
