#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH


#include <iostream>
#include "Wektor2D.hh"

/*!
 * \file
 * \brief Plik zawiera definicje klasy Macierz 2x2
 * 
 */
class Macierz2x2 {
  /*!
   *  \brief Modeluje pojecie Macierzy 2x2 przy pomocy zmiennych typu float
   */
  Wektor2D _elem[2];
public:
  float& operator () (int w,int k) {return _elem[w][k];}
  float operator () (int w,int k) const {return _elem[w][k];}
  Wektor2D operator * (const Wektor2D& Wektor) const;
};


/*
 * \brief Przeciazenie operatora wypisywania dla klasy Macierz
 */
std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac);

#endif
