/* Práctica final
Carlos Sánchez Páez 1ºD2 2016/2017 */
/*************IMPLEMENTACIÓN*************/
#include "Funciones.h"


Solucion VecinoMasCercano(const Problema &p,int inicio, int &longitud) {

	/***Declaración de variables***/

	int actual=inicio,i,j,distancia_min,ciudad;
	bool visitada[p.tamanio()];
	int vector_sol[p.tamanio()];
	longitud = 0;

	/***Inicialización***/

  //Vector de booleanos

	for(i=0;i<p.tamanio();i++)
		visitada[i]=false;

  //Primera ciudad

	vector_sol[0]=actual;
	visitada[actual] = true;

	/***Recorremos las ciudades hasta encontrar la más cercana***/

	for(i=1;i<p.tamanio();i++){
		distancia_min=INT_MAX;	//Inicializamos la distancia mínima
		for(j=0;j<p.tamanio();j++){
			if(visitada[j]==false)
				if(p.Distancia(actual,j)<distancia_min){	//Si no la hemos visitado y está más cerca, actualizamos los datos
 					ciudad=j;
					distancia_min=p.Distancia(actual,j);
				}
		}
    //Añadimos la ciudad y buscamos la siguiente más cercana
		vector_sol[i]=ciudad;
		visitada[ciudad] = true;
		actual = ciudad;
		longitud += distancia_min;
	}

	/***Fin del bucle***/

	longitud += p.Distancia(vector_sol[0],vector_sol[p.tamanio()-1]);	//Distancia a la ciudad inicial
	/***Creamos el objeto y lo devolvemos***/

	Solucion misol(vector_sol,p.tamanio());	//Cremos la solución
	return misol;

}

Solucion HallaMejorSolucion(const Problema &p){
	int distancia=0,mejorDist;
	Solucion optima, actual;

	//Inicializamos la primera ciudad

	optima = VecinoMasCercano(p, 0, mejorDist);
	//Vamos recorriendo las distintas ciudades de inicio

	for(int i=1;i<p.tamanio();i++){
		actual = VecinoMasCercano(p,i,distancia);
		if(distancia < mejorDist){	//Si encontramos una distancia menor, intercambiamos valores
			optima=actual;
			mejorDist = distancia;
		}
	}
	return optima;
}

bool GuardaSolucion(const char *out,const char *in,const Problema &p,const Solucion &s){
	bool exito=true;
	const string CABECERA="NOMBRE DE LA INSTANCIA: ",TAM="TAMANIO: ",LG="LONGITUD: ",O="ORDEN",COORD="COORDENADAS";
	ofstream salida(out);
	Punto actual;
	int indice;
	if(!salida)
		exito=false;
	if(exito){
		/***Escribir en el fichero***/
		salida<<CABECERA<<in<<endl;
		salida<<TAM<<p.tamanio()<<endl;
		salida<<LG<<p.CalculaRecorrido(s)<<endl;
		salida<<O<<endl;
		salida<<s.to_String()<<endl;
		salida<<COORD<<endl;
		for(int i=0;i<s.GetTamanio();i++){
			indice=s.GetValor(i);
			actual=p.Coordenadas(indice);
			salida<<actual.toString()<<endl;
		}
		salida.close();
	}
	return exito;
}
