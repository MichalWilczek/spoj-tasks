#include <iostream>
#include <string>
using namespace std;

bool czySlowoToPalindrom(string slowo)
{
    int slowoDlugosc = slowo.length();
    if (slowoDlugosc <= 1) return true;
    else
    {
        if (slowo[0] == slowo[slowoDlugosc-1])
        {
            slowo.erase(slowoDlugosc-1,1);
            slowo.erase(0,1);
            return czySlowoToPalindrom(slowo);
        }
        else
        {
            return false;
        }
    }
}

void odpowiedzWartosciBoolean(bool wartosc)
{
    if (wartosc==true) cout << "tak" << endl;
    else cout << "nie" << endl;
}

int main()
{
    int ileZestawowDanych;
    cin >> ileZestawowDanych;
    for (int i=0; i<ileZestawowDanych; i++)
    {
        string slowo;
        cin >> slowo;
        bool wartosc = czySlowoToPalindrom(slowo);
        odpowiedzWartosciBoolean(wartosc);
    }
    return 0;
}
