#include "Prostokat.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Prostokat, ktore zawieraja
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */


std::ostream& operator << ( std::ostream &Strm, const Prostokat &Pr)
{
  Strm << Pr[0] << Pr[1] << Pr[2] << Pr[3] << Pr[4] << Pr[5] << Pr[6] << Pr[7];
    return Strm;
}


void Prostokat::operator + (Wektor2D x)
    {
        Pkt[0] = Pkt[0] + x;
        Pkt[1] = Pkt[1] + x;
        Pkt[2] = Pkt[2] + x;
        Pkt[3] = Pkt[3] + x;
	Pkt[4] = Pkt[4] + x;
	Pkt[5] = Pkt[5] + x;
	Pkt[6] = Pkt[6] + x;
	Pkt[7] = Pkt[7] + x;
    }
