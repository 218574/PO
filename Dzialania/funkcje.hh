#ifndef FUNKCJE_HH
#define FUNKCJE_HH


using namespace std;


// Definicja typu wyliczeniowego "Symbol" dla symboli e,a,b,c,d

enum
 Symbol {z,e,a,b,c,d};

// Deklaracja funkcji

Symbol Dodaj(Symbol x, Symbol y); // Dodawania
Symbol PrzeciwnyDodawania(Symbol x); // Przeciwnej do dodawania
Symbol Odejmij(Symbol x, Symbol y); // Odejmowania
Symbol Mnoz(Symbol x, Symbol y); // Mnozenia
Symbol OdwrotnyMnozenia(Symbol x); // Odwrotna mnozenia
Symbol Dziel(Symbol x, Symbol y); // Dzielenia
Symbol Modulo(Symbol x, Symbol y); // Modulo

// Deklaracja operatorow

Symbol operator + (Symbol x, Symbol y); // Przeciazenie operatora dodawania
Symbol operator - (Symbol x, Symbol y); // Przeciazenie operatora odejmowania
Symbol operator * (Symbol x, Symbol y); // Przeciazenie operatora mnozenia 
Symbol operator / (Symbol x, Symbol y); // Przeciazenie operatora dzielenia
Symbol operator % (Symbol x, Symbol y); // Przeciazenie operatora modulo

#endif
