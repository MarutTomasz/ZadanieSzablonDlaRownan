#ifndef SWEKTOR_S
#define SWEKTOR_S

#include <iostream>
#include <math.h>
#include "LZespolona.hh"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;


template<class TYP ,unsigned int ROZMIAR>
class Wektor {
  TYP tab [ROZMIAR];
  
public:
  //  Metody sluzace jako set i get
  TYP & operator [] (unsigned int index);
  const TYP & operator [] (unsigned int index) const;
  
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
template<class TYP, unsigned int ROZMIAR>
std::ostream & operator<< (std::ostream &strm, const Wektor<TYP,ROZMIAR> &W);

template<class TYP, unsigned int ROZMIAR>
std::istream & operator>> (std::istream &strm, Wektor<TYP,ROZMIAR> &W);

// Operacja matematyczna
template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> operator * (TYP liczba, const Wektor<TYP,ROZMIAR> &W);


template<>
double Wektor<LZespolona,5>::dlugosc() const;

template<>
double Wektor<LZespolona,4>::dlugosc() const;

template<>
double Wektor<LZespolona,3>::dlugosc() const;

template<>
double Wektor<LZespolona,2>::dlugosc() const;

template<>
double Wektor<LZespolona,1>::dlugosc() const;



#endif
