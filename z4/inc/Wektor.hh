#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>

#define TYP float

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
    TYP wsp[ROZMIAR];    //punkt
public:
    Wektor();   //konstruktor
};


/*  Funkcja pobiera dwa punkty typu Wektor
 *  Zwraca odleglosc miedzy nimi w typie double
 *  Korzysta ze wzoru: d = sqrt((xb-xa)^2+(yb-ya)^2+...+(nb-na)^2)
 *  Dziala zarowno dla drugiego jak i trzeciego wymiaru
 *  Nalezy pamietac ze zwrocona wartosc bedzie minimalnie
 *   mniejsza od faktycznej ze wzgledu na skonczona dokladnosc
 *   typu double!
 */
double Dlugosc(Wektor A, Wektor B);

/* Funkcja pobiera trzy punkty typu Wektor A B i C
 * Zwraca true jesli kat miedzy prostymi AB i BC jest prosty
 *  w przeciwnym wypadku zwroci false
 * Funkcja wykorzystuje rownanie pitagorasa
 * Funkcja nie pierwiastkuje i nie dzieli wartosci
 *  powinna byc wiec odporna na zmiany wartosci
 *  ze wzgledu na dokladnosc typu double
 */
bool KatProsty(Wektor A, Wektor B, Wektor C);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */

 //z racji wszechstronnosci iostream'u to przeciazenie chwyci dowolny typ danych
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
