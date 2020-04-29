#include "SMacierzKw.cpp"
/*!
 * \file
 * \brief Jawne konkretyzacje szablonu klasy MacierzKw
 *
 * Plik zawiera jawne konkretyzacje szablonu i funkcji 
 * nie należących do klasy MacierzKw. \n
 * \attention Funkcje w tym pliku nie są udokumentowane,
 * ponieważ są to tylko konkretyzacje opisanych już funkcji.
 * 
 */


// NA STALE  RZECZYWISTE
template class MacierzKw<double,5>;
template std::istream & operator >> (std::istream &strm, MacierzKw<double,5> &M);
template std::ostream & operator << (std::ostream &strm, const MacierzKw<double,5> &M);
template MacierzKw<double,5> operator * (double liczba, const MacierzKw<double,5> &M);

// 
template class MacierzKw<double,4>;
template class MacierzKw<double,3>;
template class MacierzKw<double,2>;
template class MacierzKw<double,1>;
template MacierzKw<double,4> pomniejsz_macierz(const MacierzKw<double,5> &M, unsigned int index1, unsigned int index2);
template MacierzKw<double,3> pomniejsz_macierz(const MacierzKw<double,4> &M, unsigned int index1, unsigned int index2);
template MacierzKw<double,2> pomniejsz_macierz(const MacierzKw<double,3> &M, unsigned int index1, unsigned int index2);
template MacierzKw<double,1> pomniejsz_macierz(const MacierzKw<double,2> &M, unsigned int index1, unsigned int index2);



// NA STALE ZESPOLONE

template class MacierzKw<LZespolona,5>;
template std::istream & operator >> (std::istream &strm, MacierzKw<LZespolona,5> &M);
template std::ostream & operator << (std::ostream &strm, const MacierzKw<LZespolona,5> &M);
template MacierzKw<LZespolona,5> operator * (LZespolona liczba, const MacierzKw<LZespolona,5> &M);

// 
template class MacierzKw<LZespolona,4>;
template class MacierzKw<LZespolona,3>;
template class MacierzKw<LZespolona,2>;
template class MacierzKw<LZespolona,1>;
template MacierzKw<LZespolona,1> pomniejsz_macierz(const MacierzKw<LZespolona,2> &M, unsigned int index1, unsigned int index2);
template MacierzKw<LZespolona,2> pomniejsz_macierz(const MacierzKw<LZespolona,3> &M, unsigned int index1, unsigned int index2);
template MacierzKw<LZespolona,3> pomniejsz_macierz(const MacierzKw<LZespolona,4> &M, unsigned int index1, unsigned int index2);
template MacierzKw<LZespolona,4> pomniejsz_macierz(const MacierzKw<LZespolona,5> &M, unsigned int index1, unsigned int index2);


template std::istream & operator >> (std::istream &strm, MacierzKw<LZespolona,4> &M);
template std::ostream & operator << (std::ostream &strm, const MacierzKw<LZespolona,4> &M);
template std::istream & operator >> (std::istream &strm, MacierzKw<LZespolona,3> &M);
template std::ostream & operator << (std::ostream &strm, const MacierzKw<LZespolona,3> &M);
template std::istream & operator >> (std::istream &strm, MacierzKw<LZespolona,2> &M);
template std::ostream & operator << (std::ostream &strm, const MacierzKw<LZespolona,2> &M);
template std::istream & operator >> (std::istream &strm, MacierzKw<LZespolona,1> &M);
template std::ostream & operator << (std::ostream &strm, const MacierzKw<LZespolona,1> &M);
