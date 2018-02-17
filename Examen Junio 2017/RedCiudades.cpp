#include <cassert>
#include <cstring>
#include <fstream>
#include <cfloat>
#include "RedCiudades.hpp"


//////////////////
//IMPORTANTE: Aunque vamos a almacenar las ciudades en una matriz
//indexada de 0 a num_ciudades-1, el usuario de la clase indexará
//las ciudades de una forma más natural, numerándolas a partir de 1
//
//También en los ficheros de datos las ciudades se numerarán a partir de 1
//
//Para ello, todos los métodos que acceden directamente a la representación
//interna, restan 1 a los índices pasados como parámetros.
//El resto de métodos, los que no acceden directamente a la representación
//interna, trabajan de 1 a num_ciudades, como el usuario de la clase
//////////////////

/////////////////////////////
//Métodos auxiliares privados
/////////////////////////////
void RedCiudades::liberar_memoria(){
  //Libero las cadenas de los nombres de las ciudades
  //Compruebo si la red está vacía
  if (!EstaVacia()){
    for(int i=0; i<num_ciudades; i++)
      delete[] info[i].nombre;
    //Libero el vector de estructuras info
    delete[] info;
  
    //Libero la matriz de distancias
    delete[] distancia[0];
    delete[] distancia;
  }
}

// Reserva memoria para el vector de ciudades
// y la matriz de distancias
void RedCiudades::reservar_memoria(int numero_ciudades){
  assert(numero_ciudades>0);
  this->num_ciudades = numero_ciudades;
  
  //Reservo espacio para la información
  info = new InfoCiudad[num_ciudades];
  
  //IMPORTANTE: no estamos reservando espacio para el nombre de las ciudades
  //en las estructuras InfoCiudad. Lo haremos al leer para hacer la reserva
  //dinámica y ajustada a la longitud de cada nombre
  
  //Reservo la matriz de distancias
  //Reservo el vector de punteros
  distancia = new double*[num_ciudades];
  //Reservo el espacio de datos
  distancia[0] = new double[num_ciudades*num_ciudades];
  //Ajusto todos los punteros
  for(int i=1; i<num_ciudades; i++)
    distancia[i] = distancia[i-1] + num_ciudades;
  //Pongo a 0 la matriz de distancias
  for(int i=0; i<num_ciudades; i++)
    for(int j=0; j<num_ciudades; j++)
      distancia[i][j] = 0.0;
}



//Copia el vector de ciudades y la matriz de distancias
//IMPORTANTE: Suponemos que num_ciudades ya contiene la información
void RedCiudades::copiar(const RedCiudades & otra){
  //Recorro el vector info copiando información de ciudades
  for(int i=0; i<this->num_ciudades; i++){
    //reservo espacio para el nombre
    this->info[i].nombre = new char[strlen(otra.info[i].nombre)+1];
    //copio la información
    strcpy(this->info[i].nombre, otra.info[i].nombre);
    this->info[i].poblacion = otra.info[i].poblacion;
  }
  
  //Copio la información de la matriz de distancias
  for(int i=0; i<this->num_ciudades; i++)
    for(int j=0; j<this->num_ciudades; j++)
      this->distancia[i][j] = otra.distancia[i][j];
  //Podría haber usado memcpy, aprovechando que los datos
  //de la matriz se ubican consecutivos en memoria
//  memcpy(this->distancia[0], otra.distancia[0],
//         num_ciudades*num_ciudades*sizeof(double));
}

////////////////////////
//Métodos públicos
////////////////////////

//Métodos de consulta

int RedCiudades::NumCiudades() const{
  return num_ciudades;
}

double RedCiudades::Distancia(const int c1, const int c2) const{
  assert(c1>0 && c1<=num_ciudades);
  assert(c2>0 && c2<=num_ciudades);
  return distancia[c1-1][c2-1];
}

char * RedCiudades::NombreCiudad(const int i) const{
  assert(i>0 && i<=num_ciudades);
  return(info[i-1].nombre);
}

int RedCiudades::PoblacionCiudad(const int i) const{
  assert(i>0 && i<=num_ciudades);
  return(info[i-1].poblacion);
}

//1.1. Constructor por defecto

RedCiudades::RedCiudades(){
  num_ciudades = 0;
  //No es imprescindible, pero es una buena costumbre inicializar
  //siempre los punteros
  info = 0;
  distancia = 0;
}

bool RedCiudades::EstaVacia(){
  //En realidad, bastaría comprobar si num_ciudades es 0
  return (num_ciudades == 0 && info == 0 && distancia == 0);
}

//1.1. Destructor
RedCiudades::~RedCiudades(){
  liberar_memoria();
}

//1.2 Constructor de copia
RedCiudades::RedCiudades(const RedCiudades &otra){
  
  //Reservo memoria
  reservar_memoria(otra.num_ciudades);
  
  //Copio la información
  copiar(otra);
}

//1.2 Operador de asignación

RedCiudades& RedCiudades::operator=(const RedCiudades &otra){
  if(this!=&otra){
    liberar_memoria();
    reservar_memoria(otra.num_ciudades);
    copiar(otra);
  }
  return *this;
}

//2.1 Operador <<
ostream & operator<<(ostream & flujo, const RedCiudades & red){
  //Escribo el número de ciudades
  flujo << red.NumCiudades() << endl;
  //Escribo las ciudades con sus poblaciones
  for (int i=1; i<=red.NumCiudades(); i++)
    flujo << red.NombreCiudad(i) << " " << red.PoblacionCiudad(i) << endl;
  //Escribo las conexiones entre ciudades
  for (int i=1; i<=red.NumCiudades(); i++){
    for (int j=i+1; j<=red.NumCiudades(); j++)
      if (red.EstanConectadasDirectamente(i,j))
        flujo << i << " " << j << " " << red.Distancia(i, j) << endl;
  }
  return flujo;
}

//2.2. Operador >>
istream & operator>>(istream & flujo, RedCiudades & red){
  char cadena[LONGITUD_CADENAS];
  int n_ciudades, c1, c2;
  //Liberamos memoria para volver a construir el objeto
  red.liberar_memoria();
  //Leo el número de ciudades
  flujo >> n_ciudades;
  //Reservo memoria
  red.reservar_memoria(n_ciudades);
  //Leemos los nombres de las ciudades y sus poblaciones
  for (int i=1; i<=red.num_ciudades; i++){
    flujo >> cadena;
    red.info[i-1].nombre = new char[strlen(cadena)];
    strcpy(red.info[i-1].nombre, cadena);
    flujo>>  red.info[i-1].poblacion;
  }
  //Leemos las conexiones entre ciudades
  while (flujo >> c1 >> c2 >> red.distancia[c1-1][c2-1])
    //Copiamos la conexión en las dos direcciones
    red.distancia[c2-1][c1-1] = red.distancia[c1-1][c2-1];
  return flujo;
}

//3.1 Constructor con parámetro
RedCiudades::RedCiudades(const char * filename){
  num_ciudades = 0;
  info = 0;
  distancia = 0;
  //Delegamos en el método LeerRedCiudades
  LeerRedCiudades(filename);
}

//3.2 Método LeerRedCiudades
void RedCiudades::LeerRedCiudades(const char * filename){
  char cadena[LONGITUD_CADENAS];
  ifstream flujo(filename);
  //Libero memoria entes de comenzar
  liberar_memoria();
  
  if (flujo){ //Si se ha abierto el fichero sin problema
    //Leemos la línea de la cadena mágica
    flujo.getline(cadena, LONGITUD_CADENAS);
    if (!strcmp(cadena, "RED")){
      //Si la cadena mágica es correcta,
      //leemos delegando en el operador >>
      flujo >> *this;
    }
    else{
      cerr << "Error en la cadena mágica" << endl;
      exit(1);
    }
  }
  else{
    cerr << "ERROR: No es posible abrir el fichero " << filename << endl;
    exit(1);
  }
}

//3.3 Método EscribirRedCiudades

void RedCiudades::EscribirRedCiudades(const char * filename)const{
  ofstream flujo(filename);

  if (flujo){ //Si se ha abierto sin problema
    //Escribimos la cadena mágica
    flujo << "RED" << endl;
    //Escribimos la red delegando en el operador <<
    flujo << *this;
  }
  else{
    cerr << "ERROR: No es posible crear el fichero " << filename << endl;
  }
  
}

//4.1 Método CiudadMejorConectada
int RedCiudades::CiudadMejorConectada(){
  int mejor=0, conexiones_mejor=-1, conexiones_ciudad;
  for (int i=1; i<=NumCiudades(); i++){ //Para cada ciudad
    conexiones_ciudad = 0;              //Pongo contador a 0
    for(int j=1; j<=NumCiudades(); j++) //Busco ciudades conectadas
      conexiones_ciudad += EstanConectadasDirectamente(i, j) ? 1 : 0;
    //Si esta ciudad tiene más conexiones que el máximo provisional,
    //actualizo el máximo
    if (conexiones_ciudad > conexiones_mejor){
      mejor = i;
      conexiones_mejor = conexiones_ciudad;
    }
  }
  return mejor;
}

// Método EstanConectadasDirectamente

bool RedCiudades::EstanConectadasDirectamente(const int c1, const int c2)const{
  return (Distancia(c1, c2)!=0);
}

//4.2 Método MejorEscalaEntre
//Estamos suponiendo que las ciudades no están conectadas directamente
//y, por lo tanto, no lo comprobamos en el método
//En cualquier caso, como el mapa de distancias tiene 0 en la diagonal principal
//el algoritmo funciona correctamente aunque las ciudades estén conectadas
int RedCiudades::MejorEscalaEntre(const int c1, const int c2){
  int mejor = -1;
  double coste_ciudad, coste_mejor=DBL_MAX;
  //Recorro las ciudades de la red
  for (int i=1; i<=NumCiudades(); i++){
    //Si la ciudad i está conectada con c1 y con c2
    if (EstanConectadasDirectamente(c1,i) && EstanConectadasDirectamente(i,c2)){
      //Sumamos las distancias
      coste_ciudad = Distancia(c1, i) + Distancia(i, c2);
      // Comparamos con el mejor provisional
      if (coste_ciudad < coste_mejor){
        coste_mejor = coste_ciudad;
        mejor = i;
      }
    }
  }
  return mejor;
}
