#include "SWektor.hh"
/*!
 * \file
 * \brief Definicje metod i funkcji klasy Wektor
 *
 * Plik zawiera definicje metod i funkcji działających
 * na klasie Wektor oraz specjalizacje wybranych metod. \n
 */


/********** SET I GET **********/
template<class TYP, unsigned int ROZMIAR>
TYP & Wektor<TYP,ROZMIAR>::operator [] (unsigned int index){
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  return tab[index];
}

template<class TYP, unsigned int ROZMIAR>
const TYP & Wektor<TYP,ROZMIAR>::operator [] (unsigned int index) const {
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  return tab[index];
}

/********** KONSTRUKTORY **********/
template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR>::Wektor () {
  for (unsigned int i=0; i<ROZMIAR; ++i)
    tab[i] = 0;
}

template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR>::Wektor (TYP *tabela) {
  for (unsigned int i=0; i<ROZMIAR; ++i)
    tab[i] = tabela[i];
}

/********** WCZYTYWANIE I WYSWIETLANIE  **********/
template<class TYP, unsigned int ROZMIAR>
std::istream & operator>>(std::istream &strm, Wektor<TYP,ROZMIAR> &W){
  for (unsigned int i=0; i<ROZMIAR; ++i)
    cin >> W[i];
  return strm;
}

template<class TYP, unsigned int ROZMIAR>
std::ostream & operator << (std::ostream &strm, const Wektor<TYP,ROZMIAR> &W) {
  for (unsigned int i=0; i<ROZMIAR; ++i)
    cout << W[i] << "  ";
  return strm;
}

/********** OPERACJE MATEMATYCZNE  **********/
template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator + (const Wektor<TYP,ROZMIAR> &W) const {
  Wektor<TYP,ROZMIAR> wynik;
  for (unsigned int i=0; i<ROZMIAR; ++i)
    wynik[i] = tab[i] + W[i];
  return wynik;
} 

template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator - (const Wektor<TYP,ROZMIAR> &W) const {
  Wektor<TYP,ROZMIAR> wynik;
  for (unsigned int i=0; i<ROZMIAR; ++i)
    wynik[i] = tab[i] - W[i];
  return wynik;
} 

template<class TYP, unsigned int ROZMIAR>
TYP Wektor<TYP,ROZMIAR>::operator*(const Wektor<TYP,ROZMIAR> &W2) const {
  TYP wynik;
  wynik = 0.0;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    wynik += tab[i] * W2[i];
  return wynik;
}

template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator * (TYP liczba) const {
  Wektor<TYP,ROZMIAR> wynik;
  for (unsigned int i=0; i<ROZMIAR; ++i)
    wynik[i] = tab[i] * liczba;
  return wynik;
}

template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator / (TYP liczba) const {
  Wektor<TYP,ROZMIAR> wynik;
  if(liczba == 0){
    cout << "Niedozwolone dzielenie przez 0" << endl;
    exit(1);
  }
  for (unsigned int i=0; i<ROZMIAR; ++i)
    wynik[i] = tab[i] / liczba;  
  return wynik;
}

template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> operator * (TYP liczba, const Wektor<TYP,ROZMIAR> &W) {
  Wektor<TYP,ROZMIAR> wynik;
  for (unsigned int i=0; i<ROZMIAR; ++i)
    wynik[i] = W[i] * liczba;
  return wynik;
}

/********** OPERACJE POROWNIANIA  **********/
template<class TYP, unsigned int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator == (const Wektor<TYP,ROZMIAR> &W) const {
  double epsilon = 0.000001;
  for (unsigned int i=0; i<ROZMIAR; ++i)
    if (abs(tab[i]- W[i]) > epsilon)
      return false;
  return true;
}

template<class TYP, unsigned int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator != (const Wektor<TYP,ROZMIAR> &W) const {
  if (*this == W)
    return false;
  return true;
}

/********** OPERACJE WEKTOROWE  **********/
template<class TYP, unsigned int ROZMIAR>
double Wektor<TYP,ROZMIAR>::dlugosc() const{
  double length = 0;
  for (unsigned int i=0; i<ROZMIAR; ++i)
    length += (tab[i] * tab[i]);
  length = sqrt(length);
  return length;
}









/********** SPECJALIZACJE  **********/
/*!
 * \brief Specjalizacja wyliczenia długości wektora 
 *
 * Specjalizacja funkcji wylicza długość wektora rozmiaru 5 z elementami 
 * typu LZespolona jako pierwiastek z sumy 
 * kwadratów modułów wszystkich elementów wektora.
 * \return Zwraca długość wektora.
 */
template<>
double Wektor<LZespolona,5>::dlugosc() const {
  double length=0;
  for (unsigned int i=0;i<5;++i) 
    length += tab[i].modul2(); 
  length = sqrt(length);
  return length;
}

/*!
 * \brief Specjalizacja wyliczenia długości wektora 
 *
 * Specjalizacja funkcji wylicza długość wektora rozmiaru 4 z elementami 
 * typu LZespolona jako pierwiastek z sumy 
 * kwadratów modułów wszystkich elementów wektora.
 * \return Zwraca długość wektora.
 */
template<>
double Wektor<LZespolona,4>::dlugosc() const {
  double length=0;
  for (unsigned int i=0;i<4;++i) 
    length += tab[i].modul2(); 
  length = sqrt(length);
  return length;
}

/*!
 * \brief Specjalizacja wyliczenia długości wektora 
 *
 * Specjalizacja funkcji wylicza długość wektora rozmiaru 3 z elementami 
 * typu LZespolona jako pierwiastek z sumy 
 * kwadratów modułów wszystkich elementów wektora.
 * \return Zwraca długość wektora.
 */
template<>
double Wektor<LZespolona,3>::dlugosc() const {
  double length=0;
  for (unsigned int i=0;i<3;++i) 
    length += tab[i].modul2(); 
  length = sqrt(length);
  return length;
}

/*!
 * \brief Specjalizacja wyliczenia długości wektora 
 *
 * Specjalizacja funkcji wylicza długość wektora rozmiaru 2 z elementami 
 * typu LZespolona jako pierwiastek z sumy 
 * kwadratów modułów wszystkich elementów wektora.
 * \return Zwraca długość wektora.
 */
template<>
double Wektor<LZespolona,2>::dlugosc() const {
  double length=0;
  for (unsigned int i=0;i<2;++i) 
    length += tab[i].modul2(); 
  length = sqrt(length);
  return length;
}

/*!
 * \brief Specjalizacja wyliczenia długości wektora 
 *
 * Specjalizacja funkcji wylicza długość wektora rozmiaru 1 z elementami 
 * typu LZespolona jako pierwiastek z sumy 
 * kwadratów modułów wszystkich elementów wektora.
 * \return Zwraca długość wektora.
 */
template<>
double Wektor<LZespolona,1>::dlugosc() const {
  double length=0;
  for (unsigned int i=0;i<1;++i) 
    length += tab[i].modul2(); 
  length = sqrt(length);
  return length;
}
