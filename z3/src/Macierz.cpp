#include "Macierz.hh"
using namespace std;

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

/*
 * Przeciazenie operatora indeksowania [] dla macierzy
 * typu const.
*/
    const Wektor & Macierz::operator[] (int indeks) const{
        if (indeks < 0 || indeks > ROZMIAR)
  {
    cerr << "Blad, zly indeks wektora";
    exit(1);
  }
  return kol[indeks];
  }
/*
 * Przeciazenie operatora indeksowania [] dla macierzy
 * dowolnego typu.
*/
    Wektor & Macierz::operator[] (int indeks){
        if (indeks < 0 || indeks > ROZMIAR)
  {
    cerr << "Blad, zly indeks wektora";
    exit(1);
  }
  return kol[indeks];
  }


/*
 * Metoda wyliczajaca wyznacznik macierzy
 *  za pomoca metody Gaussa-Jordana.
 */
  double Macierz::Wyznacznik () {
    double x = 1;
  for(int i=0;i<ROZMIAR;i++){
        x = x * this->kol[i][i];
        for(int j=0;j<ROZMIAR;j++){
            if(this->kol[i][i]!=0){
                this->kol[i][j]=this->kol[i][j]/this->kol[i][i];
            }
        }
        for(int k=i+1;k<ROZMIAR;k++){
            for(int y=i;y<ROZMIAR;y++){
                this->kol[k][y]=this->kol[k][y]-(this->kol[k][i]*this->kol[i][y]);
            }           
        }
    }
    double z=1;
    for(int i=0;i<ROZMIAR;i++){
        z=z*this->kol[i][i];
    }
    double wyzn = x*z;
    return wyzn;
  }


/*
 * Metoda sluzy do transponowania macierzy.
 */
   Macierz Macierz::transpozycja() const{
    Macierz tmp;
      for( int i = 0; i < ROZMIAR; i++ ){
        for( int j = 0; j < ROZMIAR; j++ )

          tmp[i][j] = this->kol[j][i];
        }
      return tmp;
  }

/*
 * Metoda jest przeciazeniem operacji dodawania
 * do siebie dwoch macierzy, zwraca kopie.
 */
  Macierz Macierz::operator + (const Macierz & M) const{
      Macierz Wynik;
      for( int i = 0; i < ROZMIAR; i++ ){
        for( int j = 0; j < ROZMIAR; j++)

        Wynik[i][j] = this->kol[i][j] + M[i][j];
        }
        return Wynik;
  }

/*
 * Metoda jest przeciazeniem operacji odejmowania
 * od siebie dwoch macierzy, zwraca kopie.
 */
   Macierz Macierz::operator - (const Macierz & M) const{
      Macierz Wynik;
      for( int i = 0; i < ROZMIAR; i++ ){
        for( int j = 0; j < ROZMIAR; j++)
        
        Wynik[i][j] = this->kol[i][j] - M[i][j];
        }
        return Wynik;
  }

/*
 * Metoda jest przeciazeniem operacji mnozenia 
 * przez siebie dwoch macierzy, zwraca kopie.
 */
    Macierz Macierz::operator * (const Macierz & M) const{
        Macierz Wynik;
     for( int h = 0; h < ROZMIAR; h++ ){
      for( int i = 0; i < ROZMIAR; i++ )
        for( int j = 0; j < ROZMIAR; j++ )

        Wynik[h][i] += this->kol[h][j] * M[i][j];
        }
        return Wynik;
    }

/*
 * Metoda jest przeciazeniem operacji mnozenia
 * przez siebie macierzy i wektora, zwraca kopie.
 */
     Wektor Macierz::operator * (const Wektor & W) const{
         Wektor Wynik;
      for( int i = 0; i < ROZMIAR; i++ ){
        for( int j = 0; j < ROZMIAR; j++)

        Wynik[i] = this->kol[i][j] * W[j];
        }
        return Wynik;
     }

/*
 * Funkcja przeciazajaca operator 
 * przesuniecia bitowego w prawo.
 */
     std::istream& operator >> (std::istream &Strm, Macierz &Mac){
         for ( int i = 0; i < ROZMIAR; i++ ){
            for ( int j = 0; j < ROZMIAR; j++ )

            Strm >> Mac[i][j];
            }
            return Strm;
     }

/*
 * Funkcja przeciazajaca operator
 * przesuniecia bitowego w lewo.
 */
     std::ostream& operator << (std::ostream &Strm, const Macierz &Mac){
         for ( int i = 0; i < ROZMIAR; i++ ){
           Strm << endl;
            for ( int j = 0; j < ROZMIAR; j++ ){
                Strm << Mac[i][j];
                Strm << ' ';
            }}
            return Strm;
     }