#include "SWektor.cpp"

// NA STALE 5
template class Wektor<double,5>;
template std::istream & operator>>(std::istream &strm, Wektor<double,5> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<double,5> &W);
template Wektor<double,5> operator * (double liczba, const Wektor<double,5> &W);

template class Wektor<LZespolona,5>;
template std::istream & operator>>(std::istream &strm, Wektor<LZespolona,5> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<LZespolona,5> &W);
template Wektor<LZespolona,5> operator * (LZespolona liczba, const Wektor<LZespolona,5> &W);

// TYMCZASOWO 4
template class Wektor<double,4>;
template Wektor<double,4> operator * (double liczba, const Wektor<double,4> &W);

template class Wektor<LZespolona,4>;
template Wektor<LZespolona,4> operator * (LZespolona liczba, const Wektor<LZespolona,4> &W);

// TYMCZASOWO 3
template class Wektor<double,3>;
template Wektor<double,3> operator * (double liczba, const Wektor<double,3> &W);

template class Wektor<LZespolona,3>;
template Wektor<LZespolona,3> operator * (LZespolona liczba, const Wektor<LZespolona,3> &W);

// TYMCZASOWO 2
template class Wektor<double,2>;
template Wektor<double,2> operator * (double liczba, const Wektor<double,2> &W);

template class Wektor<LZespolona,2>;
template Wektor<LZespolona,2> operator * (LZespolona liczba, const Wektor<LZespolona,2> &W);

// TYMCZASOWO 1
template class Wektor<double,1>;
template Wektor<double,1> operator * (double liczba, const Wektor<double,1> &W);

template class Wektor<LZespolona,1>;
template Wektor<LZespolona,1> operator * (LZespolona liczba, const Wektor<LZespolona,1> &W);


template std::istream & operator>>(std::istream &strm, Wektor<LZespolona,2> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<LZespolona,2> &W);
