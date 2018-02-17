
#include <iostream>
using namespace std;

#ifndef RedCiudades_hpp
#define RedCiudades_hpp

#define LONGITUD_CADENAS 100

struct  InfoCiudad {
  char *  nombre; // Nombre
  int poblacion;  // Num. habs.
};

class RedCiudades {
private:
  
  
  int num_ciudades; // Número de ciudades
  InfoCiudad * info; // info[i]: info de la ciudad i
  double ** distancia; // distancia[i][j]: distancia
  // entre las ciudades i y j
  
  //Métodos auxiliares privados
  void liberar_memoria();
  void reservar_memoria(int numero_ciudades);
  void copiar(const RedCiudades & otra);
  ifstream & abrir_fichero(const char * filename);
public:
  int NumCiudades() const;
  double Distancia(const int c1, const int c2) const;
  char * NombreCiudad(const int ciudad) const;
  int PoblacionCiudad(const int i) const;
  RedCiudades(); //Constructor por defecto
  ~RedCiudades(); //Destructor
  bool EstaVacia();
  RedCiudades(const RedCiudades &otra); //Constructor de copia
  RedCiudades& operator=(const RedCiudades &otra);
  friend istream & operator>>(istream & flujo, RedCiudades & red);
  RedCiudades(const char * filename);
  void LeerRedCiudades(const char * filename);
  void EscribirRedCiudades(const char * filename) const;
  int CiudadMejorConectada();
  bool EstanConectadasDirectamente(const int c1, const int c2)const;
  int MejorEscalaEntre(const int c1, const int c2);
};

ostream & operator<<(ostream & flujo, const RedCiudades & red);

#endif /* RedCiudades_hpp */
 
