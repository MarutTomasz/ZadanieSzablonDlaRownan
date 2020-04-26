#ifndef SMACIERZ_S
#define SMACIERZ_S

#include "SWektor.hh"
#include "LZespolona.hh"

enum Wyz_Metoda {Laplace, Gauss};
enum Odw_Metoda {Gauss_Jordan, Definicja};

// IMPLEMENTACJA WEKTOROW JAKO WIERSZY MACIERZY !!


template<template<class,unsigned int>class Wektor,class TYP , unsigned int ROZMIAR>
class MacierzKw {
  Wektor<TYP,ROZMIAR> tab[ROZMIAR];
  MacierzKw<Wektor,TYP,ROZMIAR> macierz_dopelnien() const;
  void przestaw_wiersze(unsigned int index1, unsigned int index2);
  void przestaw_kolumny(unsigned int index1, unsigned int index2);
  void MacierzJednostkowa(); 
  void zmien_wiersz(unsigned int index, const Wektor<TYP,ROZMIAR> W);
 
public:
  // Metody sluzace jako set i get
  Wektor<TYP,ROZMIAR> & operator[] (unsigned int index);
  const Wektor<TYP,ROZMIAR> & operator[] (unsigned  int index) const;
  
  
  // Konstruktory  
  MacierzKw();
  MacierzKw(Wektor<TYP,ROZMIAR> *tabela);
  
  // Operacje matematyczne
  MacierzKw<Wektor,TYP,ROZMIAR> operator +(const MacierzKw<Wektor,TYP,ROZMIAR> &M) const;
  MacierzKw<Wektor,TYP,ROZMIAR> operator -(const MacierzKw<Wektor,TYP,ROZMIAR> &M) const;
  MacierzKw<Wektor,TYP,ROZMIAR> operator *(const MacierzKw<Wektor,TYP,ROZMIAR> &M) const; 
  MacierzKw<Wektor,TYP,ROZMIAR> operator *(TYP liczba) const;
  MacierzKw<Wektor,TYP,ROZMIAR> operator /(TYP liczba) const;
  Wektor<TYP,ROZMIAR> operator *(const Wektor<TYP,ROZMIAR> &W) const;
  
  // Operacje porownania
  bool operator == (const MacierzKw<Wektor,TYP,ROZMIAR> &M) const;
  bool operator != (const MacierzKw<Wektor,TYP,ROZMIAR> &M) const;
  
  // Metody macierzowe
  void transponuj();
  void zmien_kolumne(unsigned int index, const Wektor<TYP,ROZMIAR> W);
  TYP wyznacznik(Wyz_Metoda metoda) const; //Laplace, Gauss,
  MacierzKw<Wektor,TYP,ROZMIAR> odwroc(Odw_Metoda metoda) const; //Definicja, Gauss_Jordan
};
  
  
// Wyswietlanie i wczytywanie
template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
std::istream & operator >> (std::istream &strm, MacierzKw<Wektor,TYP,ROZMIAR> &M);

template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
std::ostream & operator << (std::ostream &strm, const MacierzKw<Wektor,TYP,ROZMIAR> &M);

// Operacja matematyczna
template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
MacierzKw<Wektor,TYP,ROZMIAR> operator *(TYP liczba, const MacierzKw<Wektor,TYP,ROZMIAR> &M); 






// Typowo macierzowe
template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
MacierzKw<Wektor,TYP,ROZMIAR-1> pomniejsz_macierz(const MacierzKw<Wektor,TYP,ROZMIAR> &M, unsigned int index1, unsigned int index2);
  
template<>
double MacierzKw<Wektor,double,1>::wyznacznik(Wyz_Metoda metoda) const;

template<>
MacierzKw<Wektor,double,1> MacierzKw<Wektor,double,1>::macierz_dopelnien() const;



// SPECJALIZACJE ZESPOLONE

template<>
LZespolona MacierzKw<Wektor,LZespolona,1>::wyznacznik(Wyz_Metoda metoda) const;

template<>
MacierzKw<Wektor,LZespolona,1> MacierzKw<Wektor,LZespolona,1>::macierz_dopelnien() const;

#endif
