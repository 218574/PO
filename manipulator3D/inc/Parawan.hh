#ifndef PARAWAN_HH
#define PARAWAN_HH

#include "Obiekt.hh"
#include "point.hh"
#include <vector>

using namespace std;

/*!
 * \file  Parawan.hh
 *
 *  Plik zawierajacy klase Parawan
 *
 */
/*!
 * \brief Wykorzystanie dziedziczenia na obszar publiczny
 *
 *
 *
 */
class Parawan : public Obiekt{
private:
    /*!
     * \brief w prywatnym zakresie mamy stworzony wektor Pkt
     *
     * i string nazwe
     *
     */
  vector<Point> Pkt; /*! \brief Tworzenie wektora Pkt */
  string nazwa;
public:
  /*!
   * \brief w publicznym zakresie
   *
   * mamy konstruktor Parawan
   *abstrakcje czytajaca posture ,zapis do pliku, pobranie nazwyi pobranie typu
   */
  Parawan(string plik);
  virtual void read_posture(string plik);
  
  virtual void ZapisDoPliku(string plik);
  
  virtual string getName(){
    return nazwa;
  }
  
  virtual string getType(){
    return " Parawan";
  }
  
private:
  virtual void initVector();
};
#endif
