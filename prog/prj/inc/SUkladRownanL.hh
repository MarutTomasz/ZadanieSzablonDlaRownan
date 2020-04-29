#ifndef SUKLADROWNANL_S
#define SUKLADROWNANL_S
/*!
 * \file
 * \brief Definicja szablonu klasy UkladRownanL
 *
 * Plik zawiera definicje szablonu klasy UkladRownanL, który 
 * zawiera elementy o zmiennym rozmiarze i typie danych. \n
 * Zawiera także deklaracje metod i funkcji potrzebnych do
 * rozwiązania układu równań liniowych.
 */

#include "SWektor.hh"
#include "LZespolona.hh"
#include "SMacierzKw.hh"

/*!
 * \brief Modeluje pojęcie UkladRownanL
 *
 * Szablon klasy UkladRownanL jest parametryzowany typem 
 * zmiennych oraz rozmiarem przechowywanej macierzy i wekotra 
 * wyrazów wolnych. \n
 * \param TYP - typ zmiennych przechowywanych w obiekcie.
 * \param ROZMIAR - rozmiar macierzy i wektora przechowywanych w obiekcie.
 */
template <class TYP, unsigned int ROZMIAR>
class UkladRownanL{
  /*!
   * \brief Macierz układu równań
   */
  MacierzKw<TYP,ROZMIAR> A;
  /*!
   * \brief Wektor wyrazów wolnych układu równań
   */
 Wektor<TYP,ROZMIAR> b;
  
public:
  /*!
   * \brief Konstruktor bezparametryczny układu równań
   *
   * Konstruktor inicjalizuje w ukladzie równań macierz i 
   * wektor, których wszystkie elementy mają wartość 0. 
   */
  UkladRownanL();
  /*!
   * \brief Konstruktor dwuparametryczny układu równań
   *
   * Konstruktor inicjalizuje w ukladzie równań macierz i 
   * wektor wartościami argumentów konstruktora.
   * \param[in] M - macierz, która będzie przechowywana w obiekcie.
   * \param[in] W - wektor, który będzie przechowywany w obiekcie.
   */
  UkladRownanL(const MacierzKw<TYP,ROZMIAR> & M, const Wektor<TYP,ROZMIAR> & W);
  
  /*!
   * \brief Pobranie macierzy z obiektu
   *
   * Pozawala na pobranie macierzy z obiektu.
   * \return Zwraca macierz przechowywaną w obiekcie.
   */
  const MacierzKw<TYP,ROZMIAR> & get_A() const;
  /*!
   * \brief Pobranie wektora z obiektu
   *
   * Pozawala na pobranie wektora z obiektu.
   * \return Zwraca wektor przechowywany w obiekcie.
   */
  const Wektor<TYP,ROZMIAR> & get_b() const;
  /*!
   * \brief Ustawienie wartości macierzy
   *
   * Pozawala na ustawienie w obiekcie konkretnej macierzy.
   * \param[in] M - macierz, która będzie przechowywana w obiekcie. 
   */
  void set_A(const MacierzKw<TYP,ROZMIAR> &M);
  /*!
   * \brief Ustawienie wartości wektora
   *
   * Pozawala na ustawienie w obiekcie konkretnego wektora.
   * \param[in] W - wektor, który będzie przechowywany w obiekcie. 
   */
  void set_b(const Wektor<TYP,ROZMIAR> &W);
  
  /*!
   * \brief Rozwiązuje układ równań metodą Cramera
   *
   * Funkcja rozwiązuje układ równań metodą Cramera. Wyznaczniki 
   * wyliczane są metodą podaną jako argument funkcji. \n
   * W przypadku osobliwości macierzy, funkcja kończy działanie programu
   * i wyświetla stosowny komunikat.
   * \param[in] metoda - metoda wyliczania wyznaczników. 
   * \return Zwraca wektor będący rozwiązaniem układu równań.
   */
  Wektor<TYP,ROZMIAR> rozwiaz_Cramer(Wyz_Metoda metoda) const;
  /*!
   * \brief Rozwiązuje układ równań metodą eliminacji Gaussa
   *
   * Funkcja rozwiązuje układ równań metodą eliminacji Gaussa. \n
   * W przypadku osobliwości macierzy, funkcja kończy działanie programu
   * i wyświetla stosowny komunikat.
   * \return Zwraca wektor będący rozwiązaniem układu równań.
   */
  Wektor<TYP,ROZMIAR> rozwiaz_Gauss() const;
};

/*!
 * \brief Przeciążenie operatora wczytywania
 *
 * Przeciążenie operatora wczytywania dla obiektów klasy UkladRownanL. \n
 * Należy wprowadzić kolejno wartości dla macierzy, a następnie dla wektora
 * wyrazów wolnych.
 * \param[in] &strm - strumień danych.
 * \param[in] U - obiekt układu równań, do której wczytywane są wartości.
 * \return Zwraca referencję do strumienia danych.
 * \attention  Strumień musi być poprawnie zainicjowany;\n
 *             W przypadku czytania błędnych wartości strumień psuje sie.
 */
template<class TYP, unsigned int ROZMIAR>
std::istream & operator >> (std::istream &strm, UkladRownanL<TYP,ROZMIAR> &U);

/*!
 * \brief Przeciążenie operatora wyświetlania
 *
 * Przeciążenie operatora wyświetlania dla obiektów klasy UkladRownanL. \n
 * Specjalnie zaprojektowane wyświetlanie dla paramrtru ROZMIAR=5. \n
 * Przykład wyświetlania danych typu double:
\verbatim
     | 2.00  2.00  1.00  3.00  3.00 | |x_1|   | 9.00 |
     | 1.00  2.00  1.50  1.00  2.00 | |x_2|   | 8.00 |
     | 1.00  3.00  1.00  2.00  2.00 | |x_3| = | 8.00 |
     | 1.00  1.00  1.00  4.00  0.00 | |x_4|   | 9.00 |
     | 2.00  2.00  0.00  0.00  1.00 | |x_5|   | 1.00 |
\endverbatim
 * Przykład wyświetlania danych typu LZespolona:
\verbatim
     | (2.00+1.00i)  (2.00+3.00i)  (1.00+2.00i)  (3.00+1.00i)  (3.00+2.00i) | |x_1|   | (9.00+1.00i) |
     | (1.00+1.00i)  (2.00+5.00i)  (1.50+3.00i)  (1.00+4.00i)  (2.00+2.00i) | |x_2|   | (8.00+2.00i) |
     | (1.00+1.00i)  (3.00+7.00i)  (1.00+1.00i)  (2.00+1.00i)  (2.00+0.00i) | |x_3| = | (8.00+8.00i) |
     | (1.00+2.00i)  (1.00+2.00i)  (1.00+1.00i)  (4.00+3.00i)  (0.00+1.00i) | |x_4|   | (9.00+5.00i) |
     | (2.00+3.00i)  (2.00+2.00i)  (0.00+2.00i)  (0.00+0.00i)  (1.00+1.00i) | |x_5|   | (1.00+1.00i) |
\endverbatim
 * \param[in] &strm - strumień danych.
 * \param[in] U - układ równań, ktorego elementy są wyświetlane.
 * \return Zwraca referencję do strumienia danych.
 * \attention  Strumień musi być poprawnie zainicjowany;\n
 */
template<class TYP, unsigned int ROZMIAR>
std::ostream & operator << (std::ostream &strm, const UkladRownanL<TYP,ROZMIAR> &U);


#endif
