#include "Macierz2x2.hh"
#include "Wektor2D.hh"

Wektor2D Macierz2x2::operator * (const Wektor2D &Wektor) const
{
  Wektor2D temp;
  temp[0]=_el[0][0]*Wektor[0]+_el[1][0]*Wektor[1];
  temp[1]=_el[0][1]*Wektor[0]+_el[1][1]*Wektor[1];
  return temp;
}

std::ostream &operator << (std::ostream &Strm,const Macierz2x2 &Mac)
{
  for(int w=0;w<2;w++)
    {
      for(int k=0;k<2;k++)
	Strm<<Mac(w,k)<<" ";
      Strm<<"\n";
    }
  return Strm;
}
