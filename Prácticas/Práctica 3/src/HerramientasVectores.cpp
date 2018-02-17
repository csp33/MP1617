/* Práctica 3
Carlos Sánchez Páez 1ºD2 2016/2017 */
/********IMPLEMENTACIÓN***********/

#include "HerramientasVectores.h"

const string MSG_OUT="El vector ordenado es:";

int * PosMayor(int *pv,int izda,int dcha){
	int *mayor,i;
	mayor=pv+izda;
	for(i=izda+1;i<dcha;i++)
		if(*(pv+i)>*mayor)
			mayor=pv+i;
	return mayor;
}

void RellenaAleatorios(int *v,int izda,int dcha){
	int i;
	for(i=izda;i<dcha;i++)
		*(v+i)=rand()%100;	//Generamos entre 0 y 99
}

void MuestraVectorEnteros(int *v,int max){
	for(int i=0;i<max;i++)
		cout<<*(v+i)<<" ";
	cout<<endl;
}

void MuestraVectorPunteros(int **v,int izda,int dcha){
	cout<<MSG_OUT<<endl;
	for(int i=izda;i<dcha;i++)
		cout<<**(v+i)<<" ";
	cout<<endl;
}

void SwapPtrInt(int *&uno, int *&otro){
	int *aux;
	aux=uno;
	uno=otro;
	otro=aux;
}

void AsignaPunterosVectorInt(int *vec, int **ptr,int izda,int dcha){
	for(int i=izda;i<dcha;i++)
		*(ptr+i)=vec+i;
}

void OrdenaVectorPunteros (int **ptr, int izda, int dcha){
	int i,j;
	for(i=izda;i<dcha;i++)
		for(j=izda;j<dcha-i-1;j++)
			if(*ptr[j]>*ptr[j+1])
				SwapPtrInt(ptr[j],ptr[j+1]);
}
