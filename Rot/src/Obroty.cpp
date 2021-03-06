#include "Obroty.hh"
#include <cmath>

using namespace std;

void Obroty::czytaj_obrot(void)
{
  Macierz.czytaj_obrot();
        cout << "Ile razy operacja obrotu ma byc powtorzona?" << endl;
        while(1)
	  {
            cin >> liczba_powtorzen;
            if(cin.fail())
            {
	      cin.clear();
	      cin.ignore(1000,'\n');
	      cerr << "Błedna wartosc liczby powtorzen obrotow. Wprowadz ponownie." << endl;
            }
            else break;
	  }
    }

void Obroty::wykonaj_obrot(void)
{
  czytaj_obrot();
  for(int i=0; i<liczba_powtorzen; i++)
    {
      Pro[0] = Macierz * Pro[0];
      Pro[1] = Macierz * Pro[1];
      Pro[2] = Macierz * Pro[2];
      Pro[3] = Macierz * Pro[3];
    }
}
void Obroty::przesun_o_wektor(void)
    {
      cout << "Wprowadz wspolrzedna x oraz y o ktore ma byc przesuniety prostokat"<< std::endl;
      cin >> Wektor;
      Pro + Wektor;
    }

void Obroty::sprawdz_boki(void)
{
  double Prosta[2];
  
  Prosta[0] = Pro[0] & Pro[1];
  Prosta[1] = Pro[3] & Pro[2];
  
  if (Prosta[0] > Prosta[1] - epsilon && Prosta[0] < Prosta[1] + epsilon)
    cout << "Dluzsze przeciwlegle boki sa rowne." << endl;
  else
    cout << "Dluzsze przeciwlegle boki nie sa rowne." << endl;
  
  Prosta[0] = Pro[1] & Pro[2];
  Prosta[1] = Pro[0] & Pro[3];
  
  if (Prosta[0] > Prosta[1] - epsilon && Prosta[0] < Prosta[1] + epsilon)
    cout << "Krotsze przeciwlegle boki sa rowne." << endl;
  else
    cout << "Krotsze przeciwlegle boki nie sa rowne" << endl;
}
