#include <iostream>

using namespace std;

int main()
{
    int ilosc_rachunkow;
    cin >> ilosc_rachunkow;

    int bok_kwadratu[ilosc_rachunkow];
    for (int i=0; i<ilosc_rachunkow; i++)
    {
        cin >> bok_kwadratu[i];
        cout << bok_kwadratu[i]*bok_kwadratu[i] << endl;
    }
    return 0;
}
