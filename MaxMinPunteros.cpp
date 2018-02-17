/*Máximo y mínimo en un vector. Punteros*/
#include <iostream>
using namespace std;
int main(){
	const int CAP=10;
	int vector[CAP]={90,40,30,20,50,70,60,80,10,100};
	int *ptrMax,*ptrMin;
	ptrMax=vector;
	ptrMin=vector;
	for(int i=0;i<CAP;i++){
		if(*(vector+i)>*ptrMax)
			ptrMax=vector+i;
		if(*(vector+i)<*ptrMin)
			ptrMin=vector+i;
	}
	cout<<"Valor maximo: "<<*ptrMax<<" direccion en memoria: "<<ptrMax<<endl;
	cout<<"Valor minimo: "<<*ptrMin<<" direccion en memoria: "<<ptrMin<<endl;
}
