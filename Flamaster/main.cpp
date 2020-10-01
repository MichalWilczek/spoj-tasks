
/*
Kasia niedawno poznała wszystkie literki w szkole.
Z wielką pasją potrafiła całe dnie spędzać na
pisaniu długich słów swoim ulubionym flamastrem.
Pisała i pisała "tasiemce" tak długo, aż flamaster
wypisał się. Kasia posmutniała. Z trudem, ale udało
jej się uprosić swoją mamę, aby kupiła jej nowy
pisak. Musiała jednak obiecać, że tym razem będzie
bardziej oszczędna przy jego używaniu żeby
wystarczył na dłużej. Kasia zaczęła zastanawiać się
w jaki sposób będzie mogła zrealizować obietnicę
daną mamie.

Postanowiła, że aby zaoszczędzić wkład flamastra
będzie wypisywała skróconą wersję wymyślanych
wyrazów. Jeśli miała zamiar napisać więcej niż
dwie takie same literki obok siebie w wyrazie, to
teraz napisze literkę a następnie liczbę,
określającą ilość wystąpień tej literki.

Zadanie
Twoim zadaniem jest dla zadanego wyrazu,
który wymyśliła Kasia, podanie skróconej wersji
tego wyrazu.

Wejście
W pierwszej linijce wejścia znajduje się liczba
naturalna C, 1 ≤ C ≤ 50, oznaczająca ilość zestawów
danych. W kolejnych C wierszach wejścia znajdują
się zestawy danych. Każdy zestaw składa się z
niepustego wyrazu złożonego z samych dużych liter
alfabetu amerykańskiego. Długość wyrazu nie przekracza
200 znaków.

Wyjście
Dla każdego zestawu danych, dla zadanego wyrazu,
na wyjściu powinna znaleźć się jego skrócona wersja.
*/

#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>
#include <fstream>

using namespace std;

string konwertujIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

int obliczIloscWystapienWybranegoZnaku(string wyraz, int pozycjaZnaku)
{
    int iloscWystapien = 1;
    if (wyraz.length() > pozycjaZnaku)
    {
        while(wyraz[pozycjaZnaku] == wyraz[pozycjaZnaku+1])
        {
            iloscWystapien++;
            pozycjaZnaku++;
        }
    }
    else
    {
        iloscWystapien = 0;
    }
    return iloscWystapien;
}

string skrocWyraz(string wyrazDoSkrocenia)
{
    int dlugoscWyrazu = wyrazDoSkrocenia.length();
    int iloscWystapien = 1;
    char powtarzajacySieZnak;
    for (int i=0; i<dlugoscWyrazu-2; i++)
    {
        // sprawdzamy czy wystepuja 3 identyczne znaki obok siebie
        if ((wyrazDoSkrocenia[i] == wyrazDoSkrocenia[i+1]) && (wyrazDoSkrocenia[i+1] == wyrazDoSkrocenia[i+2]))
        {
            iloscWystapien = obliczIloscWystapienWybranegoZnaku(wyrazDoSkrocenia, i);
            powtarzajacySieZnak = wyrazDoSkrocenia[i];
            wyrazDoSkrocenia.replace(i, iloscWystapien, powtarzajacySieZnak+konwertujIntNaString(iloscWystapien));
            dlugoscWyrazu = wyrazDoSkrocenia.length();
        }
    }
    return wyrazDoSkrocenia;
}

int main()
{
    int iloscTestow;
    cin >> iloscTestow;
    for (int i=0; i<iloscTestow; i++)
    {
        string wyraz;
        cin >> wyraz;
        cout << skrocWyraz(wyraz) << endl;
    }
    return 0;
}
