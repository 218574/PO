#include "Menu.hh"

using namespace std;

/*!
 * \file  Menu.cpp
 *
 * Plik zawierajacy wszyztkie informacje ktore dzieja sie w menu
 *
 */


Menu::Menu(size_t num, char* ElemTab[]){
  ifstream We;
  
  for (size_t i = 1; i < num; i++){
    We.open(ElemTab[i]);
    
    string type;
    We >> type;
    
    We.close();
    cout << "Elem tab " << ElemTab[i] << endl;
    cout << "type " << type << "equal to " << (type== "manipulator_trans") << " equal2 to " <<  (type == "manipulator_rot") << endl;
    
    if (type == "manipulator_trans"){
      this->trans = new Manipulator(string(ElemTab[i]), Manipulator::TRANS);
    }
    else if (type == "manipulator_rot"){
      this->rot = new Manipulator(string(ElemTab[i]), Manipulator::ROT);
      
    }
    else if (type == "prostopadloscian"){
      this->listaObiektow.push_back(new Prostopadloscian(string(ElemTab[i])));
    }
    else {
      this->listaObiektow.push_back(new Parawan(string(ElemTab[i])));
    }
  }

  cout << "Wielkosc bazy " <<  listaObiektow.size() << endl;

  
}



void Menu::printNames(){
  cout << (*trans).getName() << (*trans).getType()<< endl;
  cout << (*rot).getName()  << (*rot).getType()<< endl;
  
  list<Obiekt*>::iterator it = listaObiektow.begin();
  
  for(; it != listaObiektow.end(); it++){
    cout << (*it)->getName() << (*it)->getType() <<endl;
  }
}

void Menu::moveObject(){
  cout << "Nazwa obiektu> ";
  string nazwa;
  cin >> nazwa;
  
  if (nazwa==(*trans).getName()){
    string filename = PobierzNazwePliku();
    (*trans).read_posture(filename);
    
    (*trans).ZapisDoPliku((*trans).getName() + ".dat");
    
    cout << "Wykonano polecenie dla: " << (*trans).getName() << (*trans).getType()<< endl;

    
  }
  else if (nazwa==(*rot).getName()){
    string filename = PobierzNazwePliku();
    (*rot).read_posture(filename);
    
    (*rot).ZapisDoPliku((*rot).getName() + ".dat");
    
    cout << "Wykonano polecenie dla: " << (*rot).getName() << (*rot).getType()<< endl;

  }
  else {
    
    list<Obiekt*>::iterator it = listaObiektow.begin();
    
    for(; it != listaObiektow.end(); it++){
      if(nazwa == (*it)->getName() ){
	string plik = PobierzNazwePliku();
	(*it)->read_posture(plik);
	
	(*it)->ZapisDoPliku((*it)->getName() + ".dat");
	
	cout << "Wykonano polecenie dla: " << (*it)->getName() << (*it)->getType()<< endl;

      }
    }
    
  }
  

}

string Menu::PobierzNazwePliku(){
  cout << "Podaj nazwe pliku> ";
  string file;
  cin >> file;
  
  return file;
}
void Menu::platforma(){
  string menu = "n - podaj nazwe obiektu\nw - wyswietl nazwe obiektow\nm - wyswietl menu\nk - zakoncz program\n";

  cout << menu << endl;

  bool CzyKoniec = false;
  while (!CzyKoniec){
    cout << "Twoj wybor? (m - menu) > ";
    char znak;
    cin >> znak;

    switch (znak){
    case 'w':
      printNames();
      break;
    case 'n':
      moveObject();
      break;
    case 'm':
      cout << menu << endl;
      break;
    case 'k':
      CzyKoniec = true;
      break;
    }


  }
}
