/*
	* Fecha: 06-02-2022
	* Autor: Valeria Bermúdez Galván
	* Materia : Computación paralela y distribuida
	* Tema : Punto 9 del Taller Machine Learning en Computación Avanzada
	* Programa que genera la secuencia de digitos según la indica el 
	  usuario
	*/
#include <iostream>

using namespace std;

/* Funcion para imprimir triangulo*/
void ImprimirTriangulo(int numfilas){
	int i, j , espacios;
	
	espacios = numfilas-1; 
	
    for(i=1;i<=numfilas;i++){
    	
        for(int j=0;j<espacios;j++){
            cout<<" ";
        }
        for (int k=i; k<=(i*2)-1;k++){
        	cout << k%10;	
		}
		for (int z=(i*2)-1;z>i;z--){
			cout << (z-1)%10;
		}
		cout <<endl;
		espacios--;
    }
}
/* Se requiere implementar una aplicación que genere la secuencia
	de digitos mostrada
	  1
	 232
	34543...   */
	
int main(int argc, char **argv){
	int numfilas;
    do{
      cout<<"Ingrese el número de filas de la piramide , recuerde que debe estar entre 11 y 20"<<endl;
	   cin >> numfilas;
	} while(numfilas < 11 || numfilas > 20);
	
	ImprimirTriangulo(numfilas);
	return 0;
}
