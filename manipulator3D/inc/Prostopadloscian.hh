#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH
#include "Obiekt.hh"
#include "point.hh"
#include <vector>
#include <string>

using namespace std;
/*!
 * \file  Prostopadloscian.hh
 *
 * Plik zawierajacy klase Prostopadloscian
 *
 */

/*!
 * \brief Klasa prostopadloscian dziedziczy klase obiekt
 *
 *
 *
 */
class Prostopadloscian : public Obiekt{

    /*!
     * \brief W prywatnym zakresie klasy mamy stworzony wektor Pkt
     *oraz string nazwe
     *
     *
     */
private:
  vector<Point> Pkt;
  string nazwa;
public:
  /*!
   * \brief w prywatnym zakresie mamy konstruktor Prostopadloscian
   *
   * abstrakcyjne funkcje czytajace posture,zapis pliku ,wziecie nazwy oraz wziecie typu
   *
   */
  Prostopadloscian(string plik);



  virtual void read_posture(string plik);
  
  virtual void ZapisDoPliku(string plik);
  
  virtual string getName(){
    return nazwa;
  }
  
  virtual string getType(){
    return "Prostopadloscian";
  }
  
private:
  virtual void initVector();
};

#endif
