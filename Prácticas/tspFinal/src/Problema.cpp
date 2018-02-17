/* Práctica final
Carlos Sánchez Páez 1ºD2 2016/2017 */
/*************IMPLEMENTACIÓN*************/
#include "Problema.h"
#include "Solucion.h"

/*********Métodos privados*********/

void Problema::Reservar(int tamanio){
	this->coordenadas=new Punto [tamanio];
	distancias=new int *[tamanio];
	for(int i=0;i<tamanio;i++)
		distancias[i]=new int [tamanio];
}

void Problema::Liberar(){
	if(this->coordenadas!=0)
		delete []coordenadas;
	if(this->ciudades!=0){
		for(int i=0;i<ciudades;i++)
			delete [] distancias[i];
		delete [] distancias;
	}
}
/*********Constructores*********/

Problema::Problema(){
	this->ciudades=0;
	this->coordenadas=0;
	this->distancias=0;
}

Problema::Problema(char *fichero){
  string cabecera;
  ifstream archivo;
  double cx,cy;
  //Abrimos el archivo
  archivo.open(fichero);
  assert(fichero);
  //Leemos la cabecera
  archivo>>cabecera;
  //Leemos el numero de ciudades y reservamos memoria
  archivo>>this->ciudades;
	this->Reservar(this->ciudades);
  //Leemos las coordenadas de todas las ciudades
  for(int i=0;i<ciudades;i++){
    cout<<"Leyendo ciudad "<<i<<"..."<<endl;
    archivo>>cx;
    archivo>>cy;
    coordenadas[i].SetX(cx);
    coordenadas[i].SetY(cy);
  }
  for(int i=0;i<ciudades;i++)
    for(int j=0;j<ciudades;j++)
      if(i==j)
				distancias[i][j]=0;
			else
				distancias[i][j]=coordenadas[i].Distancia(coordenadas[j]);
}

/*********Destructor*********/

Problema::~Problema(){
	this->Liberar();
}


/*********Métodos Get*********/

int Problema::Distancia(int c1,int c2) const {
  return round(distancias[c1][c2]);
}

Punto Problema::Coordenadas(int c) const{
  return coordenadas[c];
}

int Problema::tamanio() const {
  return ciudades;
}
int Problema::CalculaRecorrido(const Solucion& sol) const{
	int distancia=0;

  	for(int i=0;i<sol.GetTamanio()-1;i++)
  		distancia+=this->Distancia(sol.GetValor(i),sol.GetValor(i+1));

  	distancia+=this->Distancia(sol.GetValor(this->tamanio()-1),sol.GetValor(0));	//Sumamos la distancia de la final a la inicial

  	return distancia;
}

/*********Métodos de salida*********/

int Problema::Recorrido(int *solucion,int nciudades) const{
	int distancia=0;

	for(int i=0;i<nciudades;i++)
		distancia+=Distancia(solucion[i],solucion[i+1]);

	distancia+=Distancia(solucion[nciudades-1],solucion[0]);

	return distancia;
}

/*********Sobrecarga de operadores*********/
Problema& Problema::operator=(const Problema &p){
  if(&p!=this) { //Si no estamos asignando el mismo objeto

    //Eliminamos el contenido del objeto

    this->Liberar();

    //Reservamos memoria y copiamos los campos
		this->Reservar(p.tamanio());
		//Ciudades
    this->ciudades=p.tamanio();
		//Coordenadas
		for(int i=0;i<p.tamanio();i++)
			this->coordenadas[i]=p.Coordenadas(i);
		//Matriz de distancias
    for(int i=0;i<p.tamanio();i++)
      for(int j=0;j<tamanio();j++)
        this->distancias[i][j]=p.Distancia(i,j);
  }
  return *this;
}
/**********Entrada y salida de ficheros**************/
bool Problema::Leer(const char *fichero){
	bool leido=true;
	ifstream archivo(fichero);
	if(!archivo)
		leido=false;

	else{

		if(this->tamanio()!=0)
			this->Liberar();

		string cabecera;
	  double cx,cy;
		//Leemos la cabecera
		archivo>>cabecera;
		//Leemos el numero de ciudades y reservamos memoria
		archivo>>this->ciudades;
		this->Reservar(this->ciudades);
		//Leemos las coordenadas de todas las ciudades
		for(int i=0;i<ciudades;i++){
		  cout<<"Leyendo ciudad "<<i<<"..."<<endl;
		  archivo>>cx;
		  archivo>>cy;
		  coordenadas[i].SetX(cx);
		  coordenadas[i].SetY(cy);
		}
		for(int i=0;i<ciudades;i++)
		  for(int j=0;j<ciudades;j++)
		    if(i==j)
				distancias[i][j]=0;
			else
				distancias[i][j]=coordenadas[i].Distancia(coordenadas[j]);
	}

	return leido;
}
