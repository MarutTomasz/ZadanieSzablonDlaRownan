#include "SWektor.hh"

/********** SET I GET **********/
template<class TYP, int ROZMIAR>
TYP & Wektor<TYP,ROZMIAR>::operator [] (int index){
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  return tab[index];
}

template<class TYP, int ROZMIAR>
const TYP & Wektor<TYP,ROZMIAR>::operator [] (int index) const {
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  return tab[index];
}

/********** KONSTRUKTORY **********/
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR>::Wektor () {
  for (int i=0; i<ROZMIAR; ++i)
    tab[i] = 0;
}

template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR>::Wektor (TYP xx, TYP yy, TYP zz, TYP oo, TYP uu) {
  tab[0] = xx;
  tab[1] = yy;
  tab[2] = zz;
  tab[3] = oo;
  tab[4] = uu;
}

/********** WCZYTYWANIE I WYSWIETLANIE  **********/
template<class TYP, int ROZMIAR>
std::istream & operator>>(std::istream &strm, Wektor<TYP,ROZMIAR> &W){
  for (int i=0; i<ROZMIAR; ++i)
    cin >> W[i];
  return strm;
}

template<class TYP, int ROZMIAR>
std::ostream & operator << (std::ostream &strm, const Wektor<TYP,ROZMIAR> &W) {
  for (int i=0; i<ROZMIAR; ++i)
    cout << W[i] << "  ";
  return strm;
}

/********** OPERACJE MATEMATYCZNE  **********/
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator + (const Wektor<TYP,ROZMIAR> &W) const {
  Wektor<TYP,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; ++i)
    wynik[i] = tab[i] + W[i];
  return wynik;
} 

template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator - (const Wektor<TYP,ROZMIAR> &W) const {
  Wektor<TYP,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; ++i)
    wynik[i] = tab[i] - W[i];
  return wynik;
} 

template<class TYP, int ROZMIAR>
TYP Wektor<TYP,ROZMIAR>::operator*(const Wektor<TYP,ROZMIAR> &W2) const {
  TYP wynik = 0;
  // TYP out(0)   zerowanie dla liczby zespolonej napisac pozniej 
  for (int i=0; i < ROZMIAR; ++i)
    wynik += tab[i] * W2[i];
  //  przeciazenie += dla liczb zespolonych   napisac pozniej
  return wynik;
}

template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator * (TYP liczba) const {
  Wektor<TYP,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; ++i)
    wynik[i] = tab[i] * liczba;
  return wynik;
}

template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator / (TYP liczba) const {
  Wektor<TYP,ROZMIAR> wynik;
  if(liczba == 0){
    //   porownywanie liczby zespolonej z 0
    cout << "Niedozwolone dzielenie przez 0" << endl;
    exit(1);
  }
  for (int i=0; i<ROZMIAR; ++i)
    wynik[i] = tab[i] / liczba;
  return wynik;
}

template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> operator * (TYP liczba, const Wektor<TYP,ROZMIAR> &W) {
  Wektor<TYP,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; ++i)
    wynik[i] = W[i] * liczba;
  return wynik;
}

/********** OPERACJE POROWNIANIA  **********/
template<class TYP, int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator == (const Wektor<TYP,ROZMIAR> &W) const {
  TYP epsilon = 0.000001;
  // Cos dla liczby zepolonej zeby porownac
  for (int i=0; i<ROZMIAR; ++i)
    if (abs(tab[i]- W[i]) > epsilon)
      return false;
  return true;
}

template<class TYP, int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator != (const Wektor<TYP,ROZMIAR> &W) const {
  if (*this == W)
    return false;
  return true;
}

/********** OPERACJE WEKTOROWE  **********/
template<class TYP, int ROZMIAR>
double Wektor<TYP,ROZMIAR>::dlugosc() const{
  double length = 0;
  for (int i=0; i<ROZMIAR; ++i)
    length += (tab[i] * tab[i]);
  length = sqrt(length);
  return length;
}









/*

template<>
double Wektor<LZespolona,5>::dlugosc() const {
  double out=0;
  for (int i=0;i<5;i++) {
  }
  return out;
}


template<int ROZMIAR>
double Wektor<LZ,ROZMIAR>::dlugosc() const {
  double out=0;
  for (int i=0;i<ROZMIAR;i++) {
    out += tab[i] * sprzezenie(tab[i]); 
  }
  return out;
}
 
*/
