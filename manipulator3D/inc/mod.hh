#include <list>

using namespace std;

/*!
 * \file  mod.hh
 *
 *  Plik zawierajacy klase Modyfikacja
 *
 */

class Modyfikacja
{
    /*!
     * \brief W klasie zawarta jest lista Prostopadloscianu
     * float a,b,c
     *
     *
     *
     */
  list<Prostopadloscian> lista;
  float a;
  float b;
  float c;
public:
  /*!
   * \brief Zakres publiczny klasy
   *
   * zawarta jest tutaj deklaracja funkcji obroc
   *
   */
  void obroc();


};
