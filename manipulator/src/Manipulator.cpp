#include "Manipulator.hh"
#include <cstdlib>
#include <iostream>
using namespace std;

void Manipulator::WczytajK(const char* NazwaPliku)
{
	angle.clear();
	double temp;
	ifstream plik;
	int i=0;
	plik.open(NazwaPliku);
	if(plik.good()==false)
	exit(0);
	cout<<"Postura wczytana z pliku: "<<NazwaPliku<<endl;
	cout<<"Postura:"<<endl;
	while(!plik.eof())
	  {
	    plik>>temp;
	    cout<<"q"<<i<<" = "<<temp<<" ";
	    temp = temp*M_PI/180;
	    angle.push_back(temp);
	    WyznaczWsp();
	    cout<<"Przegub "<<i<<": ( "<<coor[i]<<" )"<<endl;
	    i++;
	  }
	plik.close();
}

void Manipulator::WczytajD(const char* NazwaPliku)
{
 length.clear();
 angle.clear();
float temp;
int i=0;
ifstream plik;
plik.open(NazwaPliku);
	if(plik.good()==false)
	exit(0);
	cout<<"Konfiguracje wczytano z pliku: "<<NazwaPliku<<endl;
	cout<<"Konfiguracja:"<<endl;
	angle.push_back(90*M_PI/180);
	while(!plik.eof())
	{
		plik>>temp;
		length.push_back(temp);
		angle.push_back(0);
		cout<<"Dlugosc ogniwa "<<i<<": "<<temp<<endl;
		i++;
	}
	angle.pop_back();
	cout<<"Postura:"<<endl;
	for(unsigned int j=0;j<angle.size();j++)
	  {
	    cout<<"q"<<j<<" = "<<angle[j]*180/M_PI<<" ";
            WyznaczWsp();
            cout<<"Przegub "<<j<<": ( "<<coor[j]<<" )"<<endl;
	  }
plik.close();
}

void Manipulator::WyznaczWsp()
{
coor.clear();
for(unsigned int i=0; i<length.size(); i++)
{
	Wektor2D Translacja;
	Wektor2D Wyn;
	Wyn[0]=0;
	Wyn[1]=0;
	Macierz2x2 MacierzRotacji;

	for(int j=i-1; j>=0; j--)
	{
	MacierzRotacji(0,0)=cos(angle[j]);
	MacierzRotacji(0,1)=-sin(angle[j]);
	MacierzRotacji(1,0)=sin(angle[j]);
	MacierzRotacji(1,1)=cos(angle[j]);

	Translacja[0]=length[j];
	Translacja[1]=0;

	Wyn = MacierzRotacji * (Translacja + Wyn);
	}
	coor.push_back(Wyn);
}
}

ostream &operator <<(ostream& Strm, const Manipulator& Zm)
{
	for(int i=0; i<Zm.Rozmiar() ;i++)
		Strm<<Zm.wczytajcoor()[i]<<endl;
	return Strm;
}
