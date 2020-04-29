#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
/*!
 * \file
 * \brief Definicja struktury LZespolona
 *
 * Plik zawiera definicje struktury LZespolone,
 * która reprezentuje liczby zespolone oraz zawiera
 * deklaracje podsatwowych metod i funkcji
 * działających na tej strukturze.
 */

#include <math.h>
#include <iostream>

using std::showpos;
using std::noshowpos;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/*!
 * \brief Modeluje pojęcie LZespolona
 *
 * Struktura modeluje pojęcie liczby zespolonej przedstawianej
 * jako cześć rzeczywista re i część urojona im. Zawiera metody 
 * podsawowych operacji na liczbie zespolonej.
 */
struct  LZespolona {
  /*!
 * \brief Pole reprezentujące część rzeczywistą liczby zespolonej
 * 
 * Pole reprezentujące część rzeczywistą liczby zespolonej
 */
  double   re;    
  /*!
 * \brief Pole reprezentujące część urojoną liczby zespolonej
 * 
 * Pole reprezentujące część urojoną liczby zespolonej
 */
  double   im;    

  /*!
   * \brief Konstruktor bezparametryczny liczby zespolonej
   *
   * Konstruktor inicjalizuje liczbę zespoloą wartościami 0 dla części 
   * rzeczywstej i urojonej.
   */
  LZespolona();

  /*!
   * \brief Konstruktor dwuparametryczny liczby zespolonej
   *
   * Konstruktor inicjalizuje liczbę zespoloą wartościami zadanych argumentów.
   * \param[in] RE - wartość wstawiana do części rzeczywistej liczby zespolonej.
   * \param[in] IM - wartość wstawiana do części urojonej liczby zespolonej.
   */
  LZespolona(double RE, double IM);

  /*!
   * \brief Przeciążenie operatora przypisania
   *
   * Przeciążenie operatora przypisania dla typu LZespolona - double.
   * Dokonuje operacji podstawienia wartości argumentu w miejsce części
   * rzeczywistej oraz 0 w miejsce części urojonej
   * \param[in] liczba - wartość wstawiana do części rzeczywistej liczby zespolonej.
   * \return Zwraca liczbę zespoloną po dokonaiu operacji podstawienia.
   */
  LZespolona operator =  (double liczba);
  /*!
   * \brief Przeciążenie operatora dodawania
   *
   * Przeciążenie operatora dodawania dla typu LZespolona - LZespolona.
   * Dokonuje operacji dodania wartości argumentów.
   * \param[in] Skl - składnik w postaci liczby zespolonej.
   * \return Zwraca liczbę zespoloną po dokonaniu operacji dodawania.
   */
  LZespolona operator +  (const LZespolona & Skl) const;
  /*!
   * \brief Przeciążenie operatora odejmowania
   *
   * Przeciążenie operatora odejmowania dla typu LZespolona - LZespolona.
   * Dokonuje operacji odejmowania od siebie wartości argumentów.
   * \param[in] Skl - odjemnik w postaci liczby zespolonej.
   * \return Zwraca liczbę zespoloną po dokonaniu operacji odejmowania.
   */
  LZespolona operator -  (const LZespolona & Skl) const;
  /*!
   * \brief Przeciążenie operatora mnożenia
   *
   * Przeciążenie operatora mnożenia dla typu LZespolona - LZespolona.
   * Dokonuje operacji mnożenia wartości argumentów.
   * \param[in] Skl - czynnik w postaci liczby zespolonej.
   * \return Zwraca liczbę zespoloną po dokonaniu operacji mnożenia.
   */
  LZespolona operator *  (const LZespolona & Skl) const; 
  /*!
   * \brief Przeciążenie operatora mnożenia
   *
   * Przeciążenie operatora mnożenia dla typu LZespolona - double.
   * Dokonuje operacji mnożenia wartości argumentów.
   * \param[in] liczba - czynnik w postaci liczby typu double.
   * \return Zwraca liczbę zespoloną po dokonaniu operacji mnożenia.
   */
  LZespolona operator *  (double liczba) const; 
  /*!
   * \brief Przeciążenie operatora pzypisania mnożenia
   *
   * Przeciążenie operatora przypisania mnożenia dla typu LZespolona - double.
   * Dokonuje operacji mnożenia wyniku przez wartość argumentu.
   * \param[in] liczba - czynnik w postaci liczby typu double.
   * \return Zwraca liczbę zespoloną po dokonaniu operacji mnożenia.
   */
  LZespolona operator *= (double liczba); 
  /*!
   * \brief Przeciążenie operatora dzielenia
   *
   * Przeciążenie operatora dzielenia dla typu LZespolona - LZespolona.
   * Dokonuje operacji dzielenia wartości argumentów.
   * \param[in] Skl - dzielnik w postaci liczby zespolonej.
   * \return Zwraca liczbę zespoloną po dokonaniu operacji dzielenia.
   */
  LZespolona operator /  (const LZespolona & Skl) const;
  /*!
   * \brief Przeciążenie operatora pzypisania dodawania
   *
   * Przeciążenie operatora przypisania dodawania dla typu LZespolona - LZespolona.
   * Dokonuje operacji dodania do wyniku wartości argumentu.
   * \param[in] Skl - składnik w postaci liczby zespolonej.
   * \return Zwraca liczbę zespoloną po dokonaniu operacji dodawania.
   */
  LZespolona operator += (const LZespolona & Skl);
  /*!
   * \brief Przeciążenie operatora dzielenia
   *
   * Przeciążenie operatora dzielenia dla typu LZespolona - double.
   * Dokonuje operacji dzielenia wartości argumentów.
   * \param[in] liczba - dzielnik w postaci liczby typu double.
   * \return Zwraca liczbę zespoloną po dokonaniu operacji dzielenia.
   */
  LZespolona operator /  (double liczba) const;
  
  /*!
   * \brief Przeciążenie operatora porównania
   *
   * Przeciążenie operatora porównania dla typu LZespolona - LZespolona.
   * Sprawdza, czy liczby podane w argumentach są równe.
   * \param[in] Arg - porównywana liczba zespolona.
   * \retval true - jeśli liczby są równe,
   * \retval false - w przeciwnym przypadku.
   */
  bool operator == (const LZespolona & Arg) const;
  /*!
   * \brief Przeciążenie operatora porównania
   *
   * Przeciążenie operatora porównania dla typu LZespolona - LZespolona.
   * Sprawdza, czy liczby podane w argumentach są różne.
   * \param[in] Arg - porównywana liczba zespolona.
   * \retval true - jeśli liczby są różne,
   * \retval false - w przeciwnym przypadku.
   */
  bool operator != (const LZespolona & Arg) const;
  /*!
   * \brief Przeciążenie operatora porównania
   *
   * Przeciążenie operatora porównania dla typu LZespolona - double.
   * Sprawdza, czy moduł liczby zespolonej jest równy argumentowi.
   * \param[in] liczba - porównywana liczba typu double.
   * \retval true - jeśli moduł liczby zespolonej jest równy argumentowi,
   * \retval false - w przeciwnym przypadku.
   */
  bool operator == (double liczba) const;
  /*!
   * \brief Przeciążenie operatora porównania
   *
   * Przeciążenie operatora porównania dla typu LZespolona - double.
   * Sprawdza, czy moduł liczby zespolonej jest różny od argumentu.
   * \param[in] liczba - porównywana liczba typu double.
   * \retval true - jeśli moduł liczby zespolonej jest różny od argumentu,
   * \retval false - w przeciwnym przypadku.
   */
  bool operator != (double liczba) const;

  /*!
   * \brief Oblicza sprzężenie liczby zespolonej
   *
   * Oblicza sprzęzenie do liczby zespolonej.
   * \return Zwraca obliczoną liczbę sprzężoną.
   */
  LZespolona sprzez() const;
  /*!
   * \brief Oblicza kwadrat modułu
   *
   * Oblicza kwadrat modułu liczby zespolonej.
   * \return Zwraca kwadrat modułu liczby zespolonej.
   */
  double modul2() const;
  /*!
   * \brief Oblicza modułu
   *
   * Oblicza wartość modułu liczby zespolonej.
   * \return Zwraca moduł liczby zespolonej.
   */
  double modul() const;
  
};

/*!
 * \brief Przeciążenie operatora mnożenia
 *
 * Przeciążenie operatora mnożenia dla typu double - LZespolona.
 * Dokonuje operacji mnożenia wartości argumentów.
 * \param[in] liczba - czynnik w postaci liczby typu double.
 * \param[in] Skl - czynnik w postaci liczby zespolonej.
 * \return Zwraca liczbę zespoloną po dokonaniu operacji mnożenia.
 */
LZespolona operator * (double liczba, const LZespolona & Skl); 
/*!
 * \brief Wartość bezwzględna modułu
 *
 * Funkcja pozwala na uzyskanie wartości bezwzględnej modułu liczby zespolonej
 * \param[in] Skl - liczba zespolona, której moduł jest wyliczany.
 * \return Zwraca bezwzględną wartość modułu.
 */
double abs(const LZespolona & Skl);
/*!
 * \brief Przeciążenie operatora wczytywania
 *
 * Przeciążenie operatora wczytywania dla typu LZespolona. \n
 * Liczby wczytywane są w nawiasach okrągłych. Wartości części rzeczywistych i
 * urojonych muszą być podane, nawet jeśli wynoszą one 0. \n
 * Przykład wprowadzania liczby zespolonej: 
\verbatim
               (2.0+0.0i)
\endverbatim
 * \param[in] &strm - strumień danych.
 * \param[in] Skl - liczba zespolona, do której wczytywane są wartości.
 * \return Zwraca referencję do strumienia danych.
 * \attention  Strumień musi być poprawnie zainicjowany;\n
 *             W przypadku czytania błędnych wartości strumień psuje sie.
*/
std::istream & operator >> (std::istream &strm, LZespolona &Skl);
/*!
 * \brief Przeciążenie operatora wyświetlania
 *
 * Przeciążenie operatora wyświetlania dla typu LZespolona. \n
 * Liczby wyświetlane są w nawiasach okrągłych.  \n
 * Przykład wyświetlenia liczby zespolonej: 
\verbatim
               (1.0+3.0i)
\endverbatim
 * \param[in] strm - strumień danych.
 * \param[in] Skl - liczba zespolona, której wartości są wyświetlane.
 * \return Zwraca referencję do strumienia danych.
 * \attention  Strumień musi być poprawnie zainicjowany;\n
*/
std::ostream & operator << (std::ostream &strm, const LZespolona &Skl);

#endif
