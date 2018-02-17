#include "punto.h"
#include "circulo.h"
#include <iostream>

using namespace std;

int main(){
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

 
