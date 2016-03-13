#include "Prostokat.hh"
#include <iostream>

using namespace std;

void Prostokat::Przesuniecie(Wektor przesun)
{
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<ROZMIAR; ++j)
        {
            Pkt[i].wsp[j] += przesun.wsp[j];
        }
    }
}

void Prostokat::Wyswietl()
{
    cout << "Wspolrzedne rogow prostokata to: " << endl;
    for(int i=0; i<4; ++i)
    {
        if(i==2) cout << endl;
        cout << Pkt[i] << "   ";
    }
    cout << endl;
}

bool Prostokat::Sprawdz()
{
    return (Dlugosc(Pkt[0],Pkt[1])==Dlugosc(Pkt[2],Pkt[3]) &&
            Dlugosc(Pkt[0],Pkt[2])==Dlugosc(Pkt[1],Pkt[3]) &&
            KatProsty(Pkt[0],Pkt[2],Pkt[3]));
}

void Prostokat::Obrot(Macierz obrot)
{
    for(int i=0; i<ROZMIAR; ++i)
    {
        Pkt[i] = obrot * Pkt[i];  //przeksztalca kazdy punkt z osobna
    }
}

ostream& operator << (ostream &Strm, const Prostokat &Pr)
{
    for(int i=0; i<4; ++i)
    {
        Strm << Pr.Pkt[i] << "\b ";
    }
    Strm << endl;
    return Strm;
}
