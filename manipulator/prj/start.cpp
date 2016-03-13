#include <iostream>
#include <iomanip>
#include "lacze_do_gnuplota.hh"


using namespace std;



int main() 
{
  char  Opcja;
  PzG::LaczeDoGNUPlota  Lacze;


  Lacze.DodajNazwePliku("manipulator.dat",PzG::RR_Ciagly,6);
  Lacze.DodajNazwePliku("manipulator.dat",PzG::RR_Punktowy,2);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
  Lacze.ZmienTrybRys(PzG::TR_2D);

  Lacze.UstawZakresY(-5,35);
  Lacze.UstawZakresX(-35,35);
  Lacze.Rysuj(); 
   
  cout << "Aby zakonczyc nacisnij ENTER ..." << flush;
  cin >> noskipws >> Opcja;
}
