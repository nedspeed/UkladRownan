#include "Wektor.hh"
using namespace std;

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
/*
 * Metoda klasy wektor obliczajaca 
 * dlugosc danego wektora.
 */
double Wektor::dlugosc() const{
  double Wynik;
  double tmp;
  for( int i = 0; i < ROZMIAR; i++){
  tmp += this->dane[i]*this->dane[i];
}
Wynik = sqrt(tmp);
return Wynik;
}
  
/*
 * Metoda przeciazajaca operacje
 * mnozenia wektora przez wektor.
 */
  double Wektor::operator * (const Wektor &W2) const{
      double Wynik = 0;
for(int i = 0; i < ROZMIAR; i++)
    Wynik += this->dane[i] * W2.dane[i];
return Wynik;
  }

/*
 * Metoda przeciazajaca operacje
 * dodawania do siebie dwoch wektorow.
 */
  Wektor Wektor::operator + (const Wektor &W2) const{
      Wektor Wynik;
for(int i = 0; i < ROZMIAR; i++)
    Wynik.dane[i] = this->dane[i] + W2.dane[i];
return Wynik;
  }
  
/*
 * Metoda przeciazajaca operacje
 * odejmowania od siebie dwoch wektorow.
 */
  Wektor Wektor::operator - (const Wektor &W2) const{
      Wektor Wynik;
for(int i = 0; i < ROZMIAR; i++)
    Wynik.dane[i] = this->dane[i] - W2.dane[i];
return Wynik;
  }

/*
 * Metoda przeciazajaca operator []
 * indeksowania dla wektora typu const.
 */
  const double & Wektor::operator [] (int indeks) const{
  if (indeks < 0 || indeks > ROZMIAR)
  {
    cerr << "Blad, zly indeks wektora";
    exit(1);
  }
    return dane[indeks];
  }

/*
 * Metoda przeciazajaca operator []
 * indeksowania dla wektora dowolnego typu.
 */
  double & Wektor::operator [] (int indeks){
  if (indeks < 0 || indeks > ROZMIAR)
  {
    cerr << "Blad, zly indeks wektora";
    exit(1);
  }
    return dane[indeks];
  }

/*
 * Funkcja przeciazajaca operator
 * przesuniecia bitowego w prawo.
 */
  std::istream& operator >> (std::istream &Strm, Wektor &W){
      for(int i = 0; i < ROZMIAR; i++){
        Strm>>W[i];
      }

      return Strm;
  }

/*
 * Funkcja przeciazajaca operator
 * przesuniecia bitowego w lewo.
 */
  std::ostream& operator << (std::ostream &Strm, const Wektor &W){
      for(int i = 0; i < ROZMIAR; i++){
        Strm << W[i];
        Strm << ' ';
        }
        return Strm;
  }