/*Ejercicios 9 a 15. RP1 
Carlos Sánchez Páez 1ºD2. 2016/2017 
*/
/****PROTOTIPOS****/
#include <cstring>
using namespace std;
#ifndef _MICADENACLASICA_H
#define _MICADENACLASICA_H


int longitud_cadena(char *ptr_inicio);				//Devuelve la longitud de la cadena sin contar el carácter de fin de cadena ('\0')
bool es_palindromo(char *ptr_izq);				//Si se lee igual de izquierda a derecha y de derecha a izquierda
int compara_cadenas(char *ptr_una,char *ptr_otra);		//Compara dos cadenas mediante el orden lexicográfico
void copiar_cadena(char *ptr_una,char *ptr_otra);		//Copia la cadena del segundo argumento en la primera
void encadenar_cadena(char *ptr_una,char *ptr_otra);		//Encadena la cadena del segundo argumento en la primera
void obten_subcadena( char *ptr,int p,int l,char *resultado);	//Obtiene una subcadena a partir de los siguientes parametros: cadena original,posicion de inicio, longitud y cadena destino
void invierte(char *original,char *destino);			//Invierte la cadena del primer argumento y la almacena en el segundo

#endif
