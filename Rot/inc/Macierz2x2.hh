#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH


#include <iostream>
#include <cmath>
#include "Wektor2D.hh"

class Macierz2x2 // Klasa macierz do obracania o zadany kat
{
  Wektor2D Macierz[2];    //Tablica przechowyjaca macierz obrotu
  
  double kat_obrotu = 0; //Zmienna kat obrotu
public:
  
  void inicjuj_macierz(void); // inicjacja macierzy wartosciami sinus i cosinus
  
  Wektor2D  operator* (const Wektor2D Wektor) // Przeciazenie operatora mnozenia dla zainicjowanej  macierzy
  {
    inicjuj_macierz();
    return Wektor2D(Macierz[0]*Wektor, Macierz[1]*Wektor);
  }
  
  void czytaj_obrot (void); // Wczytywanie wartosci obrotu ze standardowego wejscia
  
};

#endif
