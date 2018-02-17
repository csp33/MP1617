#Makefile para la Práctica 2. 
#Carlos Sánchez Páez 1ºD2. 2016/2017

#Definición de etiquetas
BIN=./bin
OBJ=./obj
SRC=./src
INCLUDE=./include
LIB=./lib
FLAG=c++0x

all : PosicionPrimerBlanco SaltaPrimeraPalabra DemosCadenasClasicas

PosicionPrimerBlanco :
	@echo Generando ejecutable...
	g++ -o $(BIN)/PosicionPrimerBlanco $(SRC)/PosicionPrimerBlanco.cpp

SaltaPrimeraPalabra : 
	@echo Generando ejecutable...
	g++ -o $(BIN)/SaltaPrimeraPalabra $(SRC)/SaltaPrimeraPalabra.cpp

DemosCadenasClasicas : $(OBJ)/DemosCadenasClasicas.o $(OBJ)/MiCadenaClasica.o $(INCLUDE)/MiCadenaClasica.h
	@echo Generando ejecutable...
	g++ -o $(BIN)/DemosCadenasClasicas $(OBJ)/DemosCadenasClasicas.o $(OBJ)/MiCadenaClasica.o -I$(INCLUDE) -std=$(FLAG)

$(OBJ)/DemosCadenasClasicas.o : $(SRC)/DemosCadenasClasicas.cpp $(INCLUDE)/MiCadenaClasica.h
	@echo Generando código objeto final...
	g++ -o $(OBJ)/DemosCadenasClasicas.o -c $(SRC)/DemosCadenasClasicas.cpp -I$(INCLUDE) -std=$(FLAG)
	
$(OBJ)/MiCadenaClasica.o : $(SRC)/MiCadenaClasica.cpp $(INCLUDE)/MiCadenaClasica.h
	@echo Generando código objeto intermedio...
	g++ -o $(OBJ)/MiCadenaClasica.o -c $(SRC)/MiCadenaClasica.cpp -I$(INCLUDE) -std=$(FLAG)

clean : 
	@echo Eliminando archivos objeto...
	rm $(OBJ)/*.o
mrproper : clean
	@echo Eliminando ejecutables y códigos objeto...
	rm $(BIN)/*


