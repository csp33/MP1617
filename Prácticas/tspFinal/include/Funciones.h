/* Práctica final
Carlos Sánchez Páez 1ºD2 2016/2017 */
/*************PROTOTIPOS*************/
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Solucion.h"
#include "Problema.h"
#include <iostream>
#include <climits>

using namespace std;

Solucion VecinoMasCercano(const Problema &p,int inicio, int &longitud);
Solucion HallaMejorSolucion(const Problema &p);
bool GuardaSolucion(const char *out,const char *in,const Problema &p,const Solucion &s);

#endif
