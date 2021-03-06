#include "manipulator.hh"
#include <cstdlib>
#include <iostream>
using namespace std;

void Manipulator::wczytajKaty(const char* nazwaPliku)
{
	katy.clear();
	double tmp;
	ifstream plik;
	int i=0;
	plik.open(nazwaPliku);
	if(!plik.is_open())
	  exit(-1);
	cout<<"Postura wczytana z pliku: "<<nazwaPliku<<endl;
	cout<<"Postura:"<<endl;
	while(!plik.eof())
	  {
	    plik>>tmp;
	    cout<<"q"<<i<<" = "<<tmp<<" ";
	    tmp = tmp*M_PI/180;
	    katy.push_back(tmp);
	    wyznaczWspolrzedne();
	    cout<<"Przegub "<<i<<": ( "<<Wspolrzedne[i]<<" )"<<endl;
	    i++;
	  }
	plik.close();
}

void Manipulator::wczytajDlugosci(const char* nazwaPliku)
{
  dlugosc.clear();
 katy.clear();
float tmp;
int i=0;
ifstream plik;
plik.open(nazwaPliku);
	if(!plik.is_open())
		exit(-1);
	cout<<"Konfiguracje wczytano z pliku: "<<nazwaPliku<<endl;
	cout<<"Konfiguracja:"<<endl;
	katy.push_back(90*M_PI/180);
	while(!plik.eof())
	{
		plik>>tmp;
		dlugosc.push_back(tmp);
		katy.push_back(0);
		cout<<"Dlugosc ogniwa "<<i<<": "<<tmp<<endl;
		i++;
	}
	katy.pop_back();
	cout<<"Postura:"<<endl;
	for(unsigned int j=0;j<katy.size();j++)
	  {
	    cout<<"q"<<j<<" = "<<katy[j]*180/M_PI<<" ";
            wyznaczWspolrzedne();
            cout<<"Przegub "<<j<<": ( "<<Wspolrzedne[j]<<" )"<<endl;
	  }
plik.close();
}

void Manipulator::wyznaczWspolrzedne()
{
Wspolrzedne.clear();
for(unsigned int i=0; i<dlugosc.size(); i++)
{
	Wektor2D wektorTranslacji;
	Wektor2D wynik;
	wynik[0]=0;
	wynik[1]=0;
	Macierz2x2 macierzRotacji;

	for(int j=i-1; j>=0; j--)
	{
	macierzRotacji(0,0)=cos(katy[j]);
	macierzRotacji(0,1)=-sin(katy[j]);
	macierzRotacji(1,0)=sin(katy[j]);
	macierzRotacji(1,1)=cos(katy[j]);

	wektorTranslacji[0]=dlugosc[j];
	wektorTranslacji[1]=0;

	wynik = macierzRotacji * (wektorTranslacji + wynik);
	}
	Wspolrzedne.push_back(wynik);
}
}

ostream& operator <<(ostream& Strm, const Manipulator& Zmn)
{
	for(int i=0; i<Zmn.rozmiar() ;i++)
		Strm<<Zmn.getWspolrzedne()[i]<<endl;
	return Strm;
}
