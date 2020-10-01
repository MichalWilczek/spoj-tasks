
/*
Wczytaj ciag liczb. Nastepnie wypisz wczytane liczby
w taki sposob, aby najpierw pojawily sie te, ktore
wystapily na pozycjach parzystych, a nastepnie te,
ktore wystapily na pozycjach nieparzystych; z
zachowaniem pierwotnej kolejnosci w obrebie obu grup.
Numerujemy od 1.

Wejscie
Najpierw t - liczba testów. Nastepnie dla kazdego
testu liczba n i n liczb, n <= 100.

Wyjscie
Dla kazdego testu n liczb w opisanym porzadku.
*/

/*
PLAN PROGRAMU
1. Wczytaj ilosc powtorzen.
2. Wczytaj ilosc liczb w tablicy oraz sam ciag znakow do tablicy
3. Przedstaw na paczatku liczby parzyste a potem nieparzyste
*/

#include <iostream>
#include <string>
using namespace std;

void przestawPozycjeTablicyWzgledemPozycjiParzystych(int *tablica, int iloscLiczbWTablicy)
{
    int *wskaznik;

    wskaznik = &tablica[1];
    for (int i=1; i<iloscLiczbWTablicy; i=i+2)
    {
        cout << *wskaznik << " ";
        wskaznik+=2;
    }

    wskaznik = &tablica[0];
    for (int i=0; i<iloscLiczbWTablicy; i=i+2)
    {
        cout << *wskaznik << " ";
        wskaznik+=2;
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
        przestawPozycjeTablicyWzgledemPozycjiParzystych(tablica, iloscLiczbWTablicy);
        cout << endl;
        delete [] tablica;
    }
    return 0;
}

