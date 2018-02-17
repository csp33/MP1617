/**
   @file circulomedio.cpp
   @brief Calcula círculo con centro en medio de dos círculos y radio la mitad de la distancia
   @warning Módulo no definitivo (creado para ser modificado)

// si quieres utilizar la funcion to_string(), recuerde agregar -std=c++0x a las opciones del compilador

**/

#include <iostream>
#include <cmath> 
#include <string>

using namespace std;

const double PI = 3.14159265;
class Punto {
private:
    double x; // coordenada x del punto
    double y; // coordenada y del punto

public:
    Punto(); //constructor. Pone a 0 las dos coordenadas
    Punto(double px, double py); // constructor. Inicializa un punto con dos valores x y
    double getX(); 
    double getY(); 
    void setX(double newXValue); 
    void setY(double newYValue); 
    string toString(); ///<  devuelve el contenido del punto como un string
    double distancia(Punto p2); // calcula la distancia a otro punto
    Punto puntoMedio(Punto p2); //devuelve el punto medio entre el objeto implicito y p2
};

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


class Circulo {
private:
    Punto centro; // Centro del círculo
    double radio; // radio del círculo

public:
    Circulo(); // Constructor: Pone a 0 el punto y el radio
    Circulo(Punto centro, double rradio); // Constructor: Inicializa el círculo con un centro y un radio
    void set(Punto centro, double rradio); // Asigna el centro y el radio a un circulo
    Punto getCentro(); 
    double getRadio(); 
    string toString(); // devuelve el contenido del circulo como un string
    double area(); // Devuelve el área de un círculo
    double distancia (Circulo c2);
    bool interior (Punto p); // true si p está contenido en el círculo
};

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


int main()
{
	const string CX="Introduzca la coordenada X del centro del circulo",CY="Introduzca la 		coordenada Y del centro del circulo",R="Introduzca el radio del circulo ";
	double x,y;
	double radio;
	Punto centro;
	

	// leer datos para circulo 1
	cout<<CX<<1<<endl;
	cin>>x;
	cout<<CY<<1<<endl;
	cin>>y;
	centro.setX(x);
	centro.setY(y);
	cout<<R<<1<<endl;
	cin>>radio;

	Circulo c1(centro,radio);	
	// leer datos para circulo 2
	cout<<CX<<2<<endl;
	cin>>x;
	cout<<CY<<2<<endl;
	cin>>y;
	centro.setX(x);
	centro.setY(y);
	cout<<R<<2<<endl;
	cin>>radio;

	Circulo c2(centro,radio);	
 
    
    // realizar los cálculos
	Punto centro1,centro2;
	centro1=c1.getCentro();
	centro2=c2.getCentro();
	centro=centro1.puntoMedio(centro2);
	radio=(c2.getRadio()-c1.getRadio())/2;

	Circulo c3(centro,radio);
	
	// mostrar resultados
    
    
    cout << "\nLos circulos son\n";
	cout << "Circulo 1 -> " << c1.toString() << ", area: " << c1.area() << endl;
	cout << "Circulo 2 -> " << c2.toString() << ", area: " << c2.area() << endl;
	cout << "Circulo 3 -> " << c3.toString() << ", area: " << c3.area() << endl;
   
    
    cout << endl;
}

/* Fin: circulomedio.cpp */
 
