TRGDIR=./
OBJ=./obj
FLAGS= -Wall -pedantic -std=c++14 -iquote inc


__START__: ${OBJ} ${OBJ}/main.o ${OBJ}/CWektor.o ${OBJ}/CMacierzKw.o
	g++ -o ${TRGDIR}/uklad_rownan ${OBJ}/main.o ${OBJ}/CWektor.o ${OBJ}/CMacierzKw.o

${OBJ}:	
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/SWektor.hh inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/CWektor.o: src/CWektor.cpp inc/SWektor.hh src/SWektor.cpp 
	g++ -c ${FLAGS} -o ${OBJ}/CWektor.o src/CWektor.cpp

${OBJ}/CMacierzKw.o: src/CMacierzKw.cpp inc/SMacierzKw.hh src/SMacierzKw.cpp 
	g++ -c ${FLAGS} -o ${OBJ}/CMacierzKw.o src/CMacierzKw.cpp
