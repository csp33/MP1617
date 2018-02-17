# Práctica final
#Carlos Sánchez Páez 1ºD2 2016/2017
#############MAKEFILE#############

#Definición de etiquetas

BIN=./bin
OBJ=./obj
SRC=./src
INCLUDE=./include
INST=./instancias
LIB=./lib
FLAG=c++11
FIN="Fin del programa"
LISTA=lista.tsp
LS="Mostrando contenido del directorio $(BIN)"
VG=valgrind --leak-check=full --track-origins=yes

all : Programa
###################################

Programa : $(OBJ)/Programa.o $(OBJ)/Funciones.o $(OBJ)/Punto.o $(OBJ)/Problema.o $(OBJ)/Solucion.o $(INCLUDE)/Punto.h $(INCLUDE)/Problema.h $(INCLUDE)/Solucion.h $(INCLUDE)/Funciones.h
	@echo Generando ejecutable...
	g++ -o $(BIN)/Programa $(OBJ)/Programa.o $(OBJ)/Funciones.o $(OBJ)/Punto.o $(OBJ)/Solucion.o  $(OBJ)/Problema.o -I$(INCLUDE) -std=$(FLAG)


###################################

$(OBJ)/Punto.o : $(SRC)/Punto.cpp $(INCLUDE)/Punto.h
	@echo Generando código objeto...
	g++ -o $(OBJ)/Punto.o -c $(SRC)/Punto.cpp -I$(INCLUDE) -std=$(FLAG)

$(OBJ)/Problema.o : $(SRC)/Problema.cpp $(SRC)/Punto.cpp $(INCLUDE)/Punto.h $(INCLUDE)/Problema.h
	@echo Generando código objeto...
	g++ -o $(OBJ)/Problema.o -c $(SRC)/Problema.cpp -I$(INCLUDE) -std=$(FLAG)

$(OBJ)/Programa.o : $(SRC)/Programa.cpp $(OBJ)/Punto.o $(OBJ)/Problema.o $(OBJ)/Funciones.o $(INCLUDE)/Punto.h $(INCLUDE)/Problema.h $(INCLUDE)/Funciones.h
	@echo Generando código objeto...
	g++ -o $(OBJ)/Programa.o -c $(SRC)/Programa.cpp -I$(INCLUDE) -std=$(FLAG)

$(OBJ)/Solucion.o : $(SRC)/Solucion.cpp $(INCLUDE)/Solucion.h
	@echo Generando código objeto...
	g++ -o  $(OBJ)/Solucion.o -c $(SRC)/Solucion.cpp -I$(INCLUDE) -std=$(FLAG)

$(OBJ)/Funciones.o : $(SRC)/Funciones.cpp $(INCLUDE)/Problema.h $(INCLUDE)/Solucion.h $(INCLUDE)/Punto.h
	g++ -o $(OBJ)/Funciones.o -c $(SRC)/Funciones.cpp -I$(INCLUDE) -std=$(FLAG)

###################################
c10 : Programa copia
	@echo Ejecutando el programa con c10.tsp...
	cd $(BIN) ; ./Programa c10.tsp c10.sol ; echo $(FIN); rm *.tsp ; echo $(LS) ; ls

c29 : Programa copia
	@echo Ejecutando el programa con c29.tsp...
	cd $(BIN) ; ./Programa c29.tsp c29.sol ; echo $(FIN); rm *.tsp ; echo $(LS) ; ls

c52 : Programa copia
	@echo Ejecutando el programa con c52.tsp...
	cd $(BIN) ; ./Programa c52.tsp c52.sol ; echo $(FIN); rm *.tsp ; echo $(LS) ; ls

c100 : Programa copia
	@echo Ejecutando el programa con c100.tsp...
	cd $(BIN) ; ./Programa c100.tsp c100.sol ; echo $(FIN); rm *.tsp ; echo $(LS) ; ls

c150 : Programa copia
	@echo Ejecutando el programa con c150.tsp...
	cd $(BIN) ; ./Programa c150.tsp c150.sol ; echo $(FIN); rm *.tsp ; echo $(LS) ; ls

lista : Programa copia
	@echo Ejecutando el programa con el listado...
	cd $(BIN) ; ./Programa $(LISTA) ;  echo $(FIN) ; rm *.tsp ; echo $(LS) ; ls

###################################

clean_sol :
	@echo Eliminando soluciones...
	rm $(BIN)/*.sol
copia :
	@echo Copiando instancias...
	cp $(INST)/* $(BIN) ; cd $(BIN)

###################################

valgrind_c10 : Programa copia
	@echo Ejecutando Valgrind con c10.tsp...
	cd $(BIN) ; $(VG) ./Programa c10.tsp c10.txt ; rm *.tsp

valgrind_c29 : Programa copia
	@echo Ejecutando Valgrind con c129.tsp...
	cd $(BIN) ; $(VG) ./Programa c29.tsp c29.txt ; rm *.tsp

valgrind_c52 : Programa copia
	@echo Ejecutando Valgrind con c152.tsp...
	cd $(BIN) ; $(VG) ./Programa c52.tsp c52.txt ; rm *.tsp

valgrind_c100 : Programa copia
	@echo Ejecutando Valgrind con c100.tsp...
	cd $(BIN) ; $(VG) ./Programa c100.tsp c100.txt ; rm *.tsp

valgrind_c150 : Programa copia
	@echo Ejecutando Valgrind con c150.tsp...
	cd $(BIN) ; $(VG) ./Programa c150.tsp c150.txt ; rm *.tsp

valgrind_lista: Programa copia
	@echo Ejecutando Valgrind con lista.tsp...
	cd $(BIN) ; $(VG) ./Programa lista.tsp ; rm *.tsp

###################################

clean :
	@echo Eliminando objetos...
	rm $(OBJ)/*.o

mrproper : clean
	@echo Eliminando binarios...
	rm $(BIN)/*
