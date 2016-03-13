CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__start__: manipulator_3D
	./manipulator_3D

manipulator_3D: obj obj/main.o obj/manipulator.o obj/point.o obj/Macierz3x3.o obj/Parawan.o obj/Prostopadloscian.o obj/Menu.o obj/Obiekt.o obj/lacze_do_gnuplota.o 
	g++ -Wall -pedantic -std=c++0x -o manipulator_3D obj/main.o obj/manipulator.o\
                        obj/point.o obj/Macierz3x3.o obj/Parawan.o obj/Obiekt.o obj/Prostopadloscian.o obj/Menu.o obj/lacze_do_gnuplota.o

obj:
	mkdir obj
obj/main.o: src/main.cpp inc/lacze_do_gnuplota.hh 
	g++  -Iinc -W -Wall -pedantic -c -o obj/main.o src/main.cpp

obj/lacze_do_gnuplota.o: src/lacze_do_gnuplota.cpp inc/lacze_do_gnuplota.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/manipulator.o: src/manipulator.cpp inc/manipulator.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/manipulator.o src/manipulator.cpp

obj/point.o: src/point.cpp inc/point.hh
	g++  -Iinc -W -Wall -pedantic -c -o obj/point.o src/point.cpp

obj/Macierz3x3.o: src/Macierz3x3.cpp inc/Macierz3x3.hh
	g++ -Iinc -W -Wall -pedantic -c -o obj/Macierz3x3.o src/Macierz3x3.cpp
	
obj/Parawan.o: src/Parawan.cpp inc/Parawan.hh
	g++ -Iinc -W -Wall -pedantic -c -o obj/Parawan.o src/Parawan.cpp
	
obj/Obiekt.o: src/Obiekt.cpp inc/Obiekt.hh
	g++ -Iinc -W -Wall -pedantic -c -o obj/Obiekt.o src/Obiekt.cpp
	
obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh
	g++ -Iinc -W -Wall -pedantic -c -o obj/Prostopadloscian.o src/Prostopadloscian.cpp
	
obj/Menu.o: src/Menu.cpp inc/Menu.hh
	g++ -Iinc -W -Wall -pedantic -c -o obj/Menu.o src/Menu.cpp




clean:
	rm -f obj/*.o manipulator_2D
