/* Ejercicio 17. RP1
Carlos Sánchez Páez 1ºD2 2016/2017 */

#include <iostream>
#include "HerramientasVectores.h"
using namespace std;

const int TOPE=50,ARG_1=1,ARG_2=3;
const string ERR="Error. Numero de argumentos incorrecto.";

int main(int argc,char *argv[]){

	if(argc!=ARG_1 && argc!=ARG_2){
		cout<<ERR<<endl;
		return 1;
	}

	int vec[TOPE];
	int *ptr[TOPE];
	int izq,dcha;
	srand(time(NULL));	//Semilla del generador de números aleatorios
	RellenaAleatorios(vec,0,TOPE);	//Rellenamos el vector con números aleatorios

	if(argc==ARG_1)	{//Sin argumentos
		izq=0;
		dcha=TOPE;
	}
	else {	//Dos argumentos
		izq=atoi(argv[1]);
		dcha=atoi(argv[2]);
	}

	AsignaPunterosVectorInt(vec,ptr,izq,dcha);
	OrdenaVectorPunteros(ptr,izq,dcha);
	MuestraVectorPunteros(ptr,izq,dcha);
}
