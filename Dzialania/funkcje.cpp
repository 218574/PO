#include <iostream>
#include <cstring>
#include "funkcje.hh"

using namespace std;


enum 

Symbol TabliczkaDodawania[5][5] = // Definiuje tabeliczke dodawania
{{e,a,b,c,d},
 {a,d,e,b,c},
 {b,e,c,d,a},
 {c,b,d,a,e},
 {d,c,a,e,b}};

Symbol TabliczkaMnozenia[5][5]= // Definiuje tabliczke mnozenia
{{e,e,e,e,e},
 {e,a,b,c,d},
 {e,b,a,d,c},
 {e,c,d,b,a},
 {e,d,c,a,b}};

Symbol TabliczkaModulo[5][5]= // Definiuje tabliczke modulo
{{z,e,e,e,e},
 {z,e,a,a,a},
 {z,e,e,b,b},
 {z,e,a,e,c},
 {z,e,e,a,e}};

/***
 * Funkcja Dodawania
 * 
 * x - obiekt ze zbioru Symbol
 * y - obiekt ze zbioru Symbol
 *
 * Warunki poczatkowe:
 * x,y musza nalezec do zbioru Symbol
 *
 * Warunki koncowe:
 * Brak
 *
 * Zwracane Wartosci:
 * Elementy TablicyDodawania odpowiadajace sumie x + y
 ***/
Symbol Dodaj(Symbol x, Symbol y)
{
  return TabliczkaDodawania[x][y];
}
/***
 * Funkcja PrzeciwnyDodawania
 * 
 * x - obiekt ze zbioru Symbol
 * y - zmienna pomocnicza
 * Tablica - tablica obiektow typu Symbol
 *
 * Warunki poczatkowe:
 * x musi nalezec do zbioru Symbol
 *
 * Warunki koncowe:
 * Brak
 *
 * Zwracane Wartosci:
 * Zmienna y bedaca liczba przeciwna do x
 ***/
Symbol PrzeciwnyDodawania(Symbol x) // Funkcja przeciwna do dodawania
{
  Symbol Tablica[]={e,a,b,c,d};
 for (Symbol y: Tablica)
   {
  if(x + y == e)
    return y;
   }
cerr << "Nie znaleziono elementu przeciwnego dodawania" << endl;
 return e;
}
/***
 * Funkcja Odejmij
 * 
 * x - obiekt ze zbioru Symbol
 * y - obiekt ze zbioru Symbol
 *
 * Warunki poczatkowe:
 * x,y musza nalezec do zbioru Symbol
 *
 * Warunki koncowe:
 * Brak
 *
 * Zwracane Wartosci:
 * Element tablicy dodawania odpowiadajacy roznicy x - y
 ***/
Symbol Odejmij(Symbol x, Symbol y) // Funkcja Odejmowania
{
  return Dodaj(x, PrzeciwnyDodawania(y));
}
/***
 * Funkcja Mnoz
 * 
 * x - obiekt ze zbioru Symbol
 * y - obiekt ze zbioru Symbol
 *
 * Warunki poczatkowe:
 * x,y musza nalezec do zbioru Symbol
 *
 * Warunki koncowe:
 * Brak
 *
 * Zwracane Wartosci:
 * Elementy TablicyMnozenia odpowiadajacy iloczynowi x * y
 ***/
Symbol Mnoz(Symbol x, Symbol y) // Funkcja Mzozenia
{
  return TabliczkaMnozenia[x][y];
}
/***
 * Funkcja OdwrotnyMnozenia
 * 
 * x - obiekt ze zbioru Symbol
 * y - zmienna pomocnicza
 * Tablica - tablica obiektow typu Symbol
 *
 * Warunki poczatkowe:
 * x musi nalezec do zbioru Symbol
 *
 * Warunki koncowe:
 * Brak
 *
 * Zwracane Wartosci:
 * Zmienna y bedaca elementem odwrotnym do x
 ***/
Symbol OdwrotnyMnozenia(Symbol x)
{
  Symbol Tablica[]={e,a,b,c,d};
  for (Symbol y: Tablica)
    {
      if(x * y == a)
	return y;
    }
  cerr << "Nie znaleziono elementu odwrotnego mnozenia" << endl;
  return a;
}
/***
 * Funkcja Dzielenia
 * 
 * x - obiekt ze zbioru Symbol
 * y - obiekt ze zbioru Symbol
 *
 * Warunki poczatkowe:
 * x,y musza nalezec do zbioru Symbol
 *
 * Warunki koncowe:
 * Brak
 *
 * Zwracane Wartosci:
 * Elementy TablicyMnozenia odpowiadajace ilorazowi x / y
 ***/
Symbol Dziel(Symbol x,Symbol y) // Przeciazenie operatora dzielenia
{
  if (y == e)
    {
      cerr << "Blad dzielenie przez 0" << endl;
    }
  return TabliczkaMnozenia[x][OdwrotnyMnozenia(y)];
}
/***
 * Funkcja Modulo
 * 
 * x - obiekt ze zbioru Symbol
 * y - obiekt ze zbioru Symbol
 *
 * Warunki poczatkowe:
 * x,y musza nalezec do zbioru Symbol
 *
 * Warunki koncowe:
 * Brak
 *
 * Zwracane Wartosci:
 * Elementy TablicyModulo odpowiadajace x % y
 ***/
Symbol Modulo(Symbol x, Symbol y) // Przeciazenie operatora modulo
{
  if (TabliczkaModulo[x][y] == z);
    {
      cerr << "Blad dzielenie przez 0" << endl;
    }
  return TabliczkaModulo[x][y];
}

/****** Przeciazenie operatorow *****/ 

// Przeciazenie Dodaj
Symbol operator + (Symbol x, Symbol y)
{
return TabliczkaDodawania[x][y];
}

// Przeciazenie Odejmij
Symbol operator - (Symbol x, Symbol y)
{
return TabliczkaDodawania[x][-y];
}

// Przeciazenie Mnoz
Symbol operator * (Symbol x, Symbol y)
{
  return TabliczkaMnozenia[x][y];
}

// Przeciazenie Dziel
Symbol operator / (Symbol x, Symbol y)
{
  if(y==0)
    {
      cerr << "Nie mozna dzielic przez 0!" << endl;
    }

  return Symbol(x * OdwrotnyMnozenia(x));
}

//Przeciazenie  Modulo
Symbol operator % (Symbol x, Symbol y)
{

 if(TabliczkaModulo[x][y] == z)
    {
      cerr << "Nie mozna dzielic przez 0!" << endl;
    }
  return TabliczkaModulo[x][y];
}

