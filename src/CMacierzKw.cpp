#include "SMacierzKw.cpp"


// NA STALE  RZECZYWISTE
template class MacierzKw<Wektor,double,5>;
template std::istream & operator >> (std::istream &strm, MacierzKw<Wektor,double,5> &M);
template std::ostream & operator << (std::ostream &strm, const MacierzKw<Wektor,double,5> &M);
template MacierzKw<Wektor,double,5> operator * (double liczba, const MacierzKw<Wektor,double,5> &M);

// TYMCZASOWO
template class MacierzKw<Wektor,double,4>;
template class MacierzKw<Wektor,double,3>;
template class MacierzKw<Wektor,double,2>;
template class MacierzKw<Wektor,double,1>;
template MacierzKw<Wektor,double,4> pomniejsz_macierz(const MacierzKw<Wektor,double,5> &M, unsigned int index1, unsigned int index2);
template MacierzKw<Wektor,double,3> pomniejsz_macierz(const MacierzKw<Wektor,double,4> &M, unsigned int index1, unsigned int index2);
template MacierzKw<Wektor,double,2> pomniejsz_macierz(const MacierzKw<Wektor,double,3> &M, unsigned int index1, unsigned int index2);
template MacierzKw<Wektor,double,1> pomniejsz_macierz(const MacierzKw<Wektor,double,2> &M, unsigned int index1, unsigned int index2);



// NA STALE ZESPOLONE

template class MacierzKw<Wektor,LZespolona,5>;
template std::istream & operator >> (std::istream &strm, MacierzKw<Wektor,LZespolona,5> &M);
template std::ostream & operator << (std::ostream &strm, const MacierzKw<Wektor,LZespolona,5> &M);
template MacierzKw<Wektor,LZespolona,5> operator * (LZespolona liczba, const MacierzKw<Wektor,LZespolona,5> &M);

// TYMCZASOWO
template class MacierzKw<Wektor,LZespolona,4>;
template class MacierzKw<Wektor,LZespolona,3>;
template class MacierzKw<Wektor,LZespolona,2>;
template class MacierzKw<Wektor,LZespolona,1>;
template MacierzKw<Wektor,LZespolona,1> pomniejsz_macierz(const MacierzKw<Wektor,LZespolona,2> &M, unsigned int index1, unsigned int index2);
template MacierzKw<Wektor,LZespolona,2> pomniejsz_macierz(const MacierzKw<Wektor,LZespolona,3> &M, unsigned int index1, unsigned int index2);
template MacierzKw<Wektor,LZespolona,3> pomniejsz_macierz(const MacierzKw<Wektor,LZespolona,4> &M, unsigned int index1, unsigned int index2);
template MacierzKw<Wektor,LZespolona,4> pomniejsz_macierz(const MacierzKw<Wektor,LZespolona,5> &M, unsigned int index1, unsigned int index2);



template std::istream & operator >> (std::istream &strm, MacierzKw<Wektor,LZespolona,2> &M);
template std::ostream & operator << (std::ostream &strm, const MacierzKw<Wektor,LZespolona,2> &M);
