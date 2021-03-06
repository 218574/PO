#include "Wektor2D.hh"
#include <iomanip>
using namespace std;

istream& operator >> (istream &Strm, Wektor2D &Wek)
{
  Strm>>Wek[0]>>Wek[1];
  return Strm;
}
ostream& operator << (ostream &Strm, const Wektor2D &Wek)
{
  Strm << setw(16) << fixed << setprecision(10) << Wek[0]
       << setw(16) << fixed << setprecision(10) << Wek[1];
  return Strm;
}
Wektor2D Wektor2D::operator + (const Wektor2D& Wektor) const
{
  Wektor2D tmp;
  tmp[0]=this->_wsp[0]+Wektor[0];
  tmp[1]=this->_wsp[1]+Wektor[1];
  return tmp;
}
