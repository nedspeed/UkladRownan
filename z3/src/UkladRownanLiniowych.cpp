#include "UkladRownanLiniowych.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

/*
 *
 */
UkladRownanLiniowych::UkladRownanLiniowych()
{
  Wsp = Macierz();
  Wol = Wektor();
}

UkladRownanLiniowych::UkladRownanLiniowych(Macierz AA, Wektor BB)
{
  Wsp = AA;
  Wol = BB;
}

    const Wektor UkladRownanLiniowych::wez_wektor() const{
    return this->Wol;
    }
    const Macierz UkladRownanLiniowych::wez_macierz() const{
    return this->Wsp;
    }
      void UkladRownanLiniowych::zmien_wektor(Wektor Wej){
      Wol = Wej;
    }
      void UkladRownanLiniowych::zmien_macierz(Macierz We){
      Wsp = We;
    }
      void UkladRownanLiniowych::zmien_kolumne(int i, Wektor We, Macierz W) const
    {
    for (int j = 0; j < ROZMIAR; j++)
    {
        std::swap(W[i][j],We[j]);
    }
}
/*
 *
 */
    Wektor UkladRownanLiniowych::WyznKram() {
        Wektor Wyzn;
        UkladRownanLiniowych kopia = *this;
        Wektor tmp = kopia.wez_wektor();
        Macierz tm = kopia.wez_macierz();
        for(int i = 0; i < ROZMIAR; i++){
            kopia.zmien_kolumne(i, tmp, tm);
            Wyzn[i] = tm.Wyznacznik();
            kopia.zmien_kolumne(i, tmp, tm);
        }
        return Wyzn;
    }
/*
 *
 */
    Wektor UkladRownanLiniowych::RozwUkl() const{
        UkladRownanLiniowych kopia = *this;
        Macierz tm = kopia.wez_macierz();
        double WzG = tm.Wyznacznik();
        Wektor Wyzn = kopia.WyznKram();
        Wektor Rozw;
        for( int i = 0; i < ROZMIAR; i++){
        Rozw[i] = Wyzn[i]/WzG;
        }
        std::cout << std::endl;
        for( int k = 0; k < ROZMIAR; k++){
        std::cout << Rozw[k];
        std::cout << ' ';
        }
        std::cout << std::endl;
    return Rozw;
    }

    Wektor UkladRownanLiniowych::LiczBlad(Wektor Rozw){
        Wektor Blad, tmp;
        UkladRownanLiniowych kopia = *this;
        tmp = kopia.wez_macierz() * Rozw;
        Blad = tmp - kopia.wez_wektor();
        return Blad;
    }

  /*
   *
   */
  std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown){
     Wektor Wej;
     Macierz We;
     Strm >> We;
     Strm >> Wej;
     UklRown.zmien_wektor(Wej);
     UklRown.zmien_macierz(We);
     return Strm;
     }
  /*
   *
   */
  std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych &UklRown){
         Wektor Wyj = UklRown.wez_wektor();
         Macierz Wy = UklRown.wez_macierz();
         for ( int i = 0; i < ROZMIAR; i++ ){
            for ( int j = 0; j < ROZMIAR; j++ ){

            Strm << Wy[i][j];
            Strm << ' ';
            }
            Strm << std::endl;
            }
            for ( int k = 0; k < ROZMIAR; k++){
            Strm << Wyj[k];
            Strm << ' ';
            }
            Strm << std::endl;
            return Strm;
     }
     