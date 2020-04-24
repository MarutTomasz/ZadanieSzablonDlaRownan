#include "SWektor.hh"

enum Wyz_Metoda {Sarrus, Laplace, Gauss};
enum Odw_Metoda {Gauss_Jordan, Definicja};

// IMPLEMENTACJA WEKTOROW JAKO WIERSZY MACIERZY !!


template<template<class,unsigned int>class Wektor,class TYP , unsigned int ROZMIAR>
class MacierzKw {
  Wektor<TYP,ROZMIAR> tab[ROZMIAR];
  /*
  void przestaw_kolumny(int index1, int index2);
  double wyznacznik2_2(int index1, int index2) const; // prowizorka dla 3x3
  MacierzKw macierz_dopelnien () const;  // prowizorka dla 3x3
  */  

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
  Wektor<TYP,ROZMIAR> operator *(const Wektor<TYP,ROZMIAR> &W) const;
  
  
  // Operacje porownania
  bool operator == (const MacierzKw<Wektor,TYP,ROZMIAR> &M) const;
  bool operator != (const MacierzKw<Wektor,TYP,ROZMIAR> &M) const;

  
  void MacierzJednostkowa(); 
  /*
  // Metody macierzowe
  double wyznacznik(Wyz_Metoda metoda) const; //Laplace, Gauss, Sarrus
  MacierzKw odwroc(Odw_Metoda metoda) const; //Definicja, Gauss_Jordan
  void przestaw_wiersze(int index1, int index2);
  void transponuj();
  void zmien_wiersz(int index, const Wektor W);
  void zmien_kolumne(int index, const Wektor W);  
  */
};
  
  
// Wyswietlanie i wczytywanie
template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
std::istream & operator >> (std::istream &strm, MacierzKw<Wektor,TYP,ROZMIAR> &M);

template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
std::ostream & operator << (std::ostream &strm, const MacierzKw<Wektor,TYP,ROZMIAR> &M);

// Operacja matematyczna
template<template<class,unsigned int>class Wektor, class TYP, unsigned int ROZMIAR>
MacierzKw<Wektor,TYP,ROZMIAR> operator *(TYP liczba, const MacierzKw<Wektor,TYP,ROZMIAR> &M); 
