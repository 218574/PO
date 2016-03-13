#include <iostream>
#include <iomanip>
#include <fstream>
#include "Obroty.hh"
#include "lacze_do_gnuplota.hh"



using namespace std;



#define DL_KROTKI_BOK  100
#define DL_DLUGI_BOK   150



/*!
 * Funkcja zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Obr - klasa Obrot
 *
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */


bool zapisz( const char  *sNazwaPliku, Obroty Obr)
{
    ofstream  StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())
    {
        cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
             << ":(  nie powiodla sie." << endl;
        return false;
    }

    Obr.wsp_do_pliku(StrmPlikowy);

    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}

/*!
*   \brief Funkcja wyswietlajaca opis menu programu
*
*   Funkcja wyswietlajaca opis menu programu
*/
void wysw_menu (void)
{
    cout << "o - obrot prostokata o zadany kat" << endl;
    cout << "p - przesuniecie prostokata o zadany wektor" << endl;
    cout << "w - wyswietlenie wspolrzednych wierzcholkow" << endl;
    cout << "s - sprawdzenie dlugosci przeciwleglych bokow" << endl;
    cout << "m - wyswietl menu" << endl;
    cout << "k - koniec dzialania programu" << endl;
}

int main()
{
    char                  znak;
    Obroty Obr;
    PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
    // rysunku prostokata
    //-------------------------------------------------------
    //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
    //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
    //  na dwa sposoby:
    //   1. Rysowane jako linia ciagl o grubosci 2 piksele
    //
    Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Ciagly,2);
    //
    //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
    //      których połowa długości boku wynosi 2.
    //
    Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Punktowy,2);
    //
    //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
    //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
    //  jako wspolrzedne punktow podajemy tylko x,y.
    //
    Lacze.ZmienTrybRys(PzG::TR_2D);

    wysw_menu();

    while(1)
    {
        cin >> znak;

        switch(znak)
        {
        case 'o':
            Obr.wykonaj_obrot();
            break;

        case 'p':
            Obr.przesun_o_wektor();
            break;

        case 'w':
            Obr.wyswietl_wsp();
            if (!zapisz("prostokat.dat", Obr)) return 1;
            Lacze.Rysuj();
            break;

        case 's':
            Obr.sprawdz_rownosc();
            break;

        case 'm':
            wysw_menu();
            break;

        case 'k':
            return 0;
            break;

        default:
            cerr << "Blad niepoprawny znak." << endl << "Sprobuj ponownie. Dozwolone znaki to:" << endl;
            wysw_menu();
            break;
        }
    }
}
