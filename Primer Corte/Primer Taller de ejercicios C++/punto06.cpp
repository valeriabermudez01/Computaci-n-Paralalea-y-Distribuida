/*
	* Fecha: 06-02-2022
	* Autor: Valeria Bermúdez Galván
	* Materia : Computación paralela y distribuida
	* Tema : Punto 6 del Taller Machine Learning en Computación Avanzada
	* Programa que calcula la suma de los múltiplos de 5 desde un número 
	  a hasta un número b 
	*/
	
#include <iostream>

using namespace std;

/* Función para sumar los múltiplos de 5 entre dos números */

int sumaMultiplos(int a, int b){
	int i =0 ; int suma = 0;
	for(i = a ; i <= b ; i++){
		if(i%5 == 0){
			suma+=i;
		}
	}
	
	return suma;
	
}

/* Se requiere implementar una aplicación que sume los números 
   múltiplos de 5 de dos números no negativos */
	
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
