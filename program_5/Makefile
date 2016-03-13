APP=manipulator
 

all: obj/start.o obj/start.o obj/lacze_do_gnuplota.o obj/manipulator.o obj/Wektor2D.o obj/Macierz2x2.o
	g++ -o ./${APP} obj/start.o obj/lacze_do_gnuplota.o obj/manipulator.o obj/Wektor2D.o obj/Macierz2x2.o


obj/start.o: src/start.cpp inc/lacze_do_gnuplota.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/start.o src/start.cpp
	
obj/manipulator.o: src/manipulator.cpp inc/manipulator.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/manipulator.o src/manipulator.cpp
	
obj/Macierz2x2.o: src/Macierz2x2.cpp inc/Macierz2x2.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/Macierz2x2.o src/Macierz2x2.cpp
	
obj/Wektor2D.o: src/Wektor2D.cpp inc/Wektor2D.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/Wektor2D.o src/Wektor2D.cpp

obj/lacze_do_gnuplota.o: src/lacze_do_gnuplota.cpp inc/lacze_do_gnuplota.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp


clean:
	rm -f obj/* ./${APP} core.* core