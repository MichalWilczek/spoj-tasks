#include <iostream>

using namespace std;

int podaj_liczbe_w_formie_tablicy_z_pojedynczymi_cyframi(liczba)
{
    howManyDigits = (int)log10(liczba) + 1;
    cout << "Ilosc cyfr = " << howManyDigits;
    return howManyDigits
}

int main()
{
    int ilosc_numerow_pesel;
    cout << "Podaj ilosc numerow pesel do zapisu: ";
    cin >> ilosc_numerow_pesel;

    int pesel[ilosc_numerow_pesel];
    for (int i=0; i<ilosc_numerow_pesel; i++)
    {
        cout << "Podaj pesel numer " << i+1 << ": ";
        cin >> pesel[i];
        podaj_liczbe_w_formie_tablicy_z_pojedynczymi_cyframi(pesel[i])
    }

    return 0;
}
