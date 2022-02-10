/*
	* Fecha: 06-02-2022
	* Autor: Valeria Bermúdez Galván
	* Materia : Computación paralela y distribuida
	* Tema : Punto 11 del Taller Machine Learning en Computación Avanzada
	* Programa que calcula el importe segun tipo de vehículo, kilometros 
	 toneladas etc..
	*/
	
#include <iostream>

using namespace std;
// funcion para calcular importe bici
double ImporteBici(){
	double importe =100; 
	return importe;
}
//funcion para calcular importe de carro o moto
double ImporteMotoCarro(){
	double kilometros;
	cout << "Ingrese los kilometros: ";
	cin >> kilometros;
	return kilometros*30;
}
// funcion para calcular importe de un camión
double ImporteCamion(){
	double kilometros, toneladas;
	cout << "\nIngrese los kilometros y toneladas (separe con espacio ambas cifras): ";
	cin >> kilometros >> toneladas;
	return (30*kilometros )+ (25*toneladas);
}
/* Se requiere implementar un programa que calcule el importe segun tipo de vehículo, 
	kilometros  toneladas etc..*/
int main(int argc, char **argv){
	double toneladas, kilometros, importe;
	int op; // opcion
	
	//menu 
	cout << "\t1- Biclicleta" << endl;
	cout << "\t2- Moto" << endl;
	cout << "\t3- Coche" << endl;
	cout << "\t4- Camion" << endl;
	cout << "\t5- Salir" << endl;
	cout << "Seleccione la opcion deseada: ";
	cin >> op;
	
	switch (op){
		case 1:
			importe = ImporteBici();
			break;
		case 2:
			importe = ImporteMotoCarro();
			break;
		case 3:
			importe = ImporteMotoCarro();
			break;
		case 4: 
			importe = ImporteCamion();
			break;
		case 5: 
			exit(1);
			break;
	}
	cout<<endl<<"El importe es: " << importe;
}
