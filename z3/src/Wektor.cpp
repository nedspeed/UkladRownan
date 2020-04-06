#include "Wektor.hh"
using namespace std;

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
double Wektor::dlugosc() const{
return sqrt((this->dane[0]*this->dane[0])+(this->dane[1]*this->dane[1])+(this->dane[2]*this->dane[2]));
}
  
  double Wektor::operator * (const Wektor &W2) const{
      double Wynik = 0;
for(int i = 0; i < ROZMIAR; i++)
    Wynik += this->dane[i] * W2.dane[i];
return Wynik;
  }

  const Wektor & Wektor::operator + (const Wektor &W2) const{
      Wektor Wynik;
for(int i = 0; i < ROZMIAR; i++)
    Wynik.dane[i] = this->dane[i] + W2.dane[i];
return Wynik;
  }
  
  const Wektor & Wektor::operator - (const Wektor &W2) const{
      Wektor Wynik;
for(int i = 0; i < ROZMIAR; i++)
    Wynik.dane[i] = this->dane[i] - W2.dane[i];
return Wynik;
  }

  const double & Wektor::operator [] (double indeks) const{
  if (indeks < 0 || indeks > ROZMIAR)
  {
    cerr << "Blad, zly indeks wektora";
    exit(1);
  }
  return indeks == 0 ? this->dane[0] : indeks == 1 ? this->dane[1] : this->dane[2];
  }

  double & Wektor::operator [] (double indeks){
  if (indeks < 0 || indeks > ROZMIAR)
  {
    cerr << "Blad, zly indeks wektora";
    exit(1);
  }
  return indeks == 0 ? this->dane[0] : indeks == 1 ? this->dane[1] : this->dane[2];
  }

  std::istream& operator >> (std::istream &Strm, Wektor &W){
      for(int i = 0; i < ROZMIAR; i++)
      return Strm >> W.dane[i];
  }

  std::ostream& operator << (std::ostream &Strm, const Wektor &W){
      for(int i = 0; i < ROZMIAR; i++)
      return Strm << '|' << Strm << W.dane[i] << Strm << '|';
  }