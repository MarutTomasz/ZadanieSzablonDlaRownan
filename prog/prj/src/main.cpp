#include "SWektor.hh"
#include "SMacierzKw.hh"
#include "SUkladRownanL.hh"
#include "LZespolona.hh"

int main() {
  char wybor;
  cin >> wybor;
  if( wybor == 'r') {
    Wektor<double,5> Wr;
    MacierzKw<double,5> Mr;
  
    cin >> Mr >> Wr;
    UkladRownanL<double,5> Ur(Mr,Wr);
    cout << "Uklad rownan do rozwiazania:" << endl;
    cout << Ur << endl;


    cout << "ROZWIAZANIE METODA CRAMERA, WYZNACZNIK GAUSSEM" << endl;
    cout << "Rozwiazanie x = (x1, x2, x3, x4, x5):" << endl;
    Wektor<double,5> Xr = Ur.rozwiaz_Cramer(Gauss);
    cout << Xr << endl << endl;
   
    Wektor<double,5> errr = Mr * Xr - Wr;
    wyswietl_wektor_bledu(errr);


    cout << "ROZWIAZANIE METODA CRAMERA, WYZNACZNIK LAPLACEM" << endl;
    cout << "Rozwiazanie x = (x1, x2, x3, x4, x5):" << endl;
    Xr = Ur.rozwiaz_Cramer(Laplace);
    cout << Xr << endl << endl;
   
    errr = Mr * Xr - Wr;
    wyswietl_wektor_bledu(errr);


    cout << "ROZWIAZANIE METODA GAUSSEM" << endl;
    cout << "Rozwiazanie x = (x1, x2, x3, x4, x5):" << endl;
    Xr = Ur.rozwiaz_Gauss();
    cout << Xr << endl << endl;
   
    errr = Mr * Xr - Wr;
    wyswietl_wektor_bledu(errr);
  }
  else if (wybor == 'z'){
    Wektor<LZespolona,5> Wz;
    MacierzKw<LZespolona,5> Mz;
  
    cin >> Mz >> Wz;
    UkladRownanL<LZespolona,5> Uz(Mz,Wz);
  
  
    cout << "Uklad rownan do rozwiazania:" << endl;
    cout << Uz << endl;


    cout << "ROZWIAZANIE METODA CRAMERA, WYZNACZNIK GAUSSEM" << endl;
    cout << "Rozwiazanie x = (x1, x2, x3, x4, x5):" << endl;
    Wektor<LZespolona,5> Xz = Uz.rozwiaz_Cramer(Gauss);
    cout << Xz << endl << endl;
  
    Wektor<LZespolona,5> errz = Mz * Xz - Wz;
    wyswietl_wektor_bledu(errz);
 

    cout << "ROZWIAZANIE METODA CRAMERA, WYZNACZNIK LAPLACEM" << endl;
    cout << "Rozwiazanie x = (x1, x2, x3, x4, x5):" << endl;
    Xz = Uz.rozwiaz_Cramer(Laplace);
    cout << Xz << endl << endl;
    
    errz = Mz * Xz - Wz;
    wyswietl_wektor_bledu(errz);
    

    cout << "ROZWIAZANIE METODA GAUSSEM" << endl;
    cout << "Rozwiazanie x = (x1, x2, x3, x4, x5):" << endl;
    Xz = Uz.rozwiaz_Gauss();
    cout << Xz << endl << endl;
    
    errz = Mz * Xz - Wz;
    wyswietl_wektor_bledu(errz);
  }
  else {
    cout << " Niepoprawny wariant danych.\n Dozwolone oznaczenia 'r' lub 'z'" <<endl;
    exit(1);
  }
  return 0;
}
  
