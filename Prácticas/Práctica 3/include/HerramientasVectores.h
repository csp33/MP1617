/* Práctica 3
Carlos Sánchez Páez 1ºD2 2016/2017 */
/********PROTOTIPOS***********/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#ifndef VECTORES_H
#define VECTORES_H

int * PosMayor(int *pv,int izda,int dcha);
void RellenaAleatorios(int *v,int izda,int dcha);
void MuestraVectorEnteros(int *v,int max);
void MuestraVectorPunteros(int **v,int izda,int dcha);
void SwapPtrInt(int *&uno, int *&otro);
void AsignaPunterosVectorInt(int *vec, int **ptr,int izda,int dcha);
void OrdenaVectorPunteros (int **ptr, int izda, int dcha);

#endif
