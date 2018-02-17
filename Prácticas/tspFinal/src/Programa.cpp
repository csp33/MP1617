/* Práctica final
Carlos Sánchez Páez 1ºD2 2016/2017 */
/*************MAIN*************/
#include <iostream>
#include <fstream>

#include "Punto.h"
#include "Problema.h"
#include "Solucion.h"
#include "Funciones.h"

using namespace std;

const string ERROR_ARG="Numero de argumentos incorrecto.",FL="\nFin de la lectura",
DIST="Distancia que se recorre (km): ",
SEP="\n***********************************************************\n",
CREA="\nCreando solucion del archivo ",ERROR_L="Error en la lectura del archivo ";



int main(int argc,char **argv){

	/***Si pasamos un número erróneo de argumentos***/

 	if(argc>3){
		cout<<ERROR_ARG<<endl;
		return 1;
  }

/***************************************/

	//Declaración de variables

	ifstream entrada(argv[1]);
	Problema p;
	Solucion s;
	bool guardado;
	bool leido;

	if(entrada){	//Si se ha leido correctamente el primer argumento

		if(argc==2){		//Un argumento. Se lee la lista de ficheros y guarda cada resultado en cxx.sol
			string actual,nombre;
			entrada>>actual;
			while(!entrada.eof()){	//Mientras no lleguemos al fin del archivo
				cout<<CREA<<actual<<endl<<endl;
				sleep(1);
				leido=p.Leer(actual.c_str());
				if(leido){
					s=HallaMejorSolucion(p);
					nombre="c"+to_string(p.tamanio())+".sol";
					guardado=GuardaSolucion(nombre.c_str(),actual.c_str(),p,s);
				}
				entrada>>actual;
				cout<<SEP<<endl;
			}
	}

		else{		//Dos argumentos. Hallamos la mejor solución del primero y la guardamos en el segundo

			leido=p.Leer(argv[1]);
			if(leido){
				s=HallaMejorSolucion(p);
				guardado=GuardaSolucion(argv[2],argv[1],p,s);
				}
			}
		}

	else		//Si ha habido un error de lectura
		cout<<ERROR_L<<argv[1]<<endl;

	entrada.close();	//Cerramos el archivo para liberar el flujo


}
