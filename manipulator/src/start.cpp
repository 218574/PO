#include <iostream>
#include <iomanip>
// #include "lacze_do_gnuplota.hh" 
#include "Manipulator.hh"
#include "unistd.h"


using namespace std;



int main(int argc, char**argv)
{
  char  Opcja;
  // PzG::LaczeDoGNUPlota  Lacze;
  int i = 3;

  Manipulator manip;

  while(i<argc)
  {
  manip.WczytajD(argv[1]);
  manip.WczytajK(argv[2]);
  manip.WczytajK(argv[3]);
  manip.WyznaczWsp();

  ofstream plik("manipulator.dat");
  plik<< manip;
  plik.close();


  // Lacze.DodajNazwePliku("manipulator.dat",PzG::RR_Ciagly,6);
  //Lacze.DodajNazwePliku("manipulator.dat",PzG::RR_Punktowy,2);
  //Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
  // Lacze.ZmienTrybRys(PzG::TR_2D);

  //Lacze.UstawZakresY(-200,200);
  //Lacze.UstawZakresX(-200,200);
  //Lacze.Rysuj(); 
  sleep(2);
  i++;
  }
   
  cout << "Aby zakonczyc nacisnij ENTER ..." << flush;
  cin >> noskipws >> Opcja;
}
