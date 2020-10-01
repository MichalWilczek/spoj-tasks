
/*
Przesuń elementy tablicy cyklicznie w lewo.

Wejście
Najpierw liczba testów t (t ≤ 100). Następnie
dla każdego testu liczba n (1 < n ≤ 100) i n liczb.

Wyjście
Dla każdego testu n liczb w zmienionym porządku.
*/

/*
PLAN PROGRAMU
1. Wczytaj ilosc powtorzen.
2. Wczytaj ilosc liczb w tablicy oraz sam ciag znakow do tablicy
3. Przedstaw na liczby w tablice przestawione o jeden indeks w lewo.
*/

#include <iostream>
using namespace std;

void przestawPierwszaLiczbe(int *tablica, int iloscLiczbWTablicy)
{
    int *wskaznik;
    wskaznik = &tablica[1];
    for (int i=0; i<iloscLiczbWTablicy; i++)
    {
        cout << *wskaznik << " ";
        wskaznik++;
        if (i==iloscLiczbWTablicy-2)
        {
            wskaznik-=(iloscLiczbWTablicy);
        }
    }
}

int main()
{
    int *tablica;
    int iloscLiczbWTablicy;
    int iloscPowtorzen;
    int liczba;

    cin>>iloscPowtorzen;
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
        tablica-=iloscLiczbWTablicy;
        przestawPierwszaLiczbe(tablica, iloscLiczbWTablicy);
        cout << endl;
        delete [] tablica;
    }
    return 0;
}
