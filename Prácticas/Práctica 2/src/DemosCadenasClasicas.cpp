/*Fichero central de la Práctica 2. 
Carlos Sánchez Páez 1ºD2. 2016/2017 
*/

#include "MiCadenaClasica.h"
#include <iostream>
#include <unistd.h>
using namespace std;

/***Definición de constantes***/

const int CAP=50,NORMAL_SLEEP=1,LONG_SLEEP=2,CERO=0;
const float SHORT_SLEEP=0.5;
const string MSG_INT="Introduzca la cadena ",MSG_TAM="Tamanio maximo: ",MSG_LONG="Longitud de la cadena ",MSG_PAL="Palindroma",MSG_NPAL="No palindroma",C1="Cadena 1: ",C2="Cadena 2: "
,MSG_COMP="Comparacion de cadenas mediante el orden lexicografico.\n-->Negativo si la segunda cadena es mayor\n-->Cero si son iguales\n-->Positivo si la primera es mayor\n\nResultado:"
,MSG_E="Error! La cadena 1 no tiene espacio suficiente",MSG_P="Introduzca el punto de inicio de la subcadena deseada (empieza en 0): ",MSG_L="Introduzca la longitud de la subcadena deseada: "
,MSG_SC="Vamos a obtener una subcadena de la cadena ",MSG_S="La subcadena es: ",MSG_INV="La inversa de la cadena 1 es :",MSG_ENC="Encadenando la cadena 2 en la cadena 1:",MSG_CP_1="para copiar en la cadena 1. ",UNO="1 ",DOS="2 ",DP=":";

int main(){
	/***Declaración de variables***/

	char cadena1[CAP];
	char cadena2[CAP];
	char a_copiar[CAP];
	char subcadena[CAP];
	char inversa[CAP];
	int inicio,longitud;

	/***Lectura de cadenas***/

	cout<<MSG_INT<<UNO<<MSG_TAM<<CAP<<endl;
	cin.getline(cadena1,CAP);
	cout<<MSG_INT<<DOS<<MSG_TAM<<CAP<<endl;
	cin.getline(cadena2,CAP);
	cout<<endl;

	/***Longitud de las cadenas***/

	cout<<MSG_LONG<<UNO<<DP<<longitud_cadena(cadena1)<<endl;
	cout<<MSG_LONG<<DOS<<DP<<longitud_cadena(cadena2)<<endl;
	sleep(NORMAL_SLEEP);					//Pausamos el programa para poder leer la salida
	cout<<endl;

	/**Cadenas palíndromas***/

	if(es_palindromo(cadena1))	
		cout<<C1<<MSG_PAL<<endl;
	else
		cout<<C1<<MSG_NPAL<<endl;
	sleep(SHORT_SLEEP);
	if(es_palindromo(cadena2))	
		cout<<C2<<MSG_PAL<<endl;
	else
		cout<<C2<<MSG_NPAL<<endl;
	sleep(NORMAL_SLEEP);
	cout<<endl;

	/***Comparación de cadenas***/

	cout<<MSG_COMP<<endl;
	sleep(LONG_SLEEP);
	cout<<compara_cadenas(cadena1,cadena2)<<endl;
	sleep(NORMAL_SLEEP);
	cout<<endl;

	/***Copia de cadenas***/

	cout<<MSG_INT<<MSG_CP_1<<MSG_TAM<<CAP<<endl;
	cin.getline(a_copiar,CAP);
	copiar_cadena(cadena1,a_copiar);
	cout<<C1<<cadena1<<endl;
	sleep(NORMAL_SLEEP);
	cout<<endl;

	/***Encadenar cadenas***/

	if(longitud_cadena(cadena1)+longitud_cadena(cadena2)>CAP)
		cout<<MSG_E;
	else{
		cout<<MSG_ENC<<endl;
		sleep(NORMAL_SLEEP);
		encadenar_cadena(cadena1,cadena2);
		cout<<C1<<cadena1<<endl;
	}
	sleep(NORMAL_SLEEP);
	cout<<endl;

	/***Obtener subcadena***/

	cout<<MSG_SC<<UNO<<endl;
	do{							//Filtro de entrada de datos
		cout<<MSG_P<<endl;
		cin>>inicio;
	}while(inicio<CERO || inicio>longitud_cadena(cadena1));

	do{
		cout<<MSG_L<<endl;
		cin>>longitud;
	}while(longitud<=CERO || longitud>CAP);

	sleep(SHORT_SLEEP);
	obten_subcadena(cadena1,inicio,longitud,subcadena);
	cout<<MSG_S<<endl<<subcadena<<endl;
	sleep(NORMAL_SLEEP);
	cout<<endl;

	/***Invertir cadena***/

	invierte(cadena1,inversa);
	cout<<MSG_INV<<endl<<inversa<<endl;
	cout<<endl;

}
