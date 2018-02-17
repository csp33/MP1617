/* Práctica final
Carlos Sánchez Páez 1ºD2 2016/2017 */
/*************PROTOTIPOS*************/
#ifndef PUNTO_H
#define PUNTO_H
#include <string>
#include <cmath>
using namespace std;

class Punto{
  private:

    double x,y;

  public:

    /*********Constructores*********/

    Punto(double x=0,double y=0);

    /*********Métodos Get*********/

    double GetX();
    double GetY();

    /*********Métodos Set*********/

    void SetY(double y);
    void SetX(double x);

    /*********Métodos de salida*********/

    int Distancia(Punto p2);
    string toString();
    Punto puntoMedio(Punto p2);

};


#endif
