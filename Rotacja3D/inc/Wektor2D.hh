#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <cmath>
/*!
 * \brief   Modeluje pojecie Wektora 2D
 *
 *  Klasa modeluje pojecie Wektora 2D oraz liczne metody zwiazane z operacjami na tym wektorze
 */
class Wektor2D
{
    double _Wektor[3];      // tablica trzyelementowa zmiennoprzecinkowa typu double do przechowywania współrzednych wektora, punktu

public:

    /*!
    *  \brief Przeciazenie operatora indeksowania dla klasy Wektor2D
    *
    *   Przeciazenie operatora indeksowania dla klasy Wektor2D
    *   Dzieki temu przeciazeniu uzyskujemy mozliwosc odczytu
    *   wartosci elementow tablicy _Wektor[2]
    * \param[in] Ind - liczba calkowita dodatnia bedaca indeksem
    *                   elementu klasy (od 0 do 1)
    * \return Wartosc elementu klasy o podanym indeksie
    *
    */

    double operator [] (int Ind) const
    {
        return _Wektor[Ind];
    }

    /*!
     *  \brief Przeciazenie operatora indeksowania dla klasy Wektor2D
     *
     *   Przeciazenie operatora indeksowania dla klasy Wektor2D
     *   Dzieki temu przeciazeniu uzyskujemy mozliwosc zapisu
     *   liczby do elementow tablicy _Wektor[2]
     * \param[in] Ind - liczba calkowita dodatnia bedaca indeksem
     *                   elementu klasy (od 0 do 1)
     * \return &_Wektor[Ind] dostep to elementow tablicy _Wektor[]
     *
     */
    double & operator [] (int Ind)
    {
        return _Wektor[Ind];
    }

    /*!
    *   \brief Przeciazenie konstruktora inicjalizujacego elementy klasy zerami
    *
    *   Przeciazenie konstruktora inicjalizujacego elementy klasy zerami.
    */
    Wektor2D()
    {
        _Wektor[0]=0;
        _Wektor[1]=0;
	_Wektor[2]=0;
    }

    /*!
    *   \brief Przeciazenie konstruktora inicjalizujacego elementy klasy podanymi wartosciami.
    *
    *   Przeciazenie konstruktora inicjalizujacego elementy klasy podanymi wartosciami.
    *
    * \param[in] x - wspolrzedna x wektora
    * \param[in] y - wspolrzedna y wektora
    *
    *
    */
  Wektor2D(double x, double y, double z)
    {
        _Wektor[0]=x;
        _Wektor[1]=y;
	_Wektor[2]=z;
    }

    /*!
     *   \brief Przeciazenie operatora mnozenia wektorow
     *
     *   Przeciazenie operatora mnozenia wektorow, wektory musza miec odpowiednie ulozenie (pionowy i poziomy)
     *
     * \param[in] Wektor2D - pierwszy wektor do mnozenia
     * \param[in] x - drugi wektor do mnozenia
     *
     * \return zwraca iloczyn wektorow
     *
     */
    double operator * (Wektor2D x)
    {
        return x[0]*_Wektor[0] + x[1]*_Wektor[1] + x[2]*_Wektor[2];
    }

    /*!
     *   \brief Przeciazenie operatora dodawania wektorow
     *
     *   Przeciazenie operatora dodawania wektorow
     *
     * \param[in] Wektor2D - pierwszy wektor do dodawania
     * \param[in] x - drugi wektor do dodawania
     *
     * \return zwraca wektor bedacy suma wektorow wejsciowych
     *
     */
    Wektor2D operator + (Wektor2D x)
    {
      return Wektor2D(_Wektor[0] + x[0], _Wektor[1] + x[1], _Wektor[2] + x[2]);
    }

    /*!
    *   \brief Przeciazenie operatora & odleglosci 2 punktow
    *
    *   Przeciazenie operatora & (dlugosc wektora rozpietego miedzy dwoma punktami typu Wektor2D)
    *   lub odleglosc miedzy koncami 2 wektorow.
    *   Dlugosc
    *
    * \param[in] Wektor2D - pierwszy punkt, wektor
    * \param[in] x - drugi punkt, wektor
    *
    * \return zwraca wartosc double bedaca odlegloscia pomiedzy dwoma punktami(koncami wektorow)
    *
    */
    double operator & (Wektor2D x)
    {
      return sqrt((_Wektor[0] - x[0])*(_Wektor[0] - x[0]) + (_Wektor[1] - x[1])*(_Wektor[1] - x[1]) + (_Wektor[2] - x[2])*(_Wektor[2] - x[2]));
    }

};


    /*!
    *   \brief Przeciazenie operatora czytania ze strumienia dla klasy wektor
    *
    *   Przeciazenie operatora czytania ze strumienia dla klasy wektor.
    *   Przeciazenie wczytuje dwie wspolrzedne wektora do klasy.
    *   W przypadku podania zlej wspolrzednej jest generowany komunikat
    *   i mozna wpisac ponownie poprawna wartosc
    *
    * \param[in] &Strm - Referencja na strumien wejsciowy
    * \param[in] &Wek - Referencja na klase Wektor2D
    *
    * \return Strm - strumien wejsciowy
    */
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

    /*!
    *   \brief Przeciazenie operatora zapisu do strumienia dla klasy wektor
    *
    *   Przeciazenie operatora zapisu do strumienia dla klasy wektor.
    *   Wyswietlane sa wspolrzedne wektora o dlugosci 16 znakow z 10 miejscami
    *   po przecinku z wyrownaniem do prawej strony. Wspolrzedna x oraz y odzielone
    *   sa spacjami. Po wyswietleniu nastepuje przejscie do nowej lini.
    *
    * \param[in] &Strm - Referencja na strumien wejsciowy
    * \param[in] &Wek - Referencja na klase Wektor2D
    *
    * \return Strm - strumien wyjsciowy
    *
    */
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);

#endif
