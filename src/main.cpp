// 5 doubli
// LZespolona

#include "SWektor.hh"



// norma : H -> \mathbb{R}
//  double     || W || = sqrt <W,W>;
//  LZ         || W || = sqrt<W,~W>;



int main() {
  LZespolona tabela[5];
  for (int i=0; i < 5; ++i)
    cin >> tabela[i];
  Wektor<LZespolona,5> D(tabela);
  Wektor<LZespolona,5> E(tabela);
  Wektor<LZespolona,5> F = D + E;
  cout << D << endl;
  cout << E << endl;
  
  cout << F << endl;

  double l = D.dlugosc();
  cout << l << endl;
  
  return 0;
}
  
