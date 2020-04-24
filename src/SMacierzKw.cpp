#include "SMacierzKw.hh"

/********** SET I GET  **********/
template<template<class,unsigned int>class Wektor,class TYP , unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> & MacierzKw<Wektor,TYP,ROZMIAR>::operator[] (unsigned int index) {
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  return tab[index];
}

template<template<class,unsigned int>class Wektor,class TYP , unsigned int ROZMIAR>
const Wektor<TYP,ROZMIAR> & MacierzKw<Wektor,TYP,ROZMIAR>::operator[] (unsigned int index) const {
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  return tab[index];
}

/********** KONSTRUKTORY **********/
template<template<class,unsigned int>class Wektor,class TYP , unsigned int ROZMIAR>
MacierzKw<Wektor,TYP,ROZMIAR>::MacierzKw() {
  Wektor<TYP,ROZMIAR> W;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    tab[i] = W;  
}

template<template<class,unsigned int>class Wektor,class TYP , unsigned int ROZMIAR>
MacierzKw<Wektor,TYP,ROZMIAR>::MacierzKw(Wektor<TYP,ROZMIAR> *tabela) {
  for (unsigned int i=0; i < ROZMIAR; ++i)
    tab[i] = tabela[i];
}

/********** WCZYTYWANIE I WYSWIETLANIE **********/
template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
std::istream & operator >> (std::istream &strm, MacierzKw<Wektor,TYP,ROZMIAR> &M) {
  for (unsigned int i=0; i < ROZMIAR; ++i)
    cin >> M[i];
  //  M.transponuj();
  return strm;
}

template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
std::ostream & operator << (std::ostream &strm, const MacierzKw<Wektor,TYP,ROZMIAR> &M) {
  for (unsigned int i=0; i < ROZMIAR; ++i)
    cout << M[i] << endl;
  return strm;
}

/********** OPERACJE MATEMATYCZNE **********/
template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
MacierzKw<Wektor,TYP,ROZMIAR> MacierzKw<Wektor,TYP,ROZMIAR>::operator + (const MacierzKw<Wektor,TYP,ROZMIAR> &M) const {
  MacierzKw<Wektor,TYP,ROZMIAR> Wynik;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    Wynik [i] = tab[i] + M[i];
  return Wynik;
}

template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
MacierzKw<Wektor,TYP,ROZMIAR> MacierzKw<Wektor,TYP,ROZMIAR>::operator - (const MacierzKw<Wektor,TYP,ROZMIAR> &M) const {
  MacierzKw<Wektor,TYP,ROZMIAR> Wynik;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    Wynik [i] = tab[i] - M[i];
  return Wynik;
}

template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
MacierzKw<Wektor,TYP,ROZMIAR> MacierzKw<Wektor,TYP,ROZMIAR>::operator *(const MacierzKw<Wektor,TYP,ROZMIAR> &M) const {
  MacierzKw<Wektor,TYP,ROZMIAR> Wynik;
  MacierzKw<Wektor,TYP,ROZMIAR> KopiaM = M;
  // KopiaM.transponuj();
  for (unsigned int i=0; i < ROZMIAR; ++i)
    for (unsigned int j=0; j < ROZMIAR; ++j)
      Wynik[i][j] = tab[i] * KopiaM[j];
  return Wynik;
}

template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
MacierzKw<Wektor,TYP,ROZMIAR> MacierzKw<Wektor,TYP,ROZMIAR>::operator *(TYP liczba) const {
  MacierzKw<Wektor,TYP,ROZMIAR> Wynik;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    Wynik[i] = tab[i] * liczba;
  return Wynik;
}

template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR>MacierzKw<Wektor,TYP,ROZMIAR>::operator *(const Wektor<TYP,ROZMIAR> &W) const {
  Wektor<TYP,ROZMIAR> Wynik;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    Wynik[i] = tab[i] * W;
  return Wynik;
}

template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
MacierzKw<Wektor,TYP,ROZMIAR> operator *(TYP liczba, const MacierzKw<Wektor,TYP,ROZMIAR> &M) {
  MacierzKw<Wektor,TYP,ROZMIAR> Wynik;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    Wynik[i] = M[i] * liczba;
  return Wynik;
}


/********** OPERACJE POROWNANIA  **********/
template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
bool MacierzKw<Wektor,TYP,ROZMIAR>::operator == (const MacierzKw<Wektor,TYP,ROZMIAR> &M) const {
  double epsilon = 0.000001;
  for (unsigned int i=0; i < ROZMIAR; ++i)
    for (unsigned int j=0; j < ROZMIAR; ++j)
      if(abs(tab[i][j] - M[i][j]) > epsilon)
	return false;
  return true;
}

template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
bool MacierzKw<Wektor,TYP,ROZMIAR>::operator != (const MacierzKw<Wektor,TYP,ROZMIAR> &M) const {
  if( *this == M)
    return false;
  return true;
}

// Funkjca macierzowa
template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
void MacierzKw<Wektor,TYP,ROZMIAR>::MacierzJednostkowa() {
  for (unsigned int i=0; i < ROZMIAR; ++i)
    for (unsigned int j=0; j < ROZMIAR; ++j)
      if (i == j)
   	tab[i][j] = 1;
}
  
