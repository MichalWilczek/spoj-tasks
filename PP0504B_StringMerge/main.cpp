#include <iostream>

using namespace std;

int sumujTablice(int *tab, int iloscIndeksow)
{
    int suma=0;
    for (int i=0; i<iloscIndeksow; i++)
    {
        suma += *tab;
        tab++;
    }
    return suma;
}

int sumujIloscCiastekSpozytychPrzezGraczy(int *iloscCiastekSpozytych, int iloscGraczy)
{
    for (int i=0; i<iloscGraczy; i++)
    {
        cin >> iloscCiastekSpozytych[i];
        iloscCiastekSpozytych[i] = 3600*24/iloscCiastekSpozytych[i]; // wychodzi calkowita ilosc ciastek spozytych w 24 godziny
        //cout << iloscCiastekSpozytych[i] << endl;
    }
    return sumujTablice(iloscCiastekSpozytych, iloscGraczy);
}

int obliczIloscPudelekDoKupienia(int lacznaIloscCiastekSpozytaPrzezGraczy, int iloscCiastekWJednymPudelku)
{
    if (lacznaIloscCiastekSpozytaPrzezGraczy % iloscCiastekWJednymPudelku == 0)
    {
        return lacznaIloscCiastekSpozytaPrzezGraczy/iloscCiastekWJednymPudelku;
    }
    else
    {
        return lacznaIloscCiastekSpozytaPrzezGraczy/iloscCiastekWJednymPudelku+1;
    }
}

int main()
{
    int iloscGraczy;
    int iloscCiastekWJednymPudelku;
    int *iloscCiastekSpozytych;

    int iloscRozgrywek;
    cin >> iloscRozgrywek;

    for (int i=0; i<iloscRozgrywek; i++)
    {
        cin >> iloscGraczy >> iloscCiastekWJednymPudelku;
        iloscCiastekSpozytych = new int [iloscGraczy];
        int iloscCiastekSpozytychPrzezGraczy = sumujIloscCiastekSpozytychPrzezGraczy(iloscCiastekSpozytych, iloscGraczy);
        cout << obliczIloscPudelekDoKupienia(iloscCiastekSpozytychPrzezGraczy, iloscCiastekWJednymPudelku) << endl;
        delete [] iloscCiastekSpozytych;
    }
    return 0;
}
