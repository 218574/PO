#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include "rozmiar.h"
#include <iostream>


/* Rozklad katow:
 *  | 0 1 |
 *  | 2 3 |
 */
class Prostokat {
    Wektor Pkt[4];    //konstruktor Wektor'a zeruje!
public:
    void Obrot(Macierz obrot);   //do zrobienia!
    void Przesuniecie(Wektor przesun);
    void Wyswietl();
    bool Sprawdz();
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream& operator << ( std::ostream &Strm, const Prostokat &Pr);


#endif
