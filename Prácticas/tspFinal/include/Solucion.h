/* Práctica final
Carlos Sánchez Páez 1ºD2 2016/2017 */
/*************PROTOTIPOS*************/
#ifndef SOLUCION_H
#define SOLUCION_H

#include <iostream>
#include <string>
#include <unistd.h>


using namespace std;

class Solucion{

private:

  int *vector;
  int tamanio;
  void Permuta(const int a,const int b);
  int AleatorioMenor(const int cota) const;
  void Liberar();
  void Reservar(int tamanio);

public:

  /*********Constructores*********/

  Solucion();
  Solucion(int *vector,int tamanio);
  Solucion(int tamanio);
  Solucion(const Solucion &otra);

  /*********Destructor*********/

  ~Solucion();

  /*********Métodos Get*********/

  int GetTamanio() const;
  int GetValor(int indice) const;
  int GetPosicion(int ciudad) const;

  /*********Métodos de comprobación*********/

  bool esCorrecta() const;

  /*********Métodos de salida*********/

  string to_String() const;

  /*********Sobrecarga de operadores*********/

  Solucion& operator=(const Solucion &s);

};

#endif
