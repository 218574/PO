#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH


#include <iostream>
#include <cmath>
#include "Wektor2D.hh"

/*!
*   \brief Klasa Macierz2x2 do przechowywania macierzy obrotu oraz kata obrotu
*
*   Klasa Macierz2x2 do przechowywania macierzy obrotu oraz kata obrotu.
*   Macierz przechowywana jest w 2-wu elementowej tablicy Wektor2D
*   kat obrotu przechowywany jest w zmiennej typu double (umozliwia to obroty o niecalkowite wartosci kata).
*
*/

class Macierz2x2
{
    Wektor2D Macierz[2];    //Tablica przechowyjaca macierz obrotu

    double kat_obrotu = 0; //Zmienna przechowujaca kat obrotu
public:

/*!
*   \brief Metoda inicjujaca macierz wartosciami obrotu
*
*   Metoda inicjujaca Macierz[2] wartosciami obrotu.
*   Macierz jest inicjowana wartosciami cos i sin dla podanego
*   kata obrotu w polu kat_obrotu
*
*/
    void inicjuj_macierz(void);

/*!
*   \brief Przeciazenie operatora mnozenia dla Macierz2x2
*
*   Przeciazenie operatora mnozenia dla Macierz2x2.
*   Przeciazenie wykonuje operacje mnozenia zgodnie z zasadami mnorzenia macierzy przez wektor.
*   Przed wykonaniem mnozenia wywolywana jest metoda Macierz2x2::inicjuj_macierz()
*
*   \param[in] Macierz2x2 - Macierz do wykonania mnozenia
*   \param[in]  W  - wektor przez ktory bedzie mnozona macierz
*
*   \return wektor bedacy wynikiem mnozenia macierzy przez wektor
*/
    Wektor2D  operator* (const Wektor2D W)
    {
        inicjuj_macierz();
        return Wektor2D(Macierz[0]*W, Macierz[1]*W);
    }
/*!
*   \brief Metoda wczytujaca wartosc kata obrotu do klasy
*
*   Metoda wczytujaca wartosc kata obrotu do klasy
*   Wartosc kata obrotu pobierana jest ze standardowego wejscia std::cin
*   W przypadku podania blednej wartosci generowany jest komunikat i mozna wpisac
*   wartosc ponownie.
*
*/
    void odczytaj_kat_obr (void);


};


#endif
