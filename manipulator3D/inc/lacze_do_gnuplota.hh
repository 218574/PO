#ifndef LACZE_DO_GNUPLOTA_HH
#define LACZE_DO_GNUPLOTA_HH
#include <string>
#include <list>
#include <vector>

#ifdef __GNUG__
#pragma interface
#endif

/*!
 * \file  lacze_do_gnuplota.hh
 *  
 *  Plik zawiera definicj� klasy realizuj�cej interfejs
 *  komunikacyjny do programu gnuplot.
 */

/*!
 * \brief Modu� narz�dzi umo�liwiaj�cych po��cznie z GNUPlotem
 *
 * Niniejsza przestrze� nazw stanowi modu� logiczny zawieraj�cy
 * narz�dzia umo�liwiaj�ce realizacj� po��czenia z programem \p gnuplot.
 */
namespace PzG
    {

    /*!
     * \brief Okre�la tryb rysowania realizowanego przez program \p gnuplot
     *
     *  Typ wyliczeniowy okre�laj�ce dopuszczalne tryby rysowania
     *  realizowanego przez program \p gnuplot. Wyb�r trybu wi��e si�
     *  ze zmian� sposobu interpretacji danych zawartych pliku. Je�li
     *  np. wybrany zostanie tryb 2D, to zak�ada si�, �e w ka�dej linii
     *  pliku z danymi znajduj� si� warto�ci wsp�rz�dnych \e x, \e y.
     *  Warto�ci typu:
     *   \li \p TR_2D - rysowanie w trybie 2D, co sprowadza si� do
     *                  rysowania wykres�w funkcji jednej zmiennej.
     *   \li \p TR_3D - rysowanie w trybie 3D. Oznacza to mo�liwo��
     *                  rysowania wykres�w funkcji dw�ch zmiennych.
     *
     */
    enum TrybRysowania
	{
	TR_2D,
	TR_3D
	};
    /*!
     * \brief Spos�b rysowania linii
     *
     * Okre�la spos�b rysowania linii.
     */
    enum RodzajRysowania
	{
	RR_Ciagly,
	RR_Punktowy
	};

    /*!
     * \brief Zestaw informacji dotycz�cy pliku i sposobu rysowania
     *
     * Klasa modeluje zestaw informacji dotycz�cy pliku i sposobu
     * w jaki maj� by� wizualizowane zawarte w nim dane.
     */
    class InfoPlikuDoRysowania
	{
    public:
	/*!
	 * Inicjalizuje obiekt.
	 *  \param NazwaPliku - nazwa pliku, z kt�rego pobierane b�d� dane,
	 *  \param RodzRys - rodzaj rysowania linii,
	 *  \param Szerokosc - szerokosc linii.
	 */
	InfoPlikuDoRysowania(const char* NazwaPliku, RodzajRysowania RodzRys,
		int Szerokosc)
	    {
	    _NazwaPliku = NazwaPliku;
	    _RodzRys = RodzRys;
	    _Szerokosc = Szerokosc;
	    }
	/*!
	 * \brief Udost�pia nazw� pliku do rysowania
	 *
	 * Udost�pnia nazw� pliku z danymi do rysowania.
	 */
	const std::string WezNazwePliku() const
	    {
	    return _NazwaPliku;
	    }
	/*!
	 * \brief Zmienia nazw� pliku do rysowania
	 *
	 * Zmienia nazw� pliku z danymi do rysowania.
	 */
	void ZmienNazwePliku(const std::string& NazwaPliku)
	    {
	    _NazwaPliku = NazwaPliku;
	    }
	/*!
	 * \brief Udost�pnia spos�b rysowanej linii
	 *
	 * Udost�pnia informacj� o spos�bie rysowania linii.
	 */
	RodzajRysowania WezRodzRys() const
	    {
	    return _RodzRys;
	    }
	/*!
	 * \brief  Udost�pnia informacj� o szeroko�ci linii.
	 *
	 *  Udost�pnia informacj� o szeroko�ci rysowanej linii.
	 */
	int WezSzerokosc() const
	    {
	    return _Szerokosc;
	    }

    private:
	/*!
	 * \brief Nazwa pliku z danymi do rysowania
	 *
	 * Nazwa pliku z danymi do rysowania.
	 */
	std::string _NazwaPliku;
	/*!
	 * \brief Szeroko�� u�ytego pi�rka
	 *
	 * Okre�la szeroko�� pi�rka, jakie ma by� u�yte
	 * do rysowania obiekt�w graficznych.
	 */
	int _Szerokosc;
	/*!
	 * \brief Spos�b rysowania danej linii
	 *
	 * Przechowuje informacje o sposobie rysowania linii.
	 */
	RodzajRysowania _RodzRys;
	};

    /*!
     * \brief  Klasa realizuje interfejs do programu GNUPlot.
     *
     * Klasa realizuje interfejs do programu GNUPlot. Pozwala ona na wskazanie
     * zbioru punkt�w p�aszczyzn umieszczonych w pliku lub plikach.
     * Ka�dy taki zbi�r mo�e by� nast�pnie wizualizowany przez program
     * gnuplot w postaci oddzielnych p�aszczyzn z wycinaniem cz�ci zas�anianych.
     */
    class LaczeDoGNUPlota
	{
    protected:
	/*!
	 * \brief Lista nazw plik�w z danymi dla \e gnuplota.
	 *
	 * Pole jest zarz�dc� listy nazw plik�w, z kt�rych s� wczytywane
	 * dane dotycz�ce rysowania obrysu bry� przez program \e gnuplot.
	 * Operacja ta wykonywana jest po wywo�aniu polecenia.
	 * \link LaczeDoGNUPlota::Rysuj Rysuj\endlink.
	 */
	static std::list<InfoPlikuDoRysowania> _InfoPlikow;

	/*!
	 *  Pole przechowuje deskryptor do wej�cia standardowego uruchomionego
	 *  programu gnuplot.
	 */
	int _Wejscie_GNUPlota;
	/*!
	 *  Pole przechowuje deskryptor do weyj�cia standardowego uruchomionego
	 *  programu gnuplot.
	 */
	int _Wyjscie_GNUPlota;
	/*!
	 *  \brief Decyduje czy maj� by� wy�wietlane komunikaty o b��dach,
	 *         czy te� nie.
	 *
	 *  Warto�� tego pola decyduje o tym czy komunikaty o b��dach b�d�
	 *  wy�wietlane na wyj�cie standardowe b��d�w (\b cerr), czy te� nie.
	 *   \li \p true - komunikaty b�d� wy�wietlane,
	 *   \li \p false -  komunikaty nie b�d� wy�wietlane.
	 */
	bool _WyswietlajKomunikatyOBledach;

	/*!
	 * \brief Okre�la aktualny tryb rysowania
	 *
	 * Zawarto�� pola determinuje spos�b rysowania, jaki zostanie
	 * wymuszony na progprzegub \p gnuplot poprzez wys�anie do niego
	 * odpowiednich polece�. Wspomniane wymuszenie jest realizowane
	 * poprzez wywo�anie polecenia
	 * \link LaczeDoGNUPlota::Rysuj Rysuj()\endlink
	 */
	TrybRysowania _TrybRys;
	/*!
	 *  \brief Dolny zakres wy�wietlanej skali skali dla osi \e OX.
	 *
	 *  Okre�la dolny zakres wy�wietlanej skali dla osi \e OX.
	 */
	float _Xmin;
	/*!
	 *  \brief G�rny zakres wy�wietlanej skali skali dla osi \e OX.
	 *
	 *  Okre�la g�rny zakres wy�wietlanej skali dla osi \e OX.
	 */
	float _Xmax;
	/*!
	 *  \brief Dolny zakres wy�wietlanej skali skali dla osi \e OY.
	 *
	 *  Okre�la dolny zakres wy�wietlanej skali dla osi \e OY.
	 */
	float _Ymin;
	/*!
	 *  \brief G�rny zakres wy�wietlanej skali skali dla osi \e OY.
	 *
	 *  Okre�la g�rny zakres wy�wietlanej skali dla osi \e OY.
	 */
	float _Ymax;
	/*!
	 *  \brief Dolny zakres wy�wietlanej skali skali dla osi \e OZ.
	 *
	 *  Okre�la dolny zakres wy�wietlanej skali dla osi \e OZ.
	 */
	float _Zmin;
	/*!
	 *  \brief G�rny zakres wy�wietlanej skali skali dla osi \e OZ.
	 *
	 *  Okre�la g�rny zakres wy�wietlanej skali dla osi \e OZ.
	 */
	float _Zmax;
	/*!
	 *  Warto�� tego pola definiuje skalowanie rysunku wzd�u� osi
	 *  \e OX (o� horyzontalna ekranu).
	 */
	float _Xskala;
	/*!
	 *  Warto�� tego pola definiuje skalowanie rysunku wzd�u� osi
	 *  \e OZ (o� wertykalna ekranu).
	 */
	float _Zskala;
	/*!
	 *  Warto�� tego pola definiuje rotacj� rysunku (zmiane punktu patrzenia)
	 *  wzgl�dem osi \e OX.
	 */
	float _Xrotacja;
	/*!
	 *  Warto�� tego pola definiuje rotacj� rysunku (zmiane punktu patrzenia)
	 *  wzgl�dem osi \e OZ.
	 */
	float _Zrotacja;

	/*!
	 * \brief Czy o� OX ma by� widoczna
	 *
	 * Przechowuje informacj� decyduj�c� o tym czy o� OX b�dzie
	 * widoczna na rysunku (\p true), czy te� nie (\p false).
	 */
	bool _PokazOs_OX;

	/*!
	 * \brief Czy o� OY ma by� widoczna
	 *
	 * Przechowuje informacj� decyduj�c� o tym czy o� OY b�dzie
	 * widoczna na rysunku (\p true), czy te� nie (\p false).
	 */
	bool _PokazOs_OY;

	/*!
	 * \brief Tworzy list� parametr�w umo�liwiaj�cych rysowanie dodatkowych element�w
	 *
	 * Metoda ta przewidziana jest jako element rozszerzenia pozwalaj�cego
	 * w klasach pochodnych powi�kszy� list� rysowanych element�w.
	 * \pre Parametr \e Polecenie powinien zawiera� polecenie \e plot lub \e splot,
	 *      do kt�rego b�dzie mo�liwe dopisanie dalszego ci�gu.
	 * \param Polecenie - polecenie rysowania, do kt�rego maj� by� dopisane
	 *                    nazwy plik�w i odpowiednie parametry dla polecenia plot.
	 * \param Sep - zawiera znak separatora mi�dzy poszczeg�lnymi
	 *              parametrami. Je�eli parametry listy przeszk�d
	 *              s� generowane jako pierwsze, to zmienna ta musi
	 *              by� wska�nikiem do wska�nika na �a�cuch: " ".
	 */
	virtual bool DopiszPlikiDoPoleceniaRysowania(std::string &Polecenie,
		char const **Sep);

	/*!
	 *  \brief Tworzy polecenie ustawiaj�ce zakres dla danej wsp�rz�dnej.
	 *
	 *  Tworzy polecenie dla programu \e gnuplot ustawiaj�ce zakres
	 *  wsp�rz�dnych wybranej wsp�rz�dnej \e x, \e y lub \e z,
	 *  dla kt�rej ma by� tworzony dany rysunek.
	 *  \param Os - zawiera znak okre�laj�cy wsp�rz�dn�, dla kt�rej
	 *             ma zosta� wygenerowane polecenie ustawienia zakresu.
	 *  \return �a�cuch znak�w polecenia ustawiaj�cego ��dany zakres
	 *          dla wybranej wsp�rz�dnej.
	 */
	std::string ZapiszUstawienieZakresu(char Os) const;
	/*!
	 *  \brief Tworzy polecenie ustawiaj�ce punkt obserwacji.
	 *
	 *  Tworzy polecenie dla programu \e gnuplot ustawiajaj�ce punkt obserwacji
	 *  poprzez zadanie rotacji i skali dla poszczeg�lnych osi.
	 */
	std::string ZapiszUstawienieRotacjiISkali() const;
	/*!
	 * Przesy�a na wej�cie programu \e gnuplot zadany ci�g znak�w.
	 *  \param Polecenie - komunikat przeznaczony do przeslania.
	 *
	 * \pre  Musi by� zainicjowane po��czenie z programem gnuplot.
	 *
	 * \retval true  - jesli przeslanie polecenia zako�czy�o si� powodzeniem,
	 * \retval false - w przypadku przeciwnym.
	 *
	 */
	bool PrzeslijDoGNUPlota(const char *Polecenie);
	/*!
	 * \brief  Udost�pnia informacj� czy maj� by� wy�wietlane informacje o b��dach.
	 *
	 *  Udost�pnia warto�� pola
	 *  \link LaczeDoGNUPlota::_WyswietlajKomunikatyOBledach
	 *            _WyswietlajKomunikatyOBledach\endlink.
	 *  Okre�la ono, czy maj� by� wy�wietlane komunikaty o b��dach na wyj�cie
	 *  standardowe, czy te� nie.
	 */
	bool CzyWyswietlacKomunikaty() const
	    {
	    return _WyswietlajKomunikatyOBledach;
	    }
	/*!
	 * \brief Uruchamia program \e gnuplot jako proces potomny.
	 */
	bool UtworzProcesPotomny();
	/*!
	 * Wy�wietla na wyj�cie "standard error" komunikat (przekazany jako
	 * parametr), o ile pole
	 *   \link LaczeDoGNUPlota::_WyswietlajKomunikatyOBledach
	 *          _WyswietlajKomunikatyOBledach\endlink  ma warto��
	 * \p true. W przypadku przeciwnym komunikat nie jest wy�wietlany.
	 */
	void KomunikatBledu(const char *Komunikat) const;

	/*!
	 * \brief Tworzy preambu�� poprzedzaj�c� polecenie rysowania
	 *
	 *  Tworzy zbi�r polece�, kt�re ustawiaj� w�a�ciwy tryb rysowania
	 *  oraz zakresy wsp�rz�dnych, jak te� wszystkie inne parametry
	 *  wynikaj�ce z przyj�tego trybu rysowania.
	 */
	void BudujPreambulePoleceniaRysowania(std::string &Preambula) const;

	/*!
	 * \brief Tworzy preambu�� poprzedzaj�c� polecenie rysowania w trybie 2D
	 *
	 *  Tworzy zbi�r polece�, kt�re ustawiaj� w�a�ciwy tryb rysowania
	 *  oraz zakresy wsp�rz�dnych, jak te� wszystkie inne parametry
	 *  wynikaj�ce z trybu rysowania 2D.
	 */
	void BudujPreambule_2D(std::string &Preambula) const;

	/*!
	 * \brief Tworzy preambu�� poprzedzaj�c� polecenie rysowania w trybie 3D
	 *
	 *  Tworzy zbi�r polece�, kt�re ustawiaj� w�a�ciwy tryb rysowania
	 *  oraz zakresy wsp�rz�dnych, jak te� wszystkie inne parametry
	 *  wynikaj�ce z trybu rysowania 3D.
	 */
	void BudujPreambule_3D(std::string &Preambula) const;

    public:

	/*!
	 * \brief Umo�liwia lub zabrania rysowania osi OX
	 *
	 * Umo�liwia lub zabrania rysowania osi \e OX na rysunku wykresu.
	 * \param Pokaz - decyduje o tym czy o� \e OX b�dzie rysowana (\p true),
	 *                czy te� nie (\p false).
	 */
	void PokazOs_OX(bool Pokaz)
	    {
	    _PokazOs_OX = Pokaz;
	    }

	/*!
	 * \brief Czy o� OX ma by� rysowana
	 *
	 * Udost�pnia informacj� czy o� \e OX ma by� rysowana,
	 * czy te� nie.
	 * \retval true - gdy o� \e OX ma by� rysowana,
	 * \retval false - w przypadku przeciwnym.
	 */
	bool PokazOs_OX() const
	    {
	    return _PokazOs_OX;
	    }

	/*!
	 * \brief Umo�liwia lub zabrania rysowania osi OY
	 *
	 * Umo�liwia lub zabrania rysowania osi \e OY na rysunku wykresu.
	 * \param Pokaz - decyduje o tym czy o� \e OY b�dzie rysowana (\p true),
	 *                czy te� nie (\p false).
	 */
	void PokazOs_OY(bool Pokaz)
	    {
	    _PokazOs_OY = Pokaz;
	    }

	/*!
	 * \brief Czy o� OY ma by� rysowana
	 *
	 * Udost�pnia informacj� czy o� \e OY ma by� rysowana,
	 * czy te� nie.
	 * \retval true - gdy o� \e OY ma by� rysowana,
	 * \retval false - w przypadku przeciwnym.
	 */
	bool PokazOs_OY() const
	    {
	    return _PokazOs_OY;
	    }

	/*!
	 *  Udost�pnia doln� warto�� zakresu skali wzd�u� osi \e OX.
	 */
	float Xmin() const
	    {
	    return _Xmin;
	    }
	/*!
	 *  Udost�pnia g�rn� warto�� zakresu skali wzd�u� osi \e OX.
	 */
	float Xmax() const
	    {
	    return _Xmax;
	    }
	/*!
	 *  Udost�pnia doln� warto�� zakresu skali wzd�u� osi \e OY.
	 */
	float Ymin() const
	    {
	    return _Ymin;
	    }
	/*!
	 *  Udost�pnia g�rn� warto�� zakresu skali wzd�u� osi \e OY.
	 */
	float Ymax() const
	    {
	    return _Ymax;
	    }
	/*!
	 *  Udost�pnia doln� warto�� zakresu skali wzd�u� osi \e OZ.
	 */
	float Zmin() const
	    {
	    return _Zmin;
	    }
	/*!
	 *  Udost�pnia g�rn� warto�� zakresu skali wzd�u� osi \e OZ.
	 */
	float Zmax() const
	    {
	    return _Zmax;
	    }

	/*!
	 * \brief Zmienia tryb rysowania
	 *
	 * Zmienia tryb rysowania jaki zostanie wymuszony na progprzegub
	 * \p gnuplot.
	 * \param Tryb - warto�� parametru okre�la nowy tryb rysowania.
	 */
	void ZmienTrybRys(TrybRysowania Tryb)
	    {
	    _TrybRys = Tryb;
	    }

	/*!
	 * \brief Udost�pnia aktualny tryb rysowania
	 *
	 * Udost�pnia informacj� o aktualnym trybie rysowania.
	 */
	TrybRysowania WezTrybRys() const
	    {
	    return _TrybRys;
	    }

	/*!
	 *  \brief Ustawia zakres osi \e OX
	 *
	 * Ustawia zakres osi \e OX. Ogranicza to obszar, kt�ry b�dzie
	 * zwizualizowany przez programa \e gnuplot.
	 * \param Xo - dolna granica obszaru rysowania dla osi \e OX.
	 * \param Xn - g�rna granica obszaru rysowania dla osi \e OX.
	 */
	void UstawZakresX(float Xo, float Xn)
	    {
	    _Xmin = Xo;
	    _Xmax = Xn;
	    }
	/*!
	 *  \brief Ustawia zakres osi \e OY
	 *
	 * Ustawia zakres osi \e OY. Ogranicza to obszar, kt�ry b�dzie
	 * zwizualizowany przez programa \e gnuplot.
	 * \param Yo - dolna granica obszaru rysowania dla osi \e OY.
	 * \param Yn - g�rna granica obszaru rysowania dla osi \e OY.
	 */
	void UstawZakresY(float Yo, float Yn)
	    {
	    _Ymin = Yo;
	    _Ymax = Yn;
	    }
	/*!
	 *  \brief Ustawia zakres osi \e OZ.
	 *
	 * Ustawia zakres osi \e OZ. Ogranicza to obszar, kt�ry b�dzie
	 * zwizualizowany przez programa \e gnuplot.
	 * \param Zo - dolna granica obszaru rysowania dla osi \e OZ.
	 * \param Zn - g�rna granica obszaru rysowania dla osi \e OZ.
	 */
	void UstawZakresZ(float Zo, float Zn)
	    {
	    _Zmin = Zo;
	    _Zmax = Zn;
	    }

	/*!
	 *  \brief Udost�pnia skal� dla osi \e OX.
	 *
	 *  Udost�pnia skal� dla osi \e OX dla tworzonego rysunku.
	 */
	float SkalaX() const
	    {
	    return _Xskala;
	    }
	/*!
	 *  \brief Udost�pnia skal� dla osi \e OZ.
	 *
	 *  Udost�pnia skal� dla osi \e OZ dla tworzonego rysunku.
	 */
	float SkalaZ() const
	    {
	    return _Zskala;
	    }
	/*!
	 *  \brief Zadaje skal� wzd�u� osi \e OZ.
	 *
	 *  Zadaje skal� wzd�u� osi \e OX dla tworzonego rysunku.
	 *  \param skala_x - skala wzd�u� osi \e OX.
	 */
	void UstawSkaleX(float skala_x)
	    {
	    _Xskala = skala_x;
	    }
	/*!
	 *  \brief Zadaje skal� wzd�u� osi \e OZ.
	 *
	 *  Zadaje skal� wzd�u� osi \e OZ dla tworzonego rysunku.
	 *  \param skala_z - skala wzd�u� osi \e OZ.
	 */
	void UstawSkaleZ(float skala_z)
	    {
	    _Zskala = skala_z;
	    }
	/*!
	 *  \brief Zadaje skal� wzd�u� osi \e OX i \e OZ.
	 *
	 *  Zadaje skal� wzd�u� osi \e OX i \e OZ dla tworzonego rysunku.
	 *  \param skala_x - skala wzd�u� osi \e OX.
	 *  \param skala_z - skala wzd�u� osi \e OZ.
	 */
	void UstawSkaleXZ(float skala_x, float skala_z)
	    {
	    UstawSkaleX(skala_x);
	    UstawSkaleZ(skala_z);
	    }

	/*!
	 *  Udost�pnia warto�� k�ta rotacji renderowanego rysunku wok�
	 *  osi \e OX. Zwracana warto�� wyra�ona jest w stopiniach.
	 */
	float RotacjaX() const
	    {
	    return _Xrotacja;
	    }
	/*!
	 *  Udost�pnia warto�� k�ta rotacji renderowanego rysunku wok�
	 *  osi \e OZ. Zwracana warto�� wyra�ona jest w stopiniach.
	 */
	float RotacjaZ() const
	    {
	    return _Zrotacja;
	    }
	/*!
	 * \brief Ustawia rotacj� wok� osi \e OX.
	 *
	 * Zadaje k�t rotacji wok� osi \e OX. Umo�liwia to zmian�
	 * punktu obserwacji renderowanego rysunku.
	 * \param  kat_x - warto�� k�ta rotacji. Jego warto�� podawana
	 *                 jest w stopniach.
	 */
	void UstawRotacjeX(float kat_x)
	    {
	    _Xrotacja = kat_x;
	    }
	/*!
	 * \brief Ustawia rotacj� wok� osi \e OZ.
	 *
	 * Zadaje k�t rotacji wok� osi \e OZ. Umo�liwia to zmian�
	 * punktu obserwacji renderowanego rysunku.
	 * \param  kat_z - warto�� k�ta rotacji. Jego warto�� podawana
	 *                 jest w stopniach.
	 */
	void UstawRotacjeZ(float kat_z)
	    {
	    _Zrotacja = kat_z;
	    }
	/*!
	 * \brief Ustawia rotacj� wok� osi \e OX i \e OZ.
	 *
	 * Zadaje jednocze�nie k�t rotacji wok� osi \e OX i \e OZ.
	 * Umo�liwia to zmian�
	 * punktu obserwacji renderowanego rysunku.
	 * \param  kat_x - warto�� k�ta rotacji wzgl�dem osi \e OX.
	 *                 Jego warto�� podawana
	 *                 jest w stopniach.
	 * \param  kat_z - warto�� k�ta rotacji wzgl�dem osi \e OZ.
	 *                 Jego warto�� podawana
	 *                 jest w stopniach.
	 */
	void UstawRotacjeXZ(float kat_x, float kat_z)
	    {
	    UstawRotacjeX(kat_x);
	    UstawRotacjeZ(kat_z);
	    }

	/*!
	 *  \brief Zezwala lub zabrania wy�wietlania komunikat�w.
	 *
	 *  Metoda pozwala, albo te� zabrania wy�wietlania komunikat�w o bl�dach.
	 *  Je�eli jaka� z operacji nie powiedzie si�, to jako wynik zwracana
	 *  jest warto�� \p false. Opr�cz tego metody takie moga wy�wietla�
	 *  komunikaty, kt�re kierowane s� na wyj�cie "standard error"
	 *  Domy�lnie przymuje si�, �e programista nie chce dodatkwego wy�wietlania
	 *  komunikat�w.
	 */
	void WyswietlajKomunikatyBledow(bool Tryb = true);
	/*!
	 * \brief  Dodaje nazw� pliku.
	 *
	 * Powoduje dodanie do listy plik�w zawierajacych dane dla \e gnuplota,
	 * nowej nazwy pliku.
	 *
	 * \param  NazwaPliku  - nazwa pliku z danymi dla gnuplota.
	 *
	 * \retval true - je�eli istnieje plik o nazwie udost�pnionej poprzez
	 *            parametr
	 *            \e NazwaPliku oraz jest zezwolenie na jego czytanie.
	 *            Nazwa pliku zostaje dodana do listy plik�w z danymi
	 *            dla \e gnuplota.
	 * \retval false - Je�eli nie istnieje plik o nazwie przekazanej poprzez
	 *            parametr \e NazwaPliku.
	 *            Nazwa pliku zostaje dodana do listy plik�w z danymi
	 *            dla \e gnuplota.
	 */
	bool DodajNazwePliku(const char * NazwaPliku, RodzajRysowania RodzRys =
		RR_Ciagly, int Szerokosc = 1);

	/*!
	 * \brief Tworzy list� parametr�w umo�liwiaj�cych rysowanie bry� z plik�w.
	 */
	bool DopiszRysowanieZPlikow(std::string &Polecenie, char const **Sep);

	/*!
	 * \brief Informuje, czy po��czenie z \e gnuplot'em jest zainicjalizowane.
	 *
	 * Informuje, czy po��czenie z programem \e gnuplot jest zainicjowane.
	 * \retval true - je�li tak,
	 * \retval false - w przypadku przeciwnym.
	 */
	bool CzyPolaczenieJestZainicjowane() const;

	/*!
	 *  Je�eli lista plik�w nie jest pusta, to generuje sekwencje polece�
	 *  dla programu \e gnuplot maj�ca na celu narysowanie p�aszczyzn na
	 *  na podstawie danych zawartych w plikach z listy.
	 *
	 *  \pre  Lista plik�w nie powinna by� pusta. Nazwy plik�w na niej
	 *        mo�na umie�ci� za pomoca metody
	 *        \link LaczeDoGNUPlota::DodajNazwe DodajNazwe\endlink.
	 *        Metoda nie wymaga wcze�niejszego zainicjowania po��czenia
	 *        z \e gnuplotem.
	 *  \retval true   - gdy zostaj� poprawnie wys�ane polecenia dla gnuplota.
	 *                 Nie oznacza to jednak, �e proces rysowania zako�czy�
	 *                 si� pomy�lnie.
	 *  \retval false   - gdy po��czenie z gnuplotem nie mo�e zosta� poprawnie
	 *                 zainicjalizowane lub gdy lista plik�w jest pusta.
	 */
	bool Rysuj();
	/*!
	 *  Dzia�a analogicznie jak metoda
	 *  \link LaczeDoGNUPlota::Rysuj Rysuj\endlink, z t� r�nic�, �e
	 *  rysunek robota
	 *  sk�adowany jest w pliku o nazwie przekazanej przez parametr
	 *  \e NazwaPliku.
	 *  Rysunek jest zapisywany w formacie \e PNG.
	 *
	 *  \post Lista plik�w nie powinna by� pusta ponadto powinno by�
	 *        mo�liwe otwarcie do zapisu pliku o nazwie przekazanej przez
	 *        parametr \e NazwaPliku, do kt�rej do��czane jest rozszerzenie
	 *        .ps .
	 *        Metoda nie wymaga wcze�niejszego zainicjowania po��czenia
	 *        z programem \e gnuplot.
	 *
	 *  \retval true   - gdy zostaj� poprawnie wys�ane polecenia dla
	 *                 \e gnuplota.
	 *                 Nie oznacza to jednak, �e proces rysowania zako�czy�
	 *                 si� pomy�lnie.
	 *  \retval false   - gdy po��czenie z gnuplotem nie mo�e zosta� poprawnie
	 *                 zainicjalizowane lub gdy lista plik�w jest pusta lub
	 *                 te� gdy nie mo�na otworzy� pliku do zapisu.
	 */
	bool RysujDoPliku(const char *NazwaPliku);
	/*!
	 *  \brief  Inicjalizuje po��czenie z programem \e gnuplot.
	 *
	 *  Inicjalizuje po��czenie z programem \e gnuplot. Realizowane jest to
	 *  poprzez rozwidlenie procesu i uruchomienie jako procesu potomnego
	 *  programu \e gnuplot. Komunikacja z programem \e gnuplot realizowana jest
	 *  poprzez przej�cie jego wej�cia i wyj�cia standardowego.
	 *
	 *  \retval true - gdy po��czenie z programem \e 0gnuplot zosta�o poprawnie
	 *               zainicjalizowane lub gdy ju� wcze�niej by�o
	 *               zainicjalizowane.
	 *  \retval false - gdy proces inicjalizacji po��czenia zako�czy� si�
	 *               niepowodzeniem.
	 */
	bool Inicjalizuj();
	/*!
	 *  \brief Usuwa ostatni� nazw� pliku.
	 *
	 *  Usuwa ostatni� nazw� z listy nazw plik�w.
	 */
	void UsunOstatniaNazwe();
	/*!
	 *  \brief Kasuje zawarto�� listy nazw plik�w.
	 *
	 *  Calkowicie kasuje zawarto�� listy nazw plik�w.
	 */
	void UsunWszystkieNazwyPlikow();

	LaczeDoGNUPlota();
	virtual ~LaczeDoGNUPlota();
	};

    inline
    bool LaczeDoGNUPlota::DopiszPlikiDoPoleceniaRysowania(std::string &,
	    char const **)
	{
	return true;
	}

    }

#endif
