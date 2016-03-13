#include <iostream>
#include "Macierz3x3.hh"
#include "point.hh"
#include "manipulator.hh"
#include "Prostopadloscian.hh"
#include "Parawan.hh"
#include "Obiekt.hh"
#include "Menu.hh"
#include "lacze_do_gnuplota.hh"
#include<fstream>

using namespace std;



/*!
 * \file  main.cpp
 *
 *  W typ pliku rozgrywa sie cala akcja programu, sa tutaj zadeklarowane wszystkie funkcje
 *
 */
void menu(Manipulator* jeden, Manipulator* drugi); //ab

int main(int argc, char* argv[]){

	if (argc < 2){ /*! Liczba argumentow wczytania*/
    cout << "Podaj parametry\n";
		return 0;
	}

	Menu* menu = new Menu(argc, argv);

	menu->platforma();
	PzG::LaczeDoGNUPlota Lacze;
    Lacze.DodajNazwePliku("manipulator.dat",PzG::RR_Ciagly, 2);
	Lacze.ZmienTrybRys(PzG::TR_3D);
	Lacze.Inicjalizuj();

	Lacze.UstawZakresY(-150,150);
	Lacze.UstawZakresX(-150,150);
	Lacze.UstawZakresZ(-150,150);

    menu->rot->ZapisDoPliku("manipulator.dat");
	Lacze.Rysuj();
	return 0;
}
