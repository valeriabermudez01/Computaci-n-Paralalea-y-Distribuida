/*
	* Fecha: 06-02-2022
	* Autor: Valeria Berm�dez Galv�n
	* Materia : Computaci�n paralela y distribuida
	* Tema : Punto 6 del Taller Machine Learning en Computaci�n Avanzada
	* Programa que calcula la suma de los m�ltiplos de 5 desde un n�mero 
	  a hasta un n�mero b 
	*/
	
#include <iostream>

using namespace std;

/* Funci�n para sumar los m�ltiplos de 5 entre dos n�meros */

int sumaMultiplos(int a, int b){
	int i =0 ; int suma = 0;
	for(i = a ; i <= b ; i++){
		if(i%5 == 0){
			suma+=i;
		}
	}
	
	return suma;
	
}

/* Se requiere implementar una aplicaci�n que sume los n�meros 
   m�ltiplos de 5 de dos n�meros no negativos */
	
int main(int argc, char **argv){
	cout << "Calculadora de suma de los multiplos de 5 entre dos numeros " << "\n" ;
	int numero1 = 0 , numero2 = 0 , suma = 0;
	
	do{
       cout << "Ingrese el primer numero , recuerde que no puede insertar numeros negativos" << endl;
	   cin >> numero1;
	} while(numero1 < 0);
	
	do{
       cout << "Ingrese el segundo numero , recuerde que no puede insertar numeros negativos" << endl;
	   cin >> numero2;
	} while(numero2 < 0);
	
	
	if (numero1 < numero2){
		suma = sumaMultiplos(numero1, numero2);
		cout << "La suma de los multiplos de 5 entre  "<< numero1 << " y " << numero2 << " es igual a " << suma << endl ;
	}else{
		suma = sumaMultiplos(numero2, numero1);
		cout << "La suma de los multiplos de 5 entre  "<< numero2 << " y " << numero1 << " es igual a " << suma << endl ;
	}
}
