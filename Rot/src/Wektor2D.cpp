#include <iostream>
#include <iomanip>

#include "Wektor2D.hh"

using namespace std;

istream& operator >> (istream &Strumien, Wektor2D &Wektor) // Strumien wejsciowy
{
  while(1)
    {
      cin >> Wektor[0]; // Podajemy pierwsza wspolrzedna
      if(cin.fail())
	{
	  cin.clear();
	  cin.ignore(1000,'\n');
	  cerr << "Błedna wspolrzedna x. Wprowadz ponownie." << endl;
	}
      else break;
    }
  
  while(1)
    {
      cin >> Wektor[1]; // Podajemy druga wspolrzedna
      if(cin.fail())
	{
	  cin.clear();
	  cin.ignore(1000,'\n');
	  cerr << "Błedna wspolrzedna y. Wprowadz ponownie." << endl;
	}
      else break;
    }
  return Strumien;
}

ostream & operator << (ostream & Strumien, const Wektor2D & Wektor)
{
  Strumien << setw(16) << fixed << setprecision(10) << Wektor[0] << setw(16) << fixed << setprecision(10) << Wektor[1] << endl;
  
  return Strumien;
}
