#include "Wektor.hh"
#include <iostream>
#include <math.h>

using namespace std;

void Wektor::Wektor()
{
    for(int i=0; i<ROZMIAR; ++i)  //zeruje wartosci
        wsp[i] = 0;   // proste niejawne rzutowanie wsp[i] = 0.0;
}

double Dlugosc(Wektor A, Wektor B)
{
    double dlugosc = 0.0;
    for(int i=0; i<ROZMIAR; ++i)
    {
        dlugosc += pow(B.wsp[i]-A.wsp[i],2);
    }
    dlugosc = sqrt(dlugosc);
    return dlugosc;
}

bool KatProsty(Wektor A, Wektor B, Wektor C)
{
    double dlugoscAB = 0.0;
    double dlugoscBC = 0.0;
    double dlugoscAC = 0.0;
    for(int i=0; i<ROZMIAR; ++i)
        dlugoscAB += pow(B.wsp[i]-A.wsp[i],2);
    for(int i=0; i<ROZMIAR; ++i)
        dlugoscBC += pow(C.wsp[i]-B.wsp[i],2);
    for(int i=0; i<ROZMIAR; ++i)
        dlugoscAC += pow(C.wsp[i]-A.wsp[i],2);
    dlugoscAB = pow(dlugoscAB,2);
    dlugoscBC = pow(dlugoscBC,2);
    dlugoscAC = pow(dlugoscAC,2);

    return dlugoscAC==dlugoscAB+dlugoscBC;
}

istream& operator >> (istream &Strm, Wektor &Wek)
{
    cout << "Wpisz wspolrzedne rozdzielone znakami bialymi: " << endl;
    for(int i=0; i<ROZMIAR; ++i) //wpisuje wartosci do kolejnych wspolrzednych
        Strm >> Wek.wsp[i];

    return Strm;
}

ostream& operator << (ostream &Strm, const Wektor &Wek)
{
    for(int i=0; i<ROZMIAR; ++i)  //wypisuje wartosc kolejnych wspolrzednych
        Strm << Wek.wsp[i] << ".";

    Strm << endl;
    return Strm;
}
