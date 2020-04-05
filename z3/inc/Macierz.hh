#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include <iostream>
#include "Wektor.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class MacierzKw {   //okresl czy macierz wierszowa czy kolumnowa
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
Wektor tab[ROZMIAR];
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */    
  MacierzKw();
  MacierzKw(/*9double*/); // 1 z 3
  MacierzKw(/*3wektory*/); // 1 z 3
  MacierzKw(/*tablica n elementow */); // 1 z 3
  const Wektor & operator[] (int indeks) const;//to
  Wektor & operator[] (int idndeks);

   const double & operator() (int ind1, int ind2) const;//lub to
  double & operator() (int ind1, int ind2);

  void odwrotnosc(); //1
  const Macierz & odwrotnosc() const; //2
  double Wyznacznik();
  //laplace, gauss, sarrus
  double WyznacznikGauss () const;
  double Wyznacznik (Gauss) const; //enum

  void transpozycja(); //1
  const MacierzKw & transpozycja() const; //2
  const MacierzKw & operator + (const Macierz & W) const;
   const MacierzKw & operator - (const Macierz & W) const;
    const MacierzKw & operator * (const Macierz & W) const;
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
