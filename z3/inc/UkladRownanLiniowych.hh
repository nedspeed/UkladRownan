#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH
#include "Wektor.hh"
#include "Macierz.hh"
#include <iostream>
#include "rozmiar.h"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanLiniowych {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  Macierz Wsp; //macierz wspolczynnikow
  Wektor Wol; //Wol - wektor wyrazow wolnych
   //Rozw - rozwiazan, Blad - wektor bledu, Wyzn - wyznacznikow posrednich
   //WzG - WyznacznikGlowny, L - dlugosc wektora
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */    
  UkladRownanLiniowych();  //konstruktor domyslny
  UkladRownanLiniowych(Macierz AA, Wektor BB); //konstruktor

  Wektor WyznKram();
  Wektor RozwUkl() const;
  Wektor LiczBlad(Wektor Rozw);
  const Wektor wez_wektor()const;
  const Macierz wez_macierz() const;
  void zmien_wektor(Wektor Wej);
  void zmien_macierz(Macierz We);
  void zmien_kolumne(int i, Wektor We, Macierz W) const;
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych &UklRown);


#endif
