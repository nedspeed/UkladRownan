#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include <iostream>
#include "Wektor.hh"
#include <cmath>
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz {   //okresl czy macierz wierszowa czy kolumnowa - kolumnowa
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
    Wektor kol[ROZMIAR]; //wk-wiersze kolumny
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */    
  Macierz() = default; //domyslny konstruktor
  Macierz( Wektor kol[ROZMIAR] ); //konstruktor

  const Wektor & operator[] (int indeks) const; //przeciazenie indeksow dla macierzy typu const
  Wektor & operator[] (int indeks); //przeciazenie indeksow dla macierzy dowolnego typu
  double Wyznacznik () ; // liczenie wyznacznika Gauss-Jordan
  Macierz transpozycja() const; // transponowanie macierzy
  Macierz operator + (const Macierz & M) const; // przeciazenie operatora dodawania dwoch macierzy
  Macierz operator - (const Macierz & M) const; // przeciazenie operatora odejmowania dwoch macierzy
  Macierz operator * (const Macierz & M) const; // przeciazenie operatora mnozenia dwoch macierzy
  Wektor operator * (const Wektor & W) const; //przeciazenie operatora mnozenia macierzy i wektora
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 * Przeciazenie operatora przesuniecia bitowego w prawo,
 * za pierwszy argument bierze dana komende(np. cin) ze
 * strumienia wejsciowego z biblioteki std, 
 * a za drugi argument bierze podana macierz.
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 * Przeciazenie operatora przesuniecia bitowego w lewo,
 * za pierwszy argument bierze dana komende(np. cout) ze
 * strumienia wyjsciowego biblioteki std,
 * a za drugi argument bierze podana macierz.
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
