#Makefile
all: dzialania

dzialania: funkcje.o main.o
	g++ -Wall -pedantic -std=c++11 funkcje.o main.o -o dzialania.out

funkcje.o: funkcje.hh funkcje.cpp
	g++ -Wall -pedantic -std=c++11 funkcje.cpp -c

main.o: main.cpp
	g++ -Wall -pedantic -std=c++11 main.cpp -c
clean:
	rm -rf *o dzialania.out


