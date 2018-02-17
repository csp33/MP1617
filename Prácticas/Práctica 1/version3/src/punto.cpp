#include "punto.h"


Punto::Punto():x(0),y(0) {
}

Punto::Punto(double px, double py):x(px),y(py) {
}

double Punto::getX() {
	return x;
}

double Punto::getY() {
	return y;
}

void Punto::setX(double px) {
	x = px;
}

void Punto::setY(double py) {
	y = py;
}

string Punto::toString() {
	string cx,cy,res;
	cx=to_string(x);
	cy=to_string(y);
	res="("+cx+","+cy+")";
	return res;
 	
}

double Punto::distancia(Punto p2){
	double dist_x,dist_y,distancia;
	dist_x=x-p2.getX();
	dist_y=y-p2.getY();
	distancia=sqrt(pow(dist_x,2)-pow(dist_y,2));
	return distancia;
}


Punto Punto::puntoMedio(Punto p2){
	Punto resultado;
	double rx,ry;
	rx=(x+p2.getX())/2;
	ry=(y+p2.getY())/2;
	resultado.setX(rx);
	resultado.setY(ry);
	return resultado;
}

