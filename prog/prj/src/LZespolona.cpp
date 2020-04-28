#include "LZespolona.hh"
/*!
 * \file
 * \brief Definicje metod i funkcji dla struktury LZespolona
 *
 * Plik zawiera definicje metod i funkcji działających na 
 * strukturze LZespolona
 */


LZespolona::LZespolona(){
  re = 0;
  im = 0;
}

LZespolona::LZespolona(double RE, double IM){
  re = RE;
  im = IM;
}

LZespolona LZespolona::operator = (double liczba) {
  re = liczba;
  im = 0;
  return *this;
}

LZespolona LZespolona::operator + (const LZespolona & Skl) const {
  LZespolona  Wynik;
  Wynik.re = re + Skl.re;
  Wynik.im = im + Skl.im;
  return Wynik;
}

LZespolona LZespolona::operator += (const LZespolona & Skl){
  re = re + Skl.re;
  im = im + Skl.im;
  return *this;
}

LZespolona LZespolona::operator - (const LZespolona & Skl) const {
  LZespolona  Wynik;
  Wynik.re = re - Skl.re;
  Wynik.im = im - Skl.im;
  return Wynik;
}

LZespolona LZespolona::operator * (const LZespolona & Skl) const {
  LZespolona  Wynik;
  Wynik.re = (re * Skl.re) - (im * Skl.im);
  Wynik.im = (re * Skl.im) + (im * Skl.re);
  return Wynik;
}

LZespolona LZespolona::operator * (double liczba) const {
  LZespolona  Wynik;
  Wynik.re = re * liczba;
  Wynik.im = im * liczba;
  return Wynik;
}

LZespolona LZespolona::operator *= (double liczba) {
  re = re * liczba;
  im = im * liczba;
  return *this;
}

LZespolona operator * (double liczba, const LZespolona & Skl) {
  LZespolona  Wynik;
  Wynik.re = Skl.re * liczba;
  Wynik.im = Skl.im * liczba;
  return Wynik;
}

LZespolona LZespolona::operator / (double liczba) const {
  LZespolona  Wynik;
  if(liczba != 0){
    Wynik.re = re / liczba;
    Wynik.im = im / liczba;
    return Wynik;
  }
  cerr << "Nie można dzielić przez 0" << endl;
  exit(1);
}

LZespolona LZespolona::operator / (const LZespolona & Skl) const{
  LZespolona Wynik;
  LZespolona Sprzezenie = Skl.sprzez();
  LZespolona Licznik = *this * Sprzezenie;
  double Modul = Skl.modul2();
  Wynik = Licznik / Modul;
  return Wynik;
}

bool LZespolona::operator == (const LZespolona & Arg) const {
  if (re == Arg.re)
    if (im == Arg.im)
      return true;
  return false;
}

bool LZespolona::operator != (const LZespolona & Arg) const {
  if (*this == Arg)
    return false;
  return true;
}

bool LZespolona::operator == (double liczba) const {
  if ((*this).modul() == liczba)
      return true;
  return false;
}

bool LZespolona::operator != (double liczba) const {
  if (*this == liczba)
    return false;
  return true;
}

LZespolona LZespolona::sprzez() const {
  LZespolona Wynik;
  Wynik.re = re;
  Wynik.im = im * (-1);
  return Wynik;
}

double LZespolona::modul2() const {
  double Modul = (re * re) + (im * im);
  return Modul;
}

double LZespolona::modul() const {
  double Modul = (re * re) + (im * im);
  Modul = sqrt(Modul);
  return Modul;
}


std::ostream & operator << (std::ostream &strm, const LZespolona &Liczba) {
  cout << '(' << Liczba.re << showpos << Liczba.im << noshowpos << "i)";
  return strm; 
}

std::istream & operator >> (std::istream &strm, LZespolona &Liczba) {
  char znak;
  strm >> znak;
  if (znak != '(')
    strm.setstate(std::ios::failbit);

  strm >> Liczba.re >> Liczba.im >> znak;
  if (znak != 'i')
    strm.setstate(std::ios::failbit);

  strm >> znak;
  if (znak != ')')
    strm.setstate(std::ios::failbit);
  return strm;
}

double abs(const LZespolona & Skl) {
  return abs(Skl.modul());
}
