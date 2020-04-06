#include "Macierz.hh"
using namespace std;

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
    const Wektor & Macierz::operator[] (int indeks) const{
        if (indeks < 0 || indeks > ROZMIAR)
  {
    cerr << "Blad, zly indeks wektora";
    exit(1);
  }
  return indeks == 0 ? this->kol[0] : indeks == 1 ? this->kol[1] : this->kol[2];
  }

    Wektor & Macierz::operator[] (int indeks){
        if (indeks < 0 || indeks > ROZMIAR)
  {
    cerr << "Blad, zly indeks wektora";
    exit(1);
  }
  return indeks == 0 ? this->kol[0] : indeks == 1 ? this->kol[1] : this->kol[2];
  }

  //void odwrotnosc(); //1
  const Macierz & Macierz::odwrotnosc() const{

  }
 // double Wyznacznik();
  //laplace, gauss, sarrus
  double Macierz::WyznacznikGauss () const{

  }
 // double Wyznacznik (Gauss) const; //enum

 // void transpozycja(); //1
  const Macierz & Macierz::transpozycja() const{

  }

  const Macierz & Macierz::operator + (const Macierz & M) const{
      Macierz Wynik;
      for( int i = 0; i < ROZMIAR; i++ )
        for( int j = 0; j < ROZMIAR; j++)
        Wynik->kol[i]->dane[j] = this->kol[i]->dane[j] + M->kol[i]->dane[j];
        return Wynik;
  }

   const Macierz & Macierz::operator - (const Macierz & M) const{
      Macierz Wynik;
      for( int i = 0; i < ROZMIAR; i++ )
        for( int j = 0; j < ROZMIAR; j++)
        Wynik->kol[i]->dane[] = this->kol[i]->dane[j] - M->kol[i]->dane[j];
        return Wynik;
  }

    const Macierz & Macierz::operator * (const Macierz & M) const{
        Macierz Wynik;
     for( int h = 0; h < ROZMIAR; h++ )
      for( int i = 0; i < ROZMIAR; i++ )
        for( int j = 0; j < ROZMIAR; j++ )
        Wynik->kol[i]->dane[i] += this->kol[i]->dane[j] * M->kol[j]->dane[i];
        return Wynik;
    }

     const Wektor & Macierz::operator * (const Wektor & W) const{
         Wektor Wynik;
      for( int i = 0; i < ROZMIAR; i++ )
        for( int j = 0; j < ROZMIAR; j++)
        Wynik->dane[i] = this->kol[i]->dane[j] * W->dane[j];
        return Wynik;
     }

     std::istream& operator >> (std::istream &Strm, Macierz &Mac){
         for ( int i = 0; i < ROZMIAR; i++ )
            for ( int j = 0; j < ROZMIAR; j++ )
            return Strm >> Mac->kol[i]->dane[j];
     }

     std::ostream& operator << (std::ostream &Strm, const Macierz &Mac){
         for ( int i = 0; i < ROZMIAR; i++ )
            for ( int j = 0; j < ROZMIAR; j++ ){
                if (i = 0)
                Strm << '|';
            return Strm << Mac->kol[i]->dane[j];
                if (i = 2)
                Strm << '|';
            }
     }