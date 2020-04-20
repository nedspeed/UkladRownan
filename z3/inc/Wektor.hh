#ifndef WEKTOR_HH
#define WEKTOR_HH
#include "rozmiar.h"
#include <iostream>
#include <cmath>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
double dane[ROZMIAR];
//int x,y,z;
//int wymiar;
//double *dane;
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */    
  Wektor() = default;
  Wektor(double dane[ROZMIAR]); //konstruktor od kolekcji
  double dlugosc() const;  //metoda obliczajca dlugosc wektora
  double operator *(const Wektor &W2) const;  //przeciazenie mnozenia wektor razy wektor
  Wektor operator + (const Wektor &W2) const; //przeciazenie dodawania wektorow
  Wektor operator - (const Wektor &W2) const; //przeciazenie odejmowania wektorow
  const double & operator [] (int indeks) const; //przeciazenie operatora indeksowania dla wektora typu const
  double & operator [] (int indeks); //przeciazenie operatora indeksowania dla wektora dowolnego typu
};
/*Wektor W;
W[2];
const Wektor Wc;
Wc.dlugosc();
Wc[2]=2;
double b = Wc[2]; */
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
std::istream& operator >> (std::istream &Strm, Wektor &W);

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
std::ostream& operator << (std::ostream &Strm, const Wektor &W);

#endif
