/*
	* Fecha: 06-02-2022
	* Autor: Valeria Bermúdez Galván
	* Materia : Computación paralela y distribuida
	* Tema : Punto 7 del Taller Machine Learning en Computación Avanzada
	* Programa que permite evaluar la serie 
	*/
	
#include <iostream>

using namespace std;


/* Función para evaluar la serie */

double evaluacionSerie(int b, double  x , double y){
	double serie = 0;
	for(int a = 0 ; a <= b ; a++){
		serie+=1/(x+a*y);
	}
	return serie;
	
}

/* Se requiere implementar una aplicación que evalue 
   la serie dada  */
	
int main(int argc, char **argv){
	int b = 0 ;
	double x = 0 ,y = 0 , serie = 0 ;
	
	do{
       cout << "Ingrese el valor hasta donde sea realizar la sumatoria (b), recuerde que no puede insertar numeros negativos" << endl;
	   cin >> b;
	} while(b < 0);
	
	do{
       cout << "Ingrese el valor de x , recuerde que no puede insertar numeros negativos" << endl;
	   cin >> x;
	} while(x < 0);
	
	do{
       cout << "Ingrese el valor de y , recuerde que no puede insertar numeros negativos" << endl;
	   cin >> y;
	} while(y < 0);
	
	serie = evaluacionSerie(b ,x , y); 
	cout << "La serie hasta  "<< b << " es igual a " << serie << endl ;
	
}
