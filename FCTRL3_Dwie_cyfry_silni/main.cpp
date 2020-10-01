#include <iostream>
#include <string>
#include <sstream>

using namespace std;

long long policzSilnie(int n)
{
    if (n==0) return 1;
    else return n*policzSilnie(n-1);
}

string konwertujIntNaString(long long liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

void podajDwieOstatnieCyfryLiczby(long long liczba)
{
    string liczbaStr = konwertujIntNaString(liczba);
    int liczbaStrDlugosc = liczbaStr.length();
    if (liczbaStrDlugosc >= 2)
    {
        cout << liczbaStr[liczbaStrDlugosc-2] << " " << liczbaStr[liczbaStrDlugosc-1] << endl;
    }
    else
    {
        cout << "0 " << liczbaStr[liczbaStrDlugosc-1] << endl;
    }
}

int main()
{
    int liczbaPowtorzen;
    cin >> liczbaPowtorzen;

    for (int i=0; i<liczbaPowtorzen; i++)
    {
        int LiczbaN;
        cin >> LiczbaN;

        long long silnia = policzSilnie(LiczbaN);
        podajDwieOstatnieCyfryLiczby(silnia);
    }
    return 0;
}
