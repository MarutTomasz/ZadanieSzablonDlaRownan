#include "LZespolona.cpp"
#include "SWektor.cpp"

template class Wektor<double,5>;
template std::istream & operator>>(std::istream &strm, Wektor<double,5> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<double,5> &W);
template Wektor<double,5> operator * (double liczba, const Wektor<double,5> &W);

template class Wektor<LZespolona,5>;
template std::istream & operator>>(std::istream &strm, Wektor<LZespolona,5> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<LZespolona,5> &W);
template Wektor<LZespolona,5> operator * (LZespolona liczba, const Wektor<LZespolona,5> &W);
