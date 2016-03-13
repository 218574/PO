#include "Macierz.hh"
#include <iostream>

using namespace std;

/* tak to nie zadziala :D
 * sprobuj okreslic jak wpisac takie formuly jak sin(alfa)
 * np jesli wykryje s to niech przetlumaczy to na sin(alfa)
 */
istream& operator >> (istream &Strm, Macierz &Mac)
{
    for(int i=0; i<ROZMIAR; ++i)
    {
        Strm >> Mac.wiersz[i];
    }
    return Strm;
}

/* Podobnie jak wyzej, potrzebuje tlumaczenia funkcji na stringi
 *
 */
ostream& operator << (ostream &Strm, const Macierz &Mac)
{
    for(int i=0; i<ROZMIAR; ++i)
    {
        for(int j=0; j<ROZMIAR; ++j)
        {
            Strm << Mac.wiersz[j].wsp[i] << "\t";
        }
        Strm << endl;
    }
    return Strm;
}

Wektor operator * (Macierz mac, Wektor wekt)
{
    Wektor wynik;  //zerowany konstruktorem Wektor'a
    for(int i=0; i<ROZMIAR; ++i)
    {
        for (int j=0; j<ROZMIAR; ++j)
        {
           wynik.wsp[i] += mac.wiersz[i].wsp[j]*wekt.wsp[i];  //mnozy macierz kolumnowo
        }
    }
    return wynik;
}
