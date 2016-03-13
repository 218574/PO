#include "Parawan.hh"
#include <fstream>
#include <string>
#include <iomanip>
 using namespace std;

/*!
 * \file  Parawan.cpp
 *
 *  Plik zawierajacy informacje jak zostaje zaimplementowany Parawan i jakie operacje sie w nim dzieja
 *
 */

Parawan::Parawan(string plik){
	initVector();

	ifstream WeP;
	WeP.open(plik.c_str());

	if (WeP.good()){
		string nazwa;
		WeP >> nazwa >> nazwa;
		this->nazwa = nazwa;

		double sx, sy, sz;
		WeP >> sx >> sy >> sz;

		double tx, ty, tz;
		WeP >> tx >> ty >> tz;

		for (size_t i = 0; i < Pkt.size(); i++){
			double wx, wy, wz;
			wx = (Pkt[i].getX() * sx) + tx;
			wy = (Pkt[i].getY() * sy) + ty;
			wz = (Pkt[i].getZ() * sz) + tz;

			Pkt[i] = Point(wx, wy, wz);
		}
		WeP.close();
	}


}

void Parawan::read_posture(string plik){
	ifstream plik1;

	plik1.open(plik.c_str());

	double tx, ty, tz;
	if (plik1.good()){
		plik1 >> tx >> ty >> tz;
		Point trans(tx, ty, tz);

		plik1.close();

		for (size_t i = 0; i < Pkt.size(); i++){
			Pkt[i] = Pkt[i] + trans;
		}
	}
}

void Parawan::initVector(){
	Pkt.push_back(Point(1, -2, 1));
	Pkt.push_back(Point(-1, -2, 1));

	Pkt.push_back(Point(1, -1, -1));
	Pkt.push_back(Point(-1, -1, -1));

	Pkt.push_back(Point(1, 0, 1));
	Pkt.push_back(Point(-1, 0, 1));

	Pkt.push_back(Point(-1, 1, -1));
	Pkt.push_back(Point(1, 1, -1));

}

void Parawan::ZapisDoPliku(string plik){
	ofstream plik2;

	plik2.open(plik.c_str());

	if (plik2.good()){
		for (size_t i = 0; i < Pkt.size(); i++){
			plik2 << setw(10) << fixed << setprecision(5) << Pkt[i].getX();
			plik2 << setw(10) << fixed << setprecision(5) << Pkt[i].getY();
			plik2 << setw(10) << fixed << setprecision(5) << Pkt[i].getZ() << endl;
		}

		plik2.close();
	}
}
