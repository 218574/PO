#include <iostream>
#include "Prostokat.hh"
#include "Macierz2x2.hh"

using namespace std;

#define epsilon 0.0000001

class Obroty // Klasa okreslajaca obroty
{
  
  Prostokat Pro;  //Klasa prostokat
  Macierz2x2 Macierz;   //Klasa macierz
  Wektor2D Wektor;     //Klasa wektor
  int liczba_powtorzen; //zmienna okreslajaca ilosc wykonanych obrotow
  
public:
  void czytaj_obrot(void); // Funkcja czytajaca 
  void wykonaj_obrot(void); // Funkcja wykonania obrotu o podany kat
  void przesun_o_wektor(void); // Funkcja przesuwajaca wektor
  void wyswietl_wspolrzedne(void) // Funkcja wyswietlajaca wspolrzedne
  {
    cout << Pro << endl;
  }
  void wspolrzedne_do_zapisu(ostream & Strumien)
  {
    Strumien << Pro << Pro[0] << endl;
  }
  void sprawdz_boki(void); // Funkcja sprawdzajaca rownosc bokow
  
};



