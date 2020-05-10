TRGDIR=./
OBJ=./obj
FLAGS = -Wall -pedantic -std=c++14 -iquote inc

${TRGDIR}/zad3.out: ${OBJ} ${OBJ}/main.o ${OBJ}/wektor.o ${OBJ}/wektorC.o ${OBJ}/MacierzKw.o\
		${OBJ}/MacierzKwC.o ${OBJ}/Macierz3na3.o ${OBJ}/MacierzObrotu.o ${OBJ}/Wektor3D.o\
		${OBJ}/Bryla.o ${OBJ}/ObiektRysowalny.o ${OBJ}/Prostopadloscian.o\
		${OBJ}/InterfaceDrona.o ${OBJ}/Dron.o ${OBJ}/Dr3D_gnuplot_api.o
	g++ -o ${TRGDIR}zad3.out ${OBJ}/main.o ${OBJ}/wektor.o ${OBJ}/wektorC.o ${OBJ}/MacierzKw.o\
		${OBJ}/MacierzKwC.o ${OBJ}/Macierz3na3.o ${OBJ}/MacierzObrotu.o ${OBJ}/Wektor3D.o\
		${OBJ}/Bryla.o ${OBJ}/ObiektRysowalny.o ${OBJ}/Prostopadloscian.o\
		${OBJ}/InterfaceDrona.o ${OBJ}/Dron.o ${OBJ}/Dr3D_gnuplot_api.o -lpthread

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/wektor.o: src/wektor.cpp inc/wektor.h
	g++ -c ${FLAGS} -o ${OBJ}/wektor.o src/wektor.cpp

${OBJ}/wektorC.o: src/wektorC.cpp src/wektor.cpp 
	g++ -c ${FLAGS} -o ${OBJ}/wektorC.o src/wektorC.cpp

${OBJ}/MacierzKw.o: src/MacierzKw.cpp inc/MacierzKw.h
	g++ -c ${FLAGS} -o ${OBJ}/MacierzKw.o src/MacierzKw.cpp

${OBJ}/MacierzKwC.o: src/MacierzKwC.cpp src/MacierzKw.cpp
	g++ -c ${FLAGS} -o ${OBJ}/MacierzKwC.o src/MacierzKwC.cpp

${OBJ}/Macierz3na3.o: src/Macierz3na3.cpp inc/Macierz3na3.h
	g++ -c ${FLAGS} -o ${OBJ}/Macierz3na3.o src/Macierz3na3.cpp

${OBJ}/MacierzObrotu.o: src/MacierzObrotu.cpp inc/MacierzObrotu.h
	g++ -c ${FLAGS} -o ${OBJ}/MacierzObrotu.o src/MacierzObrotu.cpp

${OBJ}/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.h
	g++ -c ${FLAGS} -o ${OBJ}/Wektor3D.o src/Wektor3D.cpp

${OBJ}/Bryla.o: src/Bryla.cpp inc/Bryla.h
	g++ -c ${FLAGS} -o ${OBJ}/Bryla.o src/Bryla.cpp

${OBJ}/ObiektRysowalny.o: src/ObiektRysowalny.cpp inc/ObiektRysowalny.h
	g++ -c ${FLAGS} -o ${OBJ}/ObiektRysowalny.o src/ObiektRysowalny.cpp

${OBJ}/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.h
	g++ -c ${FLAGS} -o ${OBJ}/Prostopadloscian.o src/Prostopadloscian.cpp

${OBJ}/InterfaceDrona.o: src/InterfaceDrona.cpp inc/InterfaceDrona.h
	g++ -c ${FLAGS} -o ${OBJ}/InterfaceDrona.o src/InterfaceDrona.cpp

${OBJ}/Dron.o: src/Dron.cpp inc/Dron.h
	g++ -c ${FLAGS} -o ${OBJ}/Dron.o src/Dron.cpp

${OBJ}/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh\
		inc/Draw3D_api_interface.hh
	g++ -c ${FLAGS} -o ${OBJ}/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp


clear:
	rm -f ${TRGDIR}/zad3 ${OBJ}/*


run: ${TRGDIR}zad3.out
	${TRGDIR}zad3.out
