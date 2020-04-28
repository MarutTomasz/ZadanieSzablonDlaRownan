#ifndef SWEKTOR_S
#define SWEKTOR_S
/*!
 * \file
 * \brief Definicja szablonu klasy Wektor
 *
 * Plik zawiera definicje szablonu klasy Wektor o 
 * zmiennym rozmiarze i typie danych. \n
 * Zawiera także deklaracje metod i funkcji działających 
 * na wektorach.
 */

#include <iostream>
#include <math.h>
#include "LZespolona.hh"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/*!
 * \brief Modeluje pojęcie Wektor
 *
 * Szablon klasy Wektor jest parametryzowany typem 
 * przechowywanych zmiennych oraz rozmiarem (ilością elementów). \n
 * \param TYP - typ zmiennych tworzących wektor.
 * \param ROZMIAR - ilość zmiennych tworzących wektor.
*/
template<class TYP, unsigned int ROZMIAR>
class Wektor {
  /*!
   * \brief Tablica zawierająca elementy wektora.
   * 
   * Tablica zawierająca elementy wektora.
   * \param ROZMIAR - wielkość tablicy elementów.
   */
TYP tab [ROZMIAR];
  
public:
  /*!
   * \brief Przeciążenie nawiasów klamrowych
   *
   * Pozawala na odwoływanie się do wybranego elementu wektora 
   * oraz daje możliwość zmiany go.
   * \param[in] index - index elementu wektora do którego chcemy się odwołać.
   * \return Zwraca referencję do żądanego elementu wektora.
   */
  TYP & operator [] (unsigned int index);
  /*!
   * \brief Przeciążenie nawiasów klamrowych
   *
   * Pozawala na odwoływanie się do wybranego elementu wektora, 
   * ale nie daje możliwości zmiany go.
   * \param[in] index - index elementu wektora do którego chcemy się odwołać.
   * \return Zwraca referencję do żądanego elementu wektora.
   */
  const TYP & operator [] (unsigned int index) const;
  
  /*!
   * \brief Konstruktor bezparametryczny wektora 
   *
   * Konstruktor inicjalizuje wszystkie elementy wektora wartością 0. 
   */
  Wektor();
  /*!
   * \brief Konstruktor jednoparametryczny wektora 
   *
   * Konstruktor inicjalizuje elementy wektora wartościami z tablicy o
   * jednakowym rozmiarze i typie przechowywanych danych co wektor.  
   * \param[in] tabela - tablica z wartościami inicjalizującymi wektor.
    */
  Wektor(TYP *tabela);
  
  /*!
   * \brief Przeciążenie operatora dodawania
   *
   * Przeciążenie operatora dodawania dla typu Wektor - Wektor.
   * Dokonuje operacji dodania wartości argumentów.
   * \param[in] W - składnik w postaci wektora.
   * \return Zwraca wektor po dokonaniu operacji dodawania.
   */
  Wektor<TYP,ROZMIAR> operator + (const Wektor<TYP,ROZMIAR> &W) const;
  /*!
   * \brief Przeciążenie operatora odejmowania
   *
   * Przeciążenie operatora odejmowania dla typu Wektor - Wektor.
   * Dokonuje operacji odejmowania od siebie wartości argumentów.
   * \param[in] W - odjemnik w postaci wektora.
   * \return Zwraca wektor po dokonaniu operacji odejmowania.
   */
  Wektor<TYP,ROZMIAR> operator - (const Wektor<TYP,ROZMIAR> &W) const;
  /*!
   * \brief Przeciążenie operatora mnożenia
   *
   * Przeciążenie operatora mnożenia dla typu Wektor - Wektor.
   * Dokonuje operacji mnożenie wartości argumentów.
   * Jest to odpowiednik mnożenia skalarnego wektorów.
   * \param[in] W - czynnik  w postaci wektora.
   * \return Zwraca wynik mnożenia skalarnego.
   */
  TYP operator * (const Wektor<TYP,ROZMIAR> &W) const;
  /*!
   * \brief Przeciążenie operatora mnożenia
   *
   * Przeciążenie operatora odejmowania dla typu Wektor - TYP.
   * Dokonuje operacji mnożenia wartości argumentów.
   * \param[in] liczba - czynnik w postaci skalara (TYP).
   * \return Zwraca wektor po dokonaniu operacji mnożenia.
   */
  Wektor<TYP,ROZMIAR> operator * (TYP liczba) const;
  /*!
   * \brief Przeciążenie operatora dzielenia
   *
   * Przeciążenie operatora odejmowania dla typu Wektor - TYP.
   * Dokonuje operacji dzielenia wektora przez skalar (TYP).
   * \param[in] liczba - dzielnik w postaci skalara (TYP) .
   * \return Zwraca wektor po dokonaniu operacji dzielenia.
   */
  Wektor<TYP,ROZMIAR> operator / (TYP liczba) const;

  /*!
   * \brief Przeciążenie operatora porównania
   *
   * Przeciążenie operatora porównania dla typu Wektor - Wektor.
   * Sprawdza, czy wektory podane w argumentach są równe.
   * \param[in] W - porównywany wektor.
   * \retval true - jeśli wektory są równe,
   * \retval false - w przeciwnym przypadku.
   */
  bool operator == (const Wektor<TYP,ROZMIAR> &W) const;
  /*!
   * \brief Przeciążenie operatora porównania
   *
   * Przeciążenie operatora porównania dla typu Wektor - Wektor.
   * Sprawdza, czy wektory podane w argumentach są różne.
   * \param[in] W - porównywany wektor.
   * \retval true - jeśli wektory są różne,
   * \retval false - w przeciwnym przypadku.
   */
  bool operator != (const Wektor<TYP,ROZMIAR> &W) const;

  /*!
   * \brief Wyliczenie długości wektora
   *
   * Funkcja wylicza długość wektora jako pierwiastek z sumy 
   * kwadratów wszystkich elementów wektora. Dla elementów 
   * tylu LZespolona napisana jest specjalizacja
   * \return Zwraca długość wektora.
   */
  double dlugosc() const;
};

/*!
 * \brief Przeciążenie operatora wyświetlania
 *
 * Przeciążenie operatora wyświetlania dla obiektów klasy Wektor. \n
 * \param[in] &strm - strumień danych.
 * \param[in] W - wektor, ktorego wartości są wyświetlane.
 * \return Zwraca referencję do strumienia danych.
 * \attention  Strumień musi być poprawnie zainicjowany;\n
 *             W przypadku czytania błędnych wartości strumień psuje sie.
*/
template<class TYP, unsigned int ROZMIAR>
std::ostream & operator<< (std::ostream &strm, const Wektor<TYP,ROZMIAR> &W);

/*!
 * \brief Przeciążenie operatora wczytywania
 *
 * Przeciążenie operatora wczytywania dla obiektów klasy Wektor. \n
 * \param[in] &strm - strumień danych.
 * \param[in] W - wektor, do którego wczytywane są wartości.
 * \return Zwraca referencję do strumienia danych.
 * \attention  Strumień musi być poprawnie zainicjowany;\n
 *             W przypadku czytania błędnych wartości strumień psuje sie.
*/
template<class TYP, unsigned int ROZMIAR>
std::istream & operator>> (std::istream &strm, Wektor<TYP,ROZMIAR> &W);

/*!
 * \brief Przeciążenie operatora mnożenia
 *
 * Przeciążenie operatora odejmowania dla typu TYP - Wektor.
 * Dokonuje operacji mnożenia wartości argumentów.
 * \param[in] liczba - czynnik w postaci skalara (TYP).
 * \param[in] W - czynnik w postaci wektora.
 * \return Zwraca wektor po dokonaniu operacji mnożenia.
 */
template<class TYP, unsigned int ROZMIAR>
Wektor<TYP,ROZMIAR> operator * (TYP liczba, const Wektor<TYP,ROZMIAR> &W);


/*   SPECJALIZACJE 
template<>
double Wektor<LZespolona,5>::dlugosc() const;

template<>
double Wektor<LZespolona,4>::dlugosc() const;

template<>
double Wektor<LZespolona,3>::dlugosc() const;

template<>
double Wektor<LZespolona,2>::dlugosc() const;

template<>
double Wektor<LZespolona,1>::dlugosc() const;
*/


#endif
