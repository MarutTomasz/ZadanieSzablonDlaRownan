#include <iostream>
#include <math.h>
#include "LZespolona.hh"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;


template<class TYP , int ROZMIAR>
class Wektor {
  TYP tab [ROZMIAR];
  
public:
  //  Metody sluzace jako set i get
  TYP & operator [] (int index);
  const TYP & operator [] (int index) const;
  
  // Konstruktory
  Wektor();
  Wektor(TYP *tabela);
  
  // Operacje matematyczne
  Wektor<TYP,ROZMIAR> operator + (const Wektor<TYP,ROZMIAR> &W2) const;
  Wektor<TYP,ROZMIAR> operator - (const Wektor<TYP,ROZMIAR> &W2) const;
  TYP operator * (const Wektor<TYP,ROZMIAR> &W2) const;
  Wektor<TYP,ROZMIAR> operator * (TYP liczba) const;
  Wektor<TYP,ROZMIAR> operator / (TYP liczba) const;

  
  
  // Operacje porownania
  bool operator == (const Wektor<TYP,ROZMIAR> &W) const;
  bool operator != (const Wektor<TYP,ROZMIAR> &W) const;

  // Metody wektorowe
  double dlugosc() const;
  
 
};

// Wyswietlanie i wczytywanie
template<class TYP, int ROZMIAR>
std::ostream & operator<< (std::ostream &strm, const Wektor<TYP,ROZMIAR> &W);

template<class TYP, int ROZMIAR>
std::istream & operator>> (std::istream &strm, Wektor<TYP,ROZMIAR> &W);

// Operacja matematyczna
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> operator * (TYP liczba, const Wektor<TYP,ROZMIAR> &W);




template<>
double Wektor<LZespolona,5>::dlugosc() const;

template<>
bool Wektor<LZespolona,5>::operator == (const Wektor<LZespolona,5> &W) const;

template<>
Wektor<LZespolona,5> Wektor<LZespolona,5>::operator / (LZespolona liczba) const;
