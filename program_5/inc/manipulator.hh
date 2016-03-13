#ifndef INC_MANIPULATOR_HH_
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
private:
  vector<double> dlugosc;
  vector<double> katy;
  vector<Wektor2D> Wspolrzedne;
  
public:
  /*!
   * funkcja wczytuje katy z pliku o zadanej nazwie
   */
  void wczytajKaty(const char*nazwaPliku);
  /*!           
   * funkcja wczytuje dlugosci ogniw z pliku o zadanej nazwie
   */
  void wczytajDlugosci(const char* nazwaPliku);
  /*!
   * funkcja wyznacza wspolrzedne przegubow
   */
  void wyznaczWspolrzedne();
  /*!
   * funkcja zwraca liczbe ogniw
   */
  int rozmiar()const 
  { 
    return dlugosc.size(); 
  }
  
  const vector<Wektor2D>& getWspolrzedne() const { return Wspolrzedne; }
};

/*!
 * przeciazenie pozwalajace wypisywanie wszystkich wspolrzednych przegubow
 */
ostream& operator << (ostream& Strm,const Manipulator& Zmn);


#endif /* INC_MANIPULATOR_HH_ */
