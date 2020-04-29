#include "SUkladRownanL.hh"
/*!
 * \file
 * \brief Definicje metod i funkcji klasy UkladRownanL
 *
 * Plik zawiera definicje metod i funkcji działających
 * na klasie UkladRownanL.
 */

/********** KONSTRUKTORY **********/
template<class TYP, unsigned int ROZMIAR>
UkladRownanL<TYP,ROZMIAR>::UkladRownanL() {
  MacierzKw<TYP,ROZMIAR> M;
  Wektor<TYP,ROZMIAR> W;
  (*this).set_A(M);
  (*this).set_b(W);
}

template<class TYP, unsigned int ROZMIAR>
UkladRownanL<TYP,ROZMIAR>::UkladRownanL(const MacierzKw<TYP,ROZMIAR> & M, const Wektor<TYP,ROZMIAR> & W) {
  (*this).set_A(M);
  (*this).set_b(W);
}

/********** SET I GET  **********/
template<class TYP, unsigned int ROZMIAR>
void UkladRownanL<TYP,ROZMIAR>::set_A(const MacierzKw<TYP,ROZMIAR> &M) {
  (*this).A = M;
}

template<class TYP, unsigned int ROZMIAR>
void UkladRownanL<TYP,ROZMIAR>::set_b(const Wektor<TYP,ROZMIAR> &W){
  (*this).b = W;
  
}

template<class TYP, unsigned int ROZMIAR>
const MacierzKw<TYP,ROZMIAR> & UkladRownanL<TYP,ROZMIAR>::get_A() const{
  return (*this).A;
}

template<class TYP, unsigned int ROZMIAR>
const Wektor<TYP,ROZMIAR> & UkladRownanL<TYP,ROZMIAR>::get_b() const{
  return (*this).b;
}

/********** WCZYTYWANIE I WYSWIETLANIE **********/
template<class TYP, unsigned int ROZMIAR>
std::istream & operator >> (std::istream &strm, UkladRownanL<TYP,ROZMIAR> &U){
  MacierzKw<TYP,ROZMIAR> M;
  Wektor<TYP,ROZMIAR> W;
  cin >> M >> W;
  U.set_A(M);
  U.set_b(W);
  
  return strm;
}

template<class TYP, unsigned int ROZMIAR>
std::ostream & operator << (std::ostream &strm, const UkladRownanL<TYP,ROZMIAR> &U){
  MacierzKw<TYP,ROZMIAR> M = U.get_A();
  Wektor<TYP,ROZMIAR> W = U.get_b();
  cout << fixed;
  cout << setprecision(2);
  cout << "|" << M[0] << "| |x_1|   | " << W[0] << " |" << endl;
  cout << "|" << M[1] << "| |x_2|   | " << W[1] << " |" << endl;
  cout << "|" << M[2] << "| |x_3| = | " << W[2] << " |" << endl;
  cout << "|" << M[3] << "| |x_4|   | " << W[3] << " |" << endl;
  cout << "|" << M[4] << "| |x_5|   | " << W[4] << " |" << endl;
  cout << defaultfloat;
  return strm;
}

/********** SPECJALNA METODA **********/
template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> UkladRownanL<TYP,ROZMIAR>::rozwiaz_Cramer(Wyz_Metoda metoda) const{
  double epsilon = 0.000000001;
  TYP wyznacznik_A = (*this).A.wyznacznik(metoda);
  TYP wyznacznik_X;
  MacierzKw<TYP,ROZMIAR> Kopia;
  Wektor<TYP,ROZMIAR> Rozwiazanie;
  if (abs(wyznacznik_A) < epsilon){
    cerr << "Macierz osobliwa, uklad nie ma rozwiazan" << endl;
    exit(1);
  }
  
  for (unsigned int i=0; i < ROZMIAR; ++i){ 
    Kopia = (*this).A;
    Kopia.zmien_kolumne(i,(*this).b);
    wyznacznik_X = Kopia.wyznacznik(metoda);
    Rozwiazanie[i] = wyznacznik_X/wyznacznik_A;
  }
  
  return Rozwiazanie;
}

template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> UkladRownanL<TYP,ROZMIAR>::rozwiaz_Gauss() const {
  Wektor<TYP,ROZMIAR> Rozwiazanie = (*this).b;
  MacierzKw<TYP,ROZMIAR> P = (*this).A;
  double epsilon = 0.000000001;
  for(unsigned int i=0; i < ROZMIAR; ++i){
    for(unsigned int k=i+i; abs(P[i][i]) < epsilon; ++k){
      if(k >= ROZMIAR){  
	cout << "Macierz jest osobliwa, nie ma rozwiazan" << endl;
	exit(1);
      }
      P.przestaw_wiersze(i,k);
      Rozwiazanie.przestaw_elementy(i,k);
    }
    Rozwiazanie[i] = Rozwiazanie[i] / P[i][i];
    P[i] = P[i] / P[i][i];
      
    for(unsigned int j=i+1; j < ROZMIAR; ++j){  
      Rozwiazanie[j] = Rozwiazanie[j] - (Rozwiazanie[i] * P[j][i]);
      P[j] = P[j] - (P[i] * P[j][i]);
    }   
  }
    
  for(unsigned int i = ROZMIAR-1; i > 0; --i) {
    for(unsigned int j=0; j < i; ++j){  
      Rozwiazanie[j] = Rozwiazanie[j] - (Rozwiazanie[i] * P[j][i]);
      P[j] = P[j] - (P[i] * P[j][i]);
    }   
  }
    
  return Rozwiazanie;
} 
