#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Macierz3x3.hh"

#define _USE_MATH_DEFINES
#include <math.h>


using namespace std;

/*!
 * \file  Macierz3x3.cpp
 *
 *  Plik zawiera funkcje macierzy 3x3 dla obrotu wokol zadanej osi oraz PRZECIAZENIE WYJSCIA DLA KLASY MACIERZ3X3
 *
 */


/*!
 * \brief Poczatek definicji funkcji operator(), bedacej metoda klasy Macierz3x3
 *
 * Typ zwraccanej wartosci double, argumentami sa int Wiersze i int Kolumna
 *
 * \return
 * Zwracamy Tablice Wierszy i Kolumn
 */
double Macierz3x3::operator()(int Wie, int Kol)
{
    return M[Wie][Kol];
}



/*!
 * \brief Poczatek definicji funkcji obroty wokol osi z
 *
 * Typ zwraccanej wartosci void,
 * Tworzy tablice macierzy 2x2 o wartosciach takich samych jak dla macierzy 2x2 tylko z dodatkowymi 3 wierszami jako wartosci 0
 * 0 1 . Argumentami jest tymczasowy wskaznik this na zadany kat
 * Od razu jest tutaj zaimplementowana funkcja zamieniajaca radniany na stopnie
 *
 */

void Macierz3x3::setZ()
    {
    M[0][0]=cos(this->katZ* (M_PI / 180.0));
    M[0][1]=-sin(this->katZ* (M_PI / 180.0));
    M[0][2]=0;
    M[1][0]=sin(this->katZ* (M_PI / 180.0));
    M[1][1]=cos(this->katZ* (M_PI / 180.0));
    M[1][2]=0;
    M[2][0]=0;
    M[2][1]=0;
    M[2][2]=1;
    }

/*!
 * \brief Poczatek definicji funkcji obroty wokol osi y
 *
 * Typ zwraccanej wartosci void,
 * Tworzy tablice macierzy 2x2 o wartosciach takich samych jak dla macierzy 2x2 tylko z dodatkowymi 3 wierszami jako wartosci 0
 * 0 1 . Argumentami jest tymczasowy wskaznik this na zadany kat
 * Od razu jest tutaj zaimplementowana funkcja zamieniajaca radniany na stopnie
 *
 */
    void Macierz3x3::setX()
	{
	M[0][0]=1;
    M[0][1]=0;
    M[0][2]=0;
    M[1][0]=0;
    M[1][1]=cos(this->katX* (M_PI / 180.0));
    M[1][2]=-sin(this->katX* (M_PI / 180.0));
    M[2][0]=0;
    M[2][1]=sin(this->katX* (M_PI / 180.0));
    M[2][2]=cos(this->katX* (M_PI / 180.0));
    }
    /*!
     * \brief Poczatek definicji funkcji obroty wokol osi y
     *
     * Typ zwraccanej wartosci void,
     * Tworzy tablice macierzy 2x2 o wartosciach takich samych jak dla macierzy 2x2 tylko z dodatkowymi 3 wierszami jako wartosci 0
     * 0 1 . Argumentami jest tymczasowy wskaznik this na zadany kat
     * Od razu jest tutaj zaimplementowana funkcja zamieniajaca radniany na stopnie
     *
     */
   void Macierz3x3::setY()
   {
    M[0][0]=cos(this->katY* (M_PI / 180.0));
    M[0][1]=0;
    M[0][2]=sin(this->katY* (M_PI / 180.0));
    M[1][0]=0;
    M[1][1]=1;
    M[1][2]=0;
    M[2][0]=-sin(this->katY* (M_PI / 180.0));
    M[2][1]=0;
    M[2][2]=cos(this->katY* (M_PI / 180.0));
    }



   /*!
    * \brief Przeciazenie wyjscia dla klasy macierz
    *
    * Przeciaznie operatora <<
    *
    *
    * \return Zwracamy Strm<<Mac
    *
    */
ostream& operator << (ostream &Strm, const Macierz3x3 Mac)
{
return Strm << Mac <<endl;
}

