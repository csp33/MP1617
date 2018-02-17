/*Ejercicio 7. RP1 
Carlos Sánchez Páez 1ºD2. 2016/2017 
*/
#include <iostream>
using namespace std;
const int CAP=100;
const char BLANCO=' ',FIN_CADENA='\0';
const string MSG_LEER="Introduzca una cadena de caracteres.\nLongitud maxima: ",MSG_NO="No se encontro ningun espacio en blanco",MSG_SI="Espacio en blanco encontrado en la posicion ";

int main () {
	char cadena[CAP],*ptr=cadena;
	bool blanco_encontrado=false;
	//Almacenamos la cadena
	cout<<MSG_LEER<<CAP<<endl;
	cin.getline(cadena,CAP);
	//Buscamos los blancos
	while(*ptr!=FIN_CADENA && !blanco_encontrado){
		blanco_encontrado=*ptr==BLANCO;		
		ptr++;
	}
	if(blanco_encontrado)
		cout<<MSG_SI<<(ptr-cadena)<<endl;
	else
		cout<<MSG_NO<<endl;

}

