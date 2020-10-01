
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
    for (int i=iloscLiczbWTablicy; i>0; i--)
    {
        cout << tablica[i-1] << " ";
    }
}

int main()
{
    int tablica[100];
    int iloscLiczbWTablicy = 0;
    int iloscPowtorzen;
    int liczba;

    cin >> iloscPowtorzen;
    for (int j=0; j<iloscPowtorzen; j++)
    {
        cin >> iloscLiczbWTablicy;
        for (int i=0; i<iloscLiczbWTablicy; i++)
        {
            cin >> liczba;
            tablica[i] = liczba;
        }
        odwrocTablice(tablica, iloscLiczbWTablicy);
        cout << endl;
    }
    return 0;
}
