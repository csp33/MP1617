/*Ejercicio 8. RP1 
Carlos Sánchez Páez 1ºD2. 2016/2017 
*/
#include <iostream>
using namespace std;
const int CAP=100;
const char BLANCO=' ',FIN_CADENA='\0';
const string MSG_LEER="Introduzca una cadena de caracteres.\nLongitud maxima: ",MSG_NO="No se encontro ningun espacio en blanco";
int main () {
	char cadena[CAP],*ptr=cadena;
	bool hay_blancos=false;
	//Almacenamos la cadena
	cout<<MSG_LEER<<CAP<<endl;
	cin.getline(cadena,CAP);
	//Movemos el puntero a la primera posición de la 		segunda	palabra
	while(*ptr!=FIN_CADENA && !hay_blancos){	
		hay_blancos=*ptr==BLANCO;
		ptr++;
	}
	//Mostramos la cadena comenzando por el puntero
	if(hay_blancos)
		cout<<ptr<<endl;
	else
		cout<<MSG_NO<<endl;
}
