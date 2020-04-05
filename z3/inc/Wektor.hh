#ifndef WEKTOR_HH
#define WEKTOR_HH
#include "rozmiar.h"
#include <iostream>


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
  Wektor();
  Wektor(double x, double y, double z); //konstruktor od kolekcji
  double dlugosc() const;
  double operator *(const Wektor &W2) const;
  const Wektor & operator + (const Wektor &W2) const;
  const Wektor & operator - (const Wektor &W2) const;
  const double & operator [] (int indeks) const;
  double & operator [] (int indeks){
  if (indeks < 0 || indeks > ROZMIAR)
  {
    cerr << "Blad, zly indeks wektora";
    exit(1);
  }
  }
  //x,y,z
  //void set_x(double xx);
 // void set_y(double yy);
 // ...
 // double get_x();
//...


};
/*Wektor W;
W[2];

Wc.dlugosc();
const Wektor Wc;
Wc[2]=2;
double b = Wc[2]; */
/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
