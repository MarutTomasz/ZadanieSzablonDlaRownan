#include "SMacierzKw.cpp"

template class MacierzKw<Wektor,double,5>;
template std::istream & operator >> (std::istream &strm, MacierzKw<Wektor,double,5> &M);
template std::ostream & operator << (std::ostream &strm, const MacierzKw<Wektor,double,5> &M);
template MacierzKw<Wektor,double,5> operator * (double liczba, const MacierzKw<Wektor,double,5> &M);
