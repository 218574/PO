#include "Macierz2x2.hh"




void Macierz2x2::inicjuj_macierz(void)
{
    double rad = (kat_obrotu * M_PI) / 180.0;
    Macierz[0] = Wektor2D(cos(rad), -sin(rad), sin(rad));
    Macierz[1] = Wektor2D(sin(rad), cos(rad), sin(rad));
    Macierz[2] = Wektor2D(sin(rad), cos(rad), sin(rad));
}

void Macierz2x2::odczytaj_kat_obr (void)
{
    std::cout << "Podaj wartosc kata obrotu w stopniach"<< std::endl;
    while(1)
    {
        std::cin >> kat_obrotu;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cerr << "Błąd niepoprawny kat obrotu. Sprobouj ponownie." << std::endl;
        }
        else break;
    }

}
