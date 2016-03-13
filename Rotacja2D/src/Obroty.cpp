#include "Obroty.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

void Obroty:: odczytaj_obrot (void)
    {
        M.odczytaj_kat_obr();
        std::cout << "Ile razy operacja obrotu ma byc powtorzona?" << std::endl;
        while(1)
        {
            std::cin >> l_powt;
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cerr << "Błąd niepoprawna liczba powtorzen obrotow. Sprobouj ponownie." << std::endl;
            }
            else break;
        }
    }

    void Obroty::wykonaj_obrot(void)
    {
        odczytaj_obrot();
        for(int i=0; i<l_powt; i++)
        {
            P[0] = M * P[0];
            P[1] = M * P[1];
            P[2] = M * P[2];
            P[3] = M * P[3];
        }
    }

    void Obroty::przesun_o_wektor(void)
    {
        std::cout << "Wprowadz wspolrzedne wektora translacji w postaci dwoch liczb tzn. wspolrzednej x oraz wspolrzednej y."<< std::endl;
        std::cin >> W;
        P+W;
    }

    void Obroty::sprawdz_rownosc(void)
    {
        double buf[2];

        buf[0] = P[0] & P[1];
        buf[1] = P[3] & P[2];

        if (buf[0]>buf[1]-delta && buf[0]<buf[1]+delta)
            std::cout << ":) Dluzsze przeciwlegle boki sa sobie rowne." << std::endl;
        else
            std::cout << ":O Dluzsze przeciwlegle boki nie sa rowne!!!" << std::endl;

        buf[0] = P[1] & P[2];
        buf[1] = P[0] & P[3];

        if (buf[0]>buf[1]-delta && buf[0]<buf[1]+delta)
            std::cout << ":) Krotsze przeciwlegle boki sa sobie rowne." << std::endl;
        else
            std::cout << ":O Krotsze przeciwlegle boki nie sa rowne!!!" << std::endl;
    }
