/*
PRIME_T - Liczby Pierwsze
Sprawdz, które sposrod danych
liczb sa liczbami pierwszymi

Input
n - liczba testow n<100000, w
kolejnych liniach n liczb z
przedzialu [1..10000]

Output
Dla kazdej liczby slowo TAK,
jesli liczba ta jest pierwsza,
slowo: NIE, w przeciwnym wypadku.
*/

/*
PLAN PROGRAMU
1. Wprowadz pozadana ilosc testow.
2. Wprowadz liczbe do sprawdzenia.
3. Podaj odpowiedz czy liczba jest
   zlozona czy jest liczba pierwsza.
*/

#include <iostream>
#include <math.h>

using namespace std;

bool sprawdzCzyLiczbaJestPierwsza(int liczba)
{
    long long dzielnikMaksymalny = sqrt(liczba);
    long long dzielnik = 2;
    if (liczba<=1) return false;
    while (dzielnik <= dzielnikMaksymalny)
    {
        if (liczba%dzielnik == 0)
        {
            return false;
        }
        else
        {
            dzielnik++;
        }
    }
    return true;
}

int main()
{
    int liczba;
    int liczbaTestow;
    cin >> liczbaTestow;
    for (int i=0; i<liczbaTestow; i++)
    {
        cin >> liczba;
        if (sprawdzCzyLiczbaJestPierwsza(liczba)) cout << "TAK" << endl;
        else cout << "NIE" << endl;
    }
    return 0;
}
