/* Práctica final
Carlos Sánchez Páez 1ºD2 2016/2017 */
/*************PROTOTIPOS*************/
#ifndef PROBLEMA_H
#define PROBLEMA_H
#include "Punto.h"
#include <fstream>
#include <iostream>
#include "assert.h"
#include "Solucion.h"
using namespace std;


class Problema{

private:

  int ciudades;
  Punto *coordenadas;
  int **distancias;
  void GeneraAleatoriosRango(int &a,int &b,const int inferior,const int superior);
  void Swap(int &a,int &b);
  void Liberar();
  void Reservar(int tamanio);

public:

  /*********Constructores*********/

  Problema();
  Problema(char *fichero);

  /*********Destructor*********/

  ~Problema();

  /*********Métodos Get*********/

  int Distancia(int c1,int c2) const;
  Punto Coordenadas(int c) const;
  int tamanio() const;
  int CalculaRecorrido(const Solucion &sol) const;

  /*********Métodos de salida*********/

  int Recorrido(int *solucion,int numero_ciudades) const;

  /*********Sobrecarga de operadores*********/
  Problema& operator=(const Problema &p);

  /**********Entrada y salida de ficheros**************/
  bool Leer(const char *fichero);

};

#endif
