#ifndef MENU_HH
#define MENU_HH
#include "manipulator.hh"
#include "Obiekt.hh"
#include "Prostopadloscian.hh"
#include "Parawan.hh"
#include <list>
#include <string>

using namespace std;
/*!
 * \file  menu.hh
 *
 * Plik zawierajacy klase Menu, odpowiedzialna za wyswietlenie i stworzenie Menu
 *
 */



class Menu{
  /*! \brief tworzenie klasy menu */
public:	
  Manipulator *trans, *rot;
private:
  
  /*! \brief utworzenie listy obiektow wraz z metodami */
  list<Obiekt*> listaObiektow;
  void printNames();
  void moveObject();
  string PobierzNazwePliku();
public:
  Menu(size_t num, char* ElemTab[]);
  void platforma(); //menu wyboru
  
  
};


#endif
