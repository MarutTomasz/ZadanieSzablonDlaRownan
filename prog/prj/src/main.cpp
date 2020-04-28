
#include "SWektor.hh"
#include "SMacierzKw.hh"
#include "LZespolona.hh"


// norma : H -> \mathbb{R}
//  double     || W || = sqrt <W,W>;
//  LZ         || W || = sqrt<W,~W>;



int main() {
  MacierzKw<LZespolona,5> A;    
  cin >> A;
  cout << A << endl;
  MacierzKw<LZespolona,5> B;    
  B = A.macierz_dopelnien();
  LZespolona PP(17,17);
  cout << B << endl;  
  return 0;
}
  
