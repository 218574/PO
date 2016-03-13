#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Prostokat.hh"
#include "Macierz2x2.hh"

#define delta 0.00000000001

/*!
 * \brief   Modeluje pojecie Obrotu
 *
 *  Klasa zawiera w sobie wszystkie niezbedne informacje przeciazenia i metody konieczne
 *  do wykonania programu. Przechowywane sa wniej wsp prostokata, macierz obrotu, wektor oraz
 *  liczba powtorzen obrotu.
 */
class Obroty
{

    Prostokat P;    //Klasa z wspolrzednymi prostokatu
    Macierz2x2 M;   //Klasa z macierza obrotu oraz katem obrotu
    Wektor2D W;     //Klasa z wektorem obrotu
    int l_powt;     //zmienna na ilosc powtorzen oberacji obrotu prostokata o zadany kat


public:

/*!
*   \brief Metoda odczytujaca parametry obrotu prostokata
*
*   Metoda odczytujaca parametry obrotu prostokata.
*   Parametry pobierane sa ze standardowego wejscia std::cin
*   W przypadku podania blednej wartosci generowany jest komunikat i mozna wpisac
*   wartosc ponownie.
*
*/
    void odczytaj_obrot (void);

/*!
*   \brief Metoda wykonujaca obrot prostokata o zadany kat i zadana liczbe razy
*
*   Metoda wykonujaca obrot prostokata o zadany kat i zadana liczbe razy.
*   Najpierw metoda wywoluje metode odczytaj_obrot, nastepnie wykonuje
*   mnozenie punktow prostokata przez macierz obrotu
*
*/
    void wykonaj_obrot(void);

/*!
*   \brief Metoda wykonujaca przesuniecie prostokata o wektor
*
*   Metoda wykonujaca przesuniecie prostokata o wektor.
*   Najpierw metoda pobiera wspolrzedne wektora od uzytkownika ze standardowego wejscia std::cin
*   W przypadku blednego wprowadzenia wspolrzednej mozliwe jest ponowna proba wprowadzenia
*   Nastepnie wspolrzedne prostokata przesowane sa o wczytany wektor
*
*/
    void przesun_o_wektor(void);

/*!
*   \brief Metoda wyswietlajaca wspolrzedne prostokata na std::cout
*
*   Metoda wyswietlajaca wspolrzedne prostokata na std::cout
*   Metoda wykorzystuje przeciazenie operatora zapisu do strumienia
*   dla klasy Prostokat
*
*/
    void wyswietl_wsp (void)
    {
        std::cout << P << std::endl;
    }

/*!
*   \brief Metoda zapisujaca wspolrzedne prostokata do strumienia wyjsciowego Strm
*
*   Metoda zapisujaca wspolrzedne prostokata do strumienia wyjsciowego Strm
*   Metoda wykorzystuje przeciazenie operatora zapisu do strumienia
*   dla klasy Prostokat oraz dodatkowo wysyla na koncu ponownie wspolrzedne pierwszego punktu
*   dla zamkniecia prostokata w programie gnuplot
*
*/
    void wsp_do_pliku(std::ostream &Strm)
    {
        Strm << P << P[0] << std::endl;
    }
/*!
*   \brief Metoda sprawdzajaca czy przeciwlegle boki sa rowne
*
*   Metoda sprawdzajaca czy przeciwlegle boki sa rowne.
*   Dlugosc bokow jest porownywana z dokladnoscia -delta +delta (makrodefinicja #define delta)
*   Na podstawie poronan generowane sa odpowiednie komunikaty na standardowy strumien wyjsciowy std::cout
*
*/
    void sprawdz_rownosc(void);

};




#endif
