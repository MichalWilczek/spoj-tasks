
/*
Napisz program, który wypisuje w oddzielnej linii liczby od 1 do 100.
Ale dla wielokrotnoœci liczby 3 ma wyœwietliæ „Iron” zamiast liczby,
oraz dla wielokrotnoœci liczby 7, ma wyœwietliæ „Man”. Dla liczb
bêd¹cych wielokrotnoœciami 3 oraz 7, ma wyœwietliæ „IronMan”
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
