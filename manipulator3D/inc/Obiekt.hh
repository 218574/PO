#ifndef OBIEKT_HH
#define OBIEKT_HH
#include <string>
 using namespace std;

/*!
 * \file  Obiekt.hh
 *
 * Plik zawierajacy klase Obiekt ktora jest abstrakcja
 *
 */



class Obiekt{
public:

    /*!
     * \brief W publicznym zakresie
     *
     * mamy abstrakcje czytajace posture, bioracego nazwe, typ, inicjaliza\cje Vector oraz ZapisDopliku
     *
     */
	virtual void read_posture(string plik) = 0;
	virtual string getName() = 0;
	virtual string getType() = 0;
	virtual void initVector() = 0;
	virtual void ZapisDoPliku(string plik) = 0;
};

#endif
