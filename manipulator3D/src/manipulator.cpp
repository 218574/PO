#include "manipulator.hh"
#include "Macierz3x3.hh"
#include <iomanip>

using namespace std;
/*!
 * \file manipulator.cpp
 *
 * Plik zawierajacy informacje na temat manipulatora
 *
 */
Manipulator::Manipulator(string plik, int type){
  this->type = type;
  
	ifstream WeP;
	WeP.open(plik.c_str());
	
	if (WeP.good()){
	  string nazwa;
	  WeP >> nazwa >> nazwa;  /*! Wczytujemy 1 linijke po czym wczytujemy 2 i nadpisujemy zawartosc zmiennej */
	  cout << "NAzwa " << nazwa << endl;
		this->name_manipulator = nazwa;
		cout << "Konfiguracje manipulatora wczytano z pliku: " << plik << endl;
		
		double tx, ty, tz; /*! Wczytujemy punty translacji*/
		WeP >> tx >> ty >> tz;
		this->translacja = new Point(tx, ty, tz);
		
		double qr;
		WeP >> qr; /*! Wczytyujemy kat zmiany */
		this->qr = qr;
		
		double q, l;
		while (WeP >> q >> l){
		  this->skrzydlo.push_back(q); /*! Dodanie elementu na koniec*/
		  this->czesc.push_back(l);
		  
		}
		
	}
	
	oblicz_pkt();
}

void Manipulator::read_posture(string plik){ /*! Odczytywanie postury pliku*/
  ifstream WePost;
  WePost.open(plik.c_str());
  
  if (WePost.good()){
    WePost >> this->qr;
    double val;
    if (type == Manipulator::TRANS){
      this->czesc.clear(); /*! Po wczytaniu nastepuje czyszczenie wczytanego ramienia aby nie nadpisywac*/
      while (WePost >> val){
				this->czesc.push_back(val);
      }
    }
    else{
      this->skrzydlo.clear(); /*! Po wczytaniu nastepuje czyszczenie wczytanego katu aby nie nadpisywac*/
      while (WePost >> val){
	this->skrzydlo.push_back(val);
      }
    }
  }
  
  oblicz_pkt();
}

void Manipulator::oblicz_pkt() {
  /*! Obliczamy wspolrzedne przegubow oraz efektora*/
  this->points.push_back(Point(0.0, 0.0, 0.0));
  
  for (size_t i = 1; i <= czesc.size(); i++)
    {
      /*! \brief obliczenie wspolrzednych XY*/
      
      double length = this->czesc[i - 1];
      double suma = skrzydlo_sum(i) * (M_PI / 180.0);
      
      Point tmp(cos(suma), sin(suma), 0.0);
		this->points.push_back(points.back() + tmp * length);
    }
  
  /*! Obrót wzgledem osi Y*/
  Macierz3x3 mac;
  mac.katY = this->qr;
  mac.setY();
  
  for (size_t i = 0; i < points.size(); i++){
    points[i] = points[i] * mac;
    
    /*! \brief Translacja */
    
    points[i] = points[i] + *(this->translacja);
  }
  
}

double Manipulator::skrzydlo_sum(size_t n){
  
  /*! \brief Obliczamy sume katow*/
  
  double suma = 0.0;
  
  for (size_t i = 0; i < n; i++)
    {
      suma += this->skrzydlo[i];
    }
  
  return suma;
}

void Manipulator::ZapisDoPliku(string zap) 
  
/* !\brief Zapis do pliku */
  
{
  ofstream plik2;
  plik2.open(zap.c_str());
  if(plik2.good()){
    for(size_t i=0; i<points.size(); i++){
      plik2<<setw(16)<<fixed<<setprecision(10)<<points[i].getX();
      plik2<<setw(16)<<fixed<<setprecision(10)<<points[i].getY();
      plik2<<setw(16)<<fixed<<setprecision(10)<<points[i].getZ()<<endl;
    }
  }
  plik2.close();
}
