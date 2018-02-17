/* Práctica 3
Carlos Sánchez Páez 1ºD2 2016/2017 */
/********IMPLEMENTACIÓN***********/
#include "HerramientasNotas.h"

void SwapRegAlumno (RegAlumno &uno, RegAlumno &otro){
  RegAlumno aux;
  aux=uno;
  uno=otro;
  otro=aux;
}
void SwapDouble(double &una,double &otra){
  double aux;
  aux=una;
  una=otra;
  otra=aux;
}
void LeePesos(double ponderaciones[],int num_pesos){
  cout<<MSG_PESOS<<endl;
  for(int i=0;i<num_pesos;i++)
    cin>>*(ponderaciones+i);
}
bool CorrectosPesos(double ponderaciones[],int num_pesos){
  int suma=0;
  for(int i=0;i<num_pesos;i++)
    suma+=*(ponderaciones+i);
  return suma==100;
}
void MuestraPesos(double ponderaciones[],int num_pesos){
  for(int i=0;i<num_pesos;i++)
    cout<<"Ponderacion numero "<<i<<": "<<*(ponderaciones+i)<<"%"<<endl;
}
void LeerAlumnos(RegAlumno datos[],int alumnos_max,int tam_nom,int &num_alumnos,int max_notas){
  int j;                //Contador
  cout<<MSG_DATOS<<endl<<endl;
  /***Lectura adelantada***/
  cout<<MSG_NOMBRE<<endl;
  cin.ignore();
  cin.getline(datos[num_alumnos].apellido_nombre,tam_nom);
  /***********************/
  while(num_alumnos<alumnos_max && datos[num_alumnos].apellido_nombre[0]!=FIN){
    /***Lectura de notas***/
    cout<<MSG_NOTAS<<endl;
    for(j=0;j<max_notas;j++)
      cin>>datos[num_alumnos].notas[j];
    /*********************/
    num_alumnos++;          //Aumentamos el contador
    //Volvemos a leer el nombre
    cout<<MSG_NOMBRE<<endl;
    cin.ignore();
    cin.getline(datos[num_alumnos].apellido_nombre,tam_nom);
  }
}
double CalculaMediaAlumno(double *notas,double *pesos,double num_notas){
  double media=0;
  for(int i=0;i<num_notas;i++)
    media+=(notas[i]*pesos[i])/100;
  return media;
}
void MuestraAlumnos(RegAlumno datos[],double *calificacion_media,int num_alumnos){
  int i;
  for(i=0;i<num_alumnos;i++)
    cout<<"Apellidos y nombre: "<<datos[i].apellido_nombre<<endl<<
    "Nota media: "<<calificacion_media[i]<<endl;
}
void OrdenaVectorMediasAscendentes(RegAlumno *vector,double *medias,int alumnos){
  int i,j;
  for(i=0;i<alumnos;i++)
    for(j=0;j<alumnos-i-1;j++)
      if(medias[j]>medias[j+1]){
        SwapRegAlumno(vector[i],vector[i+1]);
        SwapDouble(medias[j],medias[j+1]);
      }
}
void MuestraAlumnosIntervalo(RegAlumno datos[],double *calificacion_media,int num_alumnos,int inf,int sup){
  int i;
  for(i=0;i<num_alumnos;i++)
    if(calificacion_media[i]>=inf && calificacion_media[i]<=sup)
      cout<<"Apellidos y nombre: "<<datos[i].apellido_nombre<<endl<<
      "Nota media: "<<calificacion_media[i]<<endl;
}
