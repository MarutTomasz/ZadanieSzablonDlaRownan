#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
using std::cout;
using std::showpos;
using std::noshowpos;
using std::endl;
using std::cin;

/****************************************************************
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi  *
 *  przeciazen operatorow arytmetycznych dzialajacych na tej    *
 *  strukturze.                                                 *
 ****************************************************************/

/**************************************
 * Modeluje pojecie liczby zespolonej *
 **************************************/
struct  LZespolona {
  double   re;    /* Pole repezentuje czesc rzeczywista. */
  double   im;    /* Pole repezentuje czesc urojona. */
};


LZespolona operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator / (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator / (LZespolona  Skl1,  double Mudul);
bool operator == (LZespolona Odpowiedz, LZespolona Wynik);
bool operator != (LZespolona Odpowiedz, LZespolona Wynik);
std::istream & operator >> (std::istream &strm, LZespolona &Skl);
std::ostream & operator << (std::ostream &strm, const LZespolona &Skl);

LZespolona utworz(double Re, double Im);
LZespolona sprzez(LZespolona Liczba);
double modul2(LZespolona Liczba);
#endif

//  LZ operator=(double liczba) {re = liczba; im = 0.0; return *this;}
//  LZ operator+= (const LZ &L2);
