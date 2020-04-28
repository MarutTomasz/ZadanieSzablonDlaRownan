#ifndef SUKLADROWNANL_S
#define SUKLADROWNANL_S

#include "SWektor.hh"
#include "LZespolona.hh"
#include "SMacierzKw.hh"

template <class TYP, unsigned int ROZMIAR>
class UkladRownanL{
  MacierzKw<TYP,ROZMIAR> A; // Ax = b
  Wektor<TYP,ROZMIAR> b;

public:
  // Konstruktory  
  UkladRownanL();
  UkladRownanL(const MacierzKw<TYP,ROZMIAR> & M, const Wektor<TYP,ROZMIAR> & W);
  
  // Metody sluzace jako set i get
  const MacierzKw<TYP,ROZMIAR> & get_A() const;
  const Wektor<TYP,ROZMIAR> & get_b() const;
  void set_A(const MacierzKw<TYP,ROZMIAR> &M);
  void set_b(const Wektor<TYP,ROZMIAR> &W);
  
  Wektor<TYP,ROZMIAR> rozwiaz_Cramer(Wyz_Metoda metoda) const;
  Wektor<TYP,ROZMIAR> rozwiaz_Gauss() const;
};

// Wyswietlanie i wczytywanie
template<class TYP, unsigned int ROZMIAR>
std::istream & operator >> (std::istream &strm, UkladRownanL<TYP,ROZMIAR> &U);

template<class TYP, unsigned int ROZMIAR>
std::ostream & operator << (std::ostream &strm, const UkladRownanL<TYP,ROZMIAR> &U);


#endif
