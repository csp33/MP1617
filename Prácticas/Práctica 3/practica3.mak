# Práctica 3
#Carlos Sánchez Páez 1ºD2 2016/2017
#######MAKEFILE##########

#Definición de etiquetas
BIN=./bin
OBJ=./obj
SRC=./src
INCLUDE=./include
LIB=./lib
FLAG=c++0x

all : PosMayor Ordena Alumnos

PosMayor : $(OBJ)/PosicionMayor.o $(OBJ)/HerramientasVectores.o $(INCLUDE)/HerramientasVectores.h
	@echo Generando ejecutable...
	g++ -o $(BIN)/PosMayor $(OBJ)/PosicionMayor.o $(OBJ)/HerramientasVectores.o -I$(INCLUDE) -std=$(FLAG)

$(OBJ)/PosicionMayor.o : $(SRC)/PosicionMayor.cpp $(INCLUDE)/HerramientasVectores.h
	@echo Generando código objeto final...
	g++ -o $(OBJ)/PosicionMayor.o -c $(SRC)/PosicionMayor.cpp -I$(INCLUDE) -std=$(FLAG)

Ordena : $(OBJ)/Ordena.o $(OBJ)/HerramientasVectores.o $(INCLUDE)/HerramientasVectores.h
	@echo Generando ejecutable...
	g++ -o $(BIN)/Ordena $(OBJ)/Ordena.o $(OBJ)/HerramientasVectores.o -I$(INCLUDE) -std=$(FLAG)

$(OBJ)/Ordena.o : $(SRC)/Ordena.cpp $(INCLUDE)/HerramientasVectores.h
	@echo Generando código objeto final...
	g++ -o $(OBJ)/Ordena.o -c $(SRC)/Ordena.cpp -I$(INCLUDE) -std=$(FLAG)


$(OBJ)/HerramientasVectores.o : $(SRC)/HerramientasVectores.cpp $(INCLUDE)/HerramientasVectores.h
		@echo Generando código objeto intermedio...
		g++ -o $(OBJ)/HerramientasVectores.o -c $(SRC)/HerramientasVectores.cpp -I$(INCLUDE) -std=$(FLAG)

Alumnos : $(OBJ)/alumnos.o $(OBJ)/HerramientasNotas.o $(INCLUDE)/HerramientasNotas.h
	@echo Generando ejecutable...
	g++ -o $(BIN)/Alumnos $(OBJ)/alumnos.o $(OBJ)/HerramientasNotas.o -I$(INCLUDE) -std=$(FLAG)

$(OBJ)/alumnos.o : $(SRC)/notas.cpp $(INCLUDE)/HerramientasNotas.h
	@echo Generando código objeto final...
	g++ -o $(OBJ)/alumnos.o -c $(SRC)/notas.cpp -I$(INCLUDE) -std=$(FLAG)

$(OBJ)/HerramientasNotas.o : $(SRC)/HerramientasNotas.cpp $(INCLUDE)/HerramientasNotas.h
	@echo Generando código objeto intermedio...
	g++ -o $(OBJ)/HerramientasNotas.o -c $(SRC)/HerramientasNotas.cpp -I$(INCLUDE) -std=$(FLAG)

clean :
		@echo Eliminando archivos objeto...
		rm $(OBJ)/*.o

mrproper : clean
		@echo Eliminando ejecutables y códigos objeto...
		rm $(BIN)/*
