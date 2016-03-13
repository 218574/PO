#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz {
    Wektor wiersz[ROZMIAR];   //konstruktor Wektor'a zeruje
  public:
    Macierz(); // konstruktor -> zastepcze rozwiazanie dla wpisywania danych
};


/* Przeciazenie wczytywania danych do obiektu typu Macierz
 * Funkcja pobiera z wejscia standardowego wyrazenie
 *  w formacie Wektor >> Wektor >> Wektor korzystajac
 *  z zawartego w pliku Wektor.hh przeciazenia
 *  operatora wczytywania danych dla obiektow typu Wektor
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);  //do zrobienia!


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);  // do zrobienia!


/* Przeciazenie operatora mnozenia dla obiektow typu Macierz i Wektor
 * Zwraca wynik mnozenia:
 *                         [a00 a01 a02]
 * [x' y' z'] =  [x y z] * |a10 a11 a12|
 *                         [a20 a21 a22]
 * Dziala dla dowolnego rozmiaru - nie jest konieczne sprawdzanie
 *  wymiarow, poniewaz macierz sklada sie z odpowiedniej liczby kolumn
 *  o wysokosci rownej dlugosci wektora.
 */
Wektor operator * (Macierz mac, Wektor wekt);

#endif
