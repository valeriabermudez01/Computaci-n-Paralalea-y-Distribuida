/*
	* Fecha: 06-02-2022
	* Autor: Valeria Berm�dez Galv�n
	* Materia : Computaci�n paralela y distribuida
	* Tema : Punto 8 del Taller Machine Learning en Computaci�n Avanzada
	* Programa que calcula el n�mero del Tarot a partir de la fecha de 
	  nacimiento
	*/
	
#include <iostream>

using namespace std;

/* Funci�n para sumar la fecha  */

int sumaFecha(int x , int y , int z){
	int suma = 0;
	suma = x + y + z;
	return suma;	
}

/* Funci�n para realizar el c�lculo del Tarot  */

int calculoTarot(int suma, int x){
	int num = 0;
	if (x == 1){
		while(suma / 10 > 0 ){
			num += suma%10;
			if(suma % 10 == 0 ){
				num += suma / 10;
			}	
			suma /= 10 ;
		}	
	}
	else{
		num += suma / 10;
		num += suma % 10;
	} 
	return num;
}


/* Se requiere implementar una aplicaci�n que averigue el
	numero del Tarot  */
	
int main(int argc, char **argv){
	int dia , mes , anio ,suma, tarot;
	cout << "Calculadora de su n�mero del Tarot " << "\n" ;
	
	do{
       cout << "Ingrese su fecha de nacimiento separada por espacios , por ejemplo 10 09 2001" << endl;
	   cin >> dia >> mes >> anio;
	} while(dia <= 0 || dia > 31 || mes <= 0 || mes > 12 || anio < 1900 || anio > 2022 );
	
	suma = sumaFecha(dia, mes , anio);
	
	tarot = calculoTarot(suma , 1);
	if(tarot > 9){
		 tarot = calculoTarot(tarot,0);
	}
	printf("Su numero del Tarot es %d ", tarot); 	
	}
