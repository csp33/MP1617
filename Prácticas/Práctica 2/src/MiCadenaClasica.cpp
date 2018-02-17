/*Ejercicios 9 a 15. RP1 
Carlos Sánchez Páez 1ºD2. 2016/2017 
*/
/****IMPLEMENTACIÓN****/

#include "MiCadenaClasica.h"
using namespace std;

const char FIN='\0';					//Delimitador de fin de cadena

int longitud_cadena (char *ptr_inicio){
	int longitud=0;
	while(*ptr_inicio!=FIN){
		longitud++;
		ptr_inicio++;
	}
	return longitud;
}

bool es_palindromo (char *ptr_izq){
	char *ptr_dcha=ptr_izq+strlen(ptr_izq)-1;	//Llevo el puntero a la última posición válida
	bool palindromo=true;
	while(ptr_izq<ptr_dcha && palindromo){
		if(*ptr_izq!=*ptr_dcha)
			palindromo=false;
	ptr_izq++;
	ptr_dcha--;	
	}
	return palindromo;
}

int compara_cadenas (char *ptr_una,char *ptr_otra){	
	while(*ptr_una==*ptr_otra && *ptr_una!=FIN){	//Saltamos las posiciones iguales
		ptr_una++;
		ptr_otra++;
	}
	return *ptr_una-*ptr_otra;			//Devolvemos la resta del código ASCII del primer carácter desigual de ambas cadenas
}

void copiar_cadena (char *ptr_una,char *ptr_otra){	
	while(*ptr_otra!=FIN){
		*ptr_una=*ptr_otra;
		ptr_otra++;
		ptr_una++;
	}
	*ptr_una=FIN;					//Añadimos el delimtiador
}
void encadenar_cadena (char *ptr_una,char *ptr_otra){
	ptr_una+=strlen(ptr_una);			//Llevo el puntero a la última posición ('\0')
	copiar_cadena(ptr_una,ptr_otra);
}
void obten_subcadena (char *ptr_inicio,int p,int l,char *resultado){
	char *ptr_pos,*ptr_fin;
	ptr_pos=ptr_inicio+p;				//Llevamos al puntero a la posición de inicio
	ptr_fin=ptr_pos+l;				//Llevamos al puntero a la posición final de la subcadena

	while(ptr_pos<ptr_fin){ 			//Mientras no alcancemos la longitud
		*resultado=*ptr_pos;
		ptr_pos++;
		resultado++;
	}

	*resultado=FIN;					//Añadimos el delimtiador
}
void invierte(char *original,char *destino){
	char *fin=original+strlen(original)-1;
	while(fin>=original){
		*destino=*fin;
		destino++;
		fin--;
	}
	*destino=FIN;
}
