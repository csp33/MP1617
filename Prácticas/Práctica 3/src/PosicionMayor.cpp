/* Ejercicio 16. RP1
Carlos Sánchez Páez 1ºD2 2016/2017 */
/**********MAIN***********/
#include <iostream>
#include "HerramientasVectores.h"
using namespace std;

const int TOPE= 100,MAX_ARG=4;
const string ERR="Error. Solo se permiten 3 argumentos.",SHOW="Vector de aleatorios",MAYOR_1="El valor mayor es ",MAYOR_2=" y su direccion en memoria es ";

int main(int argc,char *argv[]){

	if(argc>MAX_ARG){
		cout<<ERR<<endl;
		return 1;
	}
	int n,d,i;
	int vector[TOPE],*mayor,util;
	srand(time(NULL));	//Semilla del generador de números aleatorios

	if(argc==1){		//Sin argumentos
		n=TOPE;
		d=0;
		i=TOPE;
		util=TOPE;
	}
	else{
		n=atoi(argv[1]);
		util=n;
	 	if(argc==2){	//Un argumento
		 d=0;
		 i=n;
	 	}
		else if(argc==3){	//Dos argumentos
			d=atoi(argv[2]);
			d=0;
			i=d;
		}
		else {	//Tres argumentos
			d=atoi(argv[2]);
			i=atoi(argv[3]);
		}
	}
	RellenaAleatorios(vector,0,n);
	mayor=PosMayor(vector,d,i);

	cout<<SHOW<<endl;
	MuestraVectorEnteros(vector,util);
	cout<<MAYOR_1<<*mayor<<MAYOR_2<<mayor<<endl;
}
