#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__start__: obroty
	./obroty

obroty: obj obj/main.o obj/Prostokat.o obj/Macierz.o obj/Wektor.o\
           obj/lacze_do_gnuplota.o
	g++ -Wall -pedantic -std=c++11 -o obroty obj/main.o obj/Wektor.o\
                        obj/Macierz.o obj/Prostokat.o obj/lacze_do_gnuplota.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/Prostokat.hh inc/Macierz.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Prostokat.o: src/Prostokat.cpp inc/Prostokat.hh
	g++ -c ${CXXFLAGS} -o obj/Prostokat.o src/Prostokat.cpp

obj/Macierz.o: src/Macierz.cpp inc/Macierz.hh 
	g++ -c ${CXXFLAGS} -o obj/Macierz.o src/Macierz.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh inc/rozmiar.h
	g++ -c ${CXXFLAGS} -o obj/Wektor.o src/Wektor.cpp

clean:
	rm -f obj/*.o obroty