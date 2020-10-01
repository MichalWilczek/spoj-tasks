/*
Dla liczb calkowitych n i k, 0 <= k <= n <= 1000,
wyznacz liczbe roznych k-elementowych podzbiorow
zbioru n-elementowego. Liczby n i k beda dobrane
tak, aby wynik nie przekroczyl 1 000 000 000.

Input
T [ liczba testów, T <= 10000 ]
n_1 k_1
n_2 k_2
...
n_T k_T

Output
wynik_1
wynik_2
...
wynik_T
*/

#include <iostream>
#include <stdio.h>
using namespace std;

long long silnia(long long n)
{
    if (n==0) return 1;
    else return n*silnia(n-1);
}

long long iloczynKolejnychLiczbNaturalnych(long long nMin, long long nMax)
{
    if (nMin==nMax) return nMax;
    else return nMax*iloczynKolejnychLiczbNaturalnych(nMin, nMax-1);
}

long long symbolNewtonaMetoda1(long long n, long long k)
{
    long long licznik;
    long long mianownik;
    if (n==0 && k==0) return 1;
    else if ((n-k)>=k)
    {
        licznik = iloczynKolejnychLiczbNaturalnych(n-k+1, n);
        mianownik = silnia(k);
    }
    else
    {
        licznik = iloczynKolejnychLiczbNaturalnych(k+1, n);
        mianownik = silnia(n-k);
    }
    return licznik/mianownik;
}

double symbolNewtonaMetoda2(double n, double k)
{
    double wynik = 1;
    for (int i=1; i<=k; i++)
    {
        wynik = (wynik * (n-i+1))/i;
    }
    return wynik;
}

int main()
{
    long long n, k;
    int liczbaTestow;
    cin >> liczbaTestow;

    for (int i=0; i<liczbaTestow; i++)
    {
        cin >> n >> k;
        printf("%1.0f\n", symbolNewtonaMetoda2(n, k));
    }
    return 0;
}
