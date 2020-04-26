TRGDIR=./
OBJ=./obj
FLAGS= -Wall -pedantic -std=c++14 -iquote inc


__START__: ${OBJ} ${OBJ}/main.o ${OBJ}/LZespolona.o ${OBJ}/CWektor.o ${OBJ}/CMacierzKw.o
	g++ -o ${TRGDIR}/uklad_rownan ${OBJ}/main.o ${OBJ}/LZespolona.o ${OBJ}/CWektor.o ${OBJ}/CMacierzKw.o

${OBJ}:	
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/LZespolona.hh inc/SWektor.hh inc/SMacierzKw.hh 
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/LZespolona.o: inc/LZespolona.hh src/LZespolona.cpp
	g++ -c ${FLAGS} -o ${OBJ}/LZespolona.o src/LZespolona.cpp

${OBJ}/CWektor.o: inc/LZespolona.hh inc/SWektor.hh src/SWektor.cpp src/CWektor.cpp
	g++ -c ${FLAGS} -o ${OBJ}/CWektor.o src/CWektor.cpp

${OBJ}/CMacierzKw.o: inc/LZespolona.hh inc/SWektor.hh inc/SMacierzKw.hh src/SMacierzKw.cpp src/CMacierzKw.cpp 
	g++ -c ${FLAGS} -o ${OBJ}/CMacierzKw.o src/CMacierzKw.cpp

