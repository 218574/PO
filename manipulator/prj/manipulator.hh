#ifndef MANIPULATOR_HH
#define MANIPULATOR_HH
#include <vector>
#include <fstream>

class manipulator{
public:
  std::vector < float > dl_ogniwa;
  std::vector < float > kat_przeg;
  
  void wczytajDlOgniwa (char *nazwapliku);
  void wczytajKat(char *nazwapliku);
};

//void wyliczmacierz();
//void wyliczwektor();

#endif

