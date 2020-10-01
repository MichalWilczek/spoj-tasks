/*
Dany jest ci�g xn okre�lony rekurencyjnie:
x0=s,
xn+1=3*xn+1, je�li xn jest nieparzyste i
xn+1=xn/2, je�li xn jest parzyste

Napisz program, kt�ry oblicza pierwsze takie n,
dla kt�rego xn=1.

Wej�cie
W pierwszej linii liczba test�w t. W ka�dym
z t kolejnych wierszy jedna liczba ca�kowita s, 1 <= s <= 10000.

Wyj�cie
W ka�dej linii jedna liczba - obliczona warto�� n.
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
