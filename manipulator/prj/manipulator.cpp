#ifndef MANIPULATOR_CPP
#define MANIPULATOR_CPP
#include "manipulator.hh"
#include <iostream>
#include <fstream>

void manipulator:: wczytajDlOgniwa(char *nazwapliku )
{
  std::fstream plik;
  float dlugosc;
  plik.open(nazwapliku);
  if( plik.good() )
    {
      while (!plik.eof())
	{
	  
	  plik >> dlugosc;
	  dl_ogniwa.push_back(dlugosc);
	}
      plik.close();	
    }
}

void manipulator:: wczytajKat(char *nazwapliku )
{
  std::fstream plik;      
  float kat;
  plik.open(nazwapliku);
  if( plik.good() )
{
  while (!plik.eof()) 
    {

      plik >> kat;
      kat_przeg.push_back(kat);
    }
  plik.close();
} 
}

main ()
{
manipulator m;
m.wczytajDlOgniwa("plik_konfiguracji.dat");
std::cout << "Konfiguracja\n";
for (int i=0; i<m.dl_ogniwa.size();i++)
{
std::cout << "dlugosc ogniwa " << i;
std::cout << ": " << m.dl_ogniwa[i]<<std::endl;
}
std::cout<<std::endl;
std::cout<<"Postura\n";
m.wczytajKat("plik_postury1.dat");
for (int i=0; i<m.dl_ogniwa.size() ;i++)
{
std::cout << "q" << i ;
std::cout << ": " << m.kat_przeg[i]<<std::endl;
}
}
#endif
