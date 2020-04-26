#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <math.h>
#include <iostream>
using std::cout;
using std::showpos;
using std::noshowpos;
using std::endl;
using std::cin;
using std::cerr;

/**************************************
 * Modeluje pojecie liczby zespolonej *
 **************************************/
struct  LZespolona {
  double   re;    /* Pole repezentuje czesc rzeczywista. */
  double   im;    /* Pole repezentuje czesc urojona. */

  LZespolona();
  LZespolona(double RE, double IM);
  
  LZespolona operator =  (double liczba);
  LZespolona operator +  (const LZespolona & Skl) const;
  LZespolona operator -  (const LZespolona & Skl) const;
  LZespolona operator *  (const LZespolona & Skl) const; 
  LZespolona operator *  (double liczba) const; 
  LZespolona operator *= (double liczba) const; 
  LZespolona operator /  (const LZespolona & Skl) const;
  LZespolona operator += (const LZespolona & Skl) const;
  LZespolona operator /  (double Mudul) const;
  
  bool operator == (const LZespolona & Wynik) const;
  bool operator != (const LZespolona & Wynik) const;

  bool operator == (double liczba) const;
  bool operator != (double liczba) const;

  LZespolona sprzez() const;
  double modul2() const;
  double modul() const;
  
};

LZespolona operator * (double liczba, const LZespolona & SKl); 
double abs(const LZespolona & Skl);
std::istream & operator >> (std::istream &strm, LZespolona &Skl);
std::ostream & operator << (std::ostream &strm, const LZespolona &Skl);

#endif
