#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include <iostream>
#include "Wektor.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz {   //okresl czy macierz wierszowa czy kolumnowa - kolumnowa
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
    friend class Wektor;
    Wektor kol[ROZMIAR]; //wk-wiersze kolumny
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */    
  Macierz();
  //Macierz(double 00, double 01, double 02, double 10, double 11, double 12, double 20, double 21, double 22); // 1 z 3
  Macierz( Wektor kol[ROZMIAR] ); // 1 z 3

  const Wektor & operator[] (int indeks) const;//to
  Wektor & operator[] (int indeks);

  // const double & operator[] (int ind1, int ind2) const;//lub to
  //double & operator[] (int ind1, int ind2);

  //void odwrotnosc(); //1
  const Macierz & odwrotnosc() const; //2
 // double Wyznacznik();
  //laplace, gauss, sarrus
  double WyznacznikGauss () const;
 // double Wyznacznik (Gauss) const; //enum

 // void transpozycja(); //1
  const Macierz & transpozycja() const; //2
  const Macierz & operator + (const Macierz & M) const;
   const Macierz & operator - (const Macierz & M) const;
    const Macierz & operator * (const Macierz & M) const;
     const Wektor & operator * (const Wektor & W) const;
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
