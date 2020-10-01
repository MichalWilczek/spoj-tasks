
/*
Wypisz wszystkie liczby ai podzielne przez x i niepodzielne przez y, gdzie 1 < ai < n < 100000.

Wejœcie
Najpierw w oddzielnej linii t liczba przypadków testowych nastêpnie w kolejnych t liniach liczby n x y.

Wyjœcie
W kolejnych t liniach oddzielone pojedynczym odstêpem liczby spe³niaj¹ce warunki zadania wypisane od najmniejszej do najwiêkszej.
*/
#include <iostream>

using namespace std;

int main()
{
    int liczbaInteracji;
    int nLiczbaMaksymalna;
    int xLiczbaPodzielna;
    int yLiczbaNiepodzielna;

    cin >> liczbaInteracji;

    for (int i=0; i<liczbaInteracji; i++)
    {
        cin >> nLiczbaMaksymalna;
        cin >> xLiczbaPodzielna;
        cin >> yLiczbaNiepodzielna;

        for (int i=1; i<nLiczbaMaksymalna; i++)
        {
            if ((i%xLiczbaPodzielna == 0) && (i%yLiczbaNiepodzielna != 0))
                {
                    cout << i << " ";
                }
        }
        cout << endl;
    }
    return 0;
}
