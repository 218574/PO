#include <iostream>
#include <cstring>
#include "funkcje.hh"

using namespace std;

void WyswietlSymbol(Symbol x)
  
{
  char TablicaSymboli[] = {'e','a','b','c','d'};
  cout << TablicaSymboli[x];
}
// Przeciazenie strumienia wyjsciowego
ostream & operator << (ostream & StrumienWyjsciowy, Symbol x)
  {
  StrumienWyjsciowy << "eabcd"[x];
  return StrumienWyjsciowy;
  }
// Przeciazenie strumienia wejsciowego
istream & operator >> (istream & StrumienWejsciowy, Symbol &WczytajSymbol)
{
  Symbol Tablica[] = {e,a,b,c,d};
  char ZnakSymbolu;
  StrumienWejsciowy >> ZnakSymbolu;
  
  if (strchr("abcde", ZnakSymbolu)){
    WczytajSymbol = Tablica[ZnakSymbolu - 'a'];
  }
  else
    {
	    StrumienWejsciowy.unget();
	    StrumienWejsciowy.setstate(ios::failbit);
    }
  return StrumienWejsciowy;
}

int main() // Funkcja glowna pozwalajaca przedtawic wyniki
{
  Symbol wynik_alg, wynik_ope, wynik_fun;
  Symbol x, y, wynik;
  int WszystkieWyrazenia, DobryZapis, DobryWynik, Dodawanie, Odejmowanie, Mnozenie, Dzielenie, Modulo;
  char Oper, Rowna;
  
  // Zerowanie statystyk
  WszystkieWyrazenia = 0;
  DobryZapis = 0;
  DobryWynik = 0;
  Dodawanie = 0;
  Odejmowanie = 0;
  Mnozenie = 0;
  Dzielenie = 0;
  Modulo = 0;

  // Warunki konieczne do odczytania poprawnego dzialania
  while(!cin.eof())
    {
      cout << "Wprowadz dane :)" << endl;
      WszystkieWyrazenia++;
      cin >> x; // Podanie wartosci pierwszego argumentu
      
      if(cin.fail())
	{
	  cerr << "Bledny pierwszy argument." << endl;
	}

      cin >> Oper; // Podanie operatora
      if (Oper!='+'&& Oper!='-'&& Oper!='*'&& Oper!='/'&& Oper!='%')
	{
	  cerr << "Bledny znak operatora." << endl;
	}

      cin >> y; // Podanie wartosci drugiego argumentu
      if(cin.fail())
	{
	  cerr << "Bledny drugi argument." << endl;
	}
      cin >> Rowna; // Znak rownosci
      if (Rowna != '=')
	{
	  cout << "Brak znaku '='" << endl;
	}

      cin >> wynik; // Podanie wartosci wyniku
      if (cin.fail())
	{
	  cerr << "Brak podanego wyniku." << endl;
	}
      else 
	{
	  cout << "Odczytano wyrazenie: " << endl;
	  cout << x << Oper << y << Rowna << wynik << endl;
	  DobryZapis++; // +1 Dobrze zapisanych wyrazen, jesli dzialanie bedzie mialo powyzsza postac
	
	  switch (Oper)
	    {
	      
	    case '+': // Jesli operator w dzialaniu = '+'
	      Dodawanie++; // +1 do statystyk dodawania
	      cout << "<-----Wykonuje Dodawanie----->" << endl; // Przedstawienie wykonywanej funkcji
	      wynik_alg = x + y; //Wyrazenie przedstawione w sposob zwyczajowy
	      wynik_ope = operator + (x,y); //Wyrazenie wykorzystujace funkcje 
	      wynik_fun = Dodaj(x,y); //Wyrazenie z jawnym wykozystaniem operat
	      if (wynik_alg == wynik_fun && wynik_fun == wynik_ope && wynik == wynik_alg) // Warunek rownosci wyrazen
		{
		  cout << "Wynik poprawny" << endl; // Wypisanie na standardowe wyjcie komunikatu o poprawnym wyniku
		  DobryWynik++; // +1 Statystyk poprawnych wynikow
		}
	      else 
		{
		  cout << "Wynik niepoprawny." << endl; // Wypisanie na standardowe wyjscie komunikatu o zlym wyniku
		  cout << "Poprawny wynik to: " << wynik_alg << endl; // Przedtawienie poprawnego wyniku
		}
	      break;
	      

	    case '-':
	      Odejmowanie++; // Odejmowanie
	      cout << "<-----Wykonuje Odejmowanie----->" << endl;
	      wynik_alg = x - y;
	      wynik_ope = operator - (x,y);
	      wynik_fun = Odejmij(x,y);
	      if(wynik_alg == wynik_fun && wynik_fun == wynik_ope && wynik == wynik_alg)
		{
		  cout << "Wynik poprawny" << endl;
		  DobryWynik++;
		}
	      else 
		{
		  cout << "Wynik niepoprawny." << endl;
		  cout << "Poprawny wynik to: " << wynik_alg << endl;
		}
	      break;
	      
	      
	    case '*':
	      Mnozenie++; // Mnozenie
	      cout << "<-----Wykonuje Mnozenie----->" << endl;
	      wynik_alg = x * y;
	      wynik_ope = operator * (x,y);
	      wynik_fun = Mnoz(x,y);
	      if (wynik_alg == wynik_fun && wynik_fun == wynik_ope && wynik == wynik_alg)
		{
		  cout << "Wynik poprawny" << endl;
		  DobryWynik++;
		}
	      else 
		{
		  cout << "Wynik niepoprawny." << endl;
		  cout<< "Poprawny wynik to: " << wynik_alg << endl;
		}
	      break;
	      

	    case '/':
	      Dzielenie++; // Dzielenie
	      cout << "<-----Wykonuje Dzielenie----->" << endl;
	      wynik_alg = x / y;
	      wynik_ope = operator / (x,y);
	      wynik_fun = Dziel(x,y);
	      if (wynik_alg == wynik_ope && wynik_ope == wynik_fun && wynik == wynik_alg)
		{
		  cout << "Wynik poprawny" << endl;
		  DobryWynik++;
		}
	      else 
		{
		  cout << "Wynik niepoprawny." << endl;
		  cout << "Poprawny wynik to: " << wynik_alg << endl;
		}
	      break;
	      
	    case '%':
	      Modulo++; // Modulo
	      cout << "<-----Wykonuje Modulo----->" << endl;
	      wynik_alg = x % y;
	      wynik_ope = operator % (x,y);
	      //wynik_fun = Modulo(x,y);
	      if (wynik_alg == wynik_ope && /*wynik_fun == wynik_ope &&*/ wynik == wynik_alg)
		{
		  cout << "Wynik poprawny" << endl;
		  DobryWynik++;
		}
	      else 
		{
		  cout << "Wynik niepoprawny." << endl;
		  cout << "Poprawny wynik to: " << wynik_alg << endl;
		}
	      break; 
	    }

	  double procenty; // Zmienna pomocnicza do obliczenia wartosci procentowej wyniku
	  procenty = static_cast<double>(DobryWynik)/static_cast<double>(DobryZapis)*100; // Rzutowanie i zamiana na procenty
	  
	  cout << "<-----Statystyka----->" << endl;
	  cout << "Liczba wszystkich wyrazen: " << WszystkieWyrazenia << endl; // Wszystkie wykonane dzialania
	  cout << "Liczba poprawnych wyrazen: " << DobryZapis << endl; // Poprawnie zapisane dzialania
	  cout << "Liczba poprawnych wynikow: " << DobryWynik << endl; // Poprawne wyniki
	  cout << "Liczba procentowa poprawnych wynikow: " << procenty << "%" << endl; // Procentowo ilosc poprawnych wynikow
	  cout << "Liczba operacji dodawania: " << Dodawanie << endl; // Ilosc dzialan z wykorzystaniem dodwania
	  cout << "Liczba operacji odejmowania: " << Odejmowanie << endl; // Ilosc dzialan z wykorzystaniem odejmowania
	  cout << "Liczba operacji mnozenia: " << Mnozenie << endl; // Ilosc dzialan z wykorzystaniem mnozenia
	  cout << "Liczba operacji dzielenia: " << Dzielenie << endl; // Ilosc dzialan z wykorzystaniem dzielenia
	  cout << "Liczba operacji modulo: " << Modulo << endl; // Ilosc dzialan z wykorzystaniem modulo
	}
    }
}
