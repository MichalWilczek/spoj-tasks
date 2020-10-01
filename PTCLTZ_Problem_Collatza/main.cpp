/*
Dany jest ci¹g xn okreœlony rekurencyjnie:
x0=s,
xn+1=3*xn+1, jeœli xn jest nieparzyste i
xn+1=xn/2, jeœli xn jest parzyste

Napisz program, który oblicza pierwsze takie n,
dla którego xn=1.

Wejœcie
W pierwszej linii liczba testów t. W ka¿dym
z t kolejnych wierszy jedna liczba ca³kowita s, 1 <= s <= 10000.

Wyjœcie
W ka¿dej linii jedna liczba - obliczona wartoœæ n.
*/

#include <iostream>
using namespace std;

int obliczIloscLiczbWCiaguCollatza(int n, int licznik)
{
    if (n==1)
        return licznik;
    else
    {
        if (n%2==0)
            return obliczIloscLiczbWCiaguCollatza(n/2, licznik+1);
        else
            return obliczIloscLiczbWCiaguCollatza(3*n+1, licznik+1);
    }
}

int main()
{
    int liczba;
    int liczbaTestow;
    cin >> liczbaTestow;

    for (int i=0; i<liczbaTestow; i++)
    {
        cin >> liczba;
        int liczbaPowtorzen = obliczIloscLiczbWCiaguCollatza(liczba, 0);
        cout << liczbaPowtorzen << endl;
    }
    return 0;
}
