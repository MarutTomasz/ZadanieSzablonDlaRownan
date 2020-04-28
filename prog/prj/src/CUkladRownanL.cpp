#include "SUkladRownanL.cpp"

template class UkladRownanL<double,5>;
template std::istream & operator >> (std::istream &strm, UkladRownanL<double,5> &U);
template std::ostream & operator << (std::ostream &strm, const UkladRownanL<double,5> &U);

template class UkladRownanL<LZespolona,5>;
template std::istream & operator >> (std::istream &strm, UkladRownanL<LZespolona,5> &U);
template std::ostream & operator << (std::ostream &strm, const UkladRownanL<LZespolona,5> &U);
