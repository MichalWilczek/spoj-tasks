/*
PLAN PROGRAMU:
1. Podaj: znak obliczeniowy oraz dwie liczby.
2. Wykonaj rachunek.
3. Przelicz ilosc dotychczasowych rachunkow.
4. Jesli ilosc rachunkow przekracza 100, zakoncz program.
*/

#include <iostream>
using namespace std;

int policzSume(int skladnik1, int skladnik2)
{
    return skladnik1 + skladnik2;
}

int policzRoznice(int odjemna, int odjemnik)
{
    return odjemna - odjemnik;
}

int policzIloczyn(int mnoznik1, int mnoznik2)
{
    return mnoznik1 * mnoznik2;
}

int policzIloraz(int dzielna, int dzielnik)
{
    return dzielna / dzielnik;
}

int policzReszte(int dzielna, int dzielnik)
{
    return dzielna % dzielnik;
}

void wykonajRachunekKalkulatorem(char znakObliczeniowy, int liczba1, int liczba2)
{
    switch(znakObliczeniowy)
        {
        case '+': cout << policzSume(liczba1, liczba2) << endl; break;
        case '-': cout << policzRoznice(liczba1, liczba2) << endl; break;
        case '*': cout << policzIloczyn(liczba1, liczba2) << endl; break;
        case '/': cout << policzIloraz(liczba1, liczba2) << endl; break;
        case '%': cout << policzReszte(liczba1, liczba2) << endl; break;
        }
}

int main()
{
    int liczba1, liczba2;
    char znakObliczeniowy;
    int licznikRachunkow = 0;
    while (cin >> znakObliczeniowy >> liczba1 >> liczba2)
    {
        wykonajRachunekKalkulatorem(znakObliczeniowy, liczba1, liczba2);
        licznikRachunkow++;
        if (licznikRachunkow > 100) break;
    }
    return 0;
}
