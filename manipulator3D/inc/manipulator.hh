#ifndef MANIPULATOR_HH
#define MANIPULATOR_HH

#include <vector>
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "point.hh"

using namespace std;
/*!
 * \file manipulator.hh
 *
 *  Plik zawiera definicj� klasy manipulator realizujaca Wczytywanie postury pliku,zapis do pliku,przeliczenie wspolrzednych manipulatora
 * wypisanie punktow translacji
 *
 */


/*!
 * \brief Klasa manipulator
 *
 *
 *
 */

class Manipulator{
private:
    /*!
     * \brief Prywatny zakres
     *W prywatnym zakresie zawiera vector czescie, vector szkrzydlo i vector punkt
     * stringa nazwe manipulatora
     * wskaznik na translacje
     * obliczenie punktu
     */
  vector<double> czesc;
  vector<double> skrzydlo;
  vector<Point> points;
  
  string name_manipulator;
		int type;

  Point *translacja;
  double qr;
  
  /*!
   * \brief W publicznym zakresie klasy
   *
   * w publicznym zakresie klasy zawiera oznaczenia translacji i rotacji
   * manipulator o argumentach string plik
   * wywolanie funkcji czytajacej posture
   * wywolanie funkcji nazw\return zwracajaca nazwe manipulatora
   * wywolanie funkcji wyboru typy \return zwracajaca stringa ktory ma uwzglednic typ rotacji
   * wywolanie funkcji wypisz ktora ma wypusac punkty rotacji uwzglednionym w petli for
   *
   */
public:
  static const int TRANS = 0;
  static const int ROT = 1;
  
  Manipulator(string plik, int type);
  
  void read_posture(string plik);
  
  string getName(){
    return name_manipulator;
  }
  
  string getType(){
    return string("\t<- Manipulator (przeguby ") + string(((type == ROT)? "rotacyjne)" : "translacyjne)"));
  }
  
  void wypisz(){
    for (size_t i = 0; i < points.size(); i++){
     cout<<i<<points[i].getX()<<points[i].getY()<<points[i].getZ()<<endl;

    }
  }
  /*!
   * \brief funkcja zapisu pliku
   *
   * o argumencie string f
   *
   */
  void ZapisDoPliku(string f);
  
private:
  void oblicz_pkt();
  double skrzydlo_sum(size_t n);   /*! suma katow*/
};
#endif
