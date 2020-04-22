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
Wektor<TYP,ROZMIAR>::Wektor (TYP *tabela) {
  for (int i=0; i<ROZMIAR; ++i)
    tab[i] = tabela[i];
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
  TYP wynik;
  wynik = 0.0;
  for (int i=0; i < ROZMIAR; ++i)
    wynik += tab[i] * W2[i];
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
  double epsilon = 0.000001;
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









/********** SPECJALIZACJE  **********/

template<>
bool Wektor<LZespolona,5>::operator == (const Wektor<LZespolona,5> &W) const {
  double epsilon = 0.000001;
  for (int i=0; i<5; ++i)
    if (abs(tab[i].modul() - W[i].modul()) > epsilon)
      return false;
  return true;
}
  
template<>
Wektor<LZespolona,5> Wektor<LZespolona,5>::operator / (LZespolona liczba) const {
  Wektor<LZespolona,5> wynik;
  if(liczba.modul() == 0){
    cout << "Niedozwolone dzielenie przez 0" << endl;
    exit(1);
  }
  for (int i=0; i<5; ++i)
    wynik[i] = tab[i] / liczba;
  return wynik;
}

template<>
double Wektor<LZespolona,5>::dlugosc() const {
  double length=0;
  for (int i=0;i<5;++i) {
    length += tab[i].modul2(); 
  }
  length = sqrt(length);
  return length;
}


