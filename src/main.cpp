
#include "SWektor.hh"
#include "SMacierzKw.hh"
#include "LZespolona.hh"


// norma : H -> \mathbb{R}
//  double     || W || = sqrt <W,W>;
//  LZ         || W || = sqrt<W,~W>;



int main() {
  MacierzKw<Wektor,double,5> A;
  cin >> A;
  cout << A<< endl;

  double wyznacznik = A.wyznacznik(Gauss);
  cout << wyznacznik << endl;
  return 0;
}
  
