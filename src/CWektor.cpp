//#include "LZespolona.hh"
#include "SWektor.cpp"

template class Wektor<double,5>;
template std::istream & operator>>(std::istream &strm, Wektor<double,5> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<double,5> &W);
template Wektor<double,5> operator * (double liczba, const Wektor<double,5> &W);

//template class Wektor<LZespolona,5>;
