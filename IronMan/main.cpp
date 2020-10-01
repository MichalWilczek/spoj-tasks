
/*
Napisz program, kt�ry wypisuje w oddzielnej linii liczby od 1 do 100.
Ale dla wielokrotno�ci liczby 3 ma wy�wietli� �Iron� zamiast liczby,
oraz dla wielokrotno�ci liczby 7, ma wy�wietli� �Man�. Dla liczb
b�d�cych wielokrotno�ciami 3 oraz 7, ma wy�wietli� �IronMan�
*/

#include <iostream>

using namespace std;

int main()
{
    for (int i=1; i<=100; i++)
    {
        if (i%3==0 && i%7==0)
        {
            cout << "IronMan" << endl;
        }
        else if (i%3==0 && i%7!=0)
        {
            cout << "Iron" << endl;
        }
        else if (i%3!=0 && i%7==0)
        {
            cout << "Man" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }
}
