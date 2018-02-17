/* Práctica 3
Carlos Sánchez Páez 1ºD2 2016/2017 */
/********MAIN***********/

#include <iostream>
#include "HerramientasNotas.h"
using namespace std;
const string MSG_ERR="Error. Los pesos no suman 100%",MSG_ER_A="Numero incorrecto de argumentos.",MSG_OR="Introduzca 1 para ver los alumnos ordenados y 2 para verlos por orden de introduccion:";
const int ORDEN=1,NO_ORDEN=2;

int main(int argc,char *argv[]){
  if(argc==3 || argc==1){
    double pesos[NUM_NOTAS];
    RegAlumno alumnos[ALUMNOS_MAX];
    double calificacion_media[ALUMNOS_MAX];
    int num_alumnos=0;

    /***Leemos los pesos y comprobamos su validez***/
    LeePesos(pesos,NUM_NOTAS);
    if(!CorrectosPesos(pesos,NUM_NOTAS)){
      cout<<MSG_ERR<<endl;
      return 1;
    }
    /***Leemos los datos de cada alumno y almacenamos cuantos hay***/
    LeerAlumnos(alumnos,ALUMNOS_MAX,TAM_NOMBRE,num_alumnos,NUM_NOTAS);
    /***Calculamos la media de cada alumno***/
    for(int i=0;i<num_alumnos;i++)
      calificacion_media[i]=CalculaMediaAlumno(alumnos[i].notas,pesos,NUM_NOTAS);

    int opcion;
    cout<<MSG_OR<<endl;
    do{
      cin>>opcion;
    }while(opcion!=ORDEN && opcion!=NO_ORDEN);

    if(opcion==ORDEN){
      OrdenaVectorMediasAscendentes(alumnos,calificacion_media,num_alumnos);
      if(argc==1){  //Sin argumentos
        cout<<endl<<endl<<MSG_O<<endl<<endl;
        MuestraAlumnos(alumnos,calificacion_media,num_alumnos);
      }
      else {      //Dos Argumentos
        int inf=atoi(argv[1]),sup=atoi(argv[2]);
        cout<<MSG_A<<inf<<G<<sup<<DP<<endl;
        MuestraAlumnosIntervalo(alumnos,calificacion_media,num_alumnos,inf,sup);
      }
    }
  else
    MuestraAlumnos(alumnos,calificacion_media,num_alumnos);
  }
  else{
    cout<<MSG_ER_A<<endl;
    return 1;
  }
}
