// 5 doubli
// LZespolona

#include "SWektor.hh"




// norma : H -> \mathbb{R}
//  double     || W || = sqrt <W,W>;
//  LZ         || W || = sqrt<W,~W>;



int main() {
  
  Wektor<double,5> D(3,4,6,3,2);
  Wektor<double,5> E(8,7,6,5,4);
  Wektor<double,5> F = D + E;
  cout << D << endl;
  cout << E << endl;

  cout << F << endl;

  double l = D.dlugosc();
  cout << l << endl;
  
  return 0;
}
  
