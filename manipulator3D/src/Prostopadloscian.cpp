#include "Prostopadloscian.hh"
#include <fstream>
#include <iomanip>

using namespace std;

/*!
 * \file  Prostopadloscian.hh
 *
 *  Plik zawiera informacje jak jest zaimplementowany Prostopadloscian i jakie sie w nim odbywaja informacje
 *
 */

Prostopadloscian::Prostopadloscian(string plik){
	initVector();

	ifstream WePr;
	WePr.open(plik.c_str());

	if (WePr.good()){
		string nazwa;
		WePr >> nazwa >> nazwa;
		this->nazwa = nazwa;

		double sx, sy, sz;
		WePr >> sx >> sy >> sz;

		double tx, ty, tz;
		WePr >> tx >> ty >> tz;

		for (size_t i = 0; i < Pkt.size(); i++){
			double wx, wy, wz;
			wx = (Pkt[i].getX() * sx) + tx;
			wy = (Pkt[i].getY() * sy) + ty;
			wz = (Pkt[i].getZ() * sz) + tz;

			Pkt[i] = Point(wx, wy, wz);
		}
		WePr.close();
	}
}

void Prostopadloscian::read_posture(string plik){
	ifstream We;

	We.open(plik.c_str());

	double tx, ty, tz;
	if (We.good()){
		We >> tx >> ty >> tz;
		Point trans(tx, ty, tz);

		We.close();

		for (size_t i = 0; i < Pkt.size(); i++){
			Pkt[i] = Pkt[i] + trans;
		}
	}
}

void Prostopadloscian::initVector(){
	Pkt.push_back(Point(1 ,1 , 1));
	Pkt.push_back(Point(1, -1, 1));
	Pkt.push_back(Point(-1, -1, 1));
	Pkt.push_back(Point(-1, 1, 1));

	Pkt.push_back(Point(1, 1, -1));
	Pkt.push_back(Point(1, -1, -1));
	Pkt.push_back(Point(-1, -1, -1));
	Pkt.push_back(Point(-1, 1, -1));
}

void Prostopadloscian::ZapisDoPliku(string napis){
	ofstream plik;

	plik.open(napis.c_str());

	if (plik.good()){
		for (size_t i = 0; i < Pkt.size(); i++){
			plik << setw(10) << fixed << setprecision(5) << Pkt[i].getX();
			plik << setw(10) << fixed << setprecision(5) << Pkt[i].getY();
			plik << setw(10) << fixed << setprecision(5) << Pkt[i].getZ() << endl;
		}

		plik.close();
	}
}
