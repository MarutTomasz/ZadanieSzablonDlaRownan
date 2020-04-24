// 5 doubli
// LZespolona

#include "SWektor.hh"
#include "SMacierzKw.hh"


// norma : H -> \mathbb{R}
//  double     || W || = sqrt <W,W>;
//  LZ         || W || = sqrt<W,~W>;



int main() {
  double tab[] = {4,4,5,2,1};
  Wektor<double,5> W(tab);
  
  MacierzKw<Wektor,double,5> A;
  cin >> A;
    
  MacierzKw<Wektor,double,5> C;
  C.MacierzJednostkowa();
  
  cout << C << endl;

  
  return 0;
}
  
