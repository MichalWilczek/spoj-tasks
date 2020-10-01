/*
PP0502B - Tablice
Odwróć kolejność elementów w tablicy.

Wejście
Najpierw liczba testów t (t ≤ 100).
Następnie dla każdego testu liczba
n (n ≤ 100) i n liczb oddzielonych
spacjami.

Wyjście
Dla każdego testu n liczb w porządku
odwrotnym niż na wejściu.
*/

#include <iostream>
#include <string>
using namespace std;

void odwrocTablice(int *tablica, int iloscLiczbWTablicy)
{
    int *wskaznik;
    wskaznik = &tablica[iloscLiczbWTablicy-1];
    for (int i=0; i<iloscLiczbWTablicy; i++)
    {
        cout << (int)*wskaznik << " ";
        wskaznik--;
    }
}

int main()
{
    int *tablica;
    int iloscLiczbWTablicy;
    int iloscPowtorzen;
    int liczba;

    cin >> iloscPowtorzen;
    for (int j=0; j<iloscPowtorzen; j++)
    {
        cin >> iloscLiczbWTablicy;
        tablica = new int [iloscLiczbWTablicy];
        for (int i=0; i<iloscLiczbWTablicy; i++)
        {
            cin >> liczba;
            *tablica = liczba;
            tablica++;
        }
        tablica -= iloscLiczbWTablicy;
        odwrocTablice(tablica, iloscLiczbWTablicy);
        cout << endl;
        delete [] tablica;
    }
    return 0;
}
