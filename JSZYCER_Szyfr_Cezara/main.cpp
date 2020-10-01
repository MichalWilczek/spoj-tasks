
/*
Kazda litere tekstu jawnego zamieniamy na litere przesunieta o 3 miejsca w prawo.
I tak litere A szyfrujemy jako litere D, litere B jako E itd. W przypadku litery
Z wybieramy litere C. W celu odszyfrowania tekstu powtarzamy operacje tym razem
przesuwajac litery o 3 pozycje w lewo.

Input
Na wejsciu pojawi sie tekst zawierajacy jedynie wielkie litery alfabetu lacinskiego,
spacje oraz znaki nowej linii, a jego dlugosc nie przekracza 200 znakow.

Output
Na wyjsciu otrzymujemy zaszyfrowany tekst uzywajac Szyfru Cezara.
*/

/*
PLAN PROGRAMU
1. Odczytaj zdanie zapisane przez uzytkownika i zapisz je jako string zdanieDoZaszyfrowania.
2. Zamien kazda litere w zdaniu na adekwatna litere wg. szyfru Cezara.
3. Wypisz zdanie zapisane szyfrem Cezara.
*/

#include <iostream>
#include <string>
using namespace std;

int zamienLitereNaASCII(char litera)
{
    return int(litera);
}

int uzyjSzyfruCezara(int liczbaASCII)
{
    switch (liczbaASCII)
    {
        case 10: return liczbaASCII; break;     // przypadek nowej linii '\n'
        case 13: return liczbaASCII; break;     // przypadek nowej linii '\r'
        case 32: return liczbaASCII; break;     // przypadek dla spacji
        case 88: return liczbaASCII-23; break;  // przypadek X
        case 89: return liczbaASCII-23; break;  // przypadek Y
        case 90: return liczbaASCII-23; break;  // przypadek Z
        default: return liczbaASCII+3; break;
    }
}

char zamienACCIINaLitere(int liczbaASCII)
{
    return char(liczbaASCII);
}

int main()
{
    string zdanieDoZaszyfrowania;
    while (getline(cin, zdanieDoZaszyfrowania))
    {
    int dlugoscZdania = zdanieDoZaszyfrowania.length();
    int *tablicaZdanie;
    tablicaZdanie = new int [dlugoscZdania];

    for (int i=0; i<dlugoscZdania; i++)
    {
        *tablicaZdanie = zamienLitereNaASCII(zdanieDoZaszyfrowania[i]);
        *tablicaZdanie = uzyjSzyfruCezara(*tablicaZdanie);
        cout << zamienACCIINaLitere(*tablicaZdanie);
        tablicaZdanie++;
    }
    cout << endl;
    tablicaZdanie -= dlugoscZdania;
    delete [] tablicaZdanie;
    }
}
