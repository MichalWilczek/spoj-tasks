#include <iostream>
#include <string>
using namespace std;

int odczytajLitereSzyfru(char litera, int ktoraLitera=1)
{
    if (ktoraLitera==1)
    {
        switch (litera)
        {
            case 'A': return 0; break;
            case 'B': return 1; break;
            case 'C': return 2; break;
            case 'D': return 3; break;
            case 'E': return 4; break;
            case 'F': return 5; break;
            case 'G': return 6; break;
            case 'H': return 7; break;
            case 'I': return 8; break;
            case 'J': return 9; break;
            case 'K': return 10; break;
            case 'L': return 11; break;
            case 'M': return 12; break;
            case 'N': return 13; break;
            case 'O': return 14; break;
            case 'P': return 15; break;
            default: cout << "Prosze, podaj litere z zakresu A-P..."<<endl;
        }
    }
    else if (ktoraLitera==2)
    {
        switch (litera)
        {
            case 'A': return 0; break;
            case 'B': return 16; break;
            case 'C': return 32; break;
            case 'D': return 48; break;
            case 'E': return 64; break;
            case 'F': return 80; break;
            case 'G': return 96; break;
            case 'H': return 112; break;
            case 'I': return 128; break;
            case 'J': return 144; break;
            case 'K': return 160; break;
            case 'L': return 176; break;
            case 'M': return 192; break;
            case 'N': return 208; break;
            case 'O': return 224; break;
            case 'P': return 240; break;
            default: cout << "Prosze, podaj litere z zakresu A-P..."<<endl;
        }
    }
    else
    {
        cout << "Zmienna ktoraLitera posiada wartosc 1 lub 2..."<<endl;
    }
}

void odszyfrujKod(string hasloZaszyfrowane)
{
    int hasloDlugosc = hasloZaszyfrowane.length();
    for (int i=0; i<hasloDlugosc; i+=2)
    {
        int sumaLitera = 0;
        for (int j=0; j<2; j++)
        {
            sumaLitera += odczytajLitereSzyfru(hasloZaszyfrowane[i+j], j+1);
        }
        cout << char(sumaLitera);
    }
    cout << endl;
}

int main()
{
    string hasloZakodowane;
    while (cin>>hasloZakodowane)
    {
        odszyfrujKod(hasloZakodowane);
    }

    return 0;
}
