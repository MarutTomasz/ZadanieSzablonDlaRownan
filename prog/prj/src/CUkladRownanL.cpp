#include "SUkladRownanL.cpp"
/*!
 * \file
 * \brief Jawne konkretyzacje szablonu klasy UkladRownanL
 *
 * Plik zawiera jawne konkretyzacje szablonu i funkcji 
 * nie należących do klasy UkladRownanL. \n
 * \attention Funkcje w tym pliku nie są udokumentowane,
 * ponieważ są to tylko konkretyzacje opisanych już funkcji.
 * 
 */

template class UkladRownanL<double,5>;
template std::istream & operator >> (std::istream &strm, UkladRownanL<double,5> &U);
template std::ostream & operator << (std::ostream &strm, const UkladRownanL<double,5> &U);

template class UkladRownanL<LZespolona,5>;
template std::istream & operator >> (std::istream &strm, UkladRownanL<LZespolona,5> &U);
template std::ostream & operator << (std::ostream &strm, const UkladRownanL<LZespolona,5> &U);
