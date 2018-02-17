/* Práctica final
Carlos Sánchez Páez 1ºD2 2016/2017 */
/*************IMPLEMENTACIÓN*************/
#include "Punto.h"

/*********Constructores*********/

Punto::Punto(double x,double y){
  this->x=x;
  this->y=y;
}

/*********Métodos Get*********/

double Punto::GetX(){
  return x;
}

double Punto::GetY(){
  return y;
}

/*********Métodos Set*********/

void Punto::SetY(double y){
  this->y=y;
}

void Punto::SetX(double x){
  this->x=x;
}

/*********Métodos de salida*********/

int Punto::Distancia(Punto p2){
	double  distancia;
  distancia=sqrt(pow((x-p2.GetX()),2)+pow((y-p2.GetY()),2));
	return round(distancia);
}

string Punto::toString() {
	string cx,cy,res;
	cx=to_string(x);
	cy=to_string(y);
	res="("+cx+","+cy+")";
	return res;
}

Punto Punto::puntoMedio(Punto p2){
	Punto resultado;
	double rx,ry;
	rx=(x+p2.GetX())/2;
	ry=(y+p2.GetY())/2;
	resultado.SetX(rx);
	resultado.SetY(ry);
	return resultado;
}
