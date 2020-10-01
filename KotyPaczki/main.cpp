#include <iostream>

using namespace std;

int main()
{
    int liczba_iteracji;
    cin >> liczba_iteracji;

    for (int i=0; i< liczba_iteracji; i++)
    {
        int liczba_kotow;
        int udzwig_harrego;
        int waga_jednego_paczka;

        cin >> liczba_kotow;
        cin >> udzwig_harrego;
        cin >> waga_jednego_paczka;

        if (liczba_kotow * waga_jednego_paczka > udzwig_harrego)
            { cout << "no" << endl; }
        else {cout << "yes" << endl; }
    }

    return 0;
}
