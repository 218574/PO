#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <cmath>

using namespace std;

class Wektor2D
{
    double _Wektor[2];      // tablica do przechowywania wspolrzednych wektora

public:

    double operator [] (int Ind) const
    {
        return _Wektor[Ind];
    }

    double & operator [] (int Ind)
    {
        return _Wektor[Ind];
    }

  Wektor2D() // Przeciazenie wektora zerami
    {
        _Wektor[0]=0;
        _Wektor[1]=0;
    }

    Wektor2D(double x, double y)
    {
        _Wektor[0]=x;
        _Wektor[1]=y;
    }

  double operator * (Wektor2D x) // Przeciazenie operacji mnozenia wektorow
    {
        return x[0]*_Wektor[0] + x[1]*_Wektor[1];
    }

  Wektor2D operator + (Wektor2D x) // Przeciazenie operacji dodawania wektorow
    {
        return Wektor2D(_Wektor[0] + x[0], _Wektor[1] + x[1]);
    }

  double operator & (Wektor2D x) // Przeciazenie badania odleglosci wektorow
    {
        return sqrt((_Wektor[0] - x[0])*(_Wektor[0] - x[0]) + (_Wektor[1] - x[1])*(_Wektor[1] - x[1]));
    }

};

istream & operator >> (istream & Strumien, Wektor2D & Wektor); // Przeciazenie operatora czytajacego wektor
ostream & operator << (ostream & Strumien, const Wektor2D & Wektor); // Przeciazenie operatora zapisujacego wektor

#endif
