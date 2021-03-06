#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include "Wektor2D.hh"

using namespace std;

class Prostokat // Klasa przechowywujaca dane o prostokacie
{
  Wektor2D Punkt[4] = {Wektor2D(10,10), Wektor2D(110,10), Wektor2D(110,60), Wektor2D(10,60)};   //Tablica 4 elementowa typu Wektor2D zainicjowana wartosciami
  
  
public:
  Wektor2D operator [] (int Indeks) const // Przeciazenie operatora indeksowania dla prostokata
  {
    return Punkt[Indeks];
  }
  Wektor2D & operator [] (int Indeks) // Przeciazenie operatora indeksowania dla Wektor2D
  {
    return Punkt[Indeks];
  }
  void operator + (Wektor2D x); // Przeciazenie operatora dodawania dla prostokata
};

ostream& operator << (ostream & Strumien, const Prostokat &Prostokat); // Przeciazenie operatora zapisu do strumienia dla prostokata

#endif
