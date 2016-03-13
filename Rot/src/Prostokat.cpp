#include "Prostokat.hh"

using namespace std;

ostream & operator << (ostream & Strumien, const Prostokat & Prostokat)
{
    Strumien << Prostokat[0] << Prostokat[1] << Prostokat[2] << Prostokat[3];
    return Strumien;
}


void Prostokat::operator + (Wektor2D x) // Przesuwanie prostokata o zadany wektor
    {
        Punkt[0] = Punkt[0] + x;
        Punkt[1] = Punkt[1] + x;
        Punkt[2] = Punkt[2] + x;
        Punkt[3] = Punkt[3] + x;
    }
