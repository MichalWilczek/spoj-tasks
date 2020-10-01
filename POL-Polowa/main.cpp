
/*
POL - Po³owa
Dla podanego ci¹gu d³ugoœci 2*k, wypisz na standardowe wyjœcie dok³adnie
pierwsz¹ po³owê ci¹gu.

Wejœcie
W pierwszej linijce wejœcia znajduje siê jedna liczba ca³kowita t (1<=t<=100).
Ka¿dy wiersz o numerze od 2 do t+1, zawiera ci¹g d³ugoœci 2*k (1<=k<=1000).

Wyjœcie
Dla ka¿dego przypadku testowego na wyjœciu powinien pojawiæ siê ci¹g
bêd¹cy pierwsz¹ po³ow¹ wczytanego ci¹gu.
*/

#include <iostream>

using namespace std;

int main()
{
    int iteration;
    string word;

    cin >> iteration;
    for (int i=0; i<iteration; i++)
    {
        cin >> word;
        for (int j=0; j<word.length()/2; j++)
        {
            cout << word[j];
        }
        cout << endl;
    }
    return 0;
}
