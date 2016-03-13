#include "Wektor2D.hh"
#include <iomanip>
using namespace std;

istream &operator >> (istream &Strm, Wektor2D &Wek)
{
  Strm>>Wek[0]>>Wek[1];
  return Strm;
}
ostream &operator << (ostream &Strm, const Wektor2D &Wek)
{
  Strm << setw(8) << fixed << setprecision(5) << Wek[0]
       << setw(8) << fixed << setprecision(5) << Wek[1];
  return Strm;
}
Wektor2D Wektor2D::operator + (const Wektor2D& Wektor) const
{
  Wektor2D temp;
  temp[0]=this->_wspol[0]+Wektor[0];
  temp[1]=this->_wspol[1]+Wektor[1];
  return temp;
}
