#Makefile para la versión 3 del programa circulomedio. Se incluye información de depuración en el archivo final.
all : bin/central
#Definición de etiquetas
BIN=./bin
OBJ=./obj
SRC=./src
INCLUDE=./include
LIB=./lib
FLAG=c++0x

$(BIN)/central : $(OBJ)/central.o $(LIB)/libformas.a 
	@echo Enlazando...
	g++ -o $(BIN)/central $(OBJ)/central.o -lformas -L$(LIB)

$(OBJ)/central.o : $(SRC)/central.cpp $(INCLUDE)/punto.h $(INCLUDE)/circulo.h
	@echo Creando código objeto final...
	g++ -g -o $(OBJ)/central.o -c $(SRC)/central.cpp -I$(INCLUDE) -std=$(FLAG)

$(LIB)/libformas.a : $(OBJ)/punto.o $(OBJ)/circulo.o 
	@echo Generando biblioteca...
	ar rvs $(LIB)/libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o

$(OBJ)/punto.o : $(SRC)/punto.cpp $(INCLUDE)/punto.h
	@echo Generando código objeto intermedio...
	g++ -g -o $(OBJ)/punto.o -c $(SRC)/punto.cpp -I$(INCLUDE) -std=$(FLAG)

$(OBJ)/circulo.o : $(SRC)/circulo.cpp $(INCLUDE)/circulo.h
	@echo Generando código objeto intermedio...
	g++ -g -o $(OBJ)/circulo.o -c $(SRC)/circulo.cpp -I$(INCLUDE) -std=$(FLAG)
clean : 
	@echo Eliminando archivos objeto...
	rm $(OBJ)/*.o
mrproper : clean
	@echo Eliminando ejecutables y códigos objeto...
	rm $(BIN)/*
