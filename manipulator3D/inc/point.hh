#ifndef POINT_HH
#define POINT_HH

#define _USE_MATH_DEFINES
#include <math.h>

#include "Macierz3x3.hh"


/*!
 * \file  Point.hh
 *
 * Plik zawierajacy definicje klasy punkt, ktora ma za zadanie udostepnienia operacji na obiektach
 *
 */


class Point{
private:			/*! \brief Wspolrzedne x y z*/
  double x_val;
  double y_val;
  double z_val;
  
public:
  /*!
   * \brief W publicznym zakresie mamy:
   *
   * konstruktor tworzacy x wartosci y wartosci z wartosci
   *
   */
  Point() : x_val(0.0), y_val(0.0), z_val(0.0) {}
  Point(double x, double y, double z) : x_val(x), y_val(y), z_val(z) {}
  
  /*!\brief Przeciazenie operatora dodawania dla translacji*/
 
 Point operator+(Point const& other){
    return Point(this->x_val + other.x_val, this->y_val + other.y_val, this->z_val + other.z_val);
  }

  /*!\brief Przeciazenie operatora mnozenia dla dlugosci ramion*/
 

 Point operator*(double length){
    return Point(this->x_val * length, this->y_val * length, this->z_val*length);
  }
  
  Point operator * (Macierz3x3 M){

    /*! \brief Zmienne zastepcze, nie nadpisywac tych co byly*/

    double wx = this->getX();
    double wy = this->getY();
			double wz = this->getZ();
			
			return Point(wx*M(0, 0) + wy*M(0, 1) + wz*M(0, 2), wx*M(1, 0) + wy*M(1, 1) + wz*M(1, 2), wx*M(2, 0) + wy*M(2, 1) + wz*M(2, 2));
  }
  
  
  double getX()
  {
    return x_val;
  }
  double getY()
		{
		  return y_val;
		}
  double getZ()
  {
    return z_val;
  }
};

#endif
