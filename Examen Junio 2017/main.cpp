#include <iostream>
#include <limits>
#include "RedCiudades.hpp"

int main(int argc, const char * argv[]) {
  int mejor_conexion;
  
  if (argc !=2){
    cerr << "Error de uso" << endl;
    cerr << "Uso: " << argv[0] << " fichero" << endl;
    return(1);
  }
  else{
  
    RedCiudades red(argv[1]);

    for(int i=1; i<=red.NumCiudades(); i++)
      for(int j=i+1; j<=red.NumCiudades(); j++){
        
        if (!red.EstanConectadasDirectamente(i, j)){
          mejor_conexion = red.MejorEscalaEntre(i, j);

          cout << "Las ciudades " << i << " y " << j
               << " no están conectadas. " << endl;
          if (mejor_conexion != -1)
            cout << "La mejor conexión entre ellas con una sola ciudad "
                 << "intermedia es la ciudad " << mejor_conexion
                 << " (" << red.NombreCiudad(mejor_conexion) << ")" <<endl;
          else
            cout << "No existe conexión entre ellas "
                 << "con una sola ciudad intermedia" << endl;
        }
      }
    return (0);
  }
}
 
