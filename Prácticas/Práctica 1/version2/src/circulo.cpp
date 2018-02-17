#include "circulo.h"


Circulo::Circulo():centro(0,0), radio(0) {
}

Circulo::Circulo(Punto p, double rradio):centro(p),radio(rradio) {
}

void Circulo::set(Punto p, double rradio) {
	radio = rradio;
	centro = p;
}


Punto Circulo::getCentro()  {
	return centro;
}

double Circulo::getRadio()  {
	return radio;
}

string Circulo::toString() {
	string cx,cy,res,rad;
	cx=to_string(centro.getX());
	cy=to_string(centro.getY());
	rad=to_string(radio);
	res="Centro:("+cx+","+cy+")\nRadio:"+rad;
	return res;
}

double Circulo::area() {
    return PI * radio * radio;
}

// devuelve la distancia entre sus centros
double Circulo::distancia (Circulo c2){
	Punto uno,dos;
	double dist;
	uno=centro;
	dos=c2.getCentro();
	dist=uno.distancia(dos);
	return dist;	
}

//Comprueba si un punto es interior al círculo
bool Circulo::interior (Punto p){
	return pow(centro.getX()-p.getX(),2)+pow(centro.getY()-p.getY(),2)<=pow(radio,2);
}

