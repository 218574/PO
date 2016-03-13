#include <iostream>
#include <iomanip>

#include "Wektor2D.hh"
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor2D, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

std::istream& operator >> (std::istream &Strm, Wektor2D &Wek)
{
    while(1)
        {
            std::cin >> Wek[0];
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cerr << "Błąd niepoprawna wspolrzedna x. Sprobouj ponownie." << std::endl;
            }
            else break;
        }

        while(1)
        {
            std::cin >> Wek[1];
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cerr << "Błąd niepoprawna wspolrzedna y. Sprobouj ponownie." << std::endl;
            }
            else break;
        }
    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek)
{
    Strm << std::setw(16) << std::fixed << std::setprecision(10) << Wek[0]
           << std::setw(16) << std::fixed << std::setprecision(10) << Wek[1] << std::endl;

    return Strm;
}


