#include "Macierz2x2.hh"

using namespace std;

void Macierz2x2::inicjuj_macierz(void)
{
  double radian = (kat_obrotu * M_PI) / 180.0; // zamiana kata na radiany
  Macierz[0] = Wektor2D(cos(radian), -sin(radian)); // Macierz przedstawiona za pomoca wektorow
  Macierz[1] = Wektor2D(sin(radian), cos(radian));
}

void Macierz2x2::czytaj_obrot(void)
{
  cout << "Wprowadz wartosc kata obrotu w stopniach"<< endl;
  while(1)
    {
      cin >> kat_obrotu; // Wprowadzenie kata o ktory ma sie obrocic macierz
      if(cin.fail())
        {
	  cin.clear();
	  cin.ignore(1000,'\n');
	  cerr << "Błedny kat obrotu. Wprowadz ponownie." << endl;
        }
      else break;
    }
  
}
