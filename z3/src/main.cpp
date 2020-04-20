#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  UkladRownanLiniowych UklRown;   // To tylko przykladowe definicje zmiennej
  cout << endl << " Start programu " << endl << endl;
  cout << "Podaj skladniki ukladu rownan" << endl;
  cin >> UklRown;
  cout << "Uklad rownan to" << endl;
  cout << UklRown;
  cout << "Macierz wspolczynnikow to" << endl;
  cout << UklRown.wez_macierz() << endl;
  cout << "Wektor wyrazow wolnych to:" << endl;
  cout << UklRown.wez_wektor() << endl;
    cout << "Rozwiazania ukladu rownan to:";
      cout << endl;
        for( int j = 0; j < ROZMIAR; j++){
            cout << 'x';
            cout << j+1;
            cout << ' ';
        }
        cout << endl;
  Wektor Rozw = UklRown.RozwUkl();
    cout << "Wektor bledu to:" << endl;
    Wektor Blad = UklRown.LiczBlad(Rozw);
    cout << Blad << endl;
    cout << "Dlugosc wektora bledu wynosi:" << endl;
    cout << Blad.dlugosc() << endl;
}
