/* Práctica 3
Carlos Sánchez Páez 1ºD2 2016/2017 */
/********PROTOTIPOS***********/
#include <iostream>
#include <cstring>
using namespace std;

#ifndef NOTAS_H
#define NOTAS_H

const string MSG_PESOS="Introduzca los cuatro pesos de las calificaciones (porcentajes):",MSG_DATOS="Introduzca los datos del alumno:",
MSG_NOMBRE="Introduzca apellidos y nombre:",MSG_NOTAS="Introduzca las cuatro calificaciones",MSG_O="Los alumnos ordenados de forma ascendente segun su media son:",
MSG_A="Alumnos con una nota en el intervalo ",DP=":",G="-";
const int NUM_NOTAS=4,TAM_NOMBRE=80,ALUMNOS_MAX=100;
const char FIN='*';

struct RegAlumno{
  double notas[NUM_NOTAS];
  char apellido_nombre[TAM_NOMBRE];
};
void LeePesos(double ponderaciones[],int num_pesos);
bool CorrectosPesos(double ponderaciones[],int num_pesos);
void MuestraPesos(double ponderaciones[],int num_pesos);
void LeerAlumnos(RegAlumno datos[],int alumnos_max,int tam_nom,int &num_alumnos,int max_notas);
double CalculaMediaAlumno(double *notas,double *pesos,double num_notas);
void MuestraAlumnos(RegAlumno datos[],double *calificacion_media,int num_alumnos);
void OrdenaVectorMediasAscendentes(RegAlumno *vector,double *medias,int alumnos);
void MuestraAlumnosIntervalo(RegAlumno datos[],double *calificacion_media,int num_alumnos,int inf,int sup);

#endif
