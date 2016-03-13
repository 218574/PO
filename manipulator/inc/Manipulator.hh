#ifndef INC_MANIPULATOR_HH
#define INC_MANIPULATOR_HH_
#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
/*!
 * \file
 * \brief Plik naglowkowy definiujacy pojecie Manipulatora
 */

class Manipulator
{
  vector<double> angle;
  vector<double> length;
  vector<Wektor2D> coor;
  
public:
  /*!
   * funkcja wczytuje katy z pliku
   */
  void WczytajK(const char*NazwaPliku);
  /*!           
   * funkcja wczytuje dlugosci ogniw z pliku
   */
  void WczytajD(const char* NazwaPliku);
  /*!
   * funkcja wyznacza wspolrzedne przegubow
   */
  void WyznaczWsp();
  /*!
   * funkcja zwraca liczbe ogniw
   */
  int Rozmiar()const { return length.size(); }
  
  const vector<Wektor2D>& wczytajcoor() const { return coor; }
};

/*!
 * przeciazenie strumienia wyjscia 
 * pozwalajace wypisac wszystkie wspolrzedne przegubow
 */
ostream& operator << (ostream& Strm,const Manipulator& Zm);


#endif
