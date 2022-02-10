/*
	* Fecha: 06-02-2022
	* Autor: Valeria Bermúdez Galván
	* Materia : Computación paralela y distribuida
	* Tema : Punto 10 del Taller Machine Learning en Computación Avanzada
	* Programa que calcula los centros numéricos entre 1 y n
	*/
#include <iostream>

using namespace std;

/* Funcion  para hallar los centros numéricos*/

void buscarCentros(int n){
	
	/* declaracion variables para  suma numeros anteriores 
	* al centro y posteriores al centro.*/
	int  sumaAntes=0, sumaDespues=-1,centro;
	
	centro = 1;
	do{
		for (int i=1;i<centro;i++){
			sumaAntes+=i;
		}
		for (int j=centro+1 ;j<=centro*2;j++){
			if(sumaAntes==sumaDespues){
				cout <<"El numero "<< centro << " es centro numerico" << endl;
				break;
			}else{
				sumaDespues+=j;
			}
		}
		centro++;
		sumaAntes=0;
		sumaDespues=0;
	}while (centro<=n);
}

/* Se requiere implementar un programa que calcule los centros
	numericos entre 1 y n */
	
int main(int argc, char **argv){
	int n;
	
	do{
      cout << "Ingrese un numero 'n' mayor que 1" << endl;
	   cin >> n;
	} while(n < 1);
	buscarCentros(n);
	
}
