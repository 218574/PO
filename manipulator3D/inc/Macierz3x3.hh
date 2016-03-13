#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH
#include <iostream>
using namespace std;


/*!
 * \file  Macierz3x3.hh
 *
 *  Plik zawiera definicj� klasy Macierz3x3
 *
 *
 */

class Macierz3x3 {

    /*!
     * \brief  W publicznym obszarze mamy macierz tablice2x2 macierzy
 * double katX,katY,katZ
 * argumenty void dla setX(), setY(),set(Z)
     *
     *typ zwracany double o argumentach int Wie, int Kol
     *
     */
public:
double M[3][3];
double katX;
double katY;
double katZ;
void setX();
void setY();
void setZ();

double  operator() (int Wie, int Kol);
};
/*!
 * \brief  Przeciazenie operatora
*
* argumenty const Macierz 3x3 Mac
 *
 *
 *
 */
ostream &operator << (ostream &Strm, const Macierz3x3 Mac);

#endif
