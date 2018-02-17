/* Práctica final
Carlos Sánchez Páez 1ºD2 2016/2017 */
/*************IMPLEMENTACIÓN*************/
#include "Solucion.h"
#include "Problema.h"

/******Métodos privados*******/

void Solucion::Permuta(const int a,const int b){
  int aux;
  aux=this->vector[b];
  this->vector[b]=this->vector[a];
  this->vector[a]=aux;
}
int Solucion::AleatorioMenor(const int cota) const{
  return rand()%cota;
}

void Solucion::Liberar(){
  if(vector!=0)
    delete []vector;
}

void Solucion::Reservar(int tamanio){
  this->vector=new int [tamanio];
}
/*********Constructores*********/

Solucion::Solucion(){
	this->vector=0;
	this->tamanio=0;
}

Solucion::Solucion(int *vector,int tamanio){
  this->Reservar(tamanio);
  this->tamanio=tamanio;
  for(int i=0;i<tamanio;i++)
    this->vector[i]=vector[i];
  assert(this->esCorrecta());
}

Solucion::Solucion(int tamanio){
  //Iniciamos la semilla del generador de aleatorios
  srand(time(NULL));
  this->tamanio=tamanio;
  this->vector=new int [tamanio];
  for(int i=0;i<tamanio;i++)
    this->vector[i]=i;
  int a,b;
  a=AleatorioMenor(tamanio-1);
  sleep(1);
  b=AleatorioMenor(tamanio-1);
  Permuta(a,b);
  assert(this->esCorrecta());
}

Solucion::Solucion(const Solucion &otra){
  this->tamanio=otra.GetTamanio();
  this->Reservar(tamanio);
  for(int i=0;i<this->tamanio;i++)
    this->vector[i]=otra.GetValor(i);
}

/*********Destructor*********/

Solucion::~Solucion(){
  Liberar();
}

/*********Métodos Get*********/

int Solucion::GetTamanio() const {
  return tamanio;
}

int Solucion::GetValor(int indice) const{
  return vector[indice];
}

int Solucion::GetPosicion(int ciudad) const{
  int posicion=-1;
  for(int i=0;i<this->tamanio && posicion==-1;i++)
    if(this->vector[i]==ciudad)
      posicion=i;
  return posicion;
}

/*********Métodos de comprobación*********/

bool Solucion::esCorrecta() const{
  bool *posiciones,correcta=true;
  posiciones=new bool [this->tamanio];
  for(int i=0;i<this->tamanio;i++)
    posiciones[i]=false;
  for(int i=0;i<this->tamanio;i++)
    posiciones[this->vector[i]]=true;
  for(int i=0;i<this->tamanio && correcta;i++)
    if(!posiciones[i])
      correcta=false;
  delete []posiciones;
  return correcta;
}

/*********Métodos de salida*********/

string Solucion::to_String() const{
    string resultado;
    for(int i=0;i<this->tamanio;i++)
      resultado+=to_string(this->vector[i])+" ";
    return resultado;
}


/*********Sobrecarga de operadores*********/
Solucion& Solucion::operator=(const Solucion &s){
  if(&s!=this) { //Si no estamos asignando el mismo objeto

    //Eliminamos el contenido del objeto

    this->Liberar();

    //Asignamos los nuevos valores

    this->tamanio=s.GetTamanio();
    this->vector=new int [s.GetTamanio()];
    for(int i=0;i<s.GetTamanio();i++)
      this->vector[i]=s.GetValor(i);

  }
  return *this;
}
