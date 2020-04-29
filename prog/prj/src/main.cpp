#include "SWektor.hh"
#include "SMacierzKw.hh"
#include "SUkladRownanL.hh"
#include "LZespolona.hh"
/*!
 * \file
 * \brief Główny plik z programem wykonawczym
 */

/*!
 * Program na wstępie pobiera symbol 'r' lub 'z' ze standardowego 
 * wejścia oznaczający typ wprowadzanych danych. \n
 * Następnie pobiera dane do układu równań ze standardowego 
 * wejścia i po rozwiązaniu układu trzema róznymi metodami wyświetla 
 * wyniki wraz z błędami. \n
 * Przykładowe wyświetlenie wyniku działania programu:
\verbatim
       Uklad rownan do rozwiazania:
       | 2.00  2.00  1.00  3.00  3.00 | |x_1|   | 9.00 |
       | 1.00  2.00  1.50  1.00  2.00 | |x_2|   | 8.00 |
       | 1.00  3.00  1.00  2.00  2.00 | |x_3| = | 8.00 |
       | 1.00  1.00  1.00  4.00  0.00 | |x_4|   | 9.00 |
       | 2.00  2.00  0.00  0.00  1.00 | |x_5|   | 1.00 |
       
       ROZWIAZANIE METODA CRAMERA, WYZNACZNIK GAUSSEM
       Rozwiazanie x = (x1, x2, x3, x4, x5):
       -0.13  0.47  3.5  1.3  0.31 
       
       Wektor bledu:  Ax-b = ( -1.78e-15  -1.78e-15  -1.78e-15  0.00e+00  -2.89e-15 )
       Dlugosc wektora bledu: ||Ax-b|| = 4.22e-15
       
       
       ROZWIAZANIE METODA CRAMERA, WYZNACZNIK LAPLACEM
       Rozwiazanie x = (x1, x2, x3, x4, x5):
       -0.13  0.47  3.5  1.3  0.31 
       
       Wektor bledu:  Ax-b = ( 0.00e+00  0.00e+00  0.00e+00  0.00e+00  0.00e+00 )
       Dlugosc wektora bledu: ||Ax-b|| = 0.00e+00

       
       ROZWIAZANIE METODA GAUSSEM
       Rozwiazanie x = (x1, x2, x3, x4, x5):
       -0.13  0.47  3.5  1.3  0.31 
       
       Wektor bledu:  Ax-b = ( 0.00e+00  0.00e+00  0.00e+00  0.00e+00  2.22e-16 )
       Dlugosc wektora bledu: ||Ax-b|| = 2.22e-16
\endverbatim

 */
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
  
