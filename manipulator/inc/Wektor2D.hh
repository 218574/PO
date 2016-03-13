#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>


/*!
 * \file
 * \brief Definicja klasy Wektor 2D
 *
 *  Plik zawiera definicje klasy Wektor 2D
 *  skladajaca sie z 2 zmiennych typu float 
 */
class Wektor2D {
  float _wspol[2];
  public:
  float operator [] (int i) const {return _wspol[i];}                           
  float &operator [] (int i)  {return _wspol[i];}  
  Wektor2D operator + (const Wektor2D &Wektor) const;
};

/*!
 * \brief Przeciazenie strumienia wejscia  dla typu Wektor2D
 * pozwala na wczytanie wspolrzednych do klasy Wektor2D
 */
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

/*!
 * \brief Przeciazenie strumiena wyjscia dla typu Wektor2D
 * pozwala na wyswietlenie wspolrzednych z klasy Wektor2D
 */
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);

#endif
