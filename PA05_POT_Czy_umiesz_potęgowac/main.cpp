/*
Dla danych dwóch liczb naturalnych a i b,
wyznaczyć ostatnią cyfrę liczby ab.

Zadanie
Napisz program, który:
wczyta ze standardowego wejścia: podstawę
a oraz wykładnik b,
wyznaczy ostatnią cyfrę liczby ab,
wypisze wynik na standardowe wyjście.

Wejście
W pierwszej linii wejścia znajduje się jedna
liczba całkowia D (1≤D≤10), oznaczjąca liczbę
przypadków do rozważenia. Opis każdego przypadku
podany jest w jednym wierszu, zawierającym dwie
liczby naturalne a i b oddzielone pojedynczym
odstępem (spacją), takie, że (1 ≤ a,b ≤ 1 000 000 000).

Wyjście
Dla każdego przypadku z wejścia Twój program
powinien wypisać (w osobnej linii dla każdego
przypadku z wejścia) cyfrę jedności liczby ab
zapisanej dziesiętnie.
*/

#include <iostream>
#include <string>
using namespace std;

long long policzPotege(long long p, long long w)
{
    if (w==0) return 1;
    else return p*policzPotege(p, w-1);
}

int wyznaczOstatniaCyfreModulo(long long liczba)
{
    return liczba%10;
}

int wyznaczOstatniaCyfrePrzyPodstawieDwa(long long wykladnik)
{
    int reszta = wykladnik%4;
    switch (reszta)
    {
    case 0: return 6; break;
    case 1: return 2; break;
    case 2: return 4; break;
    case 3: return 8; break;
    }
}

int wyznaczOstatniaCyfrePrzyPodstawieTrzy(long long wykladnik)
{
    int reszta = wykladnik%4;
    switch (reszta)
    {
    case 0: return 1; break;
    case 1: return 3; break;
    case 2: return 9; break;
    case 3: return 7; break;
    }
}

int wyznaczOstatniaCyfrePrzyPodstawieCztery(long long wykladnik)
{
    int reszta = wykladnik%2;
    switch (reszta)
    {
    case 0: return 6; break;
    case 1: return 4; break;
    }
}

int wyznaczOstatniaCyfrePrzyPodstawieSiedem(long long wykladnik)
{
    int reszta = wykladnik%4;
    switch (reszta)
    {
    case 0: return 1; break;
    case 1: return 7; break;
    case 2: return 9; break;
    case 3: return 3; break;
    }
}

int wyznaczOstatniaCyfrePrzyPodstawieOsiem(long long wykladnik)
{
    int reszta = wykladnik%4;
    switch (reszta)
    {
    case 0: return 6; break;
    case 1: return 8; break;
    case 2: return 4; break;
    case 3: return 2; break;
    }
}

int wyznaczOstatniaCyfrePrzyPodstawieDziewiec(long long wykladnik)
{
    int reszta = wykladnik%2;
    switch (reszta)
    {
    case 0: return 1; break;
    case 1: return 9; break;
    default: cout << "nooooo" << endl;
    }
}

int wyznaczOstatniaCyfreZWartosciPodstawy(long long podstawa, long long wykladnik)
{
    int ostatniaCyfraPodstawy = wyznaczOstatniaCyfreModulo(podstawa);
    switch (ostatniaCyfraPodstawy)
    {
    case 0: return 0; break;
    case 1: return 1; break;
    case 2: return wyznaczOstatniaCyfrePrzyPodstawieDwa(wykladnik); break;
    case 3: return wyznaczOstatniaCyfrePrzyPodstawieTrzy(wykladnik); break;
    case 4: return wyznaczOstatniaCyfrePrzyPodstawieCztery(wykladnik); break;
    case 5: return 5; break;
    case 6: return 6; break;
    case 7: return wyznaczOstatniaCyfrePrzyPodstawieSiedem(wykladnik); break;
    case 8: return wyznaczOstatniaCyfrePrzyPodstawieOsiem(wykladnik); break;
    case 9: return wyznaczOstatniaCyfrePrzyPodstawieDziewiec(wykladnik); break;
    }
}

int main()
{
    long long podstawa, wykladnik;

    int iloscPowtorzen;
    cin >> iloscPowtorzen;

    for (int i=0; i<iloscPowtorzen; i++)
    {
        cin >> podstawa >> wykladnik;
        cout << wyznaczOstatniaCyfreZWartosciPodstawy(podstawa, wykladnik) << endl;
    }
    return 0;
}
